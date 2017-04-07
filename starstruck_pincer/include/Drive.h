/*
 * Drive.h
 *
 *  Created on: Feb 25, 2015
 *      Author: Erik
 */

#ifndef DRIVE_H_
#define DRIVE_H_

#include "main.h"

/**
 * Reference type for a two motor drive.
 */
struct Drive{

	PantherMotor frontLeftMotor;
	PantherMotor frontRightMotor;
	PantherMotor middleLeftMotor;
	PantherMotor middleRightMotor;
	PantherMotor rearLeftMotor;
	PantherMotor rearRightMotor;
	Encoder leftEncoder;
	Encoder rightEncoder;
	Gyro gyro;

}typedef Drive;

Drive* initDrive(PantherMotor frontLeftMotor, PantherMotor frontRightMotor,
		PantherMotor middleLeftMotor, PantherMotor middleRightMotor,
		PantherMotor rearLeftMotor, PantherMotor rearRightMotor,
		Encoder leftEncoder, Encoder rightEncoder, Gyro gyro);
void tankDrive(Drive* drive, int left, int right);
void arcadeDrive(Drive* drive, int magnitude, int rotation);

#endif /* DRIVE_H_ */
