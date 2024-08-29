//Adapted from: https://github.com/deangi/PIRSensor/blob/main/examples/PIRSensor.
//Adapted from https://randomnerdtutorials.com/esp32-pir-motion-sensor-interrupts-timers/
#include <Arduino.h>

#define PIRPIN 16
#define LED 5
#define INTERVAL 3000

volatile unsigned long lastTriggerTime = 0;
volatile boolean motionDetected = false;

void IRAM_ATTR motionDetectedISR() {
  motionDetected = true;
  lastTriggerTime = millis();
}

void setup() {
  Serial.begin(115200);
  Serial.println("\nPIR sensor test\n");
  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
  pinMode(PIRPIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIRPIN), motionDetectedISR, RISING);
}

void loop() {
  unsigned long currentTime = millis();

  if (motionDetected) {
    digitalWrite(LED, HIGH);
    Serial.println("Motion Detected!!");
    motionDetected = false;
  }

  if (digitalRead(LED) == HIGH && currentTime - lastTriggerTime >= INTERVAL) {
    Serial.println("Motion stopped!!");
    digitalWrite(LED, LOW);
  }
}