/*
  Project 02: ESP32 Autonomous Obstacle Avoidance Rover (Slow & Controlled)
  Board: ESP32 Dev Module
  
  Motor Pins (L298N):
  - Left Motor:  ENA = GPIO 14, IN1 = GPIO 27, IN2 = GPIO 26
  - Right Motor: ENB = GPIO 32, IN3 = GPIO 25, IN4 = GPIO 33
  
  Ultrasonic Pins (HC-SR04):
  - Trig = GPIO 5, Echo = GPIO 18
*/

// --- Pin Definitions ---
// Left Motor Pins
const int ENA = 14;
const int IN1 = 27;
const int IN2 = 26;

// Right Motor Pins
const int ENB = 32;
const int IN3 = 25;
const int IN4 = 33;

// Ultrasonic Sensor Pins
const int TRIG_PIN = 5;
const int ECHO_PIN = 18;

// --- Speed & Distance Configuration ---
// Reduced PWM speed (0-255) for smooth indoor movement without overshooting
const int motorSpeed = 80;

// Detection threshold in centimeters (reduced for lower speeds)
const int DISTANCE_THRESHOLD = 15;

// Function Declarations
long getDistance();
void moveForward();
void moveBackward();
void turnRight();
void stopMotors();

void setup() {
  // Initialize Serial Monitor for debugging distance readings
  Serial.begin(115200);

  // Set motor control pins as OUTPUT
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Set ultrasonic sensor pins
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Ensure motors start off on power-up
  stopMotors();
  delay(1000); // 1-second pause before starting movement
}

void loop() {
  long distance = getDistance();
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if an obstacle is within the safety threshold
  if (distance > 0 && distance <= DISTANCE_THRESHOLD) {
    // 1. Instant emergency stop
    stopMotors();
    delay(150);
    
    // 2. Back up slightly at low speed
    moveBackward();
    delay(300);
    
    // 3. Spin right to re-orient toward an open space
    turnRight();
    delay(350);
    
    // 4. Brief pause before scanning again
    stopMotors();
    delay(150);
  } else {
    // Path is clear ahead, continue forward motion
    moveForward();
  }

  // Short sample delay for responsive continuous scanning
  delay(40);
}

// --- Echolocation Function ---
long getDistance() {
  // Send a short 10-microsecond pulse to activate trigger
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read the echo pin pulse duration in microseconds (30ms timeout)
  long duration = pulseIn(ECHO_PIN, HIGH, 30000);
  
  // If timeout occurs (no object detected within range), return safe default
  if (duration == 0) return 999;
  
  // Calculate distance in centimeters: Speed of sound = 0.0343 cm/us (divided by 2 for round-trip)
  return duration * 0.0343 / 2;
}

// --- Low-Speed Movement Functions ---

void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, motorSpeed);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, motorSpeed);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, motorSpeed);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, motorSpeed);
}

void turnRight() {
  // Left motor forward, right motor reverse for a tight zero-radius turn
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, motorSpeed);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENB, motorSpeed);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
