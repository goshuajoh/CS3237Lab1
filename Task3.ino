#define SWITCH 4
byte state = LOW;
unsigned long lastDebounceTime = 0;  // Last time the switch was toggled
unsigned long debounceDelay = 50;    // Debounce time in milliseconds

void setup() {
  Serial.begin(115200);
  pinMode(SWITCH, INPUT_PULLUP);
}

void loop() {
  int reading = digitalRead(SWITCH);

  // Check if the switch has been pressed (reading LOW) and debounce the input
  if (reading == LOW && (millis() - lastDebounceTime) > debounceDelay) {
    state = !state;  // Toggle the state
    lastDebounceTime = millis();  // Update the last debounce time
  }

  if (state) {
    Serial.println("Toggle On");
  } else {
    Serial.println("Toggle Off");
  }

  delay(10);  // Small delay to make the serial output readable
}
