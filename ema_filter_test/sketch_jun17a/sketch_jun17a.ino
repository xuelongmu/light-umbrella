const unsigned int numReadings = 1000;
unsigned int analogVals[numReadings];
unsigned int i = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}
// the loop routine runs over and over again forever:
//void loop() {
//  // read the input on analog pin 0:
//  int sensorValue = analogRead(A0);
//  // print out the value you read:
//  Serial.print("1023 0 ");
//   Serial.println(sensorValue);
//  //delay(1);        // delay in between reads for stability
//
//  
//}

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
      for (uint16_t j=0; j<numReadings; j++)
        {
          Serial.print("1023 0 ");
          Serial.println(analogVals[j]);
        }
    }
//  }
}
