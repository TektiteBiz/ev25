#include <ICM20689.h>
#include <MT6701.h>
#include <SPI.h>

#define CS_L 17
#define CS_R 20
#define CS_IMU 21

ICM20689 imu(SPI, CS_IMU);
MT6701 encL;
MT6701 encR;

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
  SPI.begin();

  // IMU
  int status = imu.begin();
  if (status < 0) {
    displayError("IMU INITIALIZATION FAILED");
  }
  status = imu.setGyroRange(ICM20689::GYRO_RANGE_500DPS);
  if (status < 0) {
    displayError("IMU GYRO INITIALIZATION FAILED");
  }

  // Encoders
  if (!encL.initializeSSI(CS_L)) {
    displayError("LEFT ENCODER INITIALIZATION FAILED");
  }
  if (!encR.initializeSSI(CS_R)) {
    displayError("LEFT ENCODER INITIALIZATION FAILED");
  }
}

// Returns angular velocity on the yaw axis in rad/s
double readGyro() {
  imu.readSensor();
  return imu.getGyroZ_rads();
}

// Encoder funcs
double readAngleL() {
  return encL.angleRead();
}
double readAngleR() {
  return encR.angleRead();
}