#include "esp_camera.h"
#include <WiFi.h>
#include <WiFiUdp.h>

const char* ssid = "hotsiput";
const char* password = "12345678";
WiFiUDP udp;
const char* hostIP = "10.223.202.133"; // Python host
const int port = 5005;

#define FRAME_CHUNK_SIZE 1024

#define PWDN_GPIO_NUM    32
#define RESET_GPIO_NUM   -1
#define XCLK_GPIO_NUM     0
#define SIOD_GPIO_NUM    26
#define SIOC_GPIO_NUM    27
#define Y9_GPIO_NUM      35
#define Y8_GPIO_NUM      34
#define Y7_GPIO_NUM      39
#define Y6_GPIO_NUM      36
#define Y5_GPIO_NUM      21
#define Y4_GPIO_NUM      19
#define Y3_GPIO_NUM      18
#define Y2_GPIO_NUM       5
#define VSYNC_GPIO_NUM   25
#define HREF_GPIO_NUM    23
#define PCLK_GPIO_NUM    22

void setup() {
  Serial.begin(115200);

  pinMode(4, OUTPUT);
  digitalWrite(4, LOW); // LED on

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  camera_config_t config;
  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer = LEDC_TIMER_0;
  config.pin_d0 = Y2_GPIO_NUM;
  config.pin_d1 = Y3_GPIO_NUM;
  config.pin_d2 = Y4_GPIO_NUM;
  config.pin_d3 = Y5_GPIO_NUM;
  config.pin_d4 = Y6_GPIO_NUM;
  config.pin_d5 = Y7_GPIO_NUM;
  config.pin_d6 = Y8_GPIO_NUM;
  config.pin_d7 = Y9_GPIO_NUM;
  config.pin_xclk = XCLK_GPIO_NUM;
  config.pin_pclk = PCLK_GPIO_NUM;
  config.pin_vsync = VSYNC_GPIO_NUM;
  config.pin_href = HREF_GPIO_NUM;
  config.pin_sscb_sda = SIOD_GPIO_NUM;
  config.pin_sscb_scl = SIOC_GPIO_NUM;
  config.pin_pwdn = PWDN_GPIO_NUM;
  config.pin_reset = RESET_GPIO_NUM;
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size = FRAMESIZE_VGA; // safe resolution
  config.jpeg_quality = 12;
  config.fb_count = 1; // single buffer for low RAM

  if (esp_camera_init(&config) != ESP_OK) {
    Serial.println("Camera init failed");
    while (true);
  }
  Serial.println("Camera ready");
}

void loop() {
  camera_fb_t * fb = esp_camera_fb_get();
  if (!fb) return;

  uint32_t len = fb->len;
  uint8_t lenBytes[4] = { 
    (uint8_t)(len >> 24), (uint8_t)(len >> 16), 
    (uint8_t)(len >> 8), (uint8_t)(len)
  };
  udp.beginPacket(hostIP, port);
  udp.write(lenBytes, 4);
  udp.endPacket();

  for (int i = 0; i < fb->len; i += FRAME_CHUNK_SIZE) {
    int size = ((i + FRAME_CHUNK_SIZE) > fb->len) ? (fb->len - i) : FRAME_CHUNK_SIZE;
    udp.beginPacket(hostIP, port);
    udp.write(fb->buf + i, size);
    udp.endPacket();
  }

  esp_camera_fb_return(fb);
  delay(50); // ~20 FPS
}