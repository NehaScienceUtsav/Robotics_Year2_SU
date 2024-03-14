#define LIGHT_SMOKER_THRESHOLD 30    // Define threshold for a light smoker
#define HEAVY_SMOKER_THRESHOLD 100   // Define threshold for a heavy smoker
#define MQ2_PIN A3                    // Use A3 for analog input
#define LED_PIN 6                     // Define the LED pin
#define BUZZER_PIN 7                  // Define the BUZZER pin

int sensorValue;  // Variable to store sensor value

void setup() {
  Serial.begin(9600); // Sets the serial port to 9600
  Serial.println("MQ2 warming up!");
  delay(20000); // Allow the MQ2 to warm up
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
  sensorValue = analogRead(MQ2_PIN); // Read analog input pin A3
  Serial.print("Sensor Value: ");
  Serial.println(sensorValue);

  // Determine the status
  if (sensorValue < LIGHT_SMOKER_THRESHOLD) {
    printStatus("Non-Smoker", LOW, LOW);
  } else if (sensorValue < HEAVY_SMOKER_THRESHOLD) {
    printStatus("Light Smoker", HIGH, LOW);
  } else {
    printStatus("Heavy Smoker", HIGH, HIGH);
  }

  delay(2000); // Wait 2s for the next reading
}

void printStatus(const char* status, int ledState, int buzzerState) {
  Serial.print("  |  Status: ");
  Serial.println(status);
  digitalWrite(LED_PIN, ledState);       // Turn on/off the LED
  digitalWrite(BUZZER_PIN, buzzerState); // Turn on/off the buzzer
  delay(1000); // Delay for the buzzer sound (if applicable)
}

