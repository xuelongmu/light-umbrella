#include <Adafruit_NeoPixel.h>

#define PIN 6

// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  Serial.begin(9600);

}

unsigned long period_1 = 10;
unsigned long period_2 = 0;

unsigned long time_1 = 0;
unsigned long time_2 = 0;


void loop() {
  if (millis() > time_1 + period_1) {
    time_1 = millis();
        rain();
  }

  if (millis() > time_2 + period_2) {
    time_2 = millis();
    thunderstorm();
    period_2 = random(10000);
    Serial.println(period_2);
  }

  //  // Some example procedures showing how to display to the pixels:
  //  colorWipe(strip.Color(255, 0, 0), 50); // Red
  //  colorWipe(strip.Color(0, 255, 0), 50); // Green
  //  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  //  // Send a theater pixel chase in...
  //  theaterChase(strip.Color(127, 127, 127), 50); // White
  //  theaterChase(strip.Color(127,   0,   0), 50); // Red
  //  theaterChase(strip.Color(  0,   0, 127), 50); // Blue
  //
  //  rainbow(20);
  //  rainbowCycle(20);
  //  theaterChaseRainbow(50);
}

void thunderstorm() {
  int level = random(128) + 128;
  setLEDLight(255);
  delay(20);
  setLEDLight(20);
  delay(100);

  setLEDLight(128);
  delay(20);
  for (int i = 30; i >= 0; i -= 5) {
    setLEDLight(i);
    delay(4);
  }


}

void rain() {
  Serial.println("reached rain");
  int randNum = 2+random(3);
  for (int i = 0; i < 20; i++)
  {
    for (uint16_t j = 0; j < strip.numPixels(); j++) {

      if ((j % randNum) == 0) {
        strip.setPixelColor(j, strip.Color(i, i, i));
      }
      else {
        strip.setPixelColor(j, 0);
      }
    }
    strip.show();
    delay(30);
  }
  for (int i = 20; i >= 0; i--)
  {
    for (uint16_t j = 0; j < strip.numPixels(); j++) {

      if ((j % randNum) == 0) {
        strip.setPixelColor(j, strip.Color(i, i, i));
      }
      else {
        strip.setPixelColor(j, 0);
      }
    }
    strip.show();
    delay(30);
  }

}

void setLEDLight(int level) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {

    strip.setPixelColor(i, strip.Color(level, level, level));
    strip.show();
  }
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (int i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
    WheelPos -= 170;
    return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}
