// Define the digital pins
const int rainSensorPin = 2;
const int LED = 3;

void setup() {
  // Initialize serial communication with a baud rate of 9600
  Serial.begin(9600);
  // Set the rain sensor pin as an input
  pinMode(rainSensorPin, INPUT);
  // Set the LED pin as an output
  pinMode(LED, OUTPUT);
}

void loop() {
  // Read the digital value from the rain sensor
  int rainValue = digitalRead(rainSensorPin);

  // Check if rain is detected
  if (rainValue == HIGH) {
    // Turn on the LED
    digitalWrite(LED, HIGH);
    // Print message indicating rain detection
    Serial.println("Rain detected!");
  } else {
    // Turn off the LED
    digitalWrite(LED, LOW);
    // Print message indicating no rain detection
    Serial.println("No rain detected.");
  }
  
  // Delay for stability
  delay(1000);
}