#define LED 5

//Global Variable interval initialized to 4 seconds
int interval = 4000;

int cycleCount = 0;

void setup() {
  Serial.begin(115200);
  pinMode(LED, OUTPUT);
}

void loop() {
  //Turn LED on
  digitalWrite(LED, HIGH);
  Serial.printf("LED ON! \n");
  delay(interval);

  //Turn LED off
  digitalWrite(LED, LOW);
  Serial.printf("LED OFF! \n");
  delay(interval);

  cycleCount++;

  if (cycleCount >= 2){
    //Divide the interval by 2
    interval = interval / 2;
    Serial.printf("New interval: %i \n", interval);
    cycleCount = 0;
  }
  //Once frequency of blinking gets too high, we will permenantly keep LED on permanently
  if (interval < 25) {
    // Keep the LED on permanently
    digitalWrite(LED, HIGH);
    Serial.printf("LED ON! \n");
    // Stop the loop from running again
    while (true);
  }
}