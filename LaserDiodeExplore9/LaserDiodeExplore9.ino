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
  digitalWrite(laserPin, HIGH); // Turn on the laser
}

void checkSensor() {

  // Turn on the buzzer if LDR value is low, else turn it off
  digitalWrite(buzzerPin, (ldrValue == LOW) ? HIGH : LOW); // ternary operator (condition) ? true_value : false_value

  // Print "High" if LDR value is low, else print "Low" to serial monitor
  Serial.println((ldrValue == LOW) ? "High" : "Low"); 

  delay(500); // Adjust the delay as needed for stability

}
  
  delay(500); // Adjust the delay as needed for stability
}
