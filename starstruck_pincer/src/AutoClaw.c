/*
 * AutoClaw.c
 *
 *  Created on: Jan 15, 2017
 *      Author: Erik
 */

#include "main.h"

AutoClaw * initAutoClaw(Claw * claw, int type)
{
	AutoClaw * newStep = malloc(sizeof(AutoClaw));

	newStep->claw = claw;
	newStep->type = type;
	newStep->isFinished = 0;

	return newStep;
}

void autoClaw(AutoClaw * step)
{
	if(step->type == CLAW_OPEN)
	{
		step->isFinished = clawOpen(step->claw);
	}
	else if(step->type == CLAW_CLOSE)
	{
		step->isFinished = clawClose(step->claw);
	}
	else if(step->type == CLAW_FIRST_OPEN)
	{
		step->isFinished = clawFirstOpen(step->claw);
	}
	else if(step->type == CLAW_FULL_OPEN)
	{
		step->isFinished = clawFullOpen(step->claw);
	}
	else
	{
		runClawAtSpeed(step->claw, 0);
		step->isFinished = 1;
	}
}
