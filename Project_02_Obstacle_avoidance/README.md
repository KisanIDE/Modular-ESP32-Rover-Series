# Project 02: ESP32 Autonomous Obstacle Avoidance Rover

This module adds autonomous navigation and spatial awareness to the ESP32 3-wheel rover platform using an HC-SR04 ultrasonic distance sensor.

---

## Features & Logic
* **Echolocation Distance Sensing:** Continuously sends 40kHz ultrasonic sound pulses to measure front clearance in real-time.
* **Low-Speed Precision Tuning:** Configured at a lower PWM motor speed (`motorSpeed = 80`) to ensure tight indoor control and prevent overshooting obstacles.
* **Automatic Avoidance Reflex:** When an obstacle triggers the 15cm threshold, the rover executes a four-stage safety routine:
  1. Instant emergency stop
  2. Short reverse backing sequence
  3. 90-degree pivot turn to scan for clear space
  4. Automatic forward path resumption

---

## Pin Mapping Table

| Component | Pin / Terminal | ESP32 GPIO | Function |
| :--- | :--- | :--- | :--- |
| **HC-SR04** | Trig Pin | GPIO 5 | Ultrasonic Trigger Output |
| **HC-SR04** | Echo Pin | GPIO 18 | Ultrasonic Echo Input |
| **HC-SR04** | VCC | VIN / 5V Rail | 5V Power Supply |
| **HC-SR04** | GND | GND | Common Ground |
| **L298N** | ENA / ENB | GPIO 14 / GPIO 32 | Left & Right Motor PWM Speed |
| **L298N** | IN1 / IN2 | GPIO 27 / GPIO 26 | Left Motor Steering Direction |
| **L298N** | IN3 / IN4 | GPIO 25 / GPIO 33 | Right Motor Steering Direction |

---

## 📂 Included Files
* `main.c` – Autonomous C/C++ source code for the ESP32.
* `Wiring_Schematic.png` – Sensor and motor driver pinout connection diagram.

---

## 🚀 How to Run
1. Mount the HC-SR04 ultrasonic sensor facing forward at the front of the chassis.
2. Connect `Trig` to **GPIO 5** and `Echo` to **GPIO 18**. Connect sensor power to the 5V rail shared with `VIN`.
3. Open `main.c` in your IDE (Arduino IDE, PlatformIO, or ESP-IDF).
4. Select **ESP32 Dev Module** as your target board and compile/upload the code.
5. Place the rover on the floor near obstacles and power it on!

---

⬅️ [Back to Main Repository README](../README.md)
