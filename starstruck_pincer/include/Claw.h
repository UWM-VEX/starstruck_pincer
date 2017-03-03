/*
 * Claw.h
 *
 *  Created on: Jan 5, 2017
 *      Author: Erik
 */

#ifndef INCLUDE_CLAW_H_
#define INCLUDE_CLAW_H_

#define CLAW_OPEN HIGH
#define CLAW_CLOSE LOW

struct Claw{

	int solenoidPort;

}typedef Claw;

Claw * initClaw(int solenoidPort);
void clawOpen(Claw * claw);
void clawClose(Claw * claw);

#endif /* INCLUDE_CLAW_H_ */
