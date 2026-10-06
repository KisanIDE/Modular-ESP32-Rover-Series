# Smartphone-Controlled ESP32 Rover (Base Build)

This is the foundational build of the Modular ESP32 Rover Series. It establishes the power management, motor driving logic, and wireless Bluetooth communications for a 3-wheel differential-drive robot.

---

## 🛠️ Features & Specifications
* **Wireless Control:** Controlled via Bluetooth Classic using the `BluetoothSerial.h` library.
* **Differential Steering:** 2 rear DC gear motors drive forward, backward, left, right, and perform zero-radius spins.
* **Speed Stability:** PWM calibrated to half-speed (`motorSpeed = 100`) for smooth, controlled desk testing.
* **Power Architecture:** Powered by a 7.4V–9V battery pack with a mandatory **common ground** connected between the battery, L298N driver, and ESP32.

---

## 📌 Pin Mapping Table

| Component | Pin / Terminal | ESP32 GPIO | Function |
| :--- | :--- | :--- | :--- |
| **L298N** | ENA *(Jumper Off)* | GPIO 14 | Left Motor Speed (PWM) |
| **L298N** | IN1 | GPIO 27 | Left Motor Direction 1 |
| **L298N** | IN2 | GPIO 26 | Left Motor Direction 2 |
| **L298N** | IN3 | GPIO 25 | Right Motor Direction 1 |
| **L298N** | IN4 | GPIO 33 | Right Motor Direction 2 |
| **L298N** | ENB *(Jumper Off)* | GPIO 32 | Right Motor Speed (PWM) |
| **L298N** | 5V Terminal | VIN Pin | Powers ESP32 board |
| **L298N** | GND Terminal | GND Pin | Common Ground Connection |

---

## 📂 Included Files
* `Project_01_Bluetooth_Base.ino` – Full Arduino C++ firmware.
* `Wiring_Schematic.png` – Clear pin-to-pin wiring schematic diagram.

---

## 🚀 How to Run
1. Wire components according to the `Wiring_Schematic.png`.
2. Open `Project_01_Bluetooth_Base.ino` in the Arduino IDE or **ArduinoDroid**.
3. Select **ESP32 Dev Module** as your target board and upload the sketch.
4. Open your smartphone's Bluetooth settings, pair with **`ESP32_ROVER`**, and send direction commands (`F`, `B`, `L`, `R`, `S`).

---

