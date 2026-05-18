# Guardian Angel 🛸
<p align="center">
  <strong>An AI-Powered Smart Patrol Drone System for Campus Security</strong><br>
  <em>Sistem Dron Rondaan Keselamatan Pintar Berasaskan AI untuk Keselamatan Kampus</em>
</p>

---

## 🇲🇾 Bahasa Melayu

### Deskripsi Projek
**Guardian Angel** ialah sebuah projek inovasi sistem dron rondaan keselamatan pintar yang direka khusus untuk memperkukuh ekosistem keselamatan di Kolej Matrikulasi Johor (KMJ). Dibangunkan berasaskan pendekatan *Proof of Concept* (POC), projek ini bertujuan mentransformasikan pengurusan pengawasan konvensional ke arah konsep Kampus Pintar (*Smart Campus*). 

Sistem ini menggabungkan pemantauan udara autonomi bagi mengatasi keterbatasan rondaan manual manusia dan kamera litar tertutup (CCTV) statik yang mempunyai sudut liputan terhad. Dengan keupayaan mobiliti tinggi, dron ini mampu memantau kawasan kampus seluas 56 ekar termasuk lokasi-lokasi terpencil, laluan sunyi, dan kawasan berisiko tinggi seperti blok kediaman pelajar, kawasan parkir, dan perimeter bangunan.

### Ciri-Ciri Utama & Fungsi Pintar
**AI Vision & Pembelajaran Mesin:** Menggunakan algoritma penglihatan komputer untuk mengesan kehadiran manusia, pergerakan luar biasa, serta mengecam identiti pelajar (wajah, nama, dan nombor matrik) secara masa nyata.
**Pemantauan Siang & Malam:** Dilengkapi modul kamera ESP32-CAM dengan sokongan teknologi *Night Vision* / kamera terma untuk pengesanan berasaskan haba badan dalam keadaan cahaya rendah.
**Pengesanan Awal Kecemasan (Sensor Gas):** Membawa sensor gas (MQ2) untuk mengesan asap atau kebocoran gas berbahaya secara awal bagi mencegah risiko kebakaran atau letupan.
**Navigasi Autonomi GPS:** Mengintegrasikan modul GPS untuk membolehkan dron terbang secara automatik mengikut laluan rondaan berjadual yang ditetapkan serta menyokong fungsi *Return to Home*.
**Komunikasi Dua Hala & Sistem Amaran:** Dilengkapi pembesar suara, mikrofon, dan penggera akustik untuk menyalurkan amaran awal atau arahan kecemasan di lokasi.
**Kecekapan Tenaga & Operasi Senyap:** Menyokong sistem dok pengecasan automatik (*docking station*) apabila bateri pintar berada pada tahap rendah (15%), serta menggunakan kipas ultra senyap untuk operasi rahsia tanpa mengganggu persekitaran pembelajaran.

### Timbunan Teknologi & Komponen (Tech Stack)
**Perisian (Software):** Python, OpenCV (Pemprosesan video masa nyata), YOLOv8 (Algoritma pengesanan objek), PyCharm IDE.
**Perkakasan (Hardware):** Kerangka Dron Syma X5SW, ESP32-CAM, Modul GPS NEO-6M, Kamera *Night Vision* 5MP, Sensor Gas MQ2, *IR Obstacle Avoidance Sensor*.
**Komunikasi:** Sambungan WiFi & Rangkaian 4G LTE (untuk penghantaran video jarak jauh masa nyata).

---

## 🇬🇧 English

### Project Description
**Guardian Angel** is an innovative AI-powered smart patrol drone system explicitly designed to reinforce the security ecosystem at Johor Matriculation College (KMJ). Developed as a Proof of Concept (POC), this project aims to transform conventional security surveillance toward a Smart Campus framework.

The system introduces autonomous aerial monitoring to overcome the traditional constraints faced by physical manual patrols and static CCTV cameras, which suffer from limited blind spots. Leveraging high mobility, the drone is capable of monitoring the entire 56-acre campus layout, including remote paths, secluded alleys, and high-risk zones like student residential blocks, parking spaces, and building perimeters

### Key Features & Smart Functions
**AI Vision & Machine Learning:** Employs computer vision algorithms to automatically detect human presence, abnormal movements, and recognize student identities (faces, names, and matric numbers) in real-time.
**Day & Night Surveillance:** Equipped with an ESP32-CAM module integrated with Night Vision / thermal camera technology to identify human presence through body heat signature under low-light conditions.
**Early Emergency Detection (Gas Sensor):** Integrates an MQ2 gas sensor to detect hazardous smoke or gas leaks early, proactively mitigating the risk of campus fires or explosions.
**Autonomous GPS Navigation:** Embedded with a GPS module allowing the drone to navigate designated patrol routes autonomously without manual control, while supporting safety features like *Return to Home*.
**Two-Way Communication & Alarm System:** Equipped with onboard speakers, a microphone, and an acoustic alarm to broadcast early warnings or emergency instructions directly at the scene.
**Energy Efficiency & Silent Operation:** Features smart batteries with automated docking station integration for self-charging when power drops below 15%, alongside ultra-silent fans for low-profile patrolling that doesn't disrupt class sessions.

### Tech Stack & Components
**Software:** Python, OpenCV (Real-time video processing), YOLOv8 (Deep learning object detection algorithm), PyCharm IDE.
**Hardware:** Syma X5SW Drone Platform, ESP32-CAM, NEO-6M GPS Module, 5MP Night Vision Camera, MQ2 Smoke/Gas Sensor Module, IR Infrared Obstacle Avoidance Sensor.
**Communication:** WiFi & 4G LTE Connectivity (For long-range live video data streaming).
