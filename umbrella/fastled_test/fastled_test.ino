#include "FastLED.h"
#define NUM_LEDS_PER_STRIP 64
CRGB leds[NUM_LEDS_PER_STRIP];
#include <Adafruit_NeoPixel.h>


void setup() {
  FastLED.addLeds<WS2812B, 6, GRB>(leds, NUM_LEDS_PER_STRIP);
//  FastLED.addLeds<WS2812B, 7, GRB>(leds, NUM_LEDS_PER_STRIP);
//  FastLED.addLeds<WS2812B, 8, GRB>(leds, NUM_LEDS_PER_STRIP);
//  FastLED.addLeds<WS2812B, 9, GRB>(leds, NUM_LEDS_PER_STRIP);

  FastLED.clear();

}

void loop() {
  for (int i = 0; i < NUM_LEDS_PER_STRIP; i++) {
    leds[i] = CRGB::Blue;    // set our current dot to red
    FastLED.show();
    delay(50);
    leds[i] = CRGB::Black;  // set our current dot to black before we continue
    FastLED.show();
  }

  //  // Turn the LED on, then pause
  //  leds[0] = CRGB::Red;
  //  FastLED.show();
  //  delay(500);
  //  // Now turn the LED off, then pause
  //  leds[0] = CRGB::Black;
  //  FastLED.show();
  //  delay(500);
}
