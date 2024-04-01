#define ESC_PIN 9  // Connect the ESC signal wire to pin 9

void setup() {
  pinMode(ESC_PIN, OUTPUT);
}

void loop() {
  // Example: Set throttle to mid-point
  oneShotWrite(ESC_PIN, 187);  // 187 microseconds as an example for mid-throttle
  delay(1000);  // Delay for demonstration purposes, adjust as needed

  // Add your control logic here
}

void oneShotWrite(int pin, int pulseWidth) {
  digitalWrite(pin, HIGH);
  delayMicroseconds(pulseWidth);  // Send a pulse with the specified width
  digitalWrite(pin, LOW);
  // The delay between pulses should be long enough for the ESC to recognize the pulse
  // OneShot125 typically expects the next pulse within 125-250us, but the exact timing
  // may depend on your ESC's documentation and how it handles pulses outside the expected range.
}
