#ifndef StepperMotor_h
#define StepperMotor_h

#include "Arduino.h"

class StepperMotor
{
public:
	StepperMotor(int motor_pulse,int motor_dir,int motor_en,int steps_resolution)
	void setParam(int rpm,int accel,int jerk,int dir);
	void moveSteps(int numOfSteps,int dir);
	void enable();
	void disable();
private:
	int pulse_pin;
	int dir_pin;
	int en_pin;
	int stepResolution;
	int rpmSet=100;
	int dirSet=0;
	int accelLimit;
	int jerkLimit;

};

#endif