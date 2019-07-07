
#include <Adafruit_NeoPixel.h>
//this inclides the Adafriuit library

Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, 6);
//this declares neopixel object (number of LEDS, PIN)


void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.clear();
  strip.show();
  strip.setPixelColor(0, 50, 50, 50);
  strip.show();
}

void loop() {
  // put your main code here, to run repeatedly:
  strip.setPixelColor(1, 50, 50, 50);
  strip.show();
}
