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
Timeout * command62;

AutoClaw * command63;
DriveToWP * command64;
Timeout * command65;

AutoClaw * command66;
Timeout * command67;
AutoDumper * command68;
DriveToWP * command69;
Timeout * command70;

DriveToWP * command71;
DriveToWP * command72;
Timeout * command73;

AutoDumper * command74;
AutoClaw * command75;
Timeout * command76;
AutoDumper * command77;
Timeout * command78;
AutoClaw * command79;
AutoClaw * command80;
Timeout * command81;
DriveToWP * command82;
AutoClaw * command83;
AutoDumper * command84;
DriveToWP * command85;
Timeout * command86;

DriveToWP * command87;
Timeout * command88;

AutoDumper * command89;
AutoClaw * command90;

AutoClaw * command91;
DriveToWP * command92;
AutoDumper * command93;

DriveToWP * command94;
Timeout * command95;

DriveToWP * command96;
DriveToWP * command97;
AutoDumper * command98;
AutoClaw * command99;
Timeout * command100;

AutoClaw * command101;
DriveToWP * command102;
Timeout * command103;

AutoClaw * command104;
Timeout * command105;
AutoDumper * command106;
DriveToWP * command107;
Timeout * command108;

DriveToWP * command109;
DriveToWP * command110;
Timeout * command111;

AutoDumper * command112;
AutoClaw * command113;
Timeout * command114;
AutoDumper * command115;
AutoClaw * command116;
Timeout * command117;
DriveToWP * command118;
AutoClaw * command119;
Timeout * command120;
AutoDumper * command121;
DriveToWP * command122;
Timeout * command123;

AutoDumper * command124;
Timeout * command125;
AutoClaw * command126;
Timeout * command127;
AutoDumper * command128;
DriveToWP * command129;
Timeout * command130;

AutoClaw * command131;

AutoClaw * command132;
DriveToWP * command133;
AutoDumper * command134;

DriveToWP * command135;
Timeout * command136;

DriveToWP * command137;
DriveToWP * command138;
AutoDumper * command139;
AutoClaw * command140;
Timeout * command141;

AutoClaw * command142;
DriveToWP * command143;
Timeout * command144;

AutoClaw * command145;
Timeout * command146;
AutoDumper * command147;
DriveToWP * command148;
Timeout * command149;

DriveToWP * command150;
DriveToWP * command151;
Timeout * command152;

AutoDumper * command153;
AutoClaw * command154;
Timeout * command155;
AutoDumper * command156;
Timeout * command157;
DriveToWP * command158;
AutoDumper * command159;
AutoClaw * command160;
Timeout * command161;

AutoClaw * command162;
DriveToWP * command163;
Timeout * command164;
DriveToWP * command165;
Timeout * command166;
AutoClaw * command167;
Timeout * command168;
AutoDumper * command169;
DriveToWP * command170;
Timeout * command171;
DriveToWP * command172;
Timeout * command173;

AutoDumper * command174;
AutoClaw * command175;
Timeout * command176;
AutoDumper * command177;

AutoClaw * command178;
DriveToWP * command179;
AutoDumper * command180;

DriveToWP * command181;
Timeout * command182;

DriveToWP * command183;
DriveToWP * command184;
AutoDumper * command185;
AutoClaw * command186;
Timeout * command187;

AutoClaw * command188;
DriveToWP * command189;
Timeout * command190;

AutoClaw * command191;
Timeout * command192;
AutoDumper * command193;
DriveToWP * command194;
Timeout * command195;

DriveToWP * command196;
DriveToWP * command197;
Timeout * command198;

AutoDumper * command199;
AutoClaw * command200;
Timeout * command201;
AutoDumper * command202;
Timeout * command203;
AutoClaw * command204;
AutoClaw * command205;
Timeout * command206;
DriveToWP * command207;
AutoClaw * command208;
AutoDumper * command209;
DriveToWP * command210;
Timeout * command211;

DriveToWP * command212;
Timeout * command213;

AutoDumper * command214;
AutoClaw * command215;

AutoClaw * command216;
DriveToWP * command217;
AutoDumper * command218;

DriveToWP * command219;
Timeout * command220;

DriveToWP * command221;
DriveToWP * command222;
AutoDumper * command223;
AutoClaw * command224;
AutoClaw * command225;
DriveToWP * command226;
Timeout * command227;

AutoClaw * command228;
Timeout * command229;
AutoDumper * command230;
DriveToWP * command231;
Timeout * command232;

DriveToWP * command233;
DriveToWP * command234;
Timeout * command235;

AutoDumper * command236;
AutoClaw * command237;
Timeout * command238;
AutoDumper * command239;
AutoClaw * command240;
Timeout * command241;
DriveToWP * command242;
AutoClaw * command243;
Timeout * command244;
AutoDumper * command245;
DriveToWP * command246;
Timeout * command247;

AutoDumper * command248;
Timeout * command249;
AutoClaw * command250;
Timeout * command251;
AutoDumper * command252;
DriveToWP * command253;
Timeout * command254;

AutoClaw * command255;

AutoClaw * command256;
AutoClaw * command257;
DriveToWP * command258;

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
	command54 = initDriveToWP(defaultProps,20,-12,0);
	command55 = initAutoDumper(robotDumper, DUMPER_FRONT_FENCE);

	command56 = initDriveToWP(defaultProps,26,0,0);
	command57 = initTimeout(2500);

	command58 = initDriveToWP(defaultProps,-24,0,0);
	command59 = initDriveToWP(defaultProps,0,0,85);
	command60 = initAutoDumper(robotDumper, DUMPER_LOW);
	command61 = initAutoClaw(robotClaw, CLAW_OPEN);
	command62 = initTimeout(1500);

	command63 = initAutoClaw(robotClaw, CLAW_STOP);
	command64 = initDriveToWP(defaultProps,26,0,0);
	command65 = initTimeout(5000);

	command66 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command67 = initTimeout(1000);
	command68 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command69 = initDriveToWP(defaultProps,8,0,0);
	command70 = initTimeout(2500);

	command71 = initDriveToWP(defaultProps,0,0,85);
	command72 = initDriveToWP(defaultProps,-34,0,0);
	command73 = initTimeout(2500);

	command74 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command75 = initAutoClaw(robotClaw, CLAW_OPEN);
	command76 = initTimeout(2500);
	command77 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command78 = initTimeout(2500);
	command79 = initAutoClaw(robotClaw,CLAW_OPEN);
	command80 = initAutoClaw(robotClaw,CLAW_STOP);
	command81 = initTimeout(1000);
	command82 = initDriveToWP(defaultProps,20,0,0);
	command83 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command84 = initAutoDumper(robotDumper, DUMPER_MIDDLE_FENCE);
	command85 = initDriveToWP(defaultProps,-34,0,0);
	command86 = initTimeout(2500);

	command87 = initDriveToWP(defaultProps,16,0,0);
	command88 = initTimeout(2500);

	command89 = initAutoDumper(robotDumper, DUMPER_LOW);
	command90 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == FENCE_1ST_L_2)
{
	command91 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command92 = initDriveToWP(defaultProps,24,-12,0);
	command93 = initAutoDumper(robotDumper, DUMPER_FRONT_FENCE);

	command94 = initDriveToWP(defaultProps,26,0,0);
	command95 = initTimeout(2500);

	command96 = initDriveToWP(defaultProps,-24,0,0);
	command97 = initDriveToWP(defaultProps,0,0,85);
	command98 = initAutoDumper(robotDumper, DUMPER_LOW);
	command99 = initAutoClaw(robotClaw, CLAW_OPEN);
	command100 = initTimeout(1500);

	command101 = initAutoClaw(robotClaw, CLAW_STOP);
	command102 = initDriveToWP(defaultProps,26,0,0);
	command103 = initTimeout(5000);

	command104 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command105 = initTimeout(2000);
	command106 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command107 = initDriveToWP(defaultProps,8,0,0);
	command108 = initTimeout(2500);

	command109 = initDriveToWP(defaultProps,0,0,85);
	command110 = initDriveToWP(defaultProps,-34,0,0);
	command111 = initTimeout(2500);

	command112 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command113 = initAutoClaw(robotClaw, CLAW_OPEN);
	command114 = initTimeout(2500);
	command115 = initAutoDumper(robotDumper, DUMPER_LOW);
	command116 = initAutoClaw(robotClaw,CLAW_FULL_OPEN);
	command117 = initTimeout(1000);
	command118 = initDriveToWP(defaultProps,20,0,0);
	command119 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command120 = initTimeout(2500);
	command121 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command122 = initDriveToWP(defaultProps,-30,0,0);
	command123 = initTimeout(2500);

	command124 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command125 = initTimeout(1000);
	command126 = initAutoClaw(robotClaw, CLAW_OPEN);
	command127 = initTimeout(1000);
	command128 = initAutoDumper(robotDumper, DUMPER_LOW);
	command129 = initDriveToWP(defaultProps,24,0,0);
	command130 = initTimeout(2500);

	command131 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == FENCE_1ST_L_3)
{
	command132 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command133 = initDriveToWP(defaultProps,24,-12,0);
	command134 = initAutoDumper(robotDumper, DUMPER_FRONT_FENCE);

	command135 = initDriveToWP(defaultProps,26,0,0);
	command136 = initTimeout(2500);

	command137 = initDriveToWP(defaultProps,-24,0,0);
	command138 = initDriveToWP(defaultProps,0,0,85);
	command139 = initAutoDumper(robotDumper, DUMPER_LOW);
	command140 = initAutoClaw(robotClaw, CLAW_OPEN);
	command141 = initTimeout(1500);

	command142 = initAutoClaw(robotClaw, CLAW_STOP);
	command143 = initDriveToWP(defaultProps,20,0,0);
	command144 = initTimeout(5000);

	command145 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command146 = initTimeout(2000);
	command147 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command148 = initDriveToWP(defaultProps,44,0,0);
	command149 = initTimeout(5000);

	command150 = initDriveToWP(defaultProps,0,0,85);
	command151 = initDriveToWP(defaultProps,-26,0,0);
	command152 = initTimeout(5000);

	command153 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command154 = initAutoClaw(robotClaw, CLAW_OPEN);
	command155 = initTimeout(1000);
	command156 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command157 = initTimeout(1000);
	command158 = initDriveToWP(defaultProps, 12,0,0);
	command159 = initAutoDumper(robotDumper, DUMPER_LOW);
	command160 = initAutoClaw(robotClaw, CLAW_OPEN);
	command161 = initTimeout(2000);

	command162 = initAutoClaw(robotClaw, CLAW_STOP);
	command163 = initDriveToWP(defaultProps,0,0,90);
	command164 = initTimeout(500);
	command165 = initDriveToWP(defaultProps,20,0,0);
	command166 = initTimeout(500);
	command167 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command168 = initTimeout(2000);
	command169 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command170 = initDriveToWP(defaultProps,0,0,-90);
	command171 = initTimeout(500);
	command172 = initDriveToWP(defaultProps,-26,0,0);
	command173 = initTimeout(2500);

	command174 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command175 = initAutoClaw(robotClaw, CLAW_OPEN);
	command176 = initTimeout(500);
	command177 = initAutoDumper(robotDumper,DUMPER_LOW);
}
if(autonomousSelection == FENCE_1ST_R_1)
{
	command178 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command179 = initDriveToWP(defaultProps,20,6,0);
	command180 = initAutoDumper(robotDumper, DUMPER_FRONT_FENCE);

	command181 = initDriveToWP(defaultProps,22,0,0);
	command182 = initTimeout(2500);

	command183 = initDriveToWP(defaultProps,-24,0,0);
	command184 = initDriveToWP(defaultProps,0,0,-85);
	command185 = initAutoDumper(robotDumper, DUMPER_LOW);
	command186 = initAutoClaw(robotClaw, CLAW_OPEN);
	command187 = initTimeout(1500);

	command188 = initAutoClaw(robotClaw, CLAW_STOP);
	command189 = initDriveToWP(defaultProps,26,0,0);
	command190 = initTimeout(5000);

	command191 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command192 = initTimeout(1000);
	command193 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command194 = initDriveToWP(defaultProps,8,0,0);
	command195 = initTimeout(2500);

	command196 = initDriveToWP(defaultProps,0,0,-85);
	command197 = initDriveToWP(defaultProps,-34,0,0);
	command198 = initTimeout(2500);

	command199 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command200 = initAutoClaw(robotClaw, CLAW_OPEN);
	command201 = initTimeout(2500);
	command202 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command203 = initTimeout(2500);
	command204 = initAutoClaw(robotClaw,CLAW_OPEN);
	command205 = initAutoClaw(robotClaw,CLAW_STOP);
	command206 = initTimeout(1000);
	command207 = initDriveToWP(defaultProps,20,0,0);
	command208 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command209 = initAutoDumper(robotDumper, DUMPER_MIDDLE_FENCE);
	command210 = initDriveToWP(defaultProps,-34,0,0);
	command211 = initTimeout(2500);

	command212 = initDriveToWP(defaultProps,16,0,0);
	command213 = initTimeout(2500);

	command214 = initAutoDumper(robotDumper, DUMPER_LOW);
	command215 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == FENCE_1ST_R_2)
{
	command216 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command217 = initDriveToWP(defaultProps,24,6,0);
	command218 = initAutoDumper(robotDumper, DUMPER_FRONT_FENCE);

	command219 = initDriveToWP(defaultProps,36,0,0);
	command220 = initTimeout(2500);

	command221 = initDriveToWP(defaultProps,-24,0,0);
	command222 = initDriveToWP(defaultProps,0,0,-90);
	command223 = initAutoDumper(robotDumper, DUMPER_LOW);
	command224 = initAutoClaw(robotClaw, CLAW_OPEN);
	command225 = initAutoClaw(robotClaw, CLAW_STOP);
	command226 = initDriveToWP(defaultProps,30,0,0);
	command227 = initTimeout(5000);

	command228 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command229 = initTimeout(2000);
	command230 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command231 = initDriveToWP(defaultProps,16,0,0);
	command232 = initTimeout(2500);

	command233 = initDriveToWP(defaultProps,0,0,-90);
	command234 = initDriveToWP(defaultProps,-34,0,0);
	command235 = initTimeout(2500);

	command236 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command237 = initAutoClaw(robotClaw, CLAW_OPEN);
	command238 = initTimeout(2500);
	command239 = initAutoDumper(robotDumper, DUMPER_LOW);
	command240 = initAutoClaw(robotClaw,CLAW_FULL_OPEN);
	command241 = initTimeout(1000);
	command242 = initDriveToWP(defaultProps,24,0,0);
	command243 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command244 = initTimeout(2500);
	command245 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command246 = initDriveToWP(defaultProps,-30,0,0);
	command247 = initTimeout(2500);

	command248 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command249 = initTimeout(1000);
	command250 = initAutoClaw(robotClaw, CLAW_OPEN);
	command251 = initTimeout(1000);
	command252 = initAutoDumper(robotDumper, DUMPER_LOW);
	command253 = initDriveToWP(defaultProps,24,0,0);
	command254 = initTimeout(2500);

	command255 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == TEST_AUTO)
{
	command256 = initAutoClaw(robotClaw, CLAW_FIRST_OPEN);
	command257 = initAutoClaw(robotClaw, CLAW_STOP);
	command258 = initDriveToWP(defaultProps, 24, 0, 0);
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
				timeout(command62);
				autonomousInfo.isFinished = (*command61).isFinished && (*command62).isFinished;
				break;
			case(8):
				autoClaw(command63);

				autonomousInfo.isFinished = (*command63).isFinished;
				break;
			case(9):
				driveToWP(command64);
				timeout(command65);
				autonomousInfo.isFinished = (*command64).isFinished || (*command65).isFinished;
				break;
			case(10):
				autoClaw(command66);

				autonomousInfo.isFinished = (*command66).isFinished;
				break;
			case(11):
				timeout(command67);

				autonomousInfo.isFinished = (*command67).isFinished;
				break;
			case(12):
				autoDumper(command68);

				autonomousInfo.isFinished = (*command68).isFinished;
				break;
			case(13):
				driveToWP(command69);
				timeout(command70);
				autonomousInfo.isFinished = (*command69).isFinished || (*command70).isFinished;
				break;
			case(14):
				driveToWP(command71);

				autonomousInfo.isFinished = (*command71).isFinished;
				break;
			case(15):
				driveToWP(command72);
				timeout(command73);
				autonomousInfo.isFinished = (*command72).isFinished || (*command73).isFinished;
				break;
			case(16):
				autoDumper(command74);

				autonomousInfo.isFinished = (*command74).isFinished;
				break;
			case(17):
				autoClaw(command75);

				autonomousInfo.isFinished = (*command75).isFinished;
				break;
			case(18):
				timeout(command76);

				autonomousInfo.isFinished = (*command76).isFinished;
				break;
			case(19):
				autoDumper(command77);

				autonomousInfo.isFinished = (*command77).isFinished;
				break;
			case(20):
				timeout(command78);

				autonomousInfo.isFinished = (*command78).isFinished;
				break;
			case(21):
				autoClaw(command79);

				autonomousInfo.isFinished = (*command79).isFinished;
				break;
			case(22):
				autoClaw(command80);

				autonomousInfo.isFinished = (*command80).isFinished;
				break;
			case(23):
				timeout(command81);

				autonomousInfo.isFinished = (*command81).isFinished;
				break;
			case(24):
				driveToWP(command82);

				autonomousInfo.isFinished = (*command82).isFinished;
				break;
			case(25):
				autoClaw(command83);

				autonomousInfo.isFinished = (*command83).isFinished;
				break;
			case(26):
				autoDumper(command84);

				autonomousInfo.isFinished = (*command84).isFinished;
				break;
			case(27):
				driveToWP(command85);
				timeout(command86);
				autonomousInfo.isFinished = (*command85).isFinished || (*command86).isFinished;
				break;
			case(28):
				driveToWP(command87);
				timeout(command88);
				autonomousInfo.isFinished = (*command87).isFinished || (*command88).isFinished;
				break;
			case(29):
				autoDumper(command89);

				autonomousInfo.isFinished = (*command89).isFinished;
				break;
			case(30):
				autoClaw(command90);

				autonomousInfo.isFinished = (*command90).isFinished;
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
				autoClaw(command91);

				autonomousInfo.isFinished = (*command91).isFinished;
				break;
			case(2):
				driveToWP(command92);
				autoDumper(command93);
				autonomousInfo.isFinished = (*command92).isFinished || (*command93).isFinished;
				break;
			case(3):
				driveToWP(command94);
				timeout(command95);
				autonomousInfo.isFinished = (*command94).isFinished || (*command95).isFinished;
				break;
			case(4):
				driveToWP(command96);

				autonomousInfo.isFinished = (*command96).isFinished;
				break;
			case(5):
				driveToWP(command97);

				autonomousInfo.isFinished = (*command97).isFinished;
				break;
			case(6):
				autoDumper(command98);

				autonomousInfo.isFinished = (*command98).isFinished;
				break;
			case(7):
				autoClaw(command99);
				timeout(command100);
				autonomousInfo.isFinished = (*command99).isFinished && (*command100).isFinished;
				break;
			case(8):
				autoClaw(command101);

				autonomousInfo.isFinished = (*command101).isFinished;
				break;
			case(9):
				driveToWP(command102);
				timeout(command103);
				autonomousInfo.isFinished = (*command102).isFinished || (*command103).isFinished;
				break;
			case(10):
				autoClaw(command104);

				autonomousInfo.isFinished = (*command104).isFinished;
				break;
			case(11):
				timeout(command105);

				autonomousInfo.isFinished = (*command105).isFinished;
				break;
			case(12):
				autoDumper(command106);

				autonomousInfo.isFinished = (*command106).isFinished;
				break;
			case(13):
				driveToWP(command107);
				timeout(command108);
				autonomousInfo.isFinished = (*command107).isFinished || (*command108).isFinished;
				break;
			case(14):
				driveToWP(command109);

				autonomousInfo.isFinished = (*command109).isFinished;
				break;
			case(15):
				driveToWP(command110);
				timeout(command111);
				autonomousInfo.isFinished = (*command110).isFinished || (*command111).isFinished;
				break;
			case(16):
				autoDumper(command112);

				autonomousInfo.isFinished = (*command112).isFinished;
				break;
			case(17):
				autoClaw(command113);

				autonomousInfo.isFinished = (*command113).isFinished;
				break;
			case(18):
				timeout(command114);

				autonomousInfo.isFinished = (*command114).isFinished;
				break;
			case(19):
				autoDumper(command115);

				autonomousInfo.isFinished = (*command115).isFinished;
				break;
			case(20):
				autoClaw(command116);

				autonomousInfo.isFinished = (*command116).isFinished;
				break;
			case(21):
				timeout(command117);

				autonomousInfo.isFinished = (*command117).isFinished;
				break;
			case(22):
				driveToWP(command118);

				autonomousInfo.isFinished = (*command118).isFinished;
				break;
			case(23):
				autoClaw(command119);

				autonomousInfo.isFinished = (*command119).isFinished;
				break;
			case(24):
				timeout(command120);

				autonomousInfo.isFinished = (*command120).isFinished;
				break;
			case(25):
				autoDumper(command121);

				autonomousInfo.isFinished = (*command121).isFinished;
				break;
			case(26):
				driveToWP(command122);
				timeout(command123);
				autonomousInfo.isFinished = (*command122).isFinished || (*command123).isFinished;
				break;
			case(27):
				autoDumper(command124);

				autonomousInfo.isFinished = (*command124).isFinished;
				break;
			case(28):
				timeout(command125);

				autonomousInfo.isFinished = (*command125).isFinished;
				break;
			case(29):
				autoClaw(command126);

				autonomousInfo.isFinished = (*command126).isFinished;
				break;
			case(30):
				timeout(command127);

				autonomousInfo.isFinished = (*command127).isFinished;
				break;
			case(31):
				autoDumper(command128);

				autonomousInfo.isFinished = (*command128).isFinished;
				break;
			case(32):
				driveToWP(command129);
				timeout(command130);
				autonomousInfo.isFinished = (*command129).isFinished || (*command130).isFinished;
				break;
			case(33):
				autoClaw(command131);

				autonomousInfo.isFinished = (*command131).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(FENCE_1ST_L_3):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command132);

				autonomousInfo.isFinished = (*command132).isFinished;
				break;
			case(2):
				driveToWP(command133);
				autoDumper(command134);
				autonomousInfo.isFinished = (*command133).isFinished || (*command134).isFinished;
				break;
			case(3):
				driveToWP(command135);
				timeout(command136);
				autonomousInfo.isFinished = (*command135).isFinished || (*command136).isFinished;
				break;
			case(4):
				driveToWP(command137);

				autonomousInfo.isFinished = (*command137).isFinished;
				break;
			case(5):
				driveToWP(command138);

				autonomousInfo.isFinished = (*command138).isFinished;
				break;
			case(6):
				autoDumper(command139);

				autonomousInfo.isFinished = (*command139).isFinished;
				break;
			case(7):
				autoClaw(command140);
				timeout(command141);
				autonomousInfo.isFinished = (*command140).isFinished && (*command141).isFinished;
				break;
			case(8):
				autoClaw(command142);

				autonomousInfo.isFinished = (*command142).isFinished;
				break;
			case(9):
				driveToWP(command143);
				timeout(command144);
				autonomousInfo.isFinished = (*command143).isFinished || (*command144).isFinished;
				break;
			case(10):
				autoClaw(command145);

				autonomousInfo.isFinished = (*command145).isFinished;
				break;
			case(11):
				timeout(command146);

				autonomousInfo.isFinished = (*command146).isFinished;
				break;
			case(12):
				autoDumper(command147);

				autonomousInfo.isFinished = (*command147).isFinished;
				break;
			case(13):
				driveToWP(command148);
				timeout(command149);
				autonomousInfo.isFinished = (*command148).isFinished || (*command149).isFinished;
				break;
			case(14):
				driveToWP(command150);

				autonomousInfo.isFinished = (*command150).isFinished;
				break;
			case(15):
				driveToWP(command151);
				timeout(command152);
				autonomousInfo.isFinished = (*command151).isFinished || (*command152).isFinished;
				break;
			case(16):
				autoDumper(command153);

				autonomousInfo.isFinished = (*command153).isFinished;
				break;
			case(17):
				autoClaw(command154);

				autonomousInfo.isFinished = (*command154).isFinished;
				break;
			case(18):
				timeout(command155);

				autonomousInfo.isFinished = (*command155).isFinished;
				break;
			case(19):
				autoDumper(command156);

				autonomousInfo.isFinished = (*command156).isFinished;
				break;
			case(20):
				timeout(command157);

				autonomousInfo.isFinished = (*command157).isFinished;
				break;
			case(21):
				driveToWP(command158);

				autonomousInfo.isFinished = (*command158).isFinished;
				break;
			case(22):
				autoDumper(command159);

				autonomousInfo.isFinished = (*command159).isFinished;
				break;
			case(23):
				autoClaw(command160);
				timeout(command161);
				autonomousInfo.isFinished = (*command160).isFinished && (*command161).isFinished;
				break;
			case(24):
				autoClaw(command162);

				autonomousInfo.isFinished = (*command162).isFinished;
				break;
			case(25):
				driveToWP(command163);

				autonomousInfo.isFinished = (*command163).isFinished;
				break;
			case(26):
				timeout(command164);

				autonomousInfo.isFinished = (*command164).isFinished;
				break;
			case(27):
				driveToWP(command165);

				autonomousInfo.isFinished = (*command165).isFinished;
				break;
			case(28):
				timeout(command166);

				autonomousInfo.isFinished = (*command166).isFinished;
				break;
			case(29):
				autoClaw(command167);

				autonomousInfo.isFinished = (*command167).isFinished;
				break;
			case(30):
				timeout(command168);

				autonomousInfo.isFinished = (*command168).isFinished;
				break;
			case(31):
				autoDumper(command169);

				autonomousInfo.isFinished = (*command169).isFinished;
				break;
			case(32):
				driveToWP(command170);

				autonomousInfo.isFinished = (*command170).isFinished;
				break;
			case(33):
				timeout(command171);

				autonomousInfo.isFinished = (*command171).isFinished;
				break;
			case(34):
				driveToWP(command172);
				timeout(command173);
				autonomousInfo.isFinished = (*command172).isFinished || (*command173).isFinished;
				break;
			case(35):
				autoDumper(command174);

				autonomousInfo.isFinished = (*command174).isFinished;
				break;
			case(36):
				autoClaw(command175);

				autonomousInfo.isFinished = (*command175).isFinished;
				break;
			case(37):
				timeout(command176);

				autonomousInfo.isFinished = (*command176).isFinished;
				break;
			case(38):
				autoDumper(command177);

				autonomousInfo.isFinished = (*command177).isFinished;
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
				autoClaw(command178);

				autonomousInfo.isFinished = (*command178).isFinished;
				break;
			case(2):
				driveToWP(command179);
				autoDumper(command180);
				autonomousInfo.isFinished = (*command179).isFinished || (*command180).isFinished;
				break;
			case(3):
				driveToWP(command181);
				timeout(command182);
				autonomousInfo.isFinished = (*command181).isFinished || (*command182).isFinished;
				break;
			case(4):
				driveToWP(command183);

				autonomousInfo.isFinished = (*command183).isFinished;
				break;
			case(5):
				driveToWP(command184);

				autonomousInfo.isFinished = (*command184).isFinished;
				break;
			case(6):
				autoDumper(command185);

				autonomousInfo.isFinished = (*command185).isFinished;
				break;
			case(7):
				autoClaw(command186);
				timeout(command187);
				autonomousInfo.isFinished = (*command186).isFinished && (*command187).isFinished;
				break;
			case(8):
				autoClaw(command188);

				autonomousInfo.isFinished = (*command188).isFinished;
				break;
			case(9):
				driveToWP(command189);
				timeout(command190);
				autonomousInfo.isFinished = (*command189).isFinished || (*command190).isFinished;
				break;
			case(10):
				autoClaw(command191);

				autonomousInfo.isFinished = (*command191).isFinished;
				break;
			case(11):
				timeout(command192);

				autonomousInfo.isFinished = (*command192).isFinished;
				break;
			case(12):
				autoDumper(command193);

				autonomousInfo.isFinished = (*command193).isFinished;
				break;
			case(13):
				driveToWP(command194);
				timeout(command195);
				autonomousInfo.isFinished = (*command194).isFinished || (*command195).isFinished;
				break;
			case(14):
				driveToWP(command196);

				autonomousInfo.isFinished = (*command196).isFinished;
				break;
			case(15):
				driveToWP(command197);
				timeout(command198);
				autonomousInfo.isFinished = (*command197).isFinished || (*command198).isFinished;
				break;
			case(16):
				autoDumper(command199);

				autonomousInfo.isFinished = (*command199).isFinished;
				break;
			case(17):
				autoClaw(command200);

				autonomousInfo.isFinished = (*command200).isFinished;
				break;
			case(18):
				timeout(command201);

				autonomousInfo.isFinished = (*command201).isFinished;
				break;
			case(19):
				autoDumper(command202);

				autonomousInfo.isFinished = (*command202).isFinished;
				break;
			case(20):
				timeout(command203);

				autonomousInfo.isFinished = (*command203).isFinished;
				break;
			case(21):
				autoClaw(command204);

				autonomousInfo.isFinished = (*command204).isFinished;
				break;
			case(22):
				autoClaw(command205);

				autonomousInfo.isFinished = (*command205).isFinished;
				break;
			case(23):
				timeout(command206);

				autonomousInfo.isFinished = (*command206).isFinished;
				break;
			case(24):
				driveToWP(command207);

				autonomousInfo.isFinished = (*command207).isFinished;
				break;
			case(25):
				autoClaw(command208);

				autonomousInfo.isFinished = (*command208).isFinished;
				break;
			case(26):
				autoDumper(command209);

				autonomousInfo.isFinished = (*command209).isFinished;
				break;
			case(27):
				driveToWP(command210);
				timeout(command211);
				autonomousInfo.isFinished = (*command210).isFinished || (*command211).isFinished;
				break;
			case(28):
				driveToWP(command212);
				timeout(command213);
				autonomousInfo.isFinished = (*command212).isFinished || (*command213).isFinished;
				break;
			case(29):
				autoDumper(command214);

				autonomousInfo.isFinished = (*command214).isFinished;
				break;
			case(30):
				autoClaw(command215);

				autonomousInfo.isFinished = (*command215).isFinished;
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
				autoClaw(command216);

				autonomousInfo.isFinished = (*command216).isFinished;
				break;
			case(2):
				driveToWP(command217);
				autoDumper(command218);
				autonomousInfo.isFinished = (*command217).isFinished || (*command218).isFinished;
				break;
			case(3):
				driveToWP(command219);
				timeout(command220);
				autonomousInfo.isFinished = (*command219).isFinished || (*command220).isFinished;
				break;
			case(4):
				driveToWP(command221);

				autonomousInfo.isFinished = (*command221).isFinished;
				break;
			case(5):
				driveToWP(command222);

				autonomousInfo.isFinished = (*command222).isFinished;
				break;
			case(6):
				autoDumper(command223);

				autonomousInfo.isFinished = (*command223).isFinished;
				break;
			case(7):
				autoClaw(command224);

				autonomousInfo.isFinished = (*command224).isFinished;
				break;
			case(8):
				autoClaw(command225);

				autonomousInfo.isFinished = (*command225).isFinished;
				break;
			case(9):
				driveToWP(command226);
				timeout(command227);
				autonomousInfo.isFinished = (*command226).isFinished || (*command227).isFinished;
				break;
			case(10):
				autoClaw(command228);

				autonomousInfo.isFinished = (*command228).isFinished;
				break;
			case(11):
				timeout(command229);

				autonomousInfo.isFinished = (*command229).isFinished;
				break;
			case(12):
				autoDumper(command230);

				autonomousInfo.isFinished = (*command230).isFinished;
				break;
			case(13):
				driveToWP(command231);
				timeout(command232);
				autonomousInfo.isFinished = (*command231).isFinished || (*command232).isFinished;
				break;
			case(14):
				driveToWP(command233);

				autonomousInfo.isFinished = (*command233).isFinished;
				break;
			case(15):
				driveToWP(command234);
				timeout(command235);
				autonomousInfo.isFinished = (*command234).isFinished || (*command235).isFinished;
				break;
			case(16):
				autoDumper(command236);

				autonomousInfo.isFinished = (*command236).isFinished;
				break;
			case(17):
				autoClaw(command237);

				autonomousInfo.isFinished = (*command237).isFinished;
				break;
			case(18):
				timeout(command238);

				autonomousInfo.isFinished = (*command238).isFinished;
				break;
			case(19):
				autoDumper(command239);

				autonomousInfo.isFinished = (*command239).isFinished;
				break;
			case(20):
				autoClaw(command240);

				autonomousInfo.isFinished = (*command240).isFinished;
				break;
			case(21):
				timeout(command241);

				autonomousInfo.isFinished = (*command241).isFinished;
				break;
			case(22):
				driveToWP(command242);

				autonomousInfo.isFinished = (*command242).isFinished;
				break;
			case(23):
				autoClaw(command243);

				autonomousInfo.isFinished = (*command243).isFinished;
				break;
			case(24):
				timeout(command244);

				autonomousInfo.isFinished = (*command244).isFinished;
				break;
			case(25):
				autoDumper(command245);

				autonomousInfo.isFinished = (*command245).isFinished;
				break;
			case(26):
				driveToWP(command246);
				timeout(command247);
				autonomousInfo.isFinished = (*command246).isFinished || (*command247).isFinished;
				break;
			case(27):
				autoDumper(command248);

				autonomousInfo.isFinished = (*command248).isFinished;
				break;
			case(28):
				timeout(command249);

				autonomousInfo.isFinished = (*command249).isFinished;
				break;
			case(29):
				autoClaw(command250);

				autonomousInfo.isFinished = (*command250).isFinished;
				break;
			case(30):
				timeout(command251);

				autonomousInfo.isFinished = (*command251).isFinished;
				break;
			case(31):
				autoDumper(command252);

				autonomousInfo.isFinished = (*command252).isFinished;
				break;
			case(32):
				driveToWP(command253);
				timeout(command254);
				autonomousInfo.isFinished = (*command253).isFinished || (*command254).isFinished;
				break;
			case(33):
				autoClaw(command255);

				autonomousInfo.isFinished = (*command255).isFinished;
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
				autoClaw(command256);

				autonomousInfo.isFinished = (*command256).isFinished;
				break;
			case(2):
				autoClaw(command257);

				autonomousInfo.isFinished = (*command257).isFinished;
				break;
			case(3):
				driveToWP(command258);

				autonomousInfo.isFinished = (*command258).isFinished;
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

