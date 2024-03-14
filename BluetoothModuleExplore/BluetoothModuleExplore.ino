#include <SoftwareSerial.h>
SoftwareSerial BT(8, 9);
void setup()
{
  pinMode(6, OUTPUT);
  BT.begin(9600);
  BT.println("Hello from Arduino");
  Serial.begin(9600);
  while (!Serial) {
    // Wait for the serial port to connect (needed for native USB port only)
  }
}
String receivedWord; // stores incoming word from other device
void loop()
{
  if (BT.available())
  {
    char c = BT.read();


    if (c == '\n' || c == '\r') {
      // End of word, process receivedWord here
      Serial.println("Received: " + receivedWord);
      // Clear the buffer for the next word
      receivedWord = "";
    } else {
      // Append the character to receivedWord
      receivedWord += c;
    }
  }
}