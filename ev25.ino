void setup() {
  setupHardware();
  setupSensing();
}


long lastPrint = 0;
void loop() {
  if (STOPPressed()) {
    LEDWrite(1, 0, 0);
    motorWriteL(0.0);
    motorWriteR(0.2);
  } else if (GOPressed()) {
    LEDWrite(0, 1, 0);
    motorWriteL(0.2);
    motorWriteR(0.0);
  } else {
    LEDWrite(0.1, 0.1, 0.1);
    motorWriteL(0.0);
    motorWriteR(0.0);
  }

  if (millis() - lastPrint > 50) {
    Serial.print("gyro:");
    Serial.print(readGyro()*RAD_TO_DEG);
    Serial.print(",angleL:");
    Serial.print(readAngleL());
    Serial.print(",angleR:");
    Serial.println(readAngleR());
    lastPrint = millis();
  }
}
