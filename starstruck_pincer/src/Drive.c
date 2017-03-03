#include "main.h"

/**
 * Initializes a new drive object composed of six PantherMotors, two encoders and a gyro.
 */
Drive* initDrive(SmartMotor* frontLeftMotor, SmartMotor* frontRightMotor,
		SmartMotor* middleLeftMotor, SmartMotor* middleRightMotor,
		SmartMotor* rearLeftMotor, SmartMotor* rearRightMotor,
		Encoder leftEncoder, Encoder rightEncoder, Gyro gyro)
{
	Drive* newDrive = malloc(sizeof(Drive));

	newDrive->frontLeftMotor = frontLeftMotor;
	newDrive->frontRightMotor = frontRightMotor;
	newDrive->middleLeftMotor = middleLeftMotor;
	newDrive->middleRightMotor = middleRightMotor;
	newDrive->rearLeftMotor = rearLeftMotor;
	newDrive->rearRightMotor = rearRightMotor;
	newDrive->leftEncoder = leftEncoder;
	newDrive->rightEncoder = rightEncoder;
	newDrive->gyro = gyro;

	return newDrive;
}

void tankDrive(Drive* drive, int left, int right)
{
	setSmartMotor(drive->frontLeftMotor, left);
	setSmartMotor(drive->frontRightMotor, right);
	setSmartMotor(drive->middleLeftMotor, left);
	setSmartMotor(drive->middleRightMotor, right);
	setSmartMotor(drive->rearLeftMotor, left);
	setSmartMotor(drive->rearRightMotor, right);
}

void arcadeDrive(Drive* drive, int magnitude, int rotation)
{
	int left = magnitude + rotation;
	int right = magnitude - rotation;
	left = limit(left, 127, -127);
	right = limit(right, 127, -127);

	tankDrive(drive, left, right);
}
