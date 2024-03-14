#include <DHT.h>
#include <TM1637Display.h>

#define DHTPIN 4       // Pin where the DHT11 is connected
#define DHTTYPE DHT11  // DHT11 sensor type
#define CLK_PIN 9      // Pin for TM1637 CLK
#define DIO_PIN 8      // Pin for TM1637 DIO

DHT dht(DHTPIN, DHTTYPE);
TM1637Display display(CLK_PIN, DIO_PIN);

void setup() {
  Serial.begin(9600);   // Initialize serial communication for debugging
  dht.begin();           // Initialize DHT sensor
  display.setBrightness(7);  // Set the display brightness (0-7)
}

void loop() {
  float temperature = dht.readTemperature();  // Read temperature in Celsius
  int tempInt = int(temperature);             // Convert float to integer
  int digit1 = tempInt / 10;                 // Extract tens digit
  int digit2 = tempInt % 10;                 // Extract ones digit

  // Convert the int values to uint8_t values
  uint8_t tempDigits[] = {uint8_t(digit1), uint8_t(digit2), 10, 11}; // 10 and 11 represent degree symbols

  // Display temperature on the 4-digit display
  display.setSegments(tempDigits);
  delay(2000); // Delay between readings
}
