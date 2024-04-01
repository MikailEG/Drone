#include <Servo.h>

// Define motor pins (must be PWM-capable pins)
const int motorPins[] = {3, 5, 7 , 9};
Servo motor1, motor2, motor3, motor4;

// Speed variables for each motor
int motorSpeeds[] = {0, 0, 0, 0}; // Initialize all speeds to 0%
const int speedStep = 11
; // Speed change step

void setup() {
  Serial.begin(9600); // Start serial communication
  
  // Attach motors to their pins
  motor1.attach(motorPins[0]);
  motor2.attach(motorPins[1]);
  motor3.attach(motorPins[2]);
  motor4.attach(motorPins[3]);
  
  // Initial motor speed to 0 (stopped)
  updateMotorSpeeds();
  Serial.println("Setup complete. Use numbers 1-8 to control motor speeds.");
}

void loop() {
  if (Serial.available() > 0) {
    char incomingChar = Serial.read();

    // Determine action based on input
    switch (incomingChar) {
      case '1': // Increase speed of motor 1
        adjustSpeed(0, speedStep);
        break;
      case '2': // Decrease speed of motor 1
        adjustSpeed(0, -speedStep);
        break;
      case '3': // Increase speed of motor 2
        adjustSpeed(1, speedStep);
        break;
      case '4': // Decrease speed of motor 2
        adjustSpeed(1, -speedStep);
        break;
      case '5': // Increase speed of motor 3
        adjustSpeed(2, speedStep);
        break;
      case '6': // Decrease speed of motor 3
        adjustSpeed(2, -speedStep);
        break;
      case '7': // Increase speed of motor 4
        adjustSpeed(3, speedStep);
        break;
      case '8': // Decrease speed of motor 4
        adjustSpeed(3, -speedStep);
        break;
      case '9': // Increase speed of motor 4
        adjustSpeed(0, speedStep);
        adjustSpeed(1, speedStep);
        adjustSpeed(2, speedStep);
        adjustSpeed(3, speedStep);
        break;
      case '0': // Decrease speed of motor 4
        adjustSpeed(0, -speedStep);
        adjustSpeed(1, -speedStep);
        adjustSpeed(2, -speedStep);
        adjustSpeed(3, -speedStep);
        break;
      
    }
  }
}

void adjustSpeed(int motorIndex, int change) {
  // Adjust speed within bounds
  motorSpeeds[motorIndex] = constrain(motorSpeeds[motorIndex] + change, 0, 100);
  updateMotorSpeeds();
  
  // Debugging: Print current speeds
  Serial.print("Motor Speeds: ");
  for (int i = 0; i < 4; i++) {
    Serial.print(motorSpeeds[i]);
    Serial.print("% ");
  }
  Serial.println();
}

void updateMotorSpeeds() {
  // Map speed percentage to PWM value (assuming 0% -> 1000, 100% -> 2000 for ESC)
  motor1.writeMicroseconds(map(motorSpeeds[0], 0, 100, 1000, 2000));
  motor2.writeMicroseconds(map(motorSpeeds[1], 0, 100, 1000, 2000));
  motor3.writeMicroseconds(map(motorSpeeds[2], 0, 100, 1000, 2000));
  motor4.writeMicroseconds(map(motorSpeeds[3], 0, 100, 1000, 2000));
}
