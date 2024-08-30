#define LED 5

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  //Create a for loop to increase brightness
  for(int i=0;i<=256;i++){
    analogWrite(LED,i);
    Serial.printf("Current brightness: %i \n", i);
    delay(10);
  }

  //pause for 0.5 second
  delay(500);

  //After Max brightness, for loop to decrease brightness
  for(int j=256;j>0;j--){
    analogWrite(LED,j);
    Serial.printf("Current brightness: %i \n", j);
    delay(10);
  }

  //pause for 0.5 second
  delay(500);
}