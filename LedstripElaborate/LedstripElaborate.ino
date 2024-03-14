#include <FastLED.h>
#define DATA_PIN 6         // Define the digital pin connected to the data line of the LED strip
#define LED_TYPE WS2812B   // Define the type of LED strip you're using
#define COLOR_ORDER GRB    // Define the color order (RGB or GRB)
#define NUM_LEDS 60       // Define the number of LEDs in your strip
CRGB leds[NUM_LEDS];  // Create an array to store LED data
void setup() {
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(70); // Set the brightness (0-255)
}
void loop() {
  // Set the first 10 LEDs to red, leaving the rest off
  for (int i = 0; i < 10; i++) {
    leds[i] = CRGB(255, 0, 0);
  }
  FastLED.show();
  delay(1000);
  // Set the next 10 LEDs to green, leaving the rest off
  for (int i = 10; i < 20; i++) {
    leds[i] = CRGB(0, 255, 0);
  }
  FastLED.show();
  delay(1000);
  // Set the next 10 LEDs to blue, leaving the rest off
  for (int i = 20; i < 30; i++) {
    leds[i] = CRGB(0, 0, 255);
  }
  FastLED.show();
  delay(1000);
  // Turn off all LEDs
  fill_solid(leds, NUM_LEDS, CRGB(0, 0, 0));
  FastLED.show();
  delay(1000);
}