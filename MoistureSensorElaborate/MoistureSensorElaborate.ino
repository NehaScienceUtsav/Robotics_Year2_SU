const int moisturePin = A0;   // Analog pin for moisture sensor
const int motorPin = 3;       // Digital pin for motor control
const int threshold = 500;    // Adjust this threshold value as needed

void setup() {
  pinMode(moisturePin, INPUT); // Set moisture pin as input
  pinMode(motorPin, OUTPUT);   // Set motor pin as output
}

void loop() {
  int moistureValue = analogRead(moisturePin); // Read moisture level from the sensor

  // Check moisture level against the threshold
  if (moistureValue < threshold) {
    // Soil is dry, turn on motor
    digitalWrite(motorPin, HIGH);
  } else {
    // Soil is wet, turn off motor
    digitalWrite(motorPin, LOW);
  }
}
