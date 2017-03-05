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
	pinMode(newClaw->solenoidPort, OUTPUT);

	return newClaw;
}

void clawOpen(Claw * claw)
{
	digitalWrite(claw->solenoidPort, CLAW_OPEN);
}

void clawClose(Claw * claw)
{
	digitalWrite(claw->solenoidPort, CLAW_CLOSE);
}
