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
DriveToWP * command54;
AutoDumper * command55;

DriveToWP * command56;
Timeout * command57;

DriveToWP * command58;
DriveToWP * command59;
AutoDumper * command60;
AutoClaw * command61;
AutoClaw * command62;
DriveToWP * command63;
Timeout * command64;

AutoClaw * command65;
Timeout * command66;
AutoDumper * command67;
DriveToWP * command68;
Timeout * command69;

DriveToWP * command70;
DriveToWP * command71;
Timeout * command72;

AutoDumper * command73;
AutoClaw * command74;
Timeout * command75;
AutoDumper * command76;
Timeout * command77;
AutoClaw * command78;
AutoClaw * command79;
Timeout * command80;
DriveToWP * command81;
AutoClaw * command82;
AutoDumper * command83;
DriveToWP * command84;
Timeout * command85;

DriveToWP * command86;
Timeout * command87;

AutoDumper * command88;
AutoClaw * command89;

AutoClaw * command90;
DriveToWP * command91;
AutoDumper * command92;

DriveToWP * command93;
Timeout * command94;

DriveToWP * command95;
DriveToWP * command96;
AutoDumper * command97;
AutoClaw * command98;
AutoClaw * command99;
DriveToWP * command100;
Timeout * command101;

AutoClaw * command102;
Timeout * command103;
AutoDumper * command104;
DriveToWP * command105;
Timeout * command106;

DriveToWP * command107;
DriveToWP * command108;
Timeout * command109;

AutoDumper * command110;
AutoClaw * command111;
Timeout * command112;
AutoDumper * command113;
AutoClaw * command114;
Timeout * command115;
DriveToWP * command116;
AutoClaw * command117;
Timeout * command118;
AutoDumper * command119;
DriveToWP * command120;
Timeout * command121;

AutoDumper * command122;
Timeout * command123;
AutoClaw * command124;
Timeout * command125;
AutoDumper * command126;
DriveToWP * command127;
Timeout * command128;

AutoClaw * command129;

AutoClaw * command130;
DriveToWP * command131;
AutoDumper * command132;

DriveToWP * command133;
Timeout * command134;

DriveToWP * command135;
DriveToWP * command136;
AutoDumper * command137;
AutoClaw * command138;
AutoClaw * command139;
DriveToWP * command140;
Timeout * command141;

AutoClaw * command142;
Timeout * command143;
AutoDumper * command144;
DriveToWP * command145;
Timeout * command146;

DriveToWP * command147;
DriveToWP * command148;
Timeout * command149;

AutoDumper * command150;
AutoClaw * command151;
Timeout * command152;
AutoDumper * command153;
Timeout * command154;
AutoClaw * command155;
AutoClaw * command156;
Timeout * command157;
DriveToWP * command158;
AutoClaw * command159;
AutoDumper * command160;
DriveToWP * command161;
Timeout * command162;

DriveToWP * command163;
Timeout * command164;

AutoDumper * command165;
AutoClaw * command166;

AutoClaw * command167;
DriveToWP * command168;
AutoDumper * command169;

DriveToWP * command170;
Timeout * command171;

DriveToWP * command172;
DriveToWP * command173;
AutoDumper * command174;
AutoClaw * command175;
AutoClaw * command176;
DriveToWP * command177;
Timeout * command178;

AutoClaw * command179;
Timeout * command180;
AutoDumper * command181;
DriveToWP * command182;
Timeout * command183;

DriveToWP * command184;
DriveToWP * command185;
Timeout * command186;

AutoDumper * command187;
AutoClaw * command188;
Timeout * command189;
AutoDumper * command190;
AutoClaw * command191;
Timeout * command192;
DriveToWP * command193;
AutoClaw * command194;
Timeout * command195;
AutoDumper * command196;
DriveToWP * command197;
Timeout * command198;

AutoDumper * command199;
Timeout * command200;
AutoClaw * command201;
Timeout * command202;
AutoDumper * command203;
DriveToWP * command204;
Timeout * command205;

AutoClaw * command206;

AutoClaw * command207;
AutoClaw * command208;
DriveToWP * command209;

// END OF DECLARATIONS

void autonomousInit()
{
	/**
	 * Here, the different steps are instantiated and details are
	 * given about them. By hovering over the function name, you can see a
	 * list of the arguments to pass in.
	 */

	defaultProps = initDriveToWPProperties(robotDrive,
			0.5, 18, 1000, 80, 45, // MAG
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
if(autonomousSelection == FENCE_1ST_L_1)
{
	command53 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command54 = initDriveToWP(defaultProps,24,-12,0);
	command55 = initAutoDumper(robotDumper, DUMPER_FRONT_FENCE);

	command56 = initDriveToWP(defaultProps,36,0,0);
	command57 = initTimeout(2500);

	command58 = initDriveToWP(defaultProps,-24,0,0);
	command59 = initDriveToWP(defaultProps,0,0,90);
	command60 = initAutoDumper(robotDumper, DUMPER_LOW);
	command61 = initAutoClaw(robotClaw, CLAW_OPEN);
	command62 = initAutoClaw(robotClaw, CLAW_STOP);
	command63 = initDriveToWP(defaultProps,30,0,0);
	command64 = initTimeout(5000);

	command65 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command66 = initTimeout(2000);
	command67 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command68 = initDriveToWP(defaultProps,8,0,0);
	command69 = initTimeout(2500);

	command70 = initDriveToWP(defaultProps,0,0,80);
	command71 = initDriveToWP(defaultProps,-34,0,0);
	command72 = initTimeout(2500);

	command73 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command74 = initAutoClaw(robotClaw, CLAW_OPEN);
	command75 = initTimeout(2500);
	command76 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command77 = initTimeout(2500);
	command78 = initAutoClaw(robotClaw,CLAW_OPEN);
	command79 = initAutoClaw(robotClaw,CLAW_STOP);
	command80 = initTimeout(1000);
	command81 = initDriveToWP(defaultProps,20,0,0);
	command82 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command83 = initAutoDumper(robotDumper, DUMPER_MIDDLE_FENCE);
	command84 = initDriveToWP(defaultProps,-30,0,0);
	command85 = initTimeout(2500);

	command86 = initDriveToWP(defaultProps,24,0,0);
	command87 = initTimeout(2500);

	command88 = initAutoDumper(robotDumper, DUMPER_LOW);
	command89 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == FENCE_1ST_L_2)
{
	command90 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command91 = initDriveToWP(defaultProps,24,-12,0);
	command92 = initAutoDumper(robotDumper, DUMPER_FRONT_FENCE);

	command93 = initDriveToWP(defaultProps,36,0,0);
	command94 = initTimeout(2500);

	command95 = initDriveToWP(defaultProps,-24,0,0);
	command96 = initDriveToWP(defaultProps,0,0,90);
	command97 = initAutoDumper(robotDumper, DUMPER_LOW);
	command98 = initAutoClaw(robotClaw, CLAW_OPEN);
	command99 = initAutoClaw(robotClaw, CLAW_STOP);
	command100 = initDriveToWP(defaultProps,30,0,0);
	command101 = initTimeout(5000);

	command102 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command103 = initTimeout(2000);
	command104 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command105 = initDriveToWP(defaultProps,14,0,0);
	command106 = initTimeout(2500);

	command107 = initDriveToWP(defaultProps,0,0,80);
	command108 = initDriveToWP(defaultProps,-34,0,0);
	command109 = initTimeout(2500);

	command110 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command111 = initAutoClaw(robotClaw, CLAW_OPEN);
	command112 = initTimeout(2500);
	command113 = initAutoDumper(robotDumper, DUMPER_LOW);
	command114 = initAutoClaw(robotClaw,CLAW_FULL_OPEN);
	command115 = initTimeout(1000);
	command116 = initDriveToWP(defaultProps,24,0,0);
	command117 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command118 = initTimeout(2500);
	command119 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command120 = initDriveToWP(defaultProps,-30,0,0);
	command121 = initTimeout(2500);

	command122 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command123 = initTimeout(1000);
	command124 = initAutoClaw(robotClaw, CLAW_OPEN);
	command125 = initTimeout(1000);
	command126 = initAutoDumper(robotDumper, DUMPER_LOW);
	command127 = initDriveToWP(defaultProps,24,0,0);
	command128 = initTimeout(2500);

	command129 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == FENCE_1ST_R_1)
{
	command130 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command131 = initDriveToWP(defaultProps,24,8,0);
	command132 = initAutoDumper(robotDumper, DUMPER_FRONT_FENCE);

	command133 = initDriveToWP(defaultProps,36,0,0);
	command134 = initTimeout(2500);

	command135 = initDriveToWP(defaultProps,-24,0,0);
	command136 = initDriveToWP(defaultProps,0,0,-90);
	command137 = initAutoDumper(robotDumper, DUMPER_LOW);
	command138 = initAutoClaw(robotClaw, CLAW_OPEN);
	command139 = initAutoClaw(robotClaw, CLAW_STOP);
	command140 = initDriveToWP(defaultProps,30,0,0);
	command141 = initTimeout(5000);

	command142 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command143 = initTimeout(2000);
	command144 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command145 = initDriveToWP(defaultProps,14,0,0);
	command146 = initTimeout(2500);

	command147 = initDriveToWP(defaultProps,0,0,-80);
	command148 = initDriveToWP(defaultProps,-34,0,0);
	command149 = initTimeout(2500);

	command150 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command151 = initAutoClaw(robotClaw, CLAW_OPEN);
	command152 = initTimeout(2500);
	command153 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command154 = initTimeout(2500);
	command155 = initAutoClaw(robotClaw,CLAW_OPEN);
	command156 = initAutoClaw(robotClaw,CLAW_STOP);
	command157 = initTimeout(1000);
	command158 = initDriveToWP(defaultProps,20,0,0);
	command159 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command160 = initAutoDumper(robotDumper, DUMPER_MIDDLE_FENCE);
	command161 = initDriveToWP(defaultProps,-30,0,0);
	command162 = initTimeout(2500);

	command163 = initDriveToWP(defaultProps,24,0,0);
	command164 = initTimeout(2500);

	command165 = initAutoDumper(robotDumper, DUMPER_LOW);
	command166 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == FENCE_1ST_R_2)
{
	command167 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command168 = initDriveToWP(defaultProps,24,8,0);
	command169 = initAutoDumper(robotDumper, DUMPER_FRONT_FENCE);

	command170 = initDriveToWP(defaultProps,36,0,0);
	command171 = initTimeout(2500);

	command172 = initDriveToWP(defaultProps,-24,0,0);
	command173 = initDriveToWP(defaultProps,0,0,-90);
	command174 = initAutoDumper(robotDumper, DUMPER_LOW);
	command175 = initAutoClaw(robotClaw, CLAW_OPEN);
	command176 = initAutoClaw(robotClaw, CLAW_STOP);
	command177 = initDriveToWP(defaultProps,30,0,0);
	command178 = initTimeout(5000);

	command179 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command180 = initTimeout(2000);
	command181 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command182 = initDriveToWP(defaultProps,14,0,0);
	command183 = initTimeout(2500);

	command184 = initDriveToWP(defaultProps,0,0,-80);
	command185 = initDriveToWP(defaultProps,-34,0,0);
	command186 = initTimeout(2500);

	command187 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command188 = initAutoClaw(robotClaw, CLAW_OPEN);
	command189 = initTimeout(2500);
	command190 = initAutoDumper(robotDumper, DUMPER_LOW);
	command191 = initAutoClaw(robotClaw,CLAW_FULL_OPEN);
	command192 = initTimeout(1000);
	command193 = initDriveToWP(defaultProps,24,0,0);
	command194 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command195 = initTimeout(2500);
	command196 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command197 = initDriveToWP(defaultProps,-30,0,0);
	command198 = initTimeout(2500);

	command199 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command200 = initTimeout(1000);
	command201 = initAutoClaw(robotClaw, CLAW_OPEN);
	command202 = initTimeout(1000);
	command203 = initAutoDumper(robotDumper, DUMPER_LOW);
	command204 = initDriveToWP(defaultProps,24,0,0);
	command205 = initTimeout(2500);

	command206 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == TEST_AUTO)
{
	command207 = initAutoClaw(robotClaw, CLAW_FIRST_OPEN);
	command208 = initAutoClaw(robotClaw, CLAW_STOP);
	command209 = initDriveToWP(defaultProps, 24, 0, 0);
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
		case(FENCE_1ST_L_1):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command53);

				autonomousInfo.isFinished = (*command53).isFinished;
				break;
			case(2):
				driveToWP(command54);
				autoDumper(command55);
				autonomousInfo.isFinished = (*command54).isFinished || (*command55).isFinished;
				break;
			case(3):
				driveToWP(command56);
				timeout(command57);
				autonomousInfo.isFinished = (*command56).isFinished || (*command57).isFinished;
				break;
			case(4):
				driveToWP(command58);

				autonomousInfo.isFinished = (*command58).isFinished;
				break;
			case(5):
				driveToWP(command59);

				autonomousInfo.isFinished = (*command59).isFinished;
				break;
			case(6):
				autoDumper(command60);

				autonomousInfo.isFinished = (*command60).isFinished;
				break;
			case(7):
				autoClaw(command61);

				autonomousInfo.isFinished = (*command61).isFinished;
				break;
			case(8):
				autoClaw(command62);

				autonomousInfo.isFinished = (*command62).isFinished;
				break;
			case(9):
				driveToWP(command63);
				timeout(command64);
				autonomousInfo.isFinished = (*command63).isFinished || (*command64).isFinished;
				break;
			case(10):
				autoClaw(command65);

				autonomousInfo.isFinished = (*command65).isFinished;
				break;
			case(11):
				timeout(command66);

				autonomousInfo.isFinished = (*command66).isFinished;
				break;
			case(12):
				autoDumper(command67);

				autonomousInfo.isFinished = (*command67).isFinished;
				break;
			case(13):
				driveToWP(command68);
				timeout(command69);
				autonomousInfo.isFinished = (*command68).isFinished || (*command69).isFinished;
				break;
			case(14):
				driveToWP(command70);

				autonomousInfo.isFinished = (*command70).isFinished;
				break;
			case(15):
				driveToWP(command71);
				timeout(command72);
				autonomousInfo.isFinished = (*command71).isFinished || (*command72).isFinished;
				break;
			case(16):
				autoDumper(command73);

				autonomousInfo.isFinished = (*command73).isFinished;
				break;
			case(17):
				autoClaw(command74);

				autonomousInfo.isFinished = (*command74).isFinished;
				break;
			case(18):
				timeout(command75);

				autonomousInfo.isFinished = (*command75).isFinished;
				break;
			case(19):
				autoDumper(command76);

				autonomousInfo.isFinished = (*command76).isFinished;
				break;
			case(20):
				timeout(command77);

				autonomousInfo.isFinished = (*command77).isFinished;
				break;
			case(21):
				autoClaw(command78);

				autonomousInfo.isFinished = (*command78).isFinished;
				break;
			case(22):
				autoClaw(command79);

				autonomousInfo.isFinished = (*command79).isFinished;
				break;
			case(23):
				timeout(command80);

				autonomousInfo.isFinished = (*command80).isFinished;
				break;
			case(24):
				driveToWP(command81);

				autonomousInfo.isFinished = (*command81).isFinished;
				break;
			case(25):
				autoClaw(command82);

				autonomousInfo.isFinished = (*command82).isFinished;
				break;
			case(26):
				autoDumper(command83);

				autonomousInfo.isFinished = (*command83).isFinished;
				break;
			case(27):
				driveToWP(command84);
				timeout(command85);
				autonomousInfo.isFinished = (*command84).isFinished || (*command85).isFinished;
				break;
			case(28):
				driveToWP(command86);
				timeout(command87);
				autonomousInfo.isFinished = (*command86).isFinished || (*command87).isFinished;
				break;
			case(29):
				autoDumper(command88);

				autonomousInfo.isFinished = (*command88).isFinished;
				break;
			case(30):
				autoClaw(command89);

				autonomousInfo.isFinished = (*command89).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(FENCE_1ST_L_2):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command90);

				autonomousInfo.isFinished = (*command90).isFinished;
				break;
			case(2):
				driveToWP(command91);
				autoDumper(command92);
				autonomousInfo.isFinished = (*command91).isFinished || (*command92).isFinished;
				break;
			case(3):
				driveToWP(command93);
				timeout(command94);
				autonomousInfo.isFinished = (*command93).isFinished || (*command94).isFinished;
				break;
			case(4):
				driveToWP(command95);

				autonomousInfo.isFinished = (*command95).isFinished;
				break;
			case(5):
				driveToWP(command96);

				autonomousInfo.isFinished = (*command96).isFinished;
				break;
			case(6):
				autoDumper(command97);

				autonomousInfo.isFinished = (*command97).isFinished;
				break;
			case(7):
				autoClaw(command98);

				autonomousInfo.isFinished = (*command98).isFinished;
				break;
			case(8):
				autoClaw(command99);

				autonomousInfo.isFinished = (*command99).isFinished;
				break;
			case(9):
				driveToWP(command100);
				timeout(command101);
				autonomousInfo.isFinished = (*command100).isFinished || (*command101).isFinished;
				break;
			case(10):
				autoClaw(command102);

				autonomousInfo.isFinished = (*command102).isFinished;
				break;
			case(11):
				timeout(command103);

				autonomousInfo.isFinished = (*command103).isFinished;
				break;
			case(12):
				autoDumper(command104);

				autonomousInfo.isFinished = (*command104).isFinished;
				break;
			case(13):
				driveToWP(command105);
				timeout(command106);
				autonomousInfo.isFinished = (*command105).isFinished || (*command106).isFinished;
				break;
			case(14):
				driveToWP(command107);

				autonomousInfo.isFinished = (*command107).isFinished;
				break;
			case(15):
				driveToWP(command108);
				timeout(command109);
				autonomousInfo.isFinished = (*command108).isFinished || (*command109).isFinished;
				break;
			case(16):
				autoDumper(command110);

				autonomousInfo.isFinished = (*command110).isFinished;
				break;
			case(17):
				autoClaw(command111);

				autonomousInfo.isFinished = (*command111).isFinished;
				break;
			case(18):
				timeout(command112);

				autonomousInfo.isFinished = (*command112).isFinished;
				break;
			case(19):
				autoDumper(command113);

				autonomousInfo.isFinished = (*command113).isFinished;
				break;
			case(20):
				autoClaw(command114);

				autonomousInfo.isFinished = (*command114).isFinished;
				break;
			case(21):
				timeout(command115);

				autonomousInfo.isFinished = (*command115).isFinished;
				break;
			case(22):
				driveToWP(command116);

				autonomousInfo.isFinished = (*command116).isFinished;
				break;
			case(23):
				autoClaw(command117);

				autonomousInfo.isFinished = (*command117).isFinished;
				break;
			case(24):
				timeout(command118);

				autonomousInfo.isFinished = (*command118).isFinished;
				break;
			case(25):
				autoDumper(command119);

				autonomousInfo.isFinished = (*command119).isFinished;
				break;
			case(26):
				driveToWP(command120);
				timeout(command121);
				autonomousInfo.isFinished = (*command120).isFinished || (*command121).isFinished;
				break;
			case(27):
				autoDumper(command122);

				autonomousInfo.isFinished = (*command122).isFinished;
				break;
			case(28):
				timeout(command123);

				autonomousInfo.isFinished = (*command123).isFinished;
				break;
			case(29):
				autoClaw(command124);

				autonomousInfo.isFinished = (*command124).isFinished;
				break;
			case(30):
				timeout(command125);

				autonomousInfo.isFinished = (*command125).isFinished;
				break;
			case(31):
				autoDumper(command126);

				autonomousInfo.isFinished = (*command126).isFinished;
				break;
			case(32):
				driveToWP(command127);
				timeout(command128);
				autonomousInfo.isFinished = (*command127).isFinished || (*command128).isFinished;
				break;
			case(33):
				autoClaw(command129);

				autonomousInfo.isFinished = (*command129).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(FENCE_1ST_R_1):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command130);

				autonomousInfo.isFinished = (*command130).isFinished;
				break;
			case(2):
				driveToWP(command131);
				autoDumper(command132);
				autonomousInfo.isFinished = (*command131).isFinished || (*command132).isFinished;
				break;
			case(3):
				driveToWP(command133);
				timeout(command134);
				autonomousInfo.isFinished = (*command133).isFinished || (*command134).isFinished;
				break;
			case(4):
				driveToWP(command135);

				autonomousInfo.isFinished = (*command135).isFinished;
				break;
			case(5):
				driveToWP(command136);

				autonomousInfo.isFinished = (*command136).isFinished;
				break;
			case(6):
				autoDumper(command137);

				autonomousInfo.isFinished = (*command137).isFinished;
				break;
			case(7):
				autoClaw(command138);

				autonomousInfo.isFinished = (*command138).isFinished;
				break;
			case(8):
				autoClaw(command139);

				autonomousInfo.isFinished = (*command139).isFinished;
				break;
			case(9):
				driveToWP(command140);
				timeout(command141);
				autonomousInfo.isFinished = (*command140).isFinished || (*command141).isFinished;
				break;
			case(10):
				autoClaw(command142);

				autonomousInfo.isFinished = (*command142).isFinished;
				break;
			case(11):
				timeout(command143);

				autonomousInfo.isFinished = (*command143).isFinished;
				break;
			case(12):
				autoDumper(command144);

				autonomousInfo.isFinished = (*command144).isFinished;
				break;
			case(13):
				driveToWP(command145);
				timeout(command146);
				autonomousInfo.isFinished = (*command145).isFinished || (*command146).isFinished;
				break;
			case(14):
				driveToWP(command147);

				autonomousInfo.isFinished = (*command147).isFinished;
				break;
			case(15):
				driveToWP(command148);
				timeout(command149);
				autonomousInfo.isFinished = (*command148).isFinished || (*command149).isFinished;
				break;
			case(16):
				autoDumper(command150);

				autonomousInfo.isFinished = (*command150).isFinished;
				break;
			case(17):
				autoClaw(command151);

				autonomousInfo.isFinished = (*command151).isFinished;
				break;
			case(18):
				timeout(command152);

				autonomousInfo.isFinished = (*command152).isFinished;
				break;
			case(19):
				autoDumper(command153);

				autonomousInfo.isFinished = (*command153).isFinished;
				break;
			case(20):
				timeout(command154);

				autonomousInfo.isFinished = (*command154).isFinished;
				break;
			case(21):
				autoClaw(command155);

				autonomousInfo.isFinished = (*command155).isFinished;
				break;
			case(22):
				autoClaw(command156);

				autonomousInfo.isFinished = (*command156).isFinished;
				break;
			case(23):
				timeout(command157);

				autonomousInfo.isFinished = (*command157).isFinished;
				break;
			case(24):
				driveToWP(command158);

				autonomousInfo.isFinished = (*command158).isFinished;
				break;
			case(25):
				autoClaw(command159);

				autonomousInfo.isFinished = (*command159).isFinished;
				break;
			case(26):
				autoDumper(command160);

				autonomousInfo.isFinished = (*command160).isFinished;
				break;
			case(27):
				driveToWP(command161);
				timeout(command162);
				autonomousInfo.isFinished = (*command161).isFinished || (*command162).isFinished;
				break;
			case(28):
				driveToWP(command163);
				timeout(command164);
				autonomousInfo.isFinished = (*command163).isFinished || (*command164).isFinished;
				break;
			case(29):
				autoDumper(command165);

				autonomousInfo.isFinished = (*command165).isFinished;
				break;
			case(30):
				autoClaw(command166);

				autonomousInfo.isFinished = (*command166).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(FENCE_1ST_R_2):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command167);

				autonomousInfo.isFinished = (*command167).isFinished;
				break;
			case(2):
				driveToWP(command168);
				autoDumper(command169);
				autonomousInfo.isFinished = (*command168).isFinished || (*command169).isFinished;
				break;
			case(3):
				driveToWP(command170);
				timeout(command171);
				autonomousInfo.isFinished = (*command170).isFinished || (*command171).isFinished;
				break;
			case(4):
				driveToWP(command172);

				autonomousInfo.isFinished = (*command172).isFinished;
				break;
			case(5):
				driveToWP(command173);

				autonomousInfo.isFinished = (*command173).isFinished;
				break;
			case(6):
				autoDumper(command174);

				autonomousInfo.isFinished = (*command174).isFinished;
				break;
			case(7):
				autoClaw(command175);

				autonomousInfo.isFinished = (*command175).isFinished;
				break;
			case(8):
				autoClaw(command176);

				autonomousInfo.isFinished = (*command176).isFinished;
				break;
			case(9):
				driveToWP(command177);
				timeout(command178);
				autonomousInfo.isFinished = (*command177).isFinished || (*command178).isFinished;
				break;
			case(10):
				autoClaw(command179);

				autonomousInfo.isFinished = (*command179).isFinished;
				break;
			case(11):
				timeout(command180);

				autonomousInfo.isFinished = (*command180).isFinished;
				break;
			case(12):
				autoDumper(command181);

				autonomousInfo.isFinished = (*command181).isFinished;
				break;
			case(13):
				driveToWP(command182);
				timeout(command183);
				autonomousInfo.isFinished = (*command182).isFinished || (*command183).isFinished;
				break;
			case(14):
				driveToWP(command184);

				autonomousInfo.isFinished = (*command184).isFinished;
				break;
			case(15):
				driveToWP(command185);
				timeout(command186);
				autonomousInfo.isFinished = (*command185).isFinished || (*command186).isFinished;
				break;
			case(16):
				autoDumper(command187);

				autonomousInfo.isFinished = (*command187).isFinished;
				break;
			case(17):
				autoClaw(command188);

				autonomousInfo.isFinished = (*command188).isFinished;
				break;
			case(18):
				timeout(command189);

				autonomousInfo.isFinished = (*command189).isFinished;
				break;
			case(19):
				autoDumper(command190);

				autonomousInfo.isFinished = (*command190).isFinished;
				break;
			case(20):
				autoClaw(command191);

				autonomousInfo.isFinished = (*command191).isFinished;
				break;
			case(21):
				timeout(command192);

				autonomousInfo.isFinished = (*command192).isFinished;
				break;
			case(22):
				driveToWP(command193);

				autonomousInfo.isFinished = (*command193).isFinished;
				break;
			case(23):
				autoClaw(command194);

				autonomousInfo.isFinished = (*command194).isFinished;
				break;
			case(24):
				timeout(command195);

				autonomousInfo.isFinished = (*command195).isFinished;
				break;
			case(25):
				autoDumper(command196);

				autonomousInfo.isFinished = (*command196).isFinished;
				break;
			case(26):
				driveToWP(command197);
				timeout(command198);
				autonomousInfo.isFinished = (*command197).isFinished || (*command198).isFinished;
				break;
			case(27):
				autoDumper(command199);

				autonomousInfo.isFinished = (*command199).isFinished;
				break;
			case(28):
				timeout(command200);

				autonomousInfo.isFinished = (*command200).isFinished;
				break;
			case(29):
				autoClaw(command201);

				autonomousInfo.isFinished = (*command201).isFinished;
				break;
			case(30):
				timeout(command202);

				autonomousInfo.isFinished = (*command202).isFinished;
				break;
			case(31):
				autoDumper(command203);

				autonomousInfo.isFinished = (*command203).isFinished;
				break;
			case(32):
				driveToWP(command204);
				timeout(command205);
				autonomousInfo.isFinished = (*command204).isFinished || (*command205).isFinished;
				break;
			case(33):
				autoClaw(command206);

				autonomousInfo.isFinished = (*command206).isFinished;
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
				autoClaw(command207);

				autonomousInfo.isFinished = (*command207).isFinished;
				break;
			case(2):
				autoClaw(command208);

				autonomousInfo.isFinished = (*command208).isFinished;
				break;
			case(3):
				driveToWP(command209);

				autonomousInfo.isFinished = (*command209).isFinished;
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

