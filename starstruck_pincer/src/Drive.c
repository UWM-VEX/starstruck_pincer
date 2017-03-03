#include "main.h"

/**
 * Initializes a new drive object composed of six PantherMotors, two encoders and a gyro.
 */
Drive initDrive(SmartMotor* frontLeftMotor, SmartMotor* frontRightMotor,
		SmartMotor* rearLeftMotor, SmartMotor* rearRightMotor,
		Encoder frontLeftEncoder, Encoder frontRightEncoder,
		Encoder rearLeftEncoder, Encoder rearRightEncoder, Gyro gyro)
{
	Drive newDrive = {frontLeftMotor, frontRightMotor,
			rearLeftMotor, rearRightMotor,
			frontLeftEncoder, frontRightEncoder,
			rearLeftEncoder, rearRightEncoder,
			gyro};

	return newDrive;
}

void holonomicDrive(Drive drive, int magnitude, int direction, int rotation)
{
	int frontLeft = magnitude + direction + rotation;
	int frontRight = magnitude - direction + rotation;
	int rearLeft = magnitude - direction - rotation;
	int rearRight = magnitude + direction - rotation;

	frontLeft = limit(frontLeft, 127, -127);
	frontRight = limit(frontRight, 127, -127);
	rearLeft = limit(rearLeft, 127, -127);
	rearRight = limit(rearRight, 127, -127);

	frontLeft = (int) (frontLeft * 0.87);
	rearRight = (int) (rearRight * 0.87);

	setSmartMotor(drive.frontLeftMotor, frontLeft);
	setSmartMotor(drive.rearLeftMotor, frontRight);
	setSmartMotor(drive.frontRightMotor, rearLeft);
	setSmartMotor(drive.rearRightMotor, rearRight);
}
