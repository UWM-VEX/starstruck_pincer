/*
 * OI.c
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#include "main.h"

int OIGetDriveLeft()
{
	return joystickGetAnalog(1, 3);
}

int OIGetDriveRight()
{
	return joystickGetAnalog(1, 2);
}

int OIGetDriveY()
{
	return joystickGetAnalog(1, 3);
}

int OIGetDriveX()
{
	return joystickGetAnalog(1, 4);
}

int OIGetDriveMagnitude()
{
	return joystickGetAnalog(1, 3);
}

int OIGetDriveDirection()
{
	return joystickGetAnalog(1, 4);
}

int OIGetDriveRotation()
{
	return joystickGetAnalog(1, 1);
}

int OIGetDumper()
{
	return joystickGetAnalog(2, 2);
}

int OIGetDumperLow()
{
	return joystickGetDigital(2, 7, JOY_DOWN) ||
			joystickGetDigital(1, 7, JOY_DOWN);
}

int OIGetDumperTravel()
{
	return joystickGetDigital(2, 7, JOY_LEFT) ||
			joystickGetDigital(1, 7, JOY_LEFT);
}

int OIGetDumperHigh()
{
	return joystickGetDigital(2, 7, JOY_UP) ||
			joystickGetDigital(1, 7, JOY_UP);
}

int OIGetDumperHang()
{
	return joystickGetDigital(2, 8, JOY_RIGHT) ||
			joystickGetDigital(1, 8, JOY_RIGHT);
}

int OIGetClawManual()
{
	return joystickGetAnalog(2,1);
}

int OIGetClawOpen()
{
	return joystickGetDigital(1,5,JOY_UP) ||
			joystickGetDigital(2,5,JOY_UP);
}

int OIGetClawClose()
{
	return joystickGetDigital(1,6,JOY_UP) ||
			joystickGetDigital(2,6,JOY_UP);
}
