import socket
import cv2
import numpy as np
from ultralytics import YOLO

# ---------- YOLOv8 setup ----------
model = YOLO("yolov8n.pt")  # nano model
PERSON_CLASS_ID = 0  # YOLOv8 class 0 = person

# ---------- UDP setup ----------
UDP_IP = "0.0.0.0"
UDP_PORT = 5005
BUFFER_SIZE = 65535

sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind((UDP_IP, UDP_PORT))
print(f"Listening on {UDP_IP}:{UDP_PORT}")

frame_buffer = bytearray()
receiving_frame = False

# ---------- OpenCV full screen setup ----------
cv2.namedWindow("ESP32-CAM Human Detection", cv2.WINDOW_NORMAL)
cv2.setWindowProperty("ESP32-CAM Human Detection", cv2.WND_PROP_FULLSCREEN, cv2.WINDOW_FULLSCREEN)

while True:
    data, addr = sock.recvfrom(BUFFER_SIZE)

    # Detect start of JPEG
    if b'\xff\xd8' in data:
        receiving_frame = True
        frame_buffer = bytearray()
        start_index = data.find(b'\xff\xd8')
        frame_buffer.extend(data[start_index:])
        continue

    # Collect frame data
    if receiving_frame:
        frame_buffer.extend(data)

        # Detect end of JPEG
        if b'\xff\xd9' in data:
            eoi_index = frame_buffer.find(b'\xff\xd9') + 2
            jpeg_bytes = frame_buffer[:eoi_index]

            # Decode JPEG
            np_arr = np.frombuffer(jpeg_bytes, np.uint8)
            frame = cv2.imdecode(np_arr, cv2.IMREAD_COLOR)

            if frame is not None:
                # Flip upside down
                frame = cv2.flip(frame, -1)

                # Optional: resize for faster detection
                small_frame = cv2.resize(frame, (320, 240))

                # YOLOv8 inference
                results = model(small_frame)[0]

                # Draw boxes for humans only
                for box in results.boxes:
                    cls = int(box.cls[0])
                    if cls != PERSON_CLASS_ID:
                        continue
                    x1, y1, x2, y2 = map(int, box.xyxy[0])
                    conf = box.conf[0]
                    label = f"Person {conf:.2f}"
                    # Scale box back to original frame size if resized
                    scale_x = frame.shape[1] / small_frame.shape[1]
                    scale_y = frame.shape[0] / small_frame.shape[0]
                    x1 = int(x1 * scale_x)
                    y1 = int(y1 * scale_y)
                    x2 = int(x2 * scale_x)
                    y2 = int(y2 * scale_y)
                    cv2.rectangle(frame, (x1, y1), (x2, y2), (0, 255, 0), 2)
                    cv2.putText(frame, label, (x1, y1 - 10),
                                cv2.FONT_HERSHEY_SIMPLEX, 0.5, (0, 255, 0), 2)

                cv2.imshow("ESP32-CAM Human Detection", frame)
                if cv2.waitKey(1) & 0xFF == ord('q'):
                    break
            else:
                print("Warning: skipped corrupt frame")

            # Reset buffer
            frame_buffer = bytearray()
            receiving_frame = False

cv2.destroyAllWindows()
sock.close()