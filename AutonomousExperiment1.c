#pragma config(Sensor, in1,    leftLight,      sensorLineFollower)
#pragma config(Sensor, in2,    middleLight,    sensorLineFollower)
#pragma config(Sensor, in3,    rightLight,     sensorLineFollower)
#pragma config(Sensor, in4,    wristPot,       sensorPotentiometer)
#pragma config(Sensor, in6,    gyro,           sensorGyro)
#pragma config(Sensor, dgtl1,  rightEncoder,   sensorQuadEncoder)
#pragma config(Sensor, dgtl3,  leftEncoder,    sensorQuadEncoder)
#pragma config(Sensor, dgtl5,  extensionEncoder, sensorQuadEncoder)
#pragma config(Sensor, dgtl7,  touchSensor,    sensorTouch)
#pragma config(Sensor, dgtl8,  sonarSensor,    sensorSONAR_cm)
#pragma config(Sensor, dgtl11, armEncoder,     sensorQuadEncoder)
#pragma config(Motor,  port1,           rightFrontMotor, tmotorVex393_HBridge, openLoop, reversed)
#pragma config(Motor,  port2,           rightRearMotor, tmotorVex393_MC29, openLoop, reversed, encoderPort, dgtl1)
#pragma config(Motor,  port3,           leftFrontMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           leftRearMotor, tmotorVex393_MC29, openLoop, encoderPort, dgtl3)
#pragma config(Motor,  port6,           clawMotor,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           armMotor,      tmotorVex393_MC29, openLoop, encoderPort, dgtl11)
#pragma config(Motor,  port8,           leftExtendMotor, tmotorVex393_MC29, openLoop, encoderPort, dgtl5)
#pragma config(Motor,  port9,           rightExtendMotor, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          wristMotor,    tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "AutonomousExperimentFunctions.c"

task main()
{

  // Move the robot forward.
	moveForward(500, 50);

	// Turn the robot to the right.
	turnRight(480, 50);

	// Open the claw.
	openClaw(150, 10000);

	// Profit!!!
}
