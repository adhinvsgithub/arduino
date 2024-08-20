int motor1pin1 = 1;
int motor1pin2 = 2;
int ENA = 9;  // Motor speed control
int joystickX = A0; // Joystick X-axis connected to pin A0
const int NEUTRAL_VALUE = 517; // Steady state value for joystick
const int FORWARD_THRESHOLD = 530; // Threshold to detect forward movement
const int BACKWARD_THRESHOLD = 490; // Threshold to detect backward movement

void setup() {
  // Motor control pins
  pinMode(motor1pin1, OUTPUT);
  pinMode(motor1pin2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Initialize the serial monitor
  Serial.begin(9600);

  // Set initial motor state to stopped
  digitalWrite(motor1pin1, LOW);
  digitalWrite(motor1pin2, LOW);
  analogWrite(ENA, 0);
}

void loop() {
  int xValue = analogRead(joystickX); // Read X-axis value from joystick

  // Print joystick X value to Serial Monitor
  Serial.print("Joystick X value: ");
  Serial.println(xValue);

  if (xValue > FORWARD_THRESHOLD) {
    // Move forward
    digitalWrite(motor1pin1, HIGH);
    digitalWrite(motor1pin2, LOW);
    analogWrite(ENA, map(xValue, FORWARD_THRESHOLD, 1023, 0, 255)); // Adjust speed based on joystick value
    Serial.println("Motor Direction: Forward");
  } else if (xValue < BACKWARD_THRESHOLD) {
    // Move backward
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, HIGH);
    analogWrite(ENA, map(xValue, 0, BACKWARD_THRESHOLD, 255, 0)); // Adjust speed based on joystick value
    Serial.println("Motor Direction: Backward");
  } else {
    // Stop the motor if the joystick is near the neutral position
    digitalWrite(motor1pin1, LOW);
    digitalWrite(motor1pin2, LOW);
    analogWrite(ENA, 0);
    Serial.println("Motor Status: Stopped");
  }

  delay(100); // Add a small delay for readability
}
