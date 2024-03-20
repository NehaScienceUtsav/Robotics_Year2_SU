#include <TM1637Display.h>

// Define the analog pin for the soil moisture sensor
const int soilMoisturePin = A2;

// Define the pins for TM1637 display (change according to your wiring)
#define CLK 8
#define DIO 9

// Create a TM1637Display object
TM1637Display display(CLK, DIO);

void setup() {
  // Start serial communication
  Serial.begin(9600);
  // Initialize the TM1637 display
  display.setBrightness(0x0f); // set the brightness level (0x00 to 0x0f)
}

void loop() {
  // Read the soil moisture sensor value
  int soilMoistureValue = analogRead(soilMoisturePin);

  // Map the sensor value to a moisture percentage (adjust the mapping range based on your sensor)
  int moisturePercentage = map(soilMoistureValue, 0, 1023, 0, 100);

  // Print the sensor value and moisture percentage to the serial monitor
  Serial.print("Soil Moisture Value: ");
  Serial.print(soilMoistureValue);
  Serial.print("\tMoisture Percentage: ");
  Serial.print(moisturePercentage);
  Serial.println("%");

  // Display the moisture percentage on the TM1637 display
  display.showNumberDec(moisturePercentage);

  // Add a delay to avoid rapid readings
  delay(1000);  // You can adjust the delay as needed
}
