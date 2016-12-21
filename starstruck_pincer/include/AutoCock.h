/*
 * AutoCock.h
 *
 *  Created on: Nov 3, 2016
 *      Author: Erik
 */

#ifndef INCLUDE_AUTOCOCK_H_
#define INCLUDE_AUTOCOCK_H_

struct AutoCock {

	Catapult * catapult;
	int isFinished;
	int move;

}typedef AutoCock;

AutoCock * initAutoCock(Catapult * catapult, int move);
void autoCock(AutoCock * step);

#endif /* INCLUDE_AUTOCOCK_H_ */
