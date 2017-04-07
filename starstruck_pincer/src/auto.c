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

AutoClaw * command1;
DriveToWP * command2;
DriveToWP * command3;
Timeout * command4;

DriveToWP * command5;
AutoClaw * command6;
AutoDumper * command7;

AutoDumper * command8;
DriveToWP * command9;

AutoDumper * command10;
DriveToWP * command11;
Timeout * command12;

AutoDumper * command13;
AutoDumper * command14;
AutoClaw * command15;

AutoDumper * command16;
AutoClaw * command17;
DriveToWP * command18;
DriveToWP * command19;
DriveToWP * command20;
Timeout * command21;

AutoClaw * command22;
DriveToWP * command23;
AutoClaw * command24;
DriveToWP * command25;
AutoClaw * command26;
AutoDumper * command27;
AutoDumper * command28;
DriveToWP * command29;

AutoDumper * command30;
DriveToWP * command31;
Timeout * command32;

AutoDumper * command33;
AutoDumper * command34;
AutoClaw * command35;

AutoDumper * command36;

AutoClaw * command37;
DriveToWP * command38;
DriveToWP * command39;
AutoClaw * command40;
AutoDumper * command41;
DriveToWP * command42;
AutoDumper * command43;

DriveToWP * command44;
AutoDumper * command45;
Timeout * command46;

AutoDumper * command47;
AutoDumper * command48;
AutoClaw * command49;

AutoDumper * command50;
DriveToWP * command51;
DriveToWP * command52;
DriveToWP * command53;
AutoClaw * command54;
AutoDumper * command55;
DriveToWP * command56;
AutoDumper * command57;

DriveToWP * command58;
AutoDumper * command59;
Timeout * command60;

AutoDumper * command61;
AutoDumper * command62;
AutoClaw * command63;

AutoDumper * command64;

DriveToWP * command65;
DriveToWP * command66;
AutoDumper * command67;
AutoClaw * command68;
AutoDumper * command69;
Timeout * command70;


// END OF DECLARATIONS

void autonomousInit()
{
	/**
	 * Here, the different steps are instantiated and details are
	 * given about them. By hovering over the function name, you can see a
	 * list of the arguments to pass in.
	 */

	defaultProps = initDriveToWPProperties(robotDrive,
			0.5, 18, 1000, 127, 45, // MAG
			2, 40, 70, 40, 3.25, 1, 500); //ROT

	// START OF INSTANTIATIONS
if(autonomousSelection == DO_NOTHING)
{
}
if(autonomousSelection == CUBE_FIRST)
{
	command1 = initAutoClaw(robotClaw, CLAW_OPEN);
	command2 = initDriveToWP(defaultProps, -18, 0);
	command3 = initDriveToWP(defaultProps, 0, -20);
	command4 = initTimeout(2000);

	command5 = initDriveToWP(defaultProps, 99, 0);
	command6 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command7 = initAutoDumper(robotDumper, DUMPER_TRAVEL);

	command8 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command9 = initDriveToWP(defaultProps, 0, 110);

	command10 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command11 = initDriveToWP(defaultProps, -18, 0);
	command12 = initTimeout(3000);

	command13 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command14 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command15 = initAutoClaw(robotClaw, CLAW_OPEN);

	command16 = initAutoDumper(robotDumper, DUMPER_LOW);
	command17 = initAutoClaw(robotClaw, CLAW_OPEN);
	command18 = initDriveToWP(defaultProps, 6, 0);
	command19 = initDriveToWP(defaultProps, 0, -20);
	command20 = initDriveToWP(defaultProps, 34, 0);
	command21 = initTimeout(3000);

	command22 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command23 = initDriveToWP(defaultProps,0,110);
	command24 = initAutoClaw(robotClaw, CLAW_OPEN);
	command25 = initDriveToWP(defaultProps, 91, 0);
	command26 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command27 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command28 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command29 = initDriveToWP(defaultProps, 0, -90);

	command30 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command31 = initDriveToWP(defaultProps, -48, 0);
	command32 = initTimeout(3000);

	command33 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command34 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command35 = initAutoClaw(robotClaw, CLAW_OPEN);

	command36 = initAutoDumper(robotDumper, DUMPER_LOW);
}
if(autonomousSelection == MODE_1)
{
	command37 = initAutoClaw(robotClaw, CLAW_OPEN);
	command38 = initDriveToWP(defaultProps, -18, 0);
	command39 = initDriveToWP(defaultProps, 96, 0);
	command40 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command41 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command42 = initDriveToWP(defaultProps, 0, 90);
	command43 = initAutoDumper(robotDumper, DUMPER_TRAVEL);

	command44 = initDriveToWP(defaultProps, -44, 0);
	command45 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command46 = initTimeout(5000);

	command47 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command48 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command49 = initAutoClaw(robotClaw, CLAW_OPEN);

	command50 = initAutoDumper(robotDumper, DUMPER_LOW);
	command51 = initDriveToWP(defaultProps, 20, 0);
	command52 = initDriveToWP(defaultProps, 0, 90);
	command53 = initDriveToWP(defaultProps, 33, 0);
	command54 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command55 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command56 = initDriveToWP(defaultProps, 0, -90);
	command57 = initAutoDumper(robotDumper, DUMPER_TRAVEL);

	command58 = initDriveToWP(defaultProps, -24, 0);
	command59 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command60 = initTimeout(5000);

	command61 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command62 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command63 = initAutoClaw(robotClaw, CLAW_OPEN);

	command64 = initAutoDumper(robotDumper, DUMPER_LOW);
}
if(autonomousSelection == TEST)
{
	command65 = initDriveToWP(defaultProps, 24, 0);
	command66 = initDriveToWP(defaultProps, 0, -90);
	command67 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command68 = initAutoClaw(robotClaw, CLAW_OPEN);
	command69 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command70 = initTimeout(1000);

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
		case(CUBE_FIRST):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command1);

				autonomousInfo.isFinished = (*command1).isFinished;
				break;
			case(2):
				driveToWP(command2);

				autonomousInfo.isFinished = (*command2).isFinished;
				break;
			case(3):
				driveToWP(command3);
				timeout(command4);
				autonomousInfo.isFinished = (*command3).isFinished || (*command4).isFinished;
				break;
			case(4):
				driveToWP(command5);

				autonomousInfo.isFinished = (*command5).isFinished;
				break;
			case(5):
				autoClaw(command6);
				autoDumper(command7);
				autonomousInfo.isFinished = (*command6).isFinished && (*command7).isFinished;
				break;
			case(6):
				autoDumper(command8);
				driveToWP(command9);
				autonomousInfo.isFinished = (*command8).isFinished && (*command9).isFinished;
				break;
			case(7):
				autoDumper(command10);
				driveToWP(command11);
				timeout(command12);
				autonomousInfo.isFinished = (*command10).isFinished && (*command11).isFinished || (*command12).isFinished;
				break;
			case(8):
				autoDumper(command13);

				autonomousInfo.isFinished = (*command13).isFinished;
				break;
			case(9):
				autoDumper(command14);
				autoClaw(command15);
				autonomousInfo.isFinished = (*command14).isFinished && (*command15).isFinished;
				break;
			case(10):
				autoDumper(command16);

				autonomousInfo.isFinished = (*command16).isFinished;
				break;
			case(11):
				autoClaw(command17);

				autonomousInfo.isFinished = (*command17).isFinished;
				break;
			case(12):
				driveToWP(command18);

				autonomousInfo.isFinished = (*command18).isFinished;
				break;
			case(13):
				driveToWP(command19);

				autonomousInfo.isFinished = (*command19).isFinished;
				break;
			case(14):
				driveToWP(command20);
				timeout(command21);
				autonomousInfo.isFinished = (*command20).isFinished || (*command21).isFinished;
				break;
			case(15):
				autoClaw(command22);

				autonomousInfo.isFinished = (*command22).isFinished;
				break;
			case(16):
				driveToWP(command23);

				autonomousInfo.isFinished = (*command23).isFinished;
				break;
			case(17):
				autoClaw(command24);

				autonomousInfo.isFinished = (*command24).isFinished;
				break;
			case(18):
				driveToWP(command25);

				autonomousInfo.isFinished = (*command25).isFinished;
				break;
			case(19):
				autoClaw(command26);

				autonomousInfo.isFinished = (*command26).isFinished;
				break;
			case(20):
				autoDumper(command27);

				autonomousInfo.isFinished = (*command27).isFinished;
				break;
			case(21):
				autoDumper(command28);
				driveToWP(command29);
				autonomousInfo.isFinished = (*command28).isFinished && (*command29).isFinished;
				break;
			case(22):
				autoDumper(command30);
				driveToWP(command31);
				timeout(command32);
				autonomousInfo.isFinished = (*command30).isFinished && (*command31).isFinished || (*command32).isFinished;
				break;
			case(23):
				autoDumper(command33);

				autonomousInfo.isFinished = (*command33).isFinished;
				break;
			case(24):
				autoDumper(command34);
				autoClaw(command35);
				autonomousInfo.isFinished = (*command34).isFinished && (*command35).isFinished;
				break;
			case(25):
				autoDumper(command36);

				autonomousInfo.isFinished = (*command36).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(MODE_1):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command37);

				autonomousInfo.isFinished = (*command37).isFinished;
				break;
			case(2):
				driveToWP(command38);

				autonomousInfo.isFinished = (*command38).isFinished;
				break;
			case(3):
				driveToWP(command39);

				autonomousInfo.isFinished = (*command39).isFinished;
				break;
			case(4):
				autoClaw(command40);

				autonomousInfo.isFinished = (*command40).isFinished;
				break;
			case(5):
				autoDumper(command41);

				autonomousInfo.isFinished = (*command41).isFinished;
				break;
			case(6):
				driveToWP(command42);
				autoDumper(command43);
				autonomousInfo.isFinished = (*command42).isFinished && (*command43).isFinished;
				break;
			case(7):
				driveToWP(command44);
				autoDumper(command45);
				timeout(command46);
				autonomousInfo.isFinished = (*command44).isFinished && (*command45).isFinished || (*command46).isFinished;
				break;
			case(8):
				autoDumper(command47);

				autonomousInfo.isFinished = (*command47).isFinished;
				break;
			case(9):
				autoDumper(command48);
				autoClaw(command49);
				autonomousInfo.isFinished = (*command48).isFinished && (*command49).isFinished;
				break;
			case(10):
				autoDumper(command50);

				autonomousInfo.isFinished = (*command50).isFinished;
				break;
			case(11):
				driveToWP(command51);

				autonomousInfo.isFinished = (*command51).isFinished;
				break;
			case(12):
				driveToWP(command52);

				autonomousInfo.isFinished = (*command52).isFinished;
				break;
			case(13):
				driveToWP(command53);

				autonomousInfo.isFinished = (*command53).isFinished;
				break;
			case(14):
				autoClaw(command54);

				autonomousInfo.isFinished = (*command54).isFinished;
				break;
			case(15):
				autoDumper(command55);

				autonomousInfo.isFinished = (*command55).isFinished;
				break;
			case(16):
				driveToWP(command56);
				autoDumper(command57);
				autonomousInfo.isFinished = (*command56).isFinished && (*command57).isFinished;
				break;
			case(17):
				driveToWP(command58);
				autoDumper(command59);
				timeout(command60);
				autonomousInfo.isFinished = (*command58).isFinished && (*command59).isFinished || (*command60).isFinished;
				break;
			case(18):
				autoDumper(command61);

				autonomousInfo.isFinished = (*command61).isFinished;
				break;
			case(19):
				autoDumper(command62);
				autoClaw(command63);
				autonomousInfo.isFinished = (*command62).isFinished && (*command63).isFinished;
				break;
			case(20):
				autoDumper(command64);

				autonomousInfo.isFinished = (*command64).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(TEST):
		switch(autonomousInfo.step)
		{
			case(1):
				driveToWP(command65);

				autonomousInfo.isFinished = (*command65).isFinished;
				break;
			case(2):
				driveToWP(command66);

				autonomousInfo.isFinished = (*command66).isFinished;
				break;
			case(3):
				autoDumper(command67);

				autonomousInfo.isFinished = (*command67).isFinished;
				break;
			case(4):
				autoClaw(command68);
				autoDumper(command69);
				timeout(command70);
				autonomousInfo.isFinished = (*command68).isFinished && (*command69).isFinished && (*command70).isFinished;
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

