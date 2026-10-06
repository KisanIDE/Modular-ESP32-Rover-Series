/*
  Project 01: ESP32 3-Wheel Bluetooth Rover (Base Build)
  Board: ESP32 Dev Module
  
  Pin Connections:
  - Left Motor:  ENA = GPIO 14, IN1 = GPIO 27, IN2 = GPIO 26
  - Right Motor: ENB = GPIO 32, IN3 = GPIO 25, IN4 = GPIO 33
*/

#include "BluetoothSerial.h"

// Check if Bluetooth is enabled in build settings
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run make menuconfig to enable it
#endif

BluetoothSerial SerialBT;

// --- Pin Definitions ---
// Left Motor Pins
const int ENA = 14;
const int IN1 = 27;
const int IN2 = 26;

// Right Motor Pins
const int ENB = 32;
const int IN3 = 25;
const int IN4 = 33;

// --- Motor Speed Setting ---
// PWM Speed range: 0 (Stop) to 255 (Full Speed)
// Set to 100 for stable half-speed desk testing
const int motorSpeed = 100;

// Function Declarations
void moveForward();
void moveBackward();
void turnLeft();
void turnRight();
void stopMotors();

void setup() {
  // Initialize Serial Monitor for debugging
  Serial.begin(115200);

  // Set motor control pins as OUTPUT
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Stop motors on initial boot
  stopMotors();

  // Initialize Bluetooth Classic with device name
  SerialBT.begin("ESP32_ROVER");
  Serial.println("Bluetooth device ready. Pair with 'ESP32_ROVER'");
}

void loop() {
  // Check if Bluetooth data is received
  if (SerialBT.available()) {
    char command = SerialBT.read();
    Serial.print("Received Command: ");
    Serial.println(command);

    // Command handling from mobile controller app
    switch (command) {
      case 'F':
      case 'f':
        moveForward();
        break;
      case 'B':
      case 'b':
        moveBackward();
        break;
      case 'L':
      case 'l':
        turnLeft();
        break;
      case 'R':
      case 'r':
        turnRight();
        break;
      case 'S':
      case 's':
        stopMotors();
        break;
      default:
        // Optional: stop on unknown input
        break;
    }
  }
}

// --- Movement Functions ---

void moveForward() {
  // Left Motor Forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, motorSpeed);

  // Right Motor Forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, motorSpeed);
}

void moveBackward() {
  // Left Motor Reverse
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, motorSpeed);

  // Right Motor Reverse
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, motorSpeed);
}

void turnLeft() {
  // Left Motor Reverse (Spin in place)
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, motorSpeed);

  // Right Motor Forward
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, motorSpeed);
}

void turnRight() {
  // Left Motor Forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, motorSpeed);

  // Right Motor Reverse (Spin in place)
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, motorSpeed);
}

void stopMotors() {
  // Turn off enable pins and set inputs LOW
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
