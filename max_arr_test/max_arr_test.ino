
void setup() {
  int size_of = 7;

    Serial.begin(115200);
  int example_array[] = {7,1,2,3,4,5,6};
  int max_val = getIndexOfMaximumValue(example_array, size_of);
  Serial.println(max_val);

}

void loop() {
  // put your main code here, to run repeatedly:

}

int getIndexOfMaximumValue(int* array_calc, int arr_size) {
  int maxIndex = 0;
  int currentMax = 0;
  for (int i = 0; i < arr_size; i++) {
    Serial.println(array_calc[i]);
    if (currentMax < array_calc[i]) {
      currentMax = array_calc[i];
      maxIndex = i;
//      Serial.println(currentMax);
    }
  }
  return maxIndex;
}
