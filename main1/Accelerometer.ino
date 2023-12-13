
void readMpu6050Values() {
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_addr, 14, true);  // request a total of 14 registers

  AcX = Wire.read() << 8 | Wire.read();  // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read();  // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 8 | Wire.read();  // 0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp = Wire.read() << 8 | Wire.read();  // 0x41 (TEMP_OUT_H) & 0x42 (TEMP_OUT_L)
  GyX = Wire.read() << 8 | Wire.read();  // 0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY = Wire.read() << 8 | Wire.read();  // 0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ = Wire.read() << 8 | Wire.read();  // 0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)

  //calibrate values
  AcXCalibrate = AcX / (65536 * ACCELE_RANGE - 0.01);
  AcYCalibrate = AcY / (65536 * ACCELE_RANGE);
  AcZCalibrate = AcZ / (65536 * ACCELE_RANGE + 0.02);
  GyXCalibrate = GyX / 65536 * GYROSC_RANGE + 1.7;
  GyYCalibrate = GyY / 65536 * GYROSC_RANGE - 1.7;
  GyZCalibrate = GyZ / 65536 * GYROSC_RANGE + 0.25;
}

void PrintValues() {

  //// MPU6050 ////

  Serial.print(onItsSide());
  Serial.print(isMoving());
  Serial.print(AcXCalibrate);
  Serial.print(" ");
  Serial.print(AcYCalibrate);
  Serial.print(" ");
  Serial.print(AcZCalibrate);
  Serial.print(" ");
  Serial.print(sq(GyXCalibrate));
  Serial.print(" ");
  Serial.print(sq(GyYCalibrate));
  Serial.print(" ");
  Serial.print(sq(GyZCalibrate));
  Serial.println();
  

  // Values Gy while still : 55 000, 25 000, 12 000
  // Values Gy while picked-up :
}

bool onItsSide() {
  if (abs(AcXCalibrate) > 0.1 || abs(AcYCalibrate > 0.1)) {
    return true;
  } else if (abs(AcXCalibrate) < 0.5 || abs(AcYCalibrate < 0.5)) {
    return false;
  }
}

bool isMoving(){
  if (sq(GyXCalibrate)>400 || sq(GyYCalibrate)>700 || sq(GyZCalibrate) >400){
    return true;
  }
  else if(sq(GyXCalibrate)<20 || sq(GyYCalibrate)<35 || sq(GyZCalibrate) < 20){
    return false;
  }
}

void readColor(){
  if (!isMoving() && !onItsSide()){
    Serial.println(1);
  }
}


