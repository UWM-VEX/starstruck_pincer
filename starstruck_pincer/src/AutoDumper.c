/*
 * AutoDumper.c
 *
 *  Created on: Nov 3, 2016
 *      Author: Erik
 */
#include "main.h"

AutoDumper * initAutoDumper(Dumper * dumper, int height)
{
	AutoDumper * newStep = malloc(sizeof(AutoDumper));

	newStep->isFinished = 0;
	newStep->height = height;
	newStep->dumper = dumper;

	return newStep;
}

void autoDumper(AutoDumper * step)
{
	if(autonomousInfo.step != autonomousInfo.lastStep)
	{
		step->dumper->height = step->height;
	}

	switch(step->height)
	{
	case(DUMPER_LOW):
		// If the dumper is no longer moving, the step is finished
		step->isFinished = dumperToHeight(step->dumper, step->dumper->lowHeight) == 1;
		break;
	case(DUMPER_TRAVEL):
		step->isFinished = dumperToHeight(step->dumper, step->dumper->travelHeight) == 1;
		break;
	case(DUMPER_HIGH):
		step->isFinished = dumperToHeight(step->dumper, step->dumper->highHeight) == 1;
		break;
	case(DUMPER_FRONT_SIDE_FENCE):
		step->isFinished = dumperToHeight(step->dumper, step->dumper->frontSideFenceHeight) == 1;
		break;
	case(DUMPER_MIDDLE_FENCE):
			step->isFinished = dumperToHeight(step->dumper, step->dumper->dumperFrontMiddle) == 1;
			break;
	case(DUMPER_STOP):
			runDumperAtSpeed(step->dumper, 0);
			step->isFinished = 1;
			break;
	default:
		runDumperAtSpeed(step->dumper, 0);
	}
}
