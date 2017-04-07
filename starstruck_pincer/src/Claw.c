/*
 * Claw.c
 *
 *  Created on: Jan 5, 2017
 *      Author: Erik
 */

#include "main.h"

Claw * initClaw(int solenoidPort)
{
	Claw * newClaw = malloc(sizeof(Claw));

	newClaw->solenoidPort = solenoidPort;
	newClaw->clawState = CLAW_CLOSE;
	pinMode(newClaw->solenoidPort, OUTPUT);
	//digitalWrite(newClaw->solenoidPort, CLAW_CLOSE);

	return newClaw;
}

void clawOpen(Claw * claw)
{
	digitalWrite(claw->solenoidPort, CLAW_OPEN);
	claw->clawState = CLAW_OPEN;
}

void clawClose(Claw * claw)
{
	digitalWrite(claw->solenoidPort, CLAW_CLOSE);
	claw->clawState = CLAW_CLOSE;
}
