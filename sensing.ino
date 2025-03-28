#include <ICM20689.h>

#define CS_L 17
#define CS_R 20
#define CS_IMU 21

ICM20689 imu(SPI, CS_IMU);

void displayError(String error) {
  while (1) {
    Serial.println(error);
    delay(250);
    LEDWrite(1, 0, 0);
    delay(250);
    LEDWrite(0, 0, 0);
  }
}

void setupSensing() {
  int status = imu.begin();
  if (status < 0) {
    displayError("IMU INITIALIZATION FAILED");
  }
  status = imu.setGyroRange(ICM20689::GYRO_RANGE_500DPS);
  if (status < 0) {
    displayError("IMU GYRO INITIALIZATION FAILED");
  }
}

// Returns angular velocity on the yaw axis in rad/s
double readGyro() {
  imu.readSensor();
  return imu.getGyroZ_rads();
}