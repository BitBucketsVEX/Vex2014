#pragma config(I2C_Usage, I2C1, i2cSensors)
#pragma config(Sensor, dgtl1,  elevBottom,     sensorTouch)
#pragma config(Sensor, I2C_1,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_2,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_3,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Sensor, I2C_4,  ,               sensorQuadEncoderOnI2CPort,    , AutoAssign)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop, encoderPort, I2C_1)
#pragma config(Motor,  port3,           backRight,     tmotorVex393_MC29, openLoop, encoderPort, I2C_2)
#pragma config(Motor,  port4,           backLeft,      tmotorVex393_MC29, openLoop, encoderPort, I2C_3)
#pragma config(Motor,  port5,           frontLeft,     tmotorVex393_MC29, openLoop, encoderPort, I2C_4)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

/*+++++++++++++++++++++++++++++++++++++++++++++| Notes |++++++++++++++++++++++++++++++++++++++++++++++
EncoderTest.c
- Motor encoder test program for 2014 VEX omni drive base.

[I/O Port]          [Name]              [Type]                [Description]
Motor Port 2        frontRight          VEX Motor 393         Front Right motor
Motor Port 3        backRight           VEX Motor 393         Back Right motor
Motor Port 4        frontLeft           VEX Motor 393         Front Left motor
Motor Port 5        backLeft            VEX Motor 393         Back Left motor
----------------------------------------------------------------------------------------------------*/

//Global variables

int frontLeftMotorSpeed = 0;
int frontRightMotorSpeed = 0;
int backRightMotorSpeed = 0;
int backLeftMotorSpeed = 0;

// Task for the driver controlled portion of the competition.
task main()
{
	while (true)
	{
		// TODO - Add code to turn motors back and forth one at a time,
		//        based on number of encoder ticks.
	}
}