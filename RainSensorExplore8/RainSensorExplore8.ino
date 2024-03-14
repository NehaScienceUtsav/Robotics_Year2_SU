const int rainSensorPin = 2; // Digital pin connected to the rain sensor's DO pin
const int LED = 3;

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(rainSensorPin, INPUT); // Set the rain sensor pin as an input
  pinMode(LED, OUTPUT);
}

void loop() {
  int rainValue = digitalRead(rainSensorPin); // Read the digital value from the rain sensor

  // Check if rain is detected
  if (rainValue == HIGH) {
    digitalWrite(LED, HIGH);
    Serial.println("Rain detected!");
  } else {
    digitalWrite(LED, LOW);
    Serial.println("No rain detected.");
  }
  delay(1000); // Delay for stability
}