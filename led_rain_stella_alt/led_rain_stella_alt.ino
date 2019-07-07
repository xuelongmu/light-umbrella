#include <Adafruit_NeoPixel.h>
//this inclides the Adafriuit library

int num_s = 4; //number of strips
int i = 0;
int rain = 1;
int offset = 0;

Adafruit_NeoPixel strips[] = {
  Adafruit_NeoPixel(64, 6),
  Adafruit_NeoPixel(64, 8),
  Adafruit_NeoPixel(64, 10),
  Adafruit_NeoPixel(64, 12)
};


void setup() {
  for (int s = 0; s <  num_s; s++) {
    strips[s].begin();
    strips[s].clear();
  }
  Serial.begin(115200);
}
int br = 128;

unsigned long period_1 = 10;
unsigned long period_2 = 0;

unsigned long time_1 = 0;
unsigned long time_2 = 0;
int reading = 0;
int threshold = 100;
void loop() {
  if (millis() > time_1 + period_1) {
    time_1 = millis();
    reading = analogRead(A0);
    //    Serial.println(reading);
  }
  //  if (reading > threshold) {
  //    scatter();
  //  }
  //  else {
  for (int b = 0; b < 5; b++) {
    droplets_alt();
  }
  scatter();
  //  }

}

void droplets_alt() {
  int wait_time=random(80) + 20;
  for (int j = 0; j < 64; j++) {
    for (int s = 0; s < num_s; s++) {
      //Adafruit_NeoPixel strip = strips[s];
      strips[s].clear();
      for (int r = 0; r < rain; r++ ) {
        strips[s].setPixelColor(j + r * offset , random(br), random(br), random(br));
        strips[s].setPixelColor((j + 32 + r * offset) % 64, random(br), random(br), random(br));
      }
      strips[s].show();
    }
    delay(wait_time);

  }
  i++;
  rain = sin(i) * 2 + 3;
  offset = random(32);
}
void droplets() {
  for (int a = 2; a < 5; a++) {
    rain = a;
    offset = 13 - a;
    int delayTime = ((int)50 / a) + 20;
    for (int j = 0; j < 64; j++) {
      for (int s = 0; s < num_s; s++) {
        strips[s].clear();
        for (int r = 0; r < rain; r++ ) {

          strips[s].setPixelColor((j + r * offset) % 64 , random(br), random(br), random(br));
          //        Serial.println(j + r * offset);
          //        Serial.println((j + 32 + r * offset) % 64);
          strips[s].setPixelColor((j + 32 + r * offset) % 64, random(br), random(br), random(br));
        }
        strips[s].show();
      }
      delay(delayTime);
    }
  }

  Serial.println("done");
}
void scatter() {

  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 64; j++) {
      for (int s = 0; s < num_s; s++) {
        strips[s].clear();
        strips[s].setPixelColor(random(64), random(br*2), random(br*2), random(br*2));
        strips[s].show();
        delay(1); //5-i
        strips[s].setPixelColor(j, 0);
        strips[s].show();


      }
      //        int[] led_pos = int[i]
      //        for (int a = 0; a < i; a++) {
      //          led_pos[a] = random(64);
      //        }
      //        for (int a = 0; a < i; a++) {
      //          strips[s].setPixelColor(led_pos[a], random(64), random(64), random(64));
      //        }
      //                strips[s].show();
      //
      //        for
      //          strips[s].setPixelColor(led_pos, random(64), random(64), random(64));
      //          strips[s].setPixelColor(led_pos, random(64), random(64), random(64));
      //        }
      //        //        delay(1);
      //        strips[s].setPixelColor(led_pos, 0);
      //        strips[s].show();

    }

  }
  //    delay(3);
  //    for (int s = 0; s < num_s; s++) {
  //      strips[s].clear();
  //    }

}
