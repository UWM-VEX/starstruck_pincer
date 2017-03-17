/*
 * OI.c
 *
 *  Created on: Oct 29, 2015
 *      Author: Erik
 */

#include "main.h"

int OIGetDriveLeft()
{
	return enforceDeadband(joystickGetAnalog(1, 3), 0, 20);
}

int OIGetDriveRight()
{
	return enforceDeadband(joystickGetAnalog(1, 2), 0, 20);
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

int OIGetDumperFrontFence()
{
	return joystickGetDigital(2, 8, JOY_UP) ||
			joystickGetDigital(1, 8, JOY_UP);
}

int OIGetClawManual()
{
	return -joystickGetAnalog(2,4);
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

int OIGetClawChange()
{
	return joystickGetDigital(1,6,JOY_UP) ||
				joystickGetDigital(2,6,JOY_UP);
}

int OIGetDumperOverride()
{
	return (joystickGetDigital(1, 5, JOY_DOWN && joystickGetDigital(1, 6, JOY_DOWN)) ||
			(joystickGetDigital(2, 5, JOY_DOWN) && joystickGetDigital(2, 6, JOY_DOWN)));
}

int OIGetFenceMiddle()
{
	return joystickGetDigital(2, 8, JOY_DOWN);
}

int OIGetFenceSide()
{
	return joystickGetDigital(2, 8, JOY_LEFT) ||
			joystickGetDigital(2, 8, JOY_RIGHT);
}
