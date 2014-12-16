#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  elevBottom,     sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port1,           leftElevator2, tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port3,           backRight,     tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port4,           backLeft,      tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port5,           frontLeft,     tmotorVex393_MC29, openLoop, encoderPort, I2C_4)
#pragma config(Motor,  port6,           rightElevator, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           leftElevator,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           grabberLeft,   tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           grabberRight,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          rightElevator2, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
CompOpenLoop.c
- Basic driver control program for 2014 VEX omni drive base.
- The left joystick Y-axis controls the robot's forward and backward movement.
- The left joystick X-axis controls the robot's left and right movement.
- The right joystick X-axis controls the robot's rotation.
- Button 5 controls the grabber.
- Button 6 controls the elevator.

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 1				leftElevatorMotor2  VEX Motor 393					Second Left Elevator motor
Motor Port 2        frontRight          VEX Motor 393         Front Right motor
Motor Port 3        backRight           VEX Motor 393         Back Right motor
Motor Port 4        frontLeft           VEX Motor 393         Front Left motor
Motor Port 5        backLeft            VEX Motor 393         Back Left motor
Motor Port 6        rightElevator       VEX Motor 393         Right Elevator motor
Motor Port 7        leftElevator        VEX Motor 393         Left Elevator motor
Motor Port 8        grabberLeft         VEX Motor 393         Left Grabber motor
Motor Port 9				grabberRight				VEX Motor 393					Right Grabber motor
Motor Port 10				rightElevatorMotor2 VEX Motor 393 				Second Right Elevator motor
----------------------------------------------------------------------------------------------------*/
//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(60)
#pragma userControlDuration(0)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!
#include "AutonomousFunctions.c"

//Global variables

int frontLeftMotorSpeed = 0;
int frontRightMotorSpeed = 0;
int backRightMotorSpeed = 0;
int backLeftMotorSpeed = 0;

// All activities that occur before the competition starts
// Example: clearing encoders, setting servo positions, ...
void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

}

// Task for the autonomous portion of the competition.
task autonomous()
{

	// TODO - Call functions in AutonomousFunctions.c here.

}

// Task for the driver controlled portion of the competition.
task usercontrol()
{
	while (true)
	{

		// Drive commands.
		frontRightMotorSpeed = - vexRT[Ch3] + vexRT[Ch4] + vexRT[Ch1];
    backRightMotorSpeed = - vexRT[Ch3]  - vexRT[Ch4] + vexRT[Ch1];
    frontLeftMotorSpeed =  vexRT[Ch3] + vexRT[Ch4] + vexRT[Ch1];
	  backLeftMotorSpeed = vexRT[Ch3] - vexRT[Ch4] + vexRT[Ch1];
	  motor[frontRight] = frontRightMotorSpeed;
    motor[backRight] = backRightMotorSpeed;
    motor[frontLeft] = frontLeftMotorSpeed;
	  motor[backLeft] = backLeftMotorSpeed;

	  // Elevator raise/lower control.
	  if (vexRT[Btn6U] == 1) {  // raise elevator when button 6 up pressed
    	motor[rightElevator] = 127;
    	motor[leftElevator] = 127;
    	motor[leftElevator2] = 127;
    	motor[rightElevator2] = 127;
    } else if ((vexRT[Btn6D] == 1) && // lower elevator when button 6D pressed
    	         (SensorValue(elevBottom) == 0)) { // and stop at limit switch
    	motor[rightElevator] = -127;
    	motor[leftElevator] = -127;
    	motor[leftElevator2] = -127;
    	motor[rightElevator2] = -127;

    } else {  // turn motors off when neither button is pressed
      motor[rightElevator] = 0;
      motor[leftElevator] = 0;
      motor[leftElevator2] = 0;
    	motor[rightElevator2] = 0;
    }

    // Claw open/close control
    if (vexRT[Btn8D] == 1) {
    	motor[grabberRight] = 127;  // close claw
    	motor[grabberLeft] = 127;
    } else if(vexRT[Btn8L] == 1) {
    	motor[grabberLeft] = -127;  // open claw
    	motor[grabberRight] =-127;
    } else {
      motor[grabberRight] = 0; // turn right grabber off
      motor[grabberLeft] = 0; //turn left grabber off
    }
 	}
}
