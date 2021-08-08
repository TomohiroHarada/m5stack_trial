#include <M5Stack.h>
#include "utility/MPU9250.h"

MPU9250 IMU; // new a MPU9250 object

void setup() {
  M5.begin();
  Wire.begin();

  M5.Power.begin();
  M5.Lcd.print("[Initialize] Initializing M5Stack...");

  IMU.initMPU9250();
  M5.Lcd.print("[Initialize] Initializing MPU9250...");

  IMU.initAK8963(IMU.magCalibration);
  M5.Lcd.print("[Initialize] Intializing AK8963...");
  if (Serial)
  {
    M5.Lcd.println("Calibration values: ");
    M5.Lcd.print("X-Axis sensitivity adjustment value ");
    M5.Lcd.println(IMU.magCalibration[0], 2);
    M5.Lcd.print("Y-Axis sensitivity adjustment value ");
    M5.Lcd.println(IMU.magCalibration[1], 2);
    M5.Lcd.print("Z-Axis sensitivity adjustment value ");
    M5.Lcd.println(IMU.magCalibration[2], 2);
  }

}

void loop() {
  // put your main code here, to run repeatedly:

}
