const int flamePin = 2;    // Digital pin where the flame sensor is connected
const int buzzerPin = 3;   // Digital pin where the buzzer is connected
unsigned long flameStartTime = 0; // Variable to store the time when flame is detected

void setup() {
  Serial.begin(9600);
  pinMode(flamePin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  int flameValue = digitalRead(flamePin);

  if (flameValue == LOW) {
    if (flameStartTime == 0) {
      // Flame just detected, record the time
      flameStartTime = millis();
    }
    Serial.println("Flame Detected!");
    triggerBuzzer();
    
    // If flame has been continuously detected for 10 seconds
    if (millis() - flameStartTime >= 10000) { 
      activateContinuousBuzzer(); // Activate continuous buzzer function
    }
  } else {
    // No flame detected, reset flameStartTime
    flameStartTime = 0;
  }

  delay(1000); // Adjust the delay time as needed
}

void triggerBuzzer() {
  // Trigger the buzzer for a short duration
  digitalWrite(buzzerPin, HIGH);
  delay(500);  // Adjust the duration as needed
  digitalWrite(buzzerPin, LOW);
}

void activateContinuousBuzzer() {
  // Activate continuous buzzer until flame is no longer detected
  digitalWrite(buzzerPin, HIGH);
}
