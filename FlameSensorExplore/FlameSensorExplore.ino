const int flamePin = 2;    // Digital pin where the flame sensor is connected
const int buzzerPin = 3;   // Digital pin where the buzzer is connected

void setup() {
  Serial.begin(9600);
  pinMode(flamePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int flameValue = digitalRead(flamePin);

  if (flameValue == LOW) {
    Serial.println("Flame Detected!");
    
    // Trigger the buzzer for a short duration
    digitalWrite(buzzerPin, HIGH);
    delay(500);  // Adjust the duration as needed
    digitalWrite(buzzerPin, LOW);
    
    // You can add more actions or functions here when a flame is detected
  }

  delay(1000); // Adjust the delay time as needed
}
