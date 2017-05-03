#include "StepperMotor.h"

StepperMotor::StepperMotor(int motor_pulse,int motor_dir,int motor_en,int steps_resolution)
{
	pulse_pin=motor_pulse;
	dir_pin=motor_dir;
	en_pin=motor_en;
	stepResolution=steps_resolution;

	pinMode(pulse_pin,OUTPUT);
	pinMode(dir_pin,OUTPUT);
	pinMode(en_pin,OUTPUT);

	digitalWrite(en_pin,0);
}

void StepperMotor::setParam(int rpm,int accel,int jerk)
{
	rpmSet=rpm;
	accelLimit=accel;
	jerkLimit=jerk;
}

void StepperMotor::moveSteps(int numOfSteps,int dir)
{
	digitalWrite(dir_pin,dir);
}

void StepperMotor::disable()
{
	digitalWrite(en_pin,1);
}

void StepperMotor::enable()
{
	digitalWrite(en_pin,0);
}
