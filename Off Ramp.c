#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  HTServo)
#pragma config(Sensor, S1,     touch,          sensorNone)
#pragma config(Sensor, S2,     touchSensor,    sensorTouch)
#pragma config(Motor,  mtr_S1_C1_1,     belt,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C1_2,     harvester,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     rightDrive,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     leftDrive,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C3_1,     arm,           tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     motorI,        tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S1_C4_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S1_C4_6,    servo6,               tServoNone)            !!*//


#include "JoystickDriver.c"  //Include file to "handle" the Bluetooth messages.
#include "library\display.h"

void initializeRobot()
{
	// Place code here to sinitialize servos to starting positions.
	// Sensors are automatically configured and setup by ROBOTC. They may need a brief time to stabilize.

	return;
}

const int OFF_RAMP = 0;
const int START_AT_PARK_ZONE = 1;

task main()
{
	initializeRobot();

	waitForStart(); // Wait for the beginning of autonomous phase.
	int routineCounter = 0;

	nMotorEncoder[rightDrive] = 0;
	nMotorEncoder[leftDrive] = 0;
	while(nNxtButtonPressed != ORANGE_BUTTON){
		switch(nNxtButtonPressed){
		case LEFT_BUTTON:
			while(nNxtButtonPressed == LEFT_BUTTON){}	//empty while to delay until button is released
			routineCounter ++;
			break;
		case RIGHT_BUTTON:
			while(nNxtButtonPressed == LEFT_BUTTON){}	//empty while to delay until button is released
			routineCounter --;
			break;
		}//end switch
		switch (routineCounter){
		case OFF_RAMP:
			displayBigStringAt(LEFT_X, TOP_Y, "OFF_RAMP");
			break;
		case START_AT_PARK_ZONE:
			displayBigStringAt(LEFT_X, TOP_Y, "PARKING_ZONE");
			break;
		}
	}//end while (should end when Orange button is pressed)

	switch(routineCounter){
	case OFF_RAMP:
		while(nMotorEncoder[rightDrive] > -6100)
		{
			motor[rightDrive] = -50;
			motor[leftDrive] = -50;
		}
		motor[rightDrive] = 0;
		motor[leftDrive] = 0;

	break;
case START_AT_PARK_ZONE:
		/*sense for IR
		depending on where it is
			go straight forward to hit kickstand
			go forward a little bit then turn and go forward to hit kickstand
			go forward a little, straight, turn, forward to hit kickstand
		stop*/
	break;
}


//while(SensorValue[touch] = 1)
//{
//	motor[arm] = 100;
//}
//motor[arm] = 0;
//while(SensorValue[touch] = 0)
//{
//	motor[arm] = 100;
//}
//motor[arm] = 0;

while (true){}
}
