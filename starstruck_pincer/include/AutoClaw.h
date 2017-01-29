/*
 * AutoClaw.h
 *
 *  Created on: Jan 15, 2017
 *      Author: Erik
 */

#ifndef INCLUDE_AUTOCLAW_H_
#define INCLUDE_AUTOCLAW_H_

#include "main.h"

struct AutoClaw{

	int isFinished;
	Claw * claw;
	int type;

}typedef AutoClaw;

AutoClaw * initAutoClaw(Claw * claw, int type);
void autoClaw(AutoClaw * step);

#endif /* INCLUDE_AUTOCLAW_H_ */
