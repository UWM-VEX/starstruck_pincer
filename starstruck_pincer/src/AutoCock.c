/*
 * AutoCock.c
 *
 *  Created on: Nov 3, 2016
 *      Author: Erik
 */

#include "main.h"

AutoCock * initAutoCock(Catapult * catapult, int move)
{
	AutoCock * newStep = malloc(sizeof(AutoCock));

	newStep->catapult = catapult;
	newStep->move = move;
	newStep->isFinished = 0;

	return newStep;
}

void autoCock(AutoCock * step)
{
	if(step->move)
	{
		step->isFinished = runCatapult(step->catapult, 0);
	}
	else
	{
		runCatapultAtSpeed(step->catapult, 0);
		step->isFinished = 1;
	}
}
