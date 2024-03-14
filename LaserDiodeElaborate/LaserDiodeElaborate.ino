const int ldrPin = 6;
#define laserPin 2
#define buzzerPin 3
int ldrValue = 0;

void setup() {
  pinMode(laserPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  while (!Serial);
}

void loop() {
  ldrValue = digitalRead(ldrPin);
  activateLaser();
  checkSensor();
}

void activateLaser() {
  digitalWrite(laserPin, HIGH);
}

void checkSensor() {
  if (ldrValue == LOW) {
    digitalWrite(buzzerPin, HIGH);
    Serial.println("High");
  } else {
    digitalWrite(buzzerPin, LOW);
    Serial.println("Low");
  }
  
  delay(500); // Adjust the delay as needed for stability
}
