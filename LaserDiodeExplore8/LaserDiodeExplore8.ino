const int ldrPin = 6;
#define laserPin 2 
#define buzzerPin 3
int ldrValue = 0; // Variable to store the LDR sensor reading

void setup() {
  pinMode(laserPin, OUTPUT);
  pinMode(ldrPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600); // Initialize serial communication
  while (!Serial); // Wait until serial port is ready
}

void loop() {
  ldrValue = digitalRead(ldrPin); // Read LDR sensor value
  activateLaser(); // Call function to activate laser
  checkSensor(); // Call function to check sensor
}

void activateLaser() {
  digitalWrite(laserPin, HIGH);
}

void checkSensor() {
  if (ldrValue == HIGH) {
    digitalWrite(buzzerPin, HIGH); //
    Serial.println("High");
  } else {
    digitalWrite(buzzerPin, LOW);
    Serial.println("Low");
  }
  
  delay(500);
}
