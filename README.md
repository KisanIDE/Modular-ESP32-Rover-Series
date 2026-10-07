# 🚀 Modular ESP32 Rover Series

Welcome to the **ESP32 Modular Rover Project**! This repository tracks the build and progress of a low-cost, 3-wheel differential-drive robot built using accessible components and standard Arduino programming.

The goal of this project is to demonstrate how real-world engineering, microcontrollers, and autonomous systems can be learned hands-on without needing expensive commercial kits.

---

## 🛠 System Architecture
* **Microcontroller:** ESP32 Dev Module
* **Drive System:** 3-Wheel Platform (2 Rear DC Gear Motors + 1 Front Passive Caster Wheel)
* **Motor Control:** L298N Dual H-Bridge Driver Module
* **Power Management:** 7.4V–9V DC with a Common Ground System
* **Sensors:** Sequential modular integration (Ultrasonic, IR, LDR, Displays)
* **Firmware Environment:** C++ / Arduino Framework (ArduinoDroid compatible)

---

## 📂 Released Modules

### 🟢 Project 01: Smartphone-Controlled Base Build
* **Features:** Wireless Bluetooth direction control, PWM speed tuning (`motorSpeed = 100`) for smooth desk performance, differential steering logic.
* **Directory:** [`/Project_01_Bluetooth_Base`](./Project_01_Bluetooth_Base)
* **Files Included:** Source code (`Project_01_Bluetooth_Base.ino`), Wiring schematic diagram (`Wiring_Schematic.png`), Documentation.

### 🟢 Project 02: Autonomous Obstacle Avoidance Rover
* **Features:** Echolocation distance sensing via HC-SR04 ultrasonic sensor, low-speed indoor precision tuning (`motorSpeed = 80`), 15cm threshold auto-stop, backing, and turn-evasion routine.
* **Directory:** [`/Project_02_Obstacle_Avoidance`](./Project_02_Obstacle_Avoidance)
* **Files Included:** Source code (`main.c`), Wiring schematic reference, Readme.

*(New sensor integrations and modules will be appended here as they are published!)*

---

## 🎓 1-on-1 Live Mentorship & STEM Training

I teach hands-on Robotics, Embedded Systems, and IoT to K-12 students through interactive, project-based learning.

* **For Parents:** Help your child build real-world engineering skills. I offer live **1-on-1 classes and interactive group batches** tailored to beginner and intermediate levels.
* **For Educators & Recruiters:** I design practical STEM curricula, facilitate technical workshops, and provide freelance robotics training.

📩 **Get in Touch:** DM me **"ROVER"** on LinkedIn or email me at `aayushchaudhary412@gmail.com` to book a free trial class or discuss collaboration!

---

## 📜 License
Distributed under the MIT License. See `LICENSE` for details.
