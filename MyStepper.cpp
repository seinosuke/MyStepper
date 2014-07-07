#include "arduino.h"
#include "MyStepper.h"

Motor::Motor(int X1,int Y1,int X2,int Y2)
{
	pinMode(X1,OUTPUT);
	pinMode(Y1,OUTPUT);
	pinMode(X2,OUTPUT);
	pinMode(Y2,OUTPUT);
	pin[0] = X1;
	pin[1] = Y1;
	pin[2] = X2;
	pin[3] = Y2;
}

void Motor::cw1(int rotation,int interval)//1相励磁　時計回り
{
	for(int c=0; c<rotation; c++)
	{
		for(int i=0; i<4; i++)
		{
			int prev = i-1;
			if(prev == -1) prev = 3;
			digitalWrite(pin[prev], LOW);
			digitalWrite(pin[i], HIGH);
			delay(interval);
		}
	}
}
void Motor::ccw1(int rotation,int interval)//1相励磁　反時計回り
{
	for(int c=0; c<rotation; c++)
	{
		for(int i=3; i>-1; i--)
		{
			int prev = i+1;
			if(prev == 4) prev = 0;
			digitalWrite(pin[prev], LOW);
			digitalWrite(pin[i], HIGH);
			delay(interval);
		}
	}
}
void Motor::cw2(int rotation,int interval)//2相励磁　時計回り
{
	for(int c=0; c<rotation; c++)
	{
		for(int i=0; i<4; i++)
		{
			int prev = i-1;
			int next = i+1;
			if(prev == -1) prev = 3;
			if(next == 4) next = 0;
			digitalWrite(pin[prev], LOW);
			digitalWrite(pin[i], HIGH);
			digitalWrite(pin[next], HIGH);
			delay(interval);
		}
	}
}
void Motor::ccw2(int rotation,int interval)//2相励磁　反時計回り
{
	for(int c=0; c<rotation; c++)
	{
		for(int i=3; i>-1; i--)
		{
			int prev = i+1;
			int next = i-1;
			if(prev == 4) prev = 0;
			if(next == -1) next = 3;
			digitalWrite(pin[prev], LOW);
			digitalWrite(pin[i], HIGH);
			digitalWrite(pin[next], HIGH);
			delay(interval);
		}
	}
}
void Motor::cw1_2(int rotation,int interval)//1-2相励磁　時計回り
{
	for(int c=0; c<rotation; c++)
	{
		for(int i=0; i<4; i++)
		{
			int prev = i-1;
			int next = i+1;
			if(prev == -1) prev = 3;
			if(next == 4) next = 0;
			digitalWrite(pin[prev], LOW);
			digitalWrite(pin[i], HIGH);
			digitalWrite(pin[next], LOW);
			delay(interval);
			digitalWrite(pin[next], HIGH);
			delay(interval);
		}
	}
}
void Motor::ccw1_2(int rotation,int interval)//1-2相励磁　反時計回り
{
	for(int c=0; c<rotation; c++)
	{
		for(int i=3; i>-1; i--)
		{
			int prev = i+1;
			int next = i-1;
			if(prev == 4) prev = 0;
			if(next == -1) next = 3;
			digitalWrite(pin[prev], LOW);
			digitalWrite(pin[i], HIGH);
			digitalWrite(pin[next], LOW);
			delay(interval);
			digitalWrite(pin[next], HIGH);
			delay(interval);
		}
	}
}