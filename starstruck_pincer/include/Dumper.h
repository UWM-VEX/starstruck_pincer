/*
 * Shovel.h
 *
 *  Created on: Aug 16, 2016
 *      Author: Erik
 */

#ifndef INCLUDE_DUMPER_H_
#define INCLUDE_DUMPER_H_

#define DUMPER_MANUAL 0
#define DUMPER_AUTO 1

#define DUMPER_LOW 0
#define DUMPER_TRAVEL 1
#define DUMPER_HIGH 2
#define DUMPER_HANG 3
#define DUMPER_AUTO_HEIGHT 4

struct Dumper {
	PantherMotor topLeft;
	PantherMotor bottomLeft;
	PantherMotor topRight;
	PantherMotor bottomRight;
	Pot * pot;
	PIDController * pidController;
	int mode;
	int height;
	int dumpState;
	double lowHeight;
	double travelHeight;
	double highHeight;
	double hangHeight;
	double autoHeight;
}typedef Dumper;

Dumper * initDumper(PantherMotor topLeft, PantherMotor bottomLeft, PantherMotor topRight,
		PantherMotor bottomRight, Pot * pot, double kP, double kI, double kD,
		double lowHeight, double travelHeight, double highHeight, double hangHeight,
		double autoHeight);
void runDumperAtSpeed(Dumper * shovel, int speed);
int dumperToHeight(Dumper *dumper, double height);
void updateDumperPID(Dumper * dumper);
double getDumperHeight(Dumper * dumper);
void dumperTeleop(Dumper * dumper);

#endif /* INCLUDE_DUMPER_H_ */
