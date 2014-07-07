#include <MyStepper.h>

Motor stepper1(10,11,12,13);

void setup()
{
}

void loop()
{
	stepper1.cw1(25,10);
	delay(1000);
	stepper1.ccw1_2(25,10);
	delay(1000);
}