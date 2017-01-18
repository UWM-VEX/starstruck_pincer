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
	clawToPosition(step->claw, step->type);
}
