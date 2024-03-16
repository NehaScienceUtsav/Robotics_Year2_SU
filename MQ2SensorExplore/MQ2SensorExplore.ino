#define MQ2pin A2 // Use A0 for analog input
#define LEDpin 13 // Use pin 13 for the LED

void setup() {
  Serial.begin(9600); // Sets the serial port to 9600
  Serial.println("MQ2 warming up!");
  pinMode(LEDpin, OUTPUT); // Set LED pin as output
  delay(20000); // Allow the MQ2 to warm up
}

void loop() {
  float sensorValue = analogRead(MQ2pin); // Read analog input pin A0
  Serial.print("Smoke Sensor Value: ");
  Serial.println(sensorValue);
  
  if (sensorValue > 180) { // Check if sensor value exceeds threshold
    digitalWrite(LEDpin, HIGH); // Turn on LED
  } else {
    digitalWrite(LEDpin, LOW); // Turn off LED
  }
  
  delay(2000); // Wait 2 seconds for the next reading
}
