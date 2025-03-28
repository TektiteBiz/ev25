void setup() {
  setupHardware();
  setupSensing();
}


long lastPrint = 0;
void loop() {
  if (STOPPressed()) {
    LEDWrite(1, 0, 0);
  } else if (GOPressed()) {
    LEDWrite(0, 1, 0);
  } else {
    LEDWrite(0.1, 0.1, 0.1);
  }

  if (millis() - lastPrint > 50) {
    Serial.print("gyro:");
    Serial.println(readGyro()*RAD_TO_DEG);
    lastPrint = millis();
  }
}
