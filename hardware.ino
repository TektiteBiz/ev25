#define LED_R 11
#define LED_G 12
#define LED_B 10

#define DIR_R 5
#define PWM_R 6
#define DIR_L 8
#define PWM_L 9

#define GO 0
#define STOP 1

void setupHardware() {
  // Config
  analogWriteFreq(10000);
  analogWriteRange(10000);

  // LED
  pinMode(LED_R, OUTPUT);
  pinMode(LED_G, OUTPUT);
  pinMode(LED_B, OUTPUT);

  LEDWrite(1, 1, 1);

  // Motors
  pinMode(DIR_R, OUTPUT);
  pinMode(DIR_L, OUTPUT);
  pinMode(PWM_R, OUTPUT);
  pinMode(PWM_L, OUTPUT);

  analogWrite(PWM_R, 10000);
  analogWrite(PWM_L, 10000);

  // Buttons
  pinMode(GO, INPUT_PULLUP);
  pinMode(STOP, INPUT_PULLUP);

  // Serial
  Serial.begin(115200);
}

// RGB values from 0-1
void LEDWrite(double r, double g, double b) {
  analogWrite(LED_R, r * 10000.0f);
  analogWrite(LED_G, g * 10000.0f);
  analogWrite(LED_B, b * 10000.0f);
}

// Buttons
bool GOPressed() {
  return digitalRead(GO) == LOW;
}
bool STOPPressed() {
  return digitalRead(STOP) == LOW;
}