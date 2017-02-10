/*
 * Claw.c
 *
 *  Created on: Jan 5, 2017
 *      Author: Erik
 */

#include "main.h"

Claw * initClaw(PantherMotor motor1, PantherMotor motor2, Pot * pot, double open, double close)
{
	Claw * newClaw = malloc(sizeof(Claw));

	newClaw->motor1 = motor1;
	newClaw->motor2 = motor2;
	newClaw->pot = pot;
	newClaw->open = open;
	newClaw->close = close;
	newClaw->mode = CLAW_MANUAL;
	newClaw->autoState = CLAW_OPEN;
	newClaw->lastPot = potGetRawValue(newClaw->pot);

	return newClaw;
}

void runClawAtSpeed(Claw * claw, int speed)
{
	claw->lastPot = potGetRawValue(claw->pot);

	if(potGetScaledValue(claw->pot) < 0)
	{
		speed = limit(speed, 127, 0);
	}
	else if(potGetScaledValue(claw->pot) > 0.9)
	{
		speed = limit(speed, 0, -127);
	}

	setPantherMotor(claw->motor1, speed);
	setPantherMotor(claw->motor2, -speed);
}

double clawToPosition(Claw * claw, double sp, int correctPosError, int correctNegError)
{
	double pv = potGetScaledValue(claw->pot);
	int movement = potGetRawValue(claw->pot) - claw->lastPot;
	double error = sp - pv;

	if(absDouble(error) < 0.04)
	{
		runClawAtSpeed(claw, 0);
		return 1;
	}
	else if(error > 0 && correctPosError)
	{
		if(abs(movement) > 15)
		{
			runClawAtSpeed(claw, 127);
			return 0;
		}
		else
		{
			runClawAtSpeed(claw, 50);
			return 2;
		}
	}
	else if(error < 0 && correctNegError)
	{
		if(abs(movement) > 15)
		{
			runClawAtSpeed(claw, -127);
			return 0;
		}
		else
		{
			runClawAtSpeed(claw, -50);
			return 2;
		}
	}
	else
	{
		runClawAtSpeed(claw,0);
		return 1;
	}
}

int clawGetMode(Claw * claw)
{
	return claw->mode;
}

int clawOpen(Claw * claw)
{
	int result = clawToPosition(claw, claw->open, 1, 0);
	return result == 1;
}

int clawFirstOpen(Claw * claw)
{
	int result = clawToPosition(claw, claw->open, 1, 1);
	return result == 1;
}

int clawClose(Claw * claw)
{
	int result = clawToPosition(claw, claw->close, 0, 1);
	return result == 1 || result == 2;
}

int clawFullOpen(Claw * claw)
{
	int result = clawToPosition(claw, 0.5, 1, 1);
	return result == 1;
}

void clawTeleop(Claw * claw)
{
	//lcdPrint(uart1, 1, "Movement: %d", potGetRawValue(claw->pot) - claw->lastPot);
	//lcdPrint(uart1, 2, "Scaled: %f", potGetScaledValue(claw->pot));
	//lcdPrint(uart1, 1, "Raw: %d", potGetRawValue(claw->pot));
	if(abs(OIGetClawManual()) > 50)
	{
		claw->mode = CLAW_MANUAL;
		//lcdSetText(uart1, 2, "Manual");
	}
	else
	{
		//lcdSetText(uart1, 2, "Auto");
		if(OIGetClawOpen())
		{
			claw->mode = CLAW_AUTO;
			claw->autoState = CLAW_OPEN;
		}
		else if(OIGetClawClose())
		{
			claw->mode = CLAW_AUTO;
			claw->autoState = CLAW_CLOSE;
		}
	}

	if(claw->mode == CLAW_MANUAL)
	{
		runClawAtSpeed(claw, OIGetClawManual());
	}
	else
	{
		if(claw->autoState == CLAW_OPEN)
		{
			clawOpen(claw);
		}
		else
		{
			clawClose(claw);
		}
	}
}
