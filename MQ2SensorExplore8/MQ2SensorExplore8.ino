#define MQ2pin A2 // Use A0 for analog input
#define BuzzerPin 2 // Use pin 8 for the buzzer

void setup() {
  Serial.begin(9600); // Sets the serial port to 9600
  Serial.println("MQ2 warming up!");
  pinMode(BuzzerPin, OUTPUT); // Set buzzer pin as output
  delay(20000); // Allow the MQ2 to warm up
}

void loop() {
  float sensorValue = analogRead(MQ2pin); // Read analog input pin A0
  Serial.print("Smoke Sensor Value: ");
  Serial.println(sensorValue);
  
  if (sensorValue > 180 && sensorValue <= 300) { // Check if sensor value exceeds level 1 threshold
    digitalWrite(BuzzerPin, HIGH); // Turn on buzzer
    delay(1000); // Delay for 1 second
    digitalWrite(BuzzerPin, LOW); // Turn off buzzer
  } else if (sensorValue > 300) { // Check if sensor value exceeds level 2 threshold
    digitalWrite(BuzzerPin, HIGH); // Turn on buzzer
    delay(3000); // Delay for 3 seconds
    digitalWrite(BuzzerPin, LOW); // Turn off buzzer
  } else {
    digitalWrite(BuzzerPin, LOW); // Turn off buzzer
  }
  
  delay(2000); // Wait 2 seconds for the next reading
}
