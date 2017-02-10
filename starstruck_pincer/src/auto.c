/** @file auto.c
 * @brief File for autonomous code
 *
 * This file should contain the user autonomous() function and any functions

related to it.
 *
 * Copyright (c) 2011-2014, Purdue University ACM SIG BOTS.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Purdue University ACM SIG BOTS nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL PURDUE UNIVERSITY ACM SIG BOTS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Purdue Robotics OS contains FreeRTOS (http://www.freertos.org) whose source

code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"

/*
 * Runs the user autonomous code. This function will be started in its own task

with the default
 * priority and stack size whenever the robot is enabled via the Field Management

System or the
 * VEX Competition Switch in the autonomous mode. If the robot is disabled or

communications is
 * lost, the autonomous task will be stopped by the kernel. Re-enabling the robot

will restart
 * the task, not re-start it from where it left off.
 *
 * Code running in the autonomous task cannot access information from the VEX

Joystick. However,
 * the autonomous function can be invoked from another task if a VEX Competition

Switch is not
 * available, and it can access joystick information if called in this way.
 *
 * The autonomous task may exit, unlike operatorControl() which should never exit.

If it does
 * so, the robot will await a switch to another mode or disable/enable cycle.
 */

/**
 * This is where you declare all of the actions the robot will take.
 * The options are DriveForTime which is useful for driving into something
 * but shouldn't be used elsewhere, DriveToWayPoint, which will handle
 * driving forward and back, strafing, and turning (turning must be in
 * its own step) and AutoLiftToHeight which will bring the lift to a
 * specified height (Note: Once the step where this function is used has
 * completed, the lift will move down due to gravity. To avoid this,
 * create a new AutoLiftToHeight function to keep the lift at the desired
 * height. Also, the lift to height code isn't perfectly tuned yet,
 * if the autonomous stalls with the autoLiftToHeight function, help the
 * lift up.)
 *
 * Running the pickup or spinner does not require an object to be declared
 * or instantiated, an example is shown below.
 */

int isAuto = 1;

long int stepStartTime;

int globalTimeout;

/**
 * Runs at the start of autonomous. Steps should be initialized here.
 */

DriveToWPProperties * defaultProps;

// START OF DECLARATIONS

DriveToWP * command1;
AutoClaw * command2;
DriveToWP * command3;

AutoClaw * command4;
DriveToWP * command5;
DriveToWP * command6;
DriveToWP * command7;
AutoClaw * command8;
DriveToWP * command9;

DriveToWP * command10;
AutoClaw * command11;

DriveToWP * command12;
DriveToWP * command13;
AutoClaw * command14;
Timeout * command15;

AutoDumper * command16;
DriveToWP * command17;
DriveToWP * command18;
Timeout * command19;

AutoDumper * command20;
AutoClaw * command21;
AutoClaw * command22;
Timeout * command23;

DriveToWP * command24;
DriveToWP * command25;
AutoDumper * command26;

DriveToWP * command27;
DriveToWP * command28;
DriveToWP * command29;
AutoClaw * command30;
Timeout * command31;

DriveToWP * command32;
Timeout * command33;

DriveToWP * command34;
Timeout * command35;

DriveToWP * command36;
Timeout * command37;

AutoClaw * command38;
AutoClaw * command39;
Timeout * command40;

DriveToWP * command41;
Timeout * command42;

AutoClaw * command43;
Timeout * command44;

AutoDumper * command45;
DriveToWP * command46;
DriveToWP * command47;
Timeout * command48;

AutoDumper * command49;
AutoClaw * command50;
AutoClaw * command51;
Timeout * command52;


AutoClaw * command53;
AutoClaw * command54;
DriveToWP * command55;

// END OF DECLARATIONS

void autonomousInit()
{
	/**
	 * Here, the different steps are instantiated and details are
	 * given about them. By hovering over the function name, you can see a
	 * list of the arguments to pass in.
	 */

	defaultProps = initDriveToWPProperties(robotDrive,
			0.25, 18, 1000, 80, 40, // MAG
			0.5, 18, 1000, 70, 40, // DIR
			2, 40, 70, 30, 3, 0, 500); //ROT

	// START OF INSTANTIATIONS
if(autonomousSelection == DO_NOTHING)
{
}
if(autonomousSelection == MODE_1)
{
	command1 = initDriveToWP(defaultProps, 12, 0, 0);
	command2 = initAutoClaw(robotClaw, CLAW_FIRST_OPEN);
	command3 = initDriveToWP(defaultProps, 0, 0, 90);

	command4 = initAutoClaw(robotClaw, CLAW_STOP);
	command5 = initDriveToWP(defaultProps,36,0,0);
	command6 = initDriveToWP(defaultProps,0,0,-20);
	command7 = initDriveToWP(defaultProps,36,0,0);
	command8 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command9 = initDriveToWP(defaultProps,0,-20,0);
}
if(autonomousSelection == CUBE_FIRST)
{
	command10 = initDriveToWP(defaultProps,24,0,0);
	command11 = initAutoClaw(robotClaw, CLAW_FIRST_OPEN);

	command12 = initDriveToWP(defaultProps,0,0,90);
	command13 = initDriveToWP(defaultProps,20,0,0);
	command14 = initAutoClaw(robotClaw,CLAW_CLOSE);
	command15 = initTimeout(1000);

	command16 = initAutoDumper(robotDumper,DUMPER_TRAVEL);
	command17 = initDriveToWP(defaultProps,0,0,90);
	command18 = initDriveToWP(defaultProps,-24,0,0);
	command19 = initTimeout(10000);

	command20 = initAutoDumper(robotDumper,DUMPER_HIGH);
	command21 = initAutoClaw(robotClaw, CLAW_OPEN);
	command22 = initAutoClaw(robotClaw, CLAW_STOP);
	command23 = initTimeout(1000);

	command24 = initDriveToWP(defaultProps,18,0,0);
	command25 = initDriveToWP(defaultProps,0,0,90);
	command26 = initAutoDumper(robotDumper,DUMPER_LOW);

	command27 = initDriveToWP(defaultProps,-78,0,0);
	command28 = initDriveToWP(defaultProps,0,0,-90);
	command29 = initDriveToWP(defaultProps,12,0,0);
	command30 = initAutoClaw(robotClaw,CLAW_CLOSE);
	command31 = initTimeout(1000);

	command32 = initDriveToWP(defaultProps,0,0,90);
	command33 = initTimeout(10000);

	command34 = initDriveToWP(defaultProps,0,-16,0);
	command35 = initTimeout(10000);

	command36 = initDriveToWP(defaultProps,0,0,-20);
	command37 = initTimeout(10000);

	command38 = initAutoClaw(robotClaw, CLAW_OPEN);
	command39 = initAutoClaw(robotClaw, CLAW_STOP);
	command40 = initTimeout(1000);

	command41 = initDriveToWP(defaultProps,62,0,0);
	command42 = initTimeout(10000);

	command43 = initAutoClaw(robotClaw,CLAW_CLOSE);
	command44 = initTimeout(1000);

	command45 = initAutoDumper(robotDumper,DUMPER_TRAVEL);
	command46 = initDriveToWP(defaultProps,0,0,-90);
	command47 = initDriveToWP(defaultProps,-36,0,0);
	command48 = initTimeout(10000);

	command49 = initAutoDumper(robotDumper,DUMPER_HIGH);
	command50 = initAutoClaw(robotClaw, CLAW_OPEN);
	command51 = initAutoClaw(robotClaw, CLAW_STOP);
	command52 = initTimeout(1000);

}
if(autonomousSelection == TEST_AUTO)
{
	command53 = initAutoClaw(robotClaw, CLAW_FIRST_OPEN);
	command54 = initAutoClaw(robotClaw, CLAW_STOP);
	command55 = initDriveToWP(defaultProps, 24, 0, 0);
}
	// END OF INSTANTIATIONS

	autonomousInfo.lastStep = 0;
	autonomousInfo.step = 1;
	autonomousInfo.isFinished = 0;

	stepStartTime = millis();
}

/**
 * Runs continuously during autonomous, should exit relatively promptly.
 */
void autonomousPeriodic()
{
	if(autonomousInfo.step != autonomousInfo.lastStep)
	{
		stepStartTime = millis();
	}

	autonomousInfo.elapsedTime = millis() - stepStartTime;

	//lcdPrint(uart1, 1, "Step: %d", autonomousInfo.step);

	switch(autonomousSelection)
	{
	// START OF EXECUTIONS
		case(DO_NOTHING):
		switch(autonomousInfo.step)
		{


			default:
				isAuto = 0;
				break;
		}
		break;
		case(MODE_1):
		switch(autonomousInfo.step)
		{
			case(1):
				driveToWP(command1);

				autonomousInfo.isFinished = (*command1).isFinished;
				break;
			case(2):
				autoClaw(command2);
				driveToWP(command3);
				autonomousInfo.isFinished = (*command2).isFinished && (*command3).isFinished;
				break;
			case(3):
				autoClaw(command4);

				autonomousInfo.isFinished = (*command4).isFinished;
				break;
			case(4):
				driveToWP(command5);

				autonomousInfo.isFinished = (*command5).isFinished;
				break;
			case(5):
				driveToWP(command6);

				autonomousInfo.isFinished = (*command6).isFinished;
				break;
			case(6):
				driveToWP(command7);

				autonomousInfo.isFinished = (*command7).isFinished;
				break;
			case(7):
				autoClaw(command8);

				autonomousInfo.isFinished = (*command8).isFinished;
				break;
			case(8):
				driveToWP(command9);

				autonomousInfo.isFinished = (*command9).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(CUBE_FIRST):
		switch(autonomousInfo.step)
		{
			case(1):
				driveToWP(command10);
				autoClaw(command11);
				autonomousInfo.isFinished = (*command10).isFinished && (*command11).isFinished;
				break;
			case(2):
				driveToWP(command12);

				autonomousInfo.isFinished = (*command12).isFinished;
				break;
			case(3):
				driveToWP(command13);

				autonomousInfo.isFinished = (*command13).isFinished;
				break;
			case(4):
				autoClaw(command14);
				timeout(command15);
				autonomousInfo.isFinished = (*command14).isFinished && (*command15).isFinished;
				break;
			case(5):
				autoDumper(command16);

				autonomousInfo.isFinished = (*command16).isFinished;
				break;
			case(6):
				driveToWP(command17);

				autonomousInfo.isFinished = (*command17).isFinished;
				break;
			case(7):
				driveToWP(command18);
				timeout(command19);
				autonomousInfo.isFinished = (*command18).isFinished || (*command19).isFinished;
				break;
			case(8):
				autoDumper(command20);

				autonomousInfo.isFinished = (*command20).isFinished;
				break;
			case(9):
				autoClaw(command21);

				autonomousInfo.isFinished = (*command21).isFinished;
				break;
			case(10):
				autoClaw(command22);
				timeout(command23);
				autonomousInfo.isFinished = (*command22).isFinished && (*command23).isFinished;
				break;
			case(11):
				driveToWP(command24);

				autonomousInfo.isFinished = (*command24).isFinished;
				break;
			case(12):
				driveToWP(command25);
				autoDumper(command26);
				autonomousInfo.isFinished = (*command25).isFinished && (*command26).isFinished;
				break;
			case(13):
				driveToWP(command27);

				autonomousInfo.isFinished = (*command27).isFinished;
				break;
			case(14):
				driveToWP(command28);

				autonomousInfo.isFinished = (*command28).isFinished;
				break;
			case(15):
				driveToWP(command29);

				autonomousInfo.isFinished = (*command29).isFinished;
				break;
			case(16):
				autoClaw(command30);
				timeout(command31);
				autonomousInfo.isFinished = (*command30).isFinished && (*command31).isFinished;
				break;
			case(17):
				driveToWP(command32);
				timeout(command33);
				autonomousInfo.isFinished = (*command32).isFinished || (*command33).isFinished;
				break;
			case(18):
				driveToWP(command34);
				timeout(command35);
				autonomousInfo.isFinished = (*command34).isFinished || (*command35).isFinished;
				break;
			case(19):
				driveToWP(command36);
				timeout(command37);
				autonomousInfo.isFinished = (*command36).isFinished || (*command37).isFinished;
				break;
			case(20):
				autoClaw(command38);

				autonomousInfo.isFinished = (*command38).isFinished;
				break;
			case(21):
				autoClaw(command39);
				timeout(command40);
				autonomousInfo.isFinished = (*command39).isFinished && (*command40).isFinished;
				break;
			case(22):
				driveToWP(command41);
				timeout(command42);
				autonomousInfo.isFinished = (*command41).isFinished || (*command42).isFinished;
				break;
			case(23):
				autoClaw(command43);
				timeout(command44);
				autonomousInfo.isFinished = (*command43).isFinished && (*command44).isFinished;
				break;
			case(24):
				autoDumper(command45);

				autonomousInfo.isFinished = (*command45).isFinished;
				break;
			case(25):
				driveToWP(command46);

				autonomousInfo.isFinished = (*command46).isFinished;
				break;
			case(26):
				driveToWP(command47);
				timeout(command48);
				autonomousInfo.isFinished = (*command47).isFinished || (*command48).isFinished;
				break;
			case(27):
				autoDumper(command49);

				autonomousInfo.isFinished = (*command49).isFinished;
				break;
			case(28):
				autoClaw(command50);

				autonomousInfo.isFinished = (*command50).isFinished;
				break;
			case(29):
				autoClaw(command51);
				timeout(command52);
				autonomousInfo.isFinished = (*command51).isFinished && (*command52).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(TEST_AUTO):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command53);

				autonomousInfo.isFinished = (*command53).isFinished;
				break;
			case(2):
				autoClaw(command54);

				autonomousInfo.isFinished = (*command54).isFinished;
				break;
			case(3):
				driveToWP(command55);

				autonomousInfo.isFinished = (*command55).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
	// END OF EXECUTIONS

		default:
			isAuto = 0;
			break;
	}

	autonomousInfo.lastStep = autonomousInfo.step;

	//lcdPrint(uart1, 1, "Step: %d", autonomousInfo.step);

	if(autonomousInfo.isFinished)
	{
		autonomousInfo.step ++;
		autonomousInfo.isFinished = 0;
	}

}

void autonomous()
{
	lcdSetText(uart1, 1, "started");

	autonomousInit();

	//lcdSetText(uart1, 1, "initialized");

	while(isAuto)
	{
		autonomousPeriodic();

		if(isOnline())
		{
			if(!isAutonomous() || !isEnabled()) isAuto = 0;
		}

		delay(20);

		//puts("Autonomous");
	}
}

