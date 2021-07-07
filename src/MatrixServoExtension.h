#ifndef _MatrixServoExtension_H_
#define _MatrixServoExtension_H_

#include <Arduino.h>
#include <Wire.h>

#ifndef ADDR_PCA954X
#define ADDR_PCA954X 0x70
#endif

#define MatrixServo_ADDR 0x25

class MatrixServo{
private:
  typedef enum __ServoRegType
  {
    Device_ID = 1,
    Device_Control_1,
    Device_Control_2,
    Battery_Voltage,
    CH1_Angle,
    CH2_Angle,
    CH3_Angle,
    CH4_Angle,
    CH5_Angle,
    CH6_Angle,
    CH7_Angle,
    CH8_Angle
  } ServoRegType;

	uint8_t _ch=0, _ver=1;
	uint8_t i2cReadData(ServoRegType reg);
  uint8_t _EN1 = 0, _EN2 = 0, _EN3 = 0, _EN4 = 0, _EN5 = 0, _EN6 = 0, _EN7 = 0, _EN8 = 0;
	void i2cMUXSelect();
  void ChannelEN(ServoRegType ch);
	void i2cWriteData(ServoRegType reg, uint8_t data);
public:
	friend class MiniI2C;
	bool begin();
  float getVbat();
	void ChannelRelease(int ch);
	void setAngle(int ch, uint8_t Angle);
};

#endif
