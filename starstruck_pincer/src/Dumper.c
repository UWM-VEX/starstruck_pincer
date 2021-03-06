/*
 * Shovel.c
 *
 *  Created on: Aug 16, 2016
 *      Author: Erik
 */

#include "main.h"

Dumper * initDumper(PantherMotor topLeft,
		PantherMotor bottomLeft, PantherMotor topRight, PantherMotor bottomRight,
		Pot * pot, double kP, double kI, double kD, double lowHeight,
		double travelHeight, double highHeight, double frontFenceHeight, double sideFenceHeight, double frontMiddleFenceHeight, double travelTeleHeight)
{
	Dumper * newDumper = malloc(sizeof(Dumper));
	newDumper->topLeft = topLeft;
	newDumper->bottomLeft = bottomLeft;
	newDumper->topRight = topRight;
	newDumper->bottomRight = bottomRight;
	newDumper->pot = pot;
	newDumper->pidController = initPIDController(kP, kI, kD, 0, 0, 0.05);
	newDumper->mode = DUMPER_MANUAL;
	newDumper->height = DUMPER_LOW;
	newDumper->lowHeight = lowHeight;
	newDumper->travelHeight = travelHeight;
	newDumper->highHeight = highHeight;
	newDumper->frontSideFenceHeight = frontFenceHeight;
	newDumper->dumperFrontMiddle = frontMiddleFenceHeight;
	newDumper->dumperFrontSide = sideFenceHeight;
	newDumper->travelTeleHeight = travelTeleHeight;

	return newDumper;
}

void runDumperAtSpeed(Dumper * dumper, int speed)
{
	if( ! OIGetDumperOverride())
	{
		int max = (potGetScaledValue(dumper->pot) > 1.0) ? 0 : 127;
		int min = (potGetScaledValue(dumper->pot) < 0.0) ? 0 : -127;

		speed = limit(speed, max, min);
	}

	setPantherMotor(dumper->topLeft, speed);
	setPantherMotor(dumper->bottomLeft, speed);
	setPantherMotor(dumper->topRight, speed);
	setPantherMotor(dumper->bottomRight, speed);
}

int dumperToHeight(Dumper *dumper, double height)
{
	double pv = potGetScaledValue(dumper->pot);
	PIDsetSetPoint(dumper->pidController, height);
	int speed = PIDRunController(dumper->pidController, pv);
	speed = limit(speed, 127, -127);
	speed = enforceDeadband(speed, 0, 20);
	runDumperAtSpeed(dumper, speed);
	return (absDouble(pv - height) < 0.1);
}

void updateDumperPID(Dumper * dumper)
{
	double pv = potGetScaledValue(dumper->pot);
	PIDRunController(dumper->pidController, pv);

	lcdPrint(uart1, 2, "Lift: %f", potGetScaledValue(dumper->pot));
	//lcdPrint(uart1, 2, "Raw: %d", potGetRawValue(dumper->pot));
}

double getDumperHeight(Dumper * dumper)
{
	switch(dumper->height)
	{
	case(DUMPER_LOW):
		return dumper->lowHeight;
	case(DUMPER_TRAVEL):
		return dumper->travelHeight;
	case(DUMPER_HIGH):
		return dumper->highHeight;
	case(DUMPER_FRONT_SIDE_FENCE):
		return dumper->frontSideFenceHeight;
	case(DUMPER_SIDE_FENCE):
		return dumper->dumperFrontSide;
	case(DUMPER_MIDDLE_FENCE):
		return dumper->dumperFrontMiddle;
	case(DUMPER_TRAVEL_TELE):
		return dumper->travelTeleHeight;
	default:
		return dumper->travelHeight;
	}
}

void dumperTeleop(Dumper * dumper)
{
	if(abs(OIGetDumper()) > 20)
	{
		dumper->mode = DUMPER_MANUAL;
		//lcdSetText(uart1, 2, "Manual");
	}
	else
	{
		//lcdSetText(uart1, 2, "Auto");
		if(OIGetDumperLow())
		{
			dumper->mode = DUMPER_AUTO;
			dumper->height = DUMPER_LOW;
		}
		else if(OIGetDumperTravel())
		{
			dumper->mode = DUMPER_AUTO;
			dumper->height = DUMPER_TRAVEL_TELE;
		}
		else if(OIGetDumperHigh())
		{
			dumper->mode = DUMPER_AUTO;
			dumper->height = DUMPER_HIGH;
		}
		else if(OIGetDumperFrontFence())
		{
			dumper->mode = DUMPER_AUTO;
			dumper->height = DUMPER_FRONT_SIDE_FENCE;
		}
		else if(OIGetFenceMiddle())
		{
			dumper->mode = DUMPER_AUTO;
			dumper->height = DUMPER_MIDDLE_FENCE;
		}
		else if(OIGetFenceSide())
		{
			dumper->mode = DUMPER_AUTO;
			dumper->height = DUMPER_SIDE_FENCE;
		}
	}

	if(dumper->mode == DUMPER_MANUAL)
	{
		runDumperAtSpeed(dumper, OIGetDumper());
	}
	else
	{
		double height = getDumperHeight(dumper);
		dumperToHeight(dumper, height);
	}

	updateDumperPID(dumper);
}
