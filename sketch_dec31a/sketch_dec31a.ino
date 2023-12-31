
#include "Arduino.h"
#include <FastLED.h>

// How many leds in your strip?
#define NUM_LEDS 1
#define DATA_PIN 27

// Define the array of leds
CRGB leds[NUM_LEDS];
  
/* After STAMP-PICO is started or reset
  the program in the setUp () function will be run, and this part will only be run once.
  After STAMP-PICO is started or reset, the program in the setup() function will be executed, and this part will only be executed once. */
void setup() {
  FastLED.addLeds<SK6812, DATA_PIN, RGB>(leds, NUM_LEDS); // GRB ordering is typical
  Serial.begin(115200);
}

/* After the program in setup() runs, it runs the program in loop()
The loop() function is an infinite loop in which the program runs repeatedly
After the program in the setup() function is executed, the program in the loop() function will be executed
The loop() function is an endless loop, in which the program will continue to run repeatedly */
void loop() {
  // Turn the LED red
  leds[0] = 0xf00000;
  FastLED.show();
  Serial.printf("RED\n");
  delay(500);
  // Now turn the LED green
  leds[0] = 0x00f000;
  FastLED.show();
  Serial.printf("GREEN\n");
  delay(500);
  // Now turn the LED blue
  leds[0] = 0x0000f0;
  FastLED.show();
  Serial.printf("BLUE\n");
  delay(500);
  // Now turn the LED white
  leds[0] = 0xf0f0f0;
  FastLED.show();
  Serial.printf("WHITE\n");
  delay(500);
}
