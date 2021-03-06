#pragma config(Sensor, dgtl1,  elevBottom,     sensorTouch)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           backRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           frontLeft,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           rightElevator, tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           leftElevator,  tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           rightElevatorMotor2, tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          leftElevatorMotor2, tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
CompOpenLoop.c
- Basic driver control program for 2014 VEX omni drive base.
- The left joystick Y-axis controls the robot's forward and backward movement.
- The left joystick X-axis controls the robot's left and right movement.
- The right joystick X-axis controls the robot's rotation.
- Button 5 controls the claw.
- Button 6 controls the elevator.

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        frontRight          VEX Motor 393         Front Right motor
Motor Port 3        backRight           VEX Motor 393         Back Right motor
Motor Port 4        frontLeft           VEX Motor 393         Front Left motor
Motor Port 5        backLeft            VEX Motor 393         Back Left motor
Motor Port 6        rightElevator       VEX Motor 393         Right Elevator motor
Motor Port 7        leftElevator        VEX Motor 393         Left Elevator motor
Motor Port 8        claw                VEX Motor 393         Claw motor
----------------------------------------------------------------------------------------------------*/
//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

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
	// Drive forward for 0.8 seconds.
  motor[frontRight] = -127;
  motor[backRight]  = -127;
  motor[frontLeft]  =  127;
  motor[backLeft]   =  127;
	wait1Msec(800);

	// Drive backward for 0.5 seconds.
  motor[frontRight] =  127;
  motor[backRight]  =  127;
  motor[frontLeft]  = -127;
  motor[backLeft]   = -127;
	wait1Msec(500);

	// Stop motors.
  motor[frontRight] = 0;
  motor[backRight]  = 0;
  motor[frontLeft]  = 0;
  motor[backLeft]   = 0;
	wait1Msec(15000);
}

// Task for the driver controlled portion of the competition.
task usercontrol()
{
	while (true)
	{
    // Drive commands.
    motor[frontRight] = - vexRT[Ch3] + vexRT[Ch4] + vexRT[Ch1];
    motor[backRight] = - vexRT[Ch3]  - vexRT[Ch4] + vexRT[Ch1];
    motor[frontLeft] =  vexRT[Ch3] - vexRT[Ch4] + vexRT[Ch1];
	  motor[backLeft] = vexRT[Ch3] + vexRT[Ch4] + vexRT[Ch1];

	  // Elevator raise/lower control.
	  if (vexRT[Btn6U] == 1) {  // raise elevator when button 6 up pressed
    	motor[rightElevator]  = 127;
    	motor[leftElevator]  = 127;
    	motor[leftElevatorMotor2] = 127;
    	motor[rightElevatorMotor2] = 127;
    } else if ((vexRT[Btn6D] == 1) && // lower elevator when button 6D pressed
    	         (SensorValue(elevBottom) == 0)) { // and stop at limit switch
    	motor[rightElevator]  = -127;
    	motor[leftElevator]  = -127;
    	motor[leftElevatorMotor2] = -127;
    	motor[rightElevatorMotor2] = -127;

    } else {  // turn motors off when neither button is pressed
      motor[rightElevator] = 0;
      motor[leftElevator] = 0;
      motor[leftElevatorMotor2] = 0;
    	motor[rightElevatorMotor2] = 0;
    }

    // Claw open/close control
    if (vexRT[Btn8D] == 1) {
    	motor[claw]  = 127;  // close claw
    } else if(vexRT[Btn8L] == 1) {
    	motor[claw]  = -127;  // open claw
    } else {
      motor[claw] = 0; // turn claw motor off
    }
 	}
}
