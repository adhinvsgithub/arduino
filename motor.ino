int motor1pin1 = 2;
int motor1pin2 = 3;
int ENA = 9;  // Motor speed control
int joystickX = A0; // Joystick X-axis

void setup() {
  // Motor control pins
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Optional: Set initial speed to 0
  analogWrite(ENA, 0);
}

void loop() {
  int xValue = analogRead(joystickX); // Read X-axis value from joystick
  int speed = map(xValue, 0, 1023, 0, 255); // Map joystick value to speed (0-255)

  if (xValue > 512) {
    // Move forward
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
  } else if (xValue < 512) {
    // Move backward
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
  } else {
    // Stop
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
  }

  analogWrite(ENA, speed); // Control motor speed based on joystick
}
