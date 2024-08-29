#define PIN 4
volatile bool pressed = false;
volatile unsigned long lastPressTime = 0;  // Time of the last button press
volatile int pressCount = 0;
const unsigned long debounceDelay = 50;    // Debounce time in milliseconds

void IRAM_ATTR isr() {
    unsigned long currentTime = millis();

    // Check if the time since the last press is greater than the debounce delay
    if ((currentTime - lastPressTime) > debounceDelay) {
        lastPressTime = currentTime;  // Update the last press time
        pressed = true;               // Set the flag to process in the loop
    }
}

void setup() {
    Serial.begin(115200);
    pinMode(PIN, INPUT_PULLUP);
    attachInterrupt(PIN, isr, FALLING);
}

void loop() {
    if (pressed) {
        pressCount++;
        Serial.printf("Button has been pressed %u times\n", pressCount);
        pressed = false;  // Reset the pressed flag
    }
}
