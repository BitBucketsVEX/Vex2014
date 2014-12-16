// AutonomousFunctions.c
//   Functions that can be called for autonomous operation of the 2014 VEX robot.

// The following variables are used by these functions and should be mapped
// using these variables in the pragmas in the calling program:
// 		frontLeft <- Left front drive motor and encoder.
//		backLeft <- Left rear drive motor and encoder.
//		frontRight <- Right front drive motor and encoder.
//		backRight <- Right rear drive motor and encoder.
//		leftElevator <- Left primary elevator motor.
//		leftElevator2 <- Left secondary elevator motor.
//		rightElevator <- Right primary elevator motor.
//		rightElevator2 <- Right secondary elevator motor.
//    grabberLeft <- Left grabber motor.
//    grabberRight <- Right grabber motor.

// TODO - These functions shouldn't depend on pragmas defined externally.
//        It makes the library functions dependent on the calling program.
//        (Very bad software engineering practice...functions should be decoupled.)

// TODO - Many of these functions are inverses of each other (like moveForward and
//        moveBackward), so they could be combined into single functions with a direction
//        flag to indicate the signs for the motors.

// UTILITY FUNCTIONS

// Determine the maximum of four absolute values.
int maxOfFour(int value1, int value2, int value3, int value4) {
	int max = abs(value1);
	if (max < abs(value2)) {
		max = value2;
	}
	if (max < abs(value3)) {
		max = value3;
	}
	if (max < abs(value4)) {
		max = value4;
	}
	return max;
}

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

	// Clear the encoders before using them.
	clearMotorEncoders();

	// Run the motors until the specified number of encoder counts are reached.
	while(maxOfFour(nMotorEncoder[frontRight], nMotorEncoder[backRight],
									nMotorEncoder[frontLeft], nMotorEncoder[backLeft])
							< encoderCounts) {

		// TODO - Verify that motor signs are correct.

		// Move the robot forward at the specified speed.
		motor[frontRight] = speed;
		motor[backRight] = speed;
		motor[frontLeft] = -speed;
		motor[backLeft] = -speed;
	}
	// Stop the robot.
	stopRobot();
}

// Move the robot backward a specified number of encoder counts at the
// given speed.
void moveBackward(int encoderCounts, int speed) {

	// Clear the encoders before using them.
	clearMotorEncoders();

	// TODO - Add code here to make robot move backwards.

	// Stop the robot.
	stopRobot();
}

// Translate to the left for the specified encoder counts and speed.
void translateLeft(int encoderCounts, int speed) {

	// Clear the encoders before using them.
	clearMotorEncoders();

	// TODO - Add code here to translate to the left.

	// Stop the robot.
	stopRobot();
}

// Translate to the right for the specified encoder counts and speed.
void translateRight(int encoderCounts, int speed) {

	// Clear the encoders before using them.
	clearMotorEncoders();

	// TODO - Add code here to translate to the right.

	// Stop the robot.
	stopRobot();
}

// Rotate clockwise for the specified number of encoder counts and speed.
void rotateClockwise(int encoderCounts, int speed) {

	// Clear the encoders before using them.
	clearMotorEncoders();

	// TODO - Add code here to rotate the robot clockwise.

	// Stop the robot.
	stopRobot();

}

// Rotate counterclockwise for the specified number of encoder counts and speed.
void rotateCounterClockwise(int encoderCounts, int speed) {

	// Clear the encoders before using them.
	clearMotorEncoders();

	// TODO - Add code here to rotate the robot counterclockwise.

	// Stop the robot.
	stopRobot();

}


// ACTUATOR FUNCTIONS

// Stop the elevator motors.
void stopElevatorMotors() {

	motor[leftElevator] = 0;
	motor[leftElevator2] = 0;
	motor[rightElevator] = 0;
	motor[rightElevator2] = 0;

}

// Raise the elevator for the specified duration and speed.
// (Duration is specified in milliseconds.)
void raiseElevator(int duration, int speed) {

	// TODO - Verify the signs are correct for the motor speeds.

  // Start motors at specified speed.
	motor[leftElevator] = speed;
	motor[leftElevator2] = speed;
	motor[rightElevator] = speed;
	motor[rightElevator2] = speed;

	// Wait for the specified duration.
	wait1Msec(duration);

	// Stop the motors.
	stopElevatorMotors();
}

// Lower the elevator for the specified duration and speed.
// (Duration is specified in milliseconds.)
void lowerElevator(int duration, int speed) {

	// TODO - Insert code here to lower the elevator.

	// Stop the motors.
	stopElevatorMotors();
}

// Stop the grabber motors.
void stopGrabberMotors() {
	motor[grabberLeft] = 0;
	motor[grabberRight] = 0;
}

// Grab an object for the specified duration and speed.
// (Duration specified in milliseconds.)
void grab(int duration, int speed) {

	// TODO - Verify that the signs are correct for the motor speeds.

	// Start the grabber motor to grab an object.
	motor[grabberLeft] = speed;
	motor[grabberRight] = speed;

	// Wait for the specified duration.
	wait1Msec(duration);

	// Stop the grabber motors.
	stopGrabberMotors();

}

// Release an object for the specified duration and speed.
// (Duration specified in milliseconds.)
void release(int duration, int speed) {

	// TODO - Insert code here to release an object from the grabber.

// Stop the grabber motors.
	stopGrabberMotors();

}
