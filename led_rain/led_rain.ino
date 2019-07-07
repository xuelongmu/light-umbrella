
#include <Adafruit_NeoPixel.h>
//this inclides the Adafriuit library

int num_s = 4; //number of strips
int i = 0;
int rain = 1;
int offset = 0;

Adafruit_NeoPixel strips[] = {
  Adafruit_NeoPixel(64, 6),
  Adafruit_NeoPixel(64, 7),
  Adafruit_NeoPixel(64, 8),
    Adafruit_NeoPixel(64, 9),
      Adafruit_NeoPixel(64, 10)

};
//Adafruit_NeoPixel strip = Adafruit_NeoPixel(64, 6);

//this declares neopixel object (number of LEDS, PIN)

void setup() {
  for (int s = 0; s <  num_s; s++) {
    strips[s].begin();
    strips[s].clear();

  }
  //  // put your setup code here, to run once:
  //  strip.begin();
  //  strip.clear();

}
int br = 60;

void loop() {
  for (int j = 0; j < 64; j++) {
          for (int s = 0; s < num_s; s++) {
      //Adafruit_NeoPixel strip = strips[s];
       strips[s].clear();
       for(int r = 0; r<rain;r++ ){
      strips[s].setPixelColor(j+r*offset , random(br), random(br), random(br));
//      strip.setPixelColor(j + 1, random(br), random(br), random(br));
//      strip.setPixelColor(j - 10, random(br), random(br), random(br));
//      strip.setPixelColor(j - 9, random(br), random(br), random(br));
//
//      strip.setPixelColor(j + 30, random(br), random(br), random(br));
      strips[s].setPixelColor((j + 32+r*offset)%64, random(br), random(br), random(br));
       }
      strips[s].show();
    }
          delay(100);

  }
  //  strip.show();
  //  delay(100);
  //  if (i > 32) {
  //    i = 0;
  //    strip.clear();
  //  }
  //  // put your main code here, to run repeatedly:
  //  //  strip.setPix/elColor(2, 255, 255,255);
  //  strip.setPixelColor(i, 10, 10, 10);
  //  strip.show();
    i++;
  //  delay(100);
  rain=sin(i)*2+3;
  offset = random(32);
}
