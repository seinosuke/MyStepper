#ifndef MyStepper_H_
#define MyStepper_H_
#include "arduino.h"

class Motor
{
public:
	Motor(int X1,int Y1,int X2,int Y2);
	void cw1(int rotation,int interval);
	void ccw1(int rotation,int interval);
	void cw2(int rotation,int interval);
	void ccw2(int rotation,int interval);
	void cw1_2(int rotation,int interval);
	void ccw1_2(int rotation,int interval);
private:
	int pin[4];
};
#endif