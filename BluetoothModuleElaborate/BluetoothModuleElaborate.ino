#include <SoftwareSerial.h> // remove the inverted commas after you copy the code to the IDE
SoftwareSerial BT(8, 9); 
// creates a "virtual" serial port/UART
// connect BT module TX to D10
// connect BT module RX to D11
// connect BT Vcc to 5V, GND to GND
void setup()  
{
  // set digital pin to control as an output
  pinMode(6, OUTPUT);
  // set the data rate for the SoftwareSerial port
  BT.begin(9600);
  // Send test message to other device
  BT.println("Hello from Arduino");
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}
char a; // stores incoming character from other device
void loop() 
{
  if (BT.available())
  // if text arrived in from BT serial...
  {
    a=(BT.read());
    if (a=='W')
    {
      digitalWrite(6, HIGH);
      BT.println("LED on");
      Serial.println("data received W");
    }
    if (a=='w')
    {
      digitalWrite(6, LOW);
      BT.println("LED off");
      Serial.println("data received w");
    }

  }
}
