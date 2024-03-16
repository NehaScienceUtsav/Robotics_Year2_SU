#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);

char message[] = "ScienceUtsav-Science is awesome"; // Message to display
int messageLength = sizeof(message) - 1; // Length of the message

void setup() {
  // initialize the LCD
  lcd.init();

  // Turn on the backlight and print a message.
  lcd.backlight();

  // Set the cursor to the beginning of the second line
  lcd.setCursor(0, 0);

  // Display the initial message
  lcd.print(message);
}

void loop() {
  // Shift the message from right to left
  for (int i = 0; i <= messageLength; i++) {
    lcd.scrollDisplayLeft(); // Shift display left
    delay(500); // Delay for visibility
  }

  // Shift the message from left to right
  for (int i = 0; i <= messageLength; i++) {
    lcd.scrollDisplayRight(); // Shift display right
    delay(500); // Delay for visibility
  }
}