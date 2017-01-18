/*
 * Claw.h
 *
 *  Created on: Jan 5, 2017
 *      Author: Erik
 */

#ifndef INCLUDE_CLAW_H_
#define INCLUDE_CLAW_H_

#define CLAW_AUTO 0
#define CLAW_MANUAL 1
#define CLAW_OPEN 0
#define CLAW_CLOSE 1
#define CLAW_STOP 2

struct Claw{

	PantherMotor motor1;
	PantherMotor motor2;
	Pot * pot;
	double open;
	double close;
	int mode;
	int autoState;
	int lastPot;

}typedef Claw;

Claw * initClaw(PantherMotor motor1, PantherMotor motor2, Pot * pot, double open, double close);
void runClawAtSpeed(Claw * claw, int speed);
double clawToPosition(Claw * claw, double sp, int correctPosError, int correctNegError);
int clawGetMode(Claw * claw);
double clawOpen(Claw * claw);
double clawClose(Claw * claw);
void clawTeleop(Claw * claw);

#endif /* INCLUDE_CLAW_H_ */
