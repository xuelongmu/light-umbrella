// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// Released under the GPLv3 license to match the rest of the
// Adafruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include "FastLED.h"
#define NUM_LEDS_PER_STRIP 64

#ifdef __AVR__
#endif

CRGB leds[NUM_LEDS_PER_STRIP];

// Which pin on the Arduino is connected to the NeoPixels?
#define PIN_1        9 // On Trinket or Gemma, suggest changing this to 1
#define PIN_2        7
#define PIN_3        8
#define PIN_4        9


// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 64 // Popular NeoPixel ring size

// When setting up the NeoPixel library, we tell it how many pixels,
// and which pin to use to send signals. Note that for older NeoPixel
// strips you might need to change the third parameter -- see the
// strandtest example for more information on possible values.
Adafruit_NeoPixel pixels_1(NUMPIXELS, PIN_1, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixels_2(NUMPIXELS, PIN_2, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixels_3(NUMPIXELS, PIN_3, NEO_GRB + NEO_KHZ800);
//Adafruit_NeoPixel pixels_4(NUMPIXELS, PIN_4, NEO_GRB + NEO_KHZ800);


#define DELAYVAL 10 // Time (in milliseconds) to pause between pixels

void setup() {

  pixels_1.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
//  pixels_2.begin();
//  pixels_3.begin();
//  pixels_4.begin();

}

void loop() {
  pixels_1.clear(); // Set all pixel colors to 'off'
  //      pixels_2.clear();
  //      pixels_3.clear();
  //      pixels_4.clear();


  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  for (int i = 0; i < NUMPIXELS; i++) { // For each pixel...

    // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
    // Here we're using a moderately bright green color:
    pixels_1.setPixelColor(i, pixels_1.Color(random(256), random(256), random(256)));
//    pixels_2.setPixelColor(i, pixels_2.Color(random(256), random(256), random(256)));
//    pixels_3.setPixelColor(i, pixels_3.Color(random(256), random(256), random(256)));
//    pixels_4.setPixelColor(i, pixels_4.Color(random(256), random(256), random(256)));

    //    pixels.setPixelColor(i, pixels.Color(0, 150, 0));
    pixels_1.show();   // Send the updated pixel colors to the hardware.
    //    pixels_2.show();   // Send the updated pixel colors to the hardware.
    //
    //    pixels_3.show();   // Send the updated pixel colors to the hardware.
    //    pixels_4.show();   // Send the updated pixel colors to the hardware.

    //    delay(DELAYVAL); // Pause before next pass through loop

  }
  delay(DELAYVAL); // Pause before next pass through loop

}
