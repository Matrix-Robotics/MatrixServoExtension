#include "MatrixServoExtension.h"

bool MatrixServo::begin(){
	Wire.begin();
	i2cMUXSelect();
	delay(50);
	if(i2cReadData(Device_ID) == 0x46){
		i2cWriteData(Device_Control_1, 0x08); // reset
		delay(500);
		i2cWriteData(Device_Control_1, 0x00); // module enable
		delay(500);
		return true;
	}
	else{
		return false;
	}
}

float MatrixServo::getVbat(){
	i2cMUXSelect();
	return i2cReadData(Battery_Voltage)*0.033;
}

void MatrixServo::setAngle(int ch, uint8_t Angle){
	i2cMUXSelect();
	ChannelEN(ServoRegType(ch+4));
	i2cWriteData(ServoRegType(ch+4), Angle);
}

void MatrixServo::ChannelRelease(int ch){
	switch (ch){
		case 1:
			_EN1 = 0; 
			break;
		case 2:
			_EN2 = 0; 
			break;
		case 3:
			_EN3 = 0; 
			break;
		case 4:
			_EN4 = 0; 
			break;
		case 5:
			_EN5 = 0; 
			break;
		case 6:
			_EN6 = 0; 
			break;
		case 7:
			_EN7 = 0; 
			break;
		case 8:
			_EN8 = 0; 
			break;
	}
	uint8_t tx = (_EN1 << 7) + (_EN2 << 6) + (_EN3 << 5) + (_EN4 << 4) 
          	   + (_EN5 << 3) + (_EN6 << 2) + (_EN7 << 1) + _EN8;
	i2cWriteData(Device_Control_2, tx);
}

void MatrixServo::ChannelEN(ServoRegType ch){
	switch (ch){
		case CH1_Angle:
			_EN1 = 1; 
			break;
		case CH2_Angle:
			_EN2 = 1; 
			break;
		case CH3_Angle:
			_EN3 = 1; 
			break;
		case CH4_Angle:
			_EN4 = 1; 
			break;
		case CH5_Angle:
			_EN5 = 1; 
			break;
		case CH6_Angle:
			_EN6 = 1; 
			break;
		case CH7_Angle:
			_EN7 = 1; 
			break;
		case CH8_Angle:
			_EN8 = 1; 
			break;
	}
	uint8_t tx = (_EN1 << 7) + (_EN2 << 6) + (_EN3 << 5) + (_EN4 << 4) 
          	   + (_EN5 << 3) + (_EN6 << 2) + (_EN7 << 1) + _EN8;
	i2cWriteData(Device_Control_2, tx);
}

uint8_t MatrixServo::i2cReadData(ServoRegType reg){
	
	Wire.beginTransmission(MatrixServo_ADDR);
	Wire.write(reg);
	Wire.endTransmission(1);

	delay(1);

	Wire.requestFrom(MatrixServo_ADDR, 1);

	delay(1);

	return Wire.read();
}

void MatrixServo::i2cMUXSelect(){
	switch (_ver)
	{
	case 2:
		Wire.beginTransmission(ADDR_PCA954X);
		Wire.write(_ch + 4);
		Wire.endTransmission(1);

		delayMicroseconds(300);
		break;
	case 3:
		Wire.beginTransmission(ADDR_PCA954X);
		Wire.write((1 << _ch));
		Wire.endTransmission(1);
		
		delayMicroseconds(300);
		break;
	default:
		break;
	}
}

void MatrixServo::i2cWriteData(ServoRegType reg, uint8_t data){

	Wire.beginTransmission(MatrixServo_ADDR);

	Wire.write(reg);
	Wire.write(data);

	Wire.endTransmission(1);
}
