# include  " SingleEMAFilterLib.h "

SingleEMAFilter < int > singleEMAFilter ( 0.6 );




// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.print("1023 0 ");
   Serial.println(sensorValue);
  //delay(1);        // delay in between reads for stability
}
