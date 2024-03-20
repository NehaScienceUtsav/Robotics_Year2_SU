#include <TM1637Display.h>

// Define the analog pin for the soil moisture sensor
const int soilMoisturePin = A1;
// Define the pins for TM1637 display (change according to your wiring)
#define CLK 8
#define DIO 9
// Define the pins for the LEDs
const int greenLedPin = 5; // Connect green LED to pin 5
const int redLedPin = 6;   // Connect red LED to pin 6

// Create a TM1637Display object
TM1637Display display(CLK, DIO);

void setup() {
  // Start serial communication
  Serial.begin(9600);
  // Initialize the TM1637 display
  display.setBrightness(0x0f); // set the brightness level (0x00 to 0x0f)
  // Set LED pins as outputs
  pinMode(greenLedPin, OUTPUT);
  pinMode(redLedPin, OUTPUT);
}

void loop() {
  // Read the soil moisture sensor value
  int soilMoistureValue = analogRead(soilMoisturePin);

  // Calculate moisture percentage manually
  float moisturePercentage = (soilMoistureValue / 1023.0) * 100.0;

  // Print the sensor value and moisture percentage to the serial monitor
  Serial.print("Soil Moisture Value: ");
  Serial.print(soilMoistureValue);
  Serial.print("\tMoisture Percentage: ");
  Serial.print(moisturePercentage);
  Serial.println("%");

  // Display the moisture percentage on the TM1637 display
  display.showNumberDec(moisturePercentage);

  // Control the LEDs based on moisture percentage
  if (moisturePercentage > 50) {
    digitalWrite(greenLedPin, LOW); // Turn on green LED
    digitalWrite(redLedPin, HIGH);    // Turn off red LED
  } else {
    digitalWrite(greenLedPin, HIGH);  // Turn off green LED
    digitalWrite(redLedPin, LOW);  // Turn on red LED
  }

  // Add a delay to avoid rapid readings
  delay(1000);  // You can adjust the delay as needed
}
