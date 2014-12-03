// AutonomousFunctions.c
//   Functions that can be called for autonomous operation of the 2014 VEX robot.

// The following variables are used by these functions and should be mapped
// using these variables in the pragmas in the calling program:
//		leftEncoder <- Left front drive motor encoder.
//    rightEncoder <- Right front drive motor encoder.
// 		leftFrontMotor <- Left front drive motor.
//		leftRearMotor <- Left rear drive motor.
//		rightFrontMotor <- Right front drive motor.
//		rightRearMotor <- Right rear drive motor.
//		armEncoder <- Encoder on the arm motor.
//    armMotor <- Arm raising/lowering motor.
// 		extensionEncoder <- Encoder on the left extension motor.
//		leftExtendMotor <- Left arm extension motor.
//		rightExtendMotor <- Right arm extension motor.
//		clawMotor <- Claw open/close motor.
//		wristPot <- Potentiometer on the wrist motor.
//		wristMotor <- Wrist motor that the claw is mounted on.

// TODO - These functions shouldn't depend on pragmas defined externally.
//        It makes the library functions dependent on the calling program.
//        (Very bad software engineering practice...functions should be decoupled.)

// DRIVE COMMANDS

// Clear motor encoders.
void clearMotorEncoders() {

	nMotorEncoder[frontRight] = 0;
	nMotorEncoder[backRight] = 0;
	nMotorEncoder[frontLeft] = 0;
	nMotorEncoder[backLeft] = 0;

}

// Stop the robot.
void stopRobot() {

  motor[frontRight] = 0;
	motor[backRight] = 0;
	motor[frontLeft] = 0;
	motor[backLeft] = 0;

}

// Move the robot forward a specified number of encoder counts at the
// given speed.
void moveForward(int encoderCounts, int speed) {

	//Clear the encoders before using them
	clearMotorEncoders();
/*
	//While both of the encoders are less than the specified amount
	while(SensorValue[rightEncoder] < encoderCounts)
	{
		//If the two encoder values are equal
		if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder]))
		{
			//Move the robot forward at the specified speed
			motor[rightRearMotor] = speed;
			motor[rightFrontMotor] = speed;
			motor[leftRearMotor] = speed;
			motor[leftFrontMotor] = speed;
		}

		//If the right encoder is greater than the left encoder (veering to the left)
		else if(abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))
		{
			//Adjust the robot slightly to the right
			motor[rightRearMotor] = speed;
			motor[rightFrontMotor] = speed;
			motor[leftRearMotor] = speed + 10;
			motor[leftFrontMotor] = speed + 10;
		}

		//If the left encoder is greater than the right encoder (veering to the right)
		else if(abs(SensorValue[rightEncoder]) < abs(SensorValue[leftEncoder]))
		{
			//Adjust the robot slightly to the right
			motor[rightRearMotor] = speed + 10;
			motor[rightFrontMotor] = speed + 10;
			motor[leftRearMotor] = speed;
			motor[leftFrontMotor] = speed;
		}
	}
*/
	//Stop the robot
	stopRobot();
}

// Move the robot backward a specified number of encoder counts at the
// given speed.
void moveBackward(int encoderCounts, int speed) {

	//Clear the encoders before using them
	clearMotorEncoders();
	/*

	//While both of the encoders are less than the specified amount
	while(abs(SensorValue[rightEncoder]) < encoderCounts)
	{
		//If the two encoder values are equal
		if(abs(SensorValue[rightEncoder]) == abs(SensorValue[leftEncoder]))
		{
			//Move the robot forward at the specified speed
			motor[rightRearMotor] = -speed;
			motor[rightFrontMotor] = -speed;
			motor[leftRearMotor] = -speed;
			motor[leftFrontMotor] = -speed;
		}

		//If the right encoder is greater than the left encoder (veering to the left)
		else if(abs(SensorValue[rightEncoder]) > abs(SensorValue[leftEncoder]))
		{
			//Adjust the robot slightly to the right
			motor[rightRearMotor] = -speed;
			motor[rightFrontMotor] = -speed;
			motor[leftRearMotor] = -speed - 10;
			motor[leftFrontMotor] = -speed - 10;
		}

		//If the left encoder is greater than the right encoder (veering to the right)
		else if(abs(SensorValue[rightEncoder]) < abs(SensorValue[leftEncoder]))
		{
			//Adjust the robot slightly to the right
			motor[rightRearMotor] = -speed - 10;
			motor[rightFrontMotor] = -speed - 10;
			motor[leftRearMotor] = -speed;
			motor[leftFrontMotor] = -speed;
		}
	}
*/
	//Stop the robot
	stopRobot();
}

/*
//Turn the robot left for the specified encoder counts
//at a specified speed
void turnLeft(int encoderCounts, int speed)
{
	//Clear the encoders before using them
	clearMotorEncoders();

	//While the absolute value of the right motor's encoder is less
	//than the specified amount
	//while(abs(SensorValue[rightEncoder]) < encoderCounts)
	{
		//Turn the robot to the left at the specified speed
		motor[rightRearMotor] = speed;
		motor[rightFrontMotor] = speed;
		motor[leftRearMotor] = -speed;
		motor[leftFrontMotor] = -speed;
	}

	//Stop the robot
	stopRobot();
}

//Turn the robot right for the specified encoder counts
//at a specified speed
void turnRight(int encoderCounts, int speed)
{
	//Clear the encoders
	clearMotorEncoders();
	//While the absolute value of the left motor's encoder is less
	//than the specified amount
	while(abs(SensorValue[leftEncoder]) < encoderCounts)
	{
		//Turn the robot to the right at the specified speed
		motor[rightRearMotor] = -speed;
		motor[rightFrontMotor] = -speed;
		motor[leftRearMotor] = speed;
		motor[leftFrontMotor] = speed;
	}

	//Stop the robot
	stopRobot();
}

// ACTUATOR FUNCTIONS
// Raise the arm the specified angle at the given speed.
void raiseArm(int angle, int speed) {

	// Clear the arm encoder.
	SensorValue[armEncoder] = 0;

	// Rotate the arm by the specified number of degrees.
	// This only works for the shaft encoder because it has 360 ticks per rotation.
	while (abs(SensorValue[armEncoder]) < angle) {
		motor[armMotor] = speed;
	}

	// Stop motor.
	motor[armMotor] = 0;
}

// Lower the arm the specified angle at the given speed.
void lowerArm(int angle, int speed) {

	// Clear the arm encoder.
	SensorValue[armEncoder] = 0;

	// Rotate the arm by the specified number of degrees.
	// This only works for the shaft encoder because it has 360 ticks per rotation.
	while (abs(SensorValue[armEncoder]) < angle) {
		motor[armMotor] = -speed;
	}
	// Stop motor.
	motor[armMotor] = 0;
}

// Stop the arm extension motors.
void stopExtendMotors() {

	motor[leftExtendMotor] = 0;
  motor[rightExtendMotor] = 0;

}

// Extend the arm the specified distance at the given speed.
void extendArm(int distance, int speed) {

	// Clear the encoder.
  SensorValue[extensionEncoder] = 0;

  // Extend the arm until it has extended the distance specified.
  while (abs(SensorValue[extensionEncoder]) < distance) {
  	motor[leftExtendMotor] = speed;
  	motor[rightExtendMotor] = speed;
  }

  // Stop extend motors.
	stopExtendMotors();

}

// Retract the arm the specified distance at the given speed.
void retractArm(int distance, int speed) {

	// Clear the encoder.
  SensorValue[extensionEncoder] = 0;

  // Retract the arm until it has retracted the distance specified.
  while (abs(SensorValue[extensionEncoder]) < distance) {
  	motor[leftExtendMotor] = -speed;
  	motor[rightExtendMotor] = -speed;
  }

  // Stop extend motors.
	stopExtendMotors();

}

// Stop the claw.
void stopClaw() {
	motor[clawMotor] = 0;
}

// Open the claw at the given speed for the specified duration.
// (Duration is in milliseconds.)
void openClaw(int speed, int duration) {
	for (int i = 0; i < duration; i++) {
		motor[clawMotor] = speed;
		wait1Msec(1);
	}
	stopClaw();
}

// Close the claw at the given speed for the specified duration.
// (Duration is in milliseconds.)
void closeClaw(int speed, int duration) {
	for (int i = 0; i < duration; i++) {
		motor[clawMotor] = -speed;
		wait1Msec(1);
	}
	stopClaw();
}

// Rotate the wrist to the desired position at the indicated speed.
void rotateWrist(int position, int speed) {
	if (position < abs(SensorValue[wristPot])) {
		motor[wristMotor] = speed;
	} else if (position > abs(SensorValue[wristPot])) {
		motor[wristMotor] = -speed;
	} else {
		motor[wristMotor] = 0;
	}
}
*/
