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
#define CLAW_FIRST_OPEN 3
#define CLAW_FULL_OPEN 4

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
int clawOpen(Claw * claw);
int clawFirstOpen(Claw * claw);
int clawClose(Claw * claw);
int clawFullOpen(Claw * claw);
void clawTeleop(Claw * claw);

#endif /* INCLUDE_CLAW_H_ */
