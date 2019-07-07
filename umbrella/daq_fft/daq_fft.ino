#include "arduinoFFT.h"
arduinoFFT FFT = arduinoFFT(); /* Create FFT object */

const unsigned int numReadings = 5000;
unsigned int analogVals[numReadings];
unsigned int i = 0;

const uint16_t samples = 64; //This value MUST ALWAYS be a power of 2
const double samplingFrequency = 2500;


#define SCL_INDEX 0x00
#define SCL_TIME 0x01
#define SCL_FREQUENCY 0x02
#define SCL_PLOT 0x03

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}

void loop()
{

  static uint32_t tStart = millis(); // ms; start time
  const uint32_t DESIRED_PERIOD = 1; // ms
  uint32_t tNow = millis(); // ms; time now
//  if (tNow - tStart >= DESIRED_PERIOD)
//  {
//    tStart += DESIRED_PERIOD; // update start time to ensure consistent and near-exact period

//    Serial.println("taking sample");
    analogVals[i] = analogRead(A0);
//    Serial.println(analogVals[i]);
    i++;
    if (i>=numReadings)
    {
      Serial.println("resetting array");
      i = 0; //reset to beginning of array, so you don't try to save readings outside of the bounds of the array
//      for (uint16_t j=0; j<numReadings; j++)
//        {
//          Serial.print("1023 0 ");
//          Serial.println(analogVals[j]);
//        }
      Serial.println("Length of real array:");
      Serial.println(sizeof(analogVals));
      Serial.println("Data:");
      PrintVector(analogVals, samples, SCL_TIME);
      FFT.Windowing(analogVals, samples, FFT_WIN_TYP_HAMMING, FFT_FORWARD);  /* Weigh data */
      Serial.println("Weighed data:");
      PrintVector(analogVals, samples, SCL_TIME);
      FFT.Compute(analogVals, samples, FFT_FORWARD); /* Compute FFT */
      Serial.println("Computed Real values:");
      PrintVector(analogVals, samples, SCL_INDEX);
  
      Serial.println("Computed magnitudes:");
      PrintVector(analogVals, (samples >> 1), SCL_FREQUENCY);
      double x = FFT.MajorPeak(analogVals, samples, samplingFrequency);
      Serial.println(x, 6);
    }
//  }
}

void PrintVector(double *vData, uint16_t bufferSize, uint8_t scaleType)
{
  for (uint16_t i = 0; i < bufferSize; i++)
  {
    double abscissa;
    /* Print abscissa value */
    switch (scaleType)
    {
      case SCL_INDEX:
        abscissa = (i * 1.0);
  break;
      case SCL_TIME:
        abscissa = ((i * 1.0) / samplingFrequency);
  break;
      case SCL_FREQUENCY:
        abscissa = ((i * 1.0 * samplingFrequency) / samples);
  break;
    }
    Serial.print(abscissa, 6);
    if(scaleType==SCL_FREQUENCY)
      Serial.print("Hz");
    Serial.print(" ");
    Serial.println(vData[i], 4);
  }
  Serial.println();
}
