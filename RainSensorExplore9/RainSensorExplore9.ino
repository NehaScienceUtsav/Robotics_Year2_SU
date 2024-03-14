// Define the analog pin connected to the rain sensor
const int rainSensorPin = A0;

// Define the digital pin connected to the LED
const int LED = 3;

// Define the threshold for rain detection
const int rainThreshold = 500; // Adjust this value according to your sensor's output

void setup() {
  // Initialize serial communication with a baud rate of 9600
  Serial.begin(9600);

  // Set the LED pin as an output
  pinMode(LED, OUTPUT);
}

void loop() {
  // Read the analog value from the rain sensor
  int rainValue = analogRead(rainSensorPin);

  // Check if rain is detected
  if (rainValue > rainThreshold) {
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
