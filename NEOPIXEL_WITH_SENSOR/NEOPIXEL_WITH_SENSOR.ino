
//NEOPIXEL
#include <Adafruit_NeoPixel.h>
//this inclides the Adafriuit Neopixel library

Adafruit_NeoPixel strip = Adafruit_NeoPixel(8, 6);
//this declares neopixel object (number of LEDS, PIN


//PIEZO
const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 100;  // threshold value to decide when the detected sound is a knock or not

// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
bool showColor = false;         // color mode for cycling


//NEOPIXEL
void setup() {
  // put your setup code here, to run once:
  strip.begin();
  strip.clear();
  strip.show();  //Set all pixels to "off"
  Serial.begin(9600);
}

int i = 0;
void loop() {



  //PIEZO CHECK
  sensorReading = analogRead(knockSensor);

  //if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {

    const int max_sensor_val = 600;
    const int num_pix = 8; //later 32
    int num_on = map(sensorReading, 0, max_sensor_val , 0, num_pix);

    //showColor = true;
    for (int j = 0; j < num_pix; j++) {

      if (num_on) {
        num_on--;

        bool head_or_tail = random(unsigned(-1)) % 2;

        if (head_or_tail) {
          strip.setPixelColor(j, random(20), random(20), random(20));
        } else {
          strip.setPixelColor(j, 0, 0, 0);
        }
      }
    }
    Serial.print("\n");
    strip.show();

    delay(100);

    for (int j = 0; j < 8; j++) {
      strip.setPixelColor(j, 0, 0, 0);
    }
    strip.show();

  }

  delay(1);

  //  if (i > 32) {
  //    i = 0;
  //    strip.clear();
  //  }
  //  // put your main code here, to run repeatedly:
  //  //  strip.setPix/elColor(2, 255, 255,255);
  //  strip.setPixelColor(i, 10, 10, 10);
  //  strip.show();
  //  i++;
  //  delay(500);

}
