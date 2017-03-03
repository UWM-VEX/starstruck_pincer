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

DriveToWP * command4;
DriveToWP * command5;
DriveToWP * command6;
AutoClaw * command7;

DriveToWP * command8;
AutoClaw * command9;

DriveToWP * command10;
DriveToWP * command11;
AutoClaw * command12;
Timeout * command13;

AutoDumper * command14;
DriveToWP * command15;
DriveToWP * command16;
Timeout * command17;

AutoDumper * command18;
AutoClaw * command19;
Timeout * command20;
DriveToWP * command21;
DriveToWP * command22;
AutoDumper * command23;

DriveToWP * command24;
DriveToWP * command25;
DriveToWP * command26;
AutoClaw * command27;
Timeout * command28;

DriveToWP * command29;
Timeout * command30;

DriveToWP * command31;
Timeout * command32;

DriveToWP * command33;
Timeout * command34;

AutoClaw * command35;
Timeout * command36;
DriveToWP * command37;
Timeout * command38;

AutoClaw * command39;
Timeout * command40;

AutoDumper * command41;
DriveToWP * command42;
DriveToWP * command43;
Timeout * command44;

AutoDumper * command45;
AutoClaw * command46;
Timeout * command47;

AutoClaw * command48;
DriveToWP * command49;
AutoDumper * command50;

DriveToWP * command51;
Timeout * command52;

DriveToWP * command53;
DriveToWP * command54;
AutoDumper * command55;
AutoClaw * command56;
Timeout * command57;

DriveToWP * command58;
Timeout * command59;

AutoClaw * command60;
Timeout * command61;
AutoDumper * command62;
DriveToWP * command63;
Timeout * command64;

DriveToWP * command65;
DriveToWP * command66;
Timeout * command67;

AutoDumper * command68;
AutoClaw * command69;
Timeout * command70;
AutoDumper * command71;
Timeout * command72;
AutoClaw * command73;
Timeout * command74;
DriveToWP * command75;
AutoDumper * command76;
DriveToWP * command77;
Timeout * command78;

DriveToWP * command79;
Timeout * command80;

AutoDumper * command81;
AutoClaw * command82;

DriveToWP * command83;
AutoDumper * command84;

DriveToWP * command85;
Timeout * command86;

DriveToWP * command87;
DriveToWP * command88;
AutoDumper * command89;
AutoClaw * command90;
Timeout * command91;

DriveToWP * command92;
Timeout * command93;

AutoClaw * command94;
Timeout * command95;
AutoDumper * command96;
DriveToWP * command97;
Timeout * command98;

DriveToWP * command99;
DriveToWP * command100;
Timeout * command101;

AutoDumper * command102;
AutoClaw * command103;
Timeout * command104;
AutoDumper * command105;
Timeout * command106;
DriveToWP * command107;
AutoClaw * command108;
Timeout * command109;
AutoDumper * command110;
DriveToWP * command111;
Timeout * command112;

AutoDumper * command113;
Timeout * command114;
AutoClaw * command115;
Timeout * command116;
AutoDumper * command117;
DriveToWP * command118;
Timeout * command119;

AutoClaw * command120;

DriveToWP * command121;
AutoDumper * command122;

DriveToWP * command123;
Timeout * command124;

DriveToWP * command125;
DriveToWP * command126;
AutoDumper * command127;
AutoClaw * command128;
Timeout * command129;

DriveToWP * command130;
Timeout * command131;

AutoClaw * command132;
Timeout * command133;
AutoDumper * command134;
DriveToWP * command135;
Timeout * command136;

DriveToWP * command137;
DriveToWP * command138;
Timeout * command139;

AutoDumper * command140;
AutoClaw * command141;
Timeout * command142;
AutoDumper * command143;
Timeout * command144;
DriveToWP * command145;
AutoDumper * command146;
AutoClaw * command147;
Timeout * command148;

DriveToWP * command149;
Timeout * command150;
DriveToWP * command151;
Timeout * command152;
AutoClaw * command153;
Timeout * command154;
AutoDumper * command155;
DriveToWP * command156;
Timeout * command157;
DriveToWP * command158;
Timeout * command159;

AutoDumper * command160;
AutoClaw * command161;
Timeout * command162;
AutoDumper * command163;

AutoClaw * command164;
DriveToWP * command165;
AutoDumper * command166;

DriveToWP * command167;
Timeout * command168;

AutoDumper * command169;
DriveToWP * command170;
Timeout * command171;

Timeout * command172;
DriveToWP * command173;
AutoClaw * command174;
Timeout * command175;

AutoDumper * command176;
DriveToWP * command177;
AutoClaw * command178;
Timeout * command179;
AutoDumper * command180;
DriveToWP * command181;
DriveToWP * command182;

DriveToWP * command183;
Timeout * command184;

AutoDumper * command185;
AutoClaw * command186;
Timeout * command187;
AutoDumper * command188;

AutoClaw * command189;
DriveToWP * command190;
AutoDumper * command191;

DriveToWP * command192;
Timeout * command193;

DriveToWP * command194;
DriveToWP * command195;
AutoDumper * command196;
AutoClaw * command197;
Timeout * command198;

DriveToWP * command199;
Timeout * command200;

AutoClaw * command201;
Timeout * command202;
AutoDumper * command203;
DriveToWP * command204;
Timeout * command205;

DriveToWP * command206;
DriveToWP * command207;
Timeout * command208;

AutoDumper * command209;
AutoClaw * command210;
Timeout * command211;
AutoDumper * command212;
Timeout * command213;
AutoClaw * command214;
Timeout * command215;
DriveToWP * command216;
AutoDumper * command217;
DriveToWP * command218;
Timeout * command219;

DriveToWP * command220;
Timeout * command221;

AutoDumper * command222;
AutoClaw * command223;

DriveToWP * command224;
AutoDumper * command225;

DriveToWP * command226;
Timeout * command227;

DriveToWP * command228;
DriveToWP * command229;
AutoDumper * command230;
AutoClaw * command231;
Timeout * command232;

DriveToWP * command233;
Timeout * command234;

AutoClaw * command235;
Timeout * command236;
AutoDumper * command237;
DriveToWP * command238;
Timeout * command239;

DriveToWP * command240;
DriveToWP * command241;
Timeout * command242;

AutoDumper * command243;
AutoClaw * command244;
Timeout * command245;
AutoDumper * command246;
AutoClaw * command247;
Timeout * command248;
DriveToWP * command249;
AutoClaw * command250;
Timeout * command251;
AutoDumper * command252;
DriveToWP * command253;
Timeout * command254;

AutoDumper * command255;
Timeout * command256;
AutoClaw * command257;
Timeout * command258;
AutoDumper * command259;
DriveToWP * command260;
Timeout * command261;

AutoClaw * command262;

AutoClaw * command263;
DriveToWP * command264;

DriveToWP * command265;
AutoClaw * command266;

DriveToWP * command267;
AutoDumper * command268;

Timeout * command269;
AutoClaw * command270;
Timeout * command271;

DriveToWP * command272;
AutoClaw * command273;
AutoDumper * command274;

Timeout * command275;
AutoDumper * command276;
DriveToWP * command277;

Timeout * command278;
AutoClaw * command279;
Timeout * command280;

DriveToWP * command281;
AutoClaw * command282;
AutoDumper * command283;

AutoDumper * command284;
Timeout * command285;
DriveToWP * command286;
DriveToWP * command287;
AutoDumper * command288;

DriveToWP * command289;
AutoClaw * command290;
Timeout * command291;

AutoDumper * command292;
DriveToWP * command293;

DriveToWP * command294;
DriveToWP * command295;
AutoClaw * command296;
AutoDumper * command297;

Timeout * command298;

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
			2, 40, 70, 35, 3, 0, 500); //ROT

	// START OF INSTANTIATIONS
if(autonomousSelection == DO_NOTHING)
{
}
if(autonomousSelection == MODE_1)
{
	command1 = initDriveToWP(defaultProps, 12, 0);
	command2 = initAutoClaw(robotClaw, CLAW_OPEN);
	command3 = initDriveToWP(defaultProps, 0, 90);

	command4 = initDriveToWP(defaultProps,36,0);
	command5 = initDriveToWP(defaultProps,0,-20);
	command6 = initDriveToWP(defaultProps,36,0);
	command7 = initAutoClaw(robotClaw, CLAW_CLOSE);
}
if(autonomousSelection == CUBE_FIRST)
{
	command8 = initDriveToWP(defaultProps,24,0);
	command9 = initAutoClaw(robotClaw, CLAW_OPEN);

	command10 = initDriveToWP(defaultProps,0,90);
	command11 = initDriveToWP(defaultProps,20,0);
	command12 = initAutoClaw(robotClaw,CLAW_CLOSE);
	command13 = initTimeout(1000);

	command14 = initAutoDumper(robotDumper,DUMPER_TRAVEL);
	command15 = initDriveToWP(defaultProps,0,90);
	command16 = initDriveToWP(defaultProps,-24,0);
	command17 = initTimeout(10000);

	command18 = initAutoDumper(robotDumper,DUMPER_HIGH);
	command19 = initAutoClaw(robotClaw, CLAW_OPEN);
	command20 = initTimeout(1000);
	command21 = initDriveToWP(defaultProps,18,0);
	command22 = initDriveToWP(defaultProps,0,90);
	command23 = initAutoDumper(robotDumper,DUMPER_LOW);

	command24 = initDriveToWP(defaultProps,-78,0);
	command25 = initDriveToWP(defaultProps,0,-90);
	command26 = initDriveToWP(defaultProps,12,0);
	command27 = initAutoClaw(robotClaw,CLAW_CLOSE);
	command28 = initTimeout(1000);

	command29 = initDriveToWP(defaultProps,0,90);
	command30 = initTimeout(10000);

	command31 = initDriveToWP(defaultProps,0,0);
	command32 = initTimeout(10000);

	command33 = initDriveToWP(defaultProps,0,-20);
	command34 = initTimeout(10000);

	command35 = initAutoClaw(robotClaw, CLAW_OPEN);
	command36 = initTimeout(1000);
	command37 = initDriveToWP(defaultProps,62,0);
	command38 = initTimeout(10000);

	command39 = initAutoClaw(robotClaw,CLAW_CLOSE);
	command40 = initTimeout(1000);

	command41 = initAutoDumper(robotDumper,DUMPER_TRAVEL);
	command42 = initDriveToWP(defaultProps,0,-90);
	command43 = initDriveToWP(defaultProps,-36,0);
	command44 = initTimeout(10000);

	command45 = initAutoDumper(robotDumper,DUMPER_HIGH);
	command46 = initAutoClaw(robotClaw, CLAW_OPEN);
	command47 = initTimeout(1000);
}
if(autonomousSelection == FENCE_1ST_L_1)
{
	command48 = initAutoClaw(robotClaw, CLAW_OPEN);
	command49 = initDriveToWP(defaultProps,20,0);
	command50 = initAutoDumper(robotDumper, DUMPER_FRONT_SIDE_FENCE);

	command51 = initDriveToWP(defaultProps,26,0);
	command52 = initTimeout(2500);

	command53 = initDriveToWP(defaultProps,-24,0);
	command54 = initDriveToWP(defaultProps,0,85);
	command55 = initAutoDumper(robotDumper, DUMPER_LOW);
	command56 = initAutoClaw(robotClaw, CLAW_OPEN);
	command57 = initTimeout(1500);

	command58 = initDriveToWP(defaultProps,26,0);
	command59 = initTimeout(5000);

	command60 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command61 = initTimeout(1000);
	command62 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command63 = initDriveToWP(defaultProps,8,0);
	command64 = initTimeout(2500);

	command65 = initDriveToWP(defaultProps,0,85);
	command66 = initDriveToWP(defaultProps,-34,0);
	command67 = initTimeout(2500);

	command68 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command69 = initAutoClaw(robotClaw, CLAW_OPEN);
	command70 = initTimeout(2500);
	command71 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command72 = initTimeout(2500);
	command73 = initAutoClaw(robotClaw,CLAW_OPEN);
	command74 = initTimeout(1000);
	command75 = initDriveToWP(defaultProps,20,0);
	command76 = initAutoDumper(robotDumper, DUMPER_MIDDLE_FENCE);
	command77 = initDriveToWP(defaultProps,-34,0);
	command78 = initTimeout(2500);

	command79 = initDriveToWP(defaultProps,16,0);
	command80 = initTimeout(2500);

	command81 = initAutoDumper(robotDumper, DUMPER_LOW);
	command82 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == FENCE_1ST_L_2)
{
	command83 = initDriveToWP(defaultProps,24,0);
	command84 = initAutoDumper(robotDumper, DUMPER_FRONT_SIDE_FENCE);

	command85 = initDriveToWP(defaultProps,26,0);
	command86 = initTimeout(2500);

	command87 = initDriveToWP(defaultProps,-24,0);
	command88 = initDriveToWP(defaultProps,0,85);
	command89 = initAutoDumper(robotDumper, DUMPER_LOW);
	command90 = initAutoClaw(robotClaw, CLAW_OPEN);
	command91 = initTimeout(1500);

	command92 = initDriveToWP(defaultProps,26,0);
	command93 = initTimeout(5000);

	command94 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command95 = initTimeout(2000);
	command96 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command97 = initDriveToWP(defaultProps,8,0);
	command98 = initTimeout(2500);

	command99 = initDriveToWP(defaultProps,0,85);
	command100 = initDriveToWP(defaultProps,-34,0);
	command101 = initTimeout(2500);

	command102 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command103 = initAutoClaw(robotClaw, CLAW_OPEN);
	command104 = initTimeout(2500);
	command105 = initAutoDumper(robotDumper, DUMPER_LOW);
	command106 = initTimeout(1000);
	command107 = initDriveToWP(defaultProps,20,0);
	command108 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command109 = initTimeout(2500);
	command110 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command111 = initDriveToWP(defaultProps,-30,0);
	command112 = initTimeout(2500);

	command113 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command114 = initTimeout(1000);
	command115 = initAutoClaw(robotClaw, CLAW_OPEN);
	command116 = initTimeout(1000);
	command117 = initAutoDumper(robotDumper, DUMPER_LOW);
	command118 = initDriveToWP(defaultProps,24,0);
	command119 = initTimeout(2500);

	command120 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == FENCE_1ST_L_3)
{
	command121 = initDriveToWP(defaultProps,24,0);
	command122 = initAutoDumper(robotDumper, DUMPER_FRONT_SIDE_FENCE);

	command123 = initDriveToWP(defaultProps,26,0);
	command124 = initTimeout(2500);

	command125 = initDriveToWP(defaultProps,-24,0);
	command126 = initDriveToWP(defaultProps,0,85);
	command127 = initAutoDumper(robotDumper, DUMPER_LOW);
	command128 = initAutoClaw(robotClaw, CLAW_OPEN);
	command129 = initTimeout(1500);

	command130 = initDriveToWP(defaultProps,20,0);
	command131 = initTimeout(5000);

	command132 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command133 = initTimeout(2000);
	command134 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command135 = initDriveToWP(defaultProps,44,0);
	command136 = initTimeout(5000);

	command137 = initDriveToWP(defaultProps,0,85);
	command138 = initDriveToWP(defaultProps,-26,0);
	command139 = initTimeout(5000);

	command140 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command141 = initAutoClaw(robotClaw, CLAW_OPEN);
	command142 = initTimeout(1000);
	command143 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command144 = initTimeout(1000);
	command145 = initDriveToWP(defaultProps, 12,0);
	command146 = initAutoDumper(robotDumper, DUMPER_LOW);
	command147 = initAutoClaw(robotClaw, CLAW_OPEN);
	command148 = initTimeout(2000);

	command149 = initDriveToWP(defaultProps,0,90);
	command150 = initTimeout(500);
	command151 = initDriveToWP(defaultProps,20,0);
	command152 = initTimeout(500);
	command153 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command154 = initTimeout(2000);
	command155 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command156 = initDriveToWP(defaultProps,0,-90);
	command157 = initTimeout(500);
	command158 = initDriveToWP(defaultProps,-26,0);
	command159 = initTimeout(2500);

	command160 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command161 = initAutoClaw(robotClaw, CLAW_OPEN);
	command162 = initTimeout(500);
	command163 = initAutoDumper(robotDumper,DUMPER_LOW);
}
if(autonomousSelection == FENCE_1ST_L_4)
{
	command164 = initAutoClaw(robotClaw, CLAW_OPEN);
	command165 = initDriveToWP(defaultProps,20,0);
	command166 = initAutoDumper(robotDumper, DUMPER_FRONT_SIDE_FENCE);

	command167 = initDriveToWP(defaultProps,26,0);
	command168 = initTimeout(2500);

	command169 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command170 = initDriveToWP(defaultProps,-36,0);
	command171 = initTimeout(2500);

	command172 = initTimeout(3000);
	command173 = initDriveToWP(defaultProps, 0,90);
	command174 = initAutoClaw(robotClaw, CLAW_OPEN);
	command175 = initTimeout(1500);

	command176 = initAutoDumper(robotDumper, DUMPER_LOW);
	command177 = initDriveToWP(defaultProps, 56,0);
	command178 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command179 = initTimeout(1500);
	command180 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command181 = initDriveToWP(defaultProps,0,0);
	command182 = initDriveToWP(defaultProps,0,90);

	command183 = initDriveToWP(defaultProps,-24,0);
	command184 = initTimeout(2500);

	command185 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command186 = initAutoClaw(robotClaw, CLAW_OPEN);
	command187 = initTimeout(1000);
	command188 = initAutoDumper(robotDumper, DUMPER_LOW);
}
if(autonomousSelection == FENCE_1ST_R_1)
{
	command189 = initAutoClaw(robotClaw, CLAW_OPEN);
	command190 = initDriveToWP(defaultProps,20,0);
	command191 = initAutoDumper(robotDumper, DUMPER_FRONT_SIDE_FENCE);

	command192 = initDriveToWP(defaultProps,22,0);
	command193 = initTimeout(2500);

	command194 = initDriveToWP(defaultProps,-24,0);
	command195 = initDriveToWP(defaultProps,0,-85);
	command196 = initAutoDumper(robotDumper, DUMPER_LOW);
	command197 = initAutoClaw(robotClaw, CLAW_OPEN);
	command198 = initTimeout(1500);

	command199 = initDriveToWP(defaultProps,26,0);
	command200 = initTimeout(5000);

	command201 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command202 = initTimeout(1000);
	command203 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command204 = initDriveToWP(defaultProps,8,0);
	command205 = initTimeout(2500);

	command206 = initDriveToWP(defaultProps,0,-85);
	command207 = initDriveToWP(defaultProps,-34,0);
	command208 = initTimeout(2500);

	command209 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command210 = initAutoClaw(robotClaw, CLAW_OPEN);
	command211 = initTimeout(2500);
	command212 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command213 = initTimeout(2500);
	command214 = initAutoClaw(robotClaw,CLAW_OPEN);
	command215 = initTimeout(1000);
	command216 = initDriveToWP(defaultProps,20,0);
	command217 = initAutoDumper(robotDumper, DUMPER_MIDDLE_FENCE);
	command218 = initDriveToWP(defaultProps,-34,0);
	command219 = initTimeout(2500);

	command220 = initDriveToWP(defaultProps,16,0);
	command221 = initTimeout(2500);

	command222 = initAutoDumper(robotDumper, DUMPER_LOW);
	command223 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == FENCE_1ST_R_2)
{
	command224 = initDriveToWP(defaultProps,24,0);
	command225 = initAutoDumper(robotDumper, DUMPER_FRONT_SIDE_FENCE);

	command226 = initDriveToWP(defaultProps,36,0);
	command227 = initTimeout(2500);

	command228 = initDriveToWP(defaultProps,-24,0);
	command229 = initDriveToWP(defaultProps,0,-90);
	command230 = initAutoDumper(robotDumper, DUMPER_LOW);
	command231 = initAutoClaw(robotClaw, CLAW_OPEN);
	command232 = initTimeout(1500);

	command233 = initDriveToWP(defaultProps,30,0);
	command234 = initTimeout(5000);

	command235 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command236 = initTimeout(2000);
	command237 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command238 = initDriveToWP(defaultProps,16,0);
	command239 = initTimeout(2500);

	command240 = initDriveToWP(defaultProps,0,-90);
	command241 = initDriveToWP(defaultProps,-34,0);
	command242 = initTimeout(2500);

	command243 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command244 = initAutoClaw(robotClaw, CLAW_OPEN);
	command245 = initTimeout(2500);
	command246 = initAutoDumper(robotDumper, DUMPER_LOW);
	command247 = initAutoClaw(robotClaw,CLAW_OPEN);
	command248 = initTimeout(1000);
	command249 = initDriveToWP(defaultProps,24,0);
	command250 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command251 = initTimeout(2500);
	command252 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command253 = initDriveToWP(defaultProps,-30,0);
	command254 = initTimeout(2500);

	command255 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command256 = initTimeout(1000);
	command257 = initAutoClaw(robotClaw, CLAW_OPEN);
	command258 = initTimeout(1000);
	command259 = initAutoDumper(robotDumper, DUMPER_LOW);
	command260 = initDriveToWP(defaultProps,24,0);
	command261 = initTimeout(2500);

	command262 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == TEST_AUTO)
{
	command263 = initAutoClaw(robotClaw, CLAW_OPEN);
	command264 = initDriveToWP(defaultProps, 24, 0);
}
if(autonomousSelection == SKILLS_L)
{
	command265 = initDriveToWP(defaultProps, -24,0);
	command266 = initAutoClaw(robotClaw, CLAW_OPEN);

	command267 = initDriveToWP(defaultProps, 12, 0);
	command268 = initAutoDumper(robotDumper, DUMPER_TRAVEL);

	command269 = initTimeout(1000);
	command270 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command271 = initTimeout(1000);

	command272 = initDriveToWP(defaultProps, -30, 0);
	command273 = initAutoClaw(robotClaw, CLAW_OPEN);
	command274 = initAutoDumper(robotDumper, DUMPER_HIGH);

	command275 = initTimeout(500);
	command276 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command277 = initDriveToWP(defaultProps, 30, 0);

	command278 = initTimeout(1000);
	command279 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command280 = initTimeout(1000);

	command281 = initDriveToWP(defaultProps, -30, 0);
	command282 = initAutoClaw(robotClaw, CLAW_OPEN);
	command283 = initAutoDumper(robotDumper, DUMPER_HIGH);

	command284 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command285 = initTimeout(500);
	command286 = initDriveToWP(defaultProps, 20, 0);
	command287 = initDriveToWP(defaultProps, 0, -90);
	command288 = initAutoDumper(robotDumper, DUMPER_LOW);

	command289 = initDriveToWP(defaultProps, 18, 0);
	command290 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command291 = initTimeout(2000);

	command292 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command293 = initDriveToWP(defaultProps, 48, 0);

	command294 = initDriveToWP(defaultProps, 0, 90);
	command295 = initDriveToWP(defaultProps, -20, 0);
	command296 = initAutoClaw(robotClaw, CLAW_OPEN);
	command297 = initAutoDumper(robotDumper, DUMPER_HIGH);

	command298 = initTimeout(500);
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
				driveToWP(command4);

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
				autoClaw(command7);

				autonomousInfo.isFinished = (*command7).isFinished;
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
				driveToWP(command8);
				autoClaw(command9);
				autonomousInfo.isFinished = (*command8).isFinished && (*command9).isFinished;
				break;
			case(2):
				driveToWP(command10);

				autonomousInfo.isFinished = (*command10).isFinished;
				break;
			case(3):
				driveToWP(command11);

				autonomousInfo.isFinished = (*command11).isFinished;
				break;
			case(4):
				autoClaw(command12);
				timeout(command13);
				autonomousInfo.isFinished = (*command12).isFinished && (*command13).isFinished;
				break;
			case(5):
				autoDumper(command14);

				autonomousInfo.isFinished = (*command14).isFinished;
				break;
			case(6):
				driveToWP(command15);

				autonomousInfo.isFinished = (*command15).isFinished;
				break;
			case(7):
				driveToWP(command16);
				timeout(command17);
				autonomousInfo.isFinished = (*command16).isFinished || (*command17).isFinished;
				break;
			case(8):
				autoDumper(command18);

				autonomousInfo.isFinished = (*command18).isFinished;
				break;
			case(9):
				autoClaw(command19);

				autonomousInfo.isFinished = (*command19).isFinished;
				break;
			case(10):
				timeout(command20);

				autonomousInfo.isFinished = (*command20).isFinished;
				break;
			case(11):
				driveToWP(command21);

				autonomousInfo.isFinished = (*command21).isFinished;
				break;
			case(12):
				driveToWP(command22);
				autoDumper(command23);
				autonomousInfo.isFinished = (*command22).isFinished && (*command23).isFinished;
				break;
			case(13):
				driveToWP(command24);

				autonomousInfo.isFinished = (*command24).isFinished;
				break;
			case(14):
				driveToWP(command25);

				autonomousInfo.isFinished = (*command25).isFinished;
				break;
			case(15):
				driveToWP(command26);

				autonomousInfo.isFinished = (*command26).isFinished;
				break;
			case(16):
				autoClaw(command27);
				timeout(command28);
				autonomousInfo.isFinished = (*command27).isFinished && (*command28).isFinished;
				break;
			case(17):
				driveToWP(command29);
				timeout(command30);
				autonomousInfo.isFinished = (*command29).isFinished || (*command30).isFinished;
				break;
			case(18):
				driveToWP(command31);
				timeout(command32);
				autonomousInfo.isFinished = (*command31).isFinished || (*command32).isFinished;
				break;
			case(19):
				driveToWP(command33);
				timeout(command34);
				autonomousInfo.isFinished = (*command33).isFinished || (*command34).isFinished;
				break;
			case(20):
				autoClaw(command35);

				autonomousInfo.isFinished = (*command35).isFinished;
				break;
			case(21):
				timeout(command36);

				autonomousInfo.isFinished = (*command36).isFinished;
				break;
			case(22):
				driveToWP(command37);
				timeout(command38);
				autonomousInfo.isFinished = (*command37).isFinished || (*command38).isFinished;
				break;
			case(23):
				autoClaw(command39);
				timeout(command40);
				autonomousInfo.isFinished = (*command39).isFinished && (*command40).isFinished;
				break;
			case(24):
				autoDumper(command41);

				autonomousInfo.isFinished = (*command41).isFinished;
				break;
			case(25):
				driveToWP(command42);

				autonomousInfo.isFinished = (*command42).isFinished;
				break;
			case(26):
				driveToWP(command43);
				timeout(command44);
				autonomousInfo.isFinished = (*command43).isFinished || (*command44).isFinished;
				break;
			case(27):
				autoDumper(command45);

				autonomousInfo.isFinished = (*command45).isFinished;
				break;
			case(28):
				autoClaw(command46);

				autonomousInfo.isFinished = (*command46).isFinished;
				break;
			case(29):
				timeout(command47);

				autonomousInfo.isFinished = (*command47).isFinished;
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
				autoClaw(command48);

				autonomousInfo.isFinished = (*command48).isFinished;
				break;
			case(2):
				driveToWP(command49);
				autoDumper(command50);
				autonomousInfo.isFinished = (*command49).isFinished || (*command50).isFinished;
				break;
			case(3):
				driveToWP(command51);
				timeout(command52);
				autonomousInfo.isFinished = (*command51).isFinished || (*command52).isFinished;
				break;
			case(4):
				driveToWP(command53);

				autonomousInfo.isFinished = (*command53).isFinished;
				break;
			case(5):
				driveToWP(command54);

				autonomousInfo.isFinished = (*command54).isFinished;
				break;
			case(6):
				autoDumper(command55);

				autonomousInfo.isFinished = (*command55).isFinished;
				break;
			case(7):
				autoClaw(command56);
				timeout(command57);
				autonomousInfo.isFinished = (*command56).isFinished && (*command57).isFinished;
				break;
			case(8):
				driveToWP(command58);
				timeout(command59);
				autonomousInfo.isFinished = (*command58).isFinished || (*command59).isFinished;
				break;
			case(9):
				autoClaw(command60);

				autonomousInfo.isFinished = (*command60).isFinished;
				break;
			case(10):
				timeout(command61);

				autonomousInfo.isFinished = (*command61).isFinished;
				break;
			case(11):
				autoDumper(command62);

				autonomousInfo.isFinished = (*command62).isFinished;
				break;
			case(12):
				driveToWP(command63);
				timeout(command64);
				autonomousInfo.isFinished = (*command63).isFinished || (*command64).isFinished;
				break;
			case(13):
				driveToWP(command65);

				autonomousInfo.isFinished = (*command65).isFinished;
				break;
			case(14):
				driveToWP(command66);
				timeout(command67);
				autonomousInfo.isFinished = (*command66).isFinished || (*command67).isFinished;
				break;
			case(15):
				autoDumper(command68);

				autonomousInfo.isFinished = (*command68).isFinished;
				break;
			case(16):
				autoClaw(command69);

				autonomousInfo.isFinished = (*command69).isFinished;
				break;
			case(17):
				timeout(command70);

				autonomousInfo.isFinished = (*command70).isFinished;
				break;
			case(18):
				autoDumper(command71);

				autonomousInfo.isFinished = (*command71).isFinished;
				break;
			case(19):
				timeout(command72);

				autonomousInfo.isFinished = (*command72).isFinished;
				break;
			case(20):
				autoClaw(command73);

				autonomousInfo.isFinished = (*command73).isFinished;
				break;
			case(21):
				timeout(command74);

				autonomousInfo.isFinished = (*command74).isFinished;
				break;
			case(22):
				driveToWP(command75);

				autonomousInfo.isFinished = (*command75).isFinished;
				break;
			case(23):
				autoDumper(command76);

				autonomousInfo.isFinished = (*command76).isFinished;
				break;
			case(24):
				driveToWP(command77);
				timeout(command78);
				autonomousInfo.isFinished = (*command77).isFinished || (*command78).isFinished;
				break;
			case(25):
				driveToWP(command79);
				timeout(command80);
				autonomousInfo.isFinished = (*command79).isFinished || (*command80).isFinished;
				break;
			case(26):
				autoDumper(command81);

				autonomousInfo.isFinished = (*command81).isFinished;
				break;
			case(27):
				autoClaw(command82);

				autonomousInfo.isFinished = (*command82).isFinished;
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
				driveToWP(command83);
				autoDumper(command84);
				autonomousInfo.isFinished = (*command83).isFinished || (*command84).isFinished;
				break;
			case(2):
				driveToWP(command85);
				timeout(command86);
				autonomousInfo.isFinished = (*command85).isFinished || (*command86).isFinished;
				break;
			case(3):
				driveToWP(command87);

				autonomousInfo.isFinished = (*command87).isFinished;
				break;
			case(4):
				driveToWP(command88);

				autonomousInfo.isFinished = (*command88).isFinished;
				break;
			case(5):
				autoDumper(command89);

				autonomousInfo.isFinished = (*command89).isFinished;
				break;
			case(6):
				autoClaw(command90);
				timeout(command91);
				autonomousInfo.isFinished = (*command90).isFinished && (*command91).isFinished;
				break;
			case(7):
				driveToWP(command92);
				timeout(command93);
				autonomousInfo.isFinished = (*command92).isFinished || (*command93).isFinished;
				break;
			case(8):
				autoClaw(command94);

				autonomousInfo.isFinished = (*command94).isFinished;
				break;
			case(9):
				timeout(command95);

				autonomousInfo.isFinished = (*command95).isFinished;
				break;
			case(10):
				autoDumper(command96);

				autonomousInfo.isFinished = (*command96).isFinished;
				break;
			case(11):
				driveToWP(command97);
				timeout(command98);
				autonomousInfo.isFinished = (*command97).isFinished || (*command98).isFinished;
				break;
			case(12):
				driveToWP(command99);

				autonomousInfo.isFinished = (*command99).isFinished;
				break;
			case(13):
				driveToWP(command100);
				timeout(command101);
				autonomousInfo.isFinished = (*command100).isFinished || (*command101).isFinished;
				break;
			case(14):
				autoDumper(command102);

				autonomousInfo.isFinished = (*command102).isFinished;
				break;
			case(15):
				autoClaw(command103);

				autonomousInfo.isFinished = (*command103).isFinished;
				break;
			case(16):
				timeout(command104);

				autonomousInfo.isFinished = (*command104).isFinished;
				break;
			case(17):
				autoDumper(command105);

				autonomousInfo.isFinished = (*command105).isFinished;
				break;
			case(18):
				timeout(command106);

				autonomousInfo.isFinished = (*command106).isFinished;
				break;
			case(19):
				driveToWP(command107);

				autonomousInfo.isFinished = (*command107).isFinished;
				break;
			case(20):
				autoClaw(command108);

				autonomousInfo.isFinished = (*command108).isFinished;
				break;
			case(21):
				timeout(command109);

				autonomousInfo.isFinished = (*command109).isFinished;
				break;
			case(22):
				autoDumper(command110);

				autonomousInfo.isFinished = (*command110).isFinished;
				break;
			case(23):
				driveToWP(command111);
				timeout(command112);
				autonomousInfo.isFinished = (*command111).isFinished || (*command112).isFinished;
				break;
			case(24):
				autoDumper(command113);

				autonomousInfo.isFinished = (*command113).isFinished;
				break;
			case(25):
				timeout(command114);

				autonomousInfo.isFinished = (*command114).isFinished;
				break;
			case(26):
				autoClaw(command115);

				autonomousInfo.isFinished = (*command115).isFinished;
				break;
			case(27):
				timeout(command116);

				autonomousInfo.isFinished = (*command116).isFinished;
				break;
			case(28):
				autoDumper(command117);

				autonomousInfo.isFinished = (*command117).isFinished;
				break;
			case(29):
				driveToWP(command118);
				timeout(command119);
				autonomousInfo.isFinished = (*command118).isFinished || (*command119).isFinished;
				break;
			case(30):
				autoClaw(command120);

				autonomousInfo.isFinished = (*command120).isFinished;
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
				driveToWP(command121);
				autoDumper(command122);
				autonomousInfo.isFinished = (*command121).isFinished || (*command122).isFinished;
				break;
			case(2):
				driveToWP(command123);
				timeout(command124);
				autonomousInfo.isFinished = (*command123).isFinished || (*command124).isFinished;
				break;
			case(3):
				driveToWP(command125);

				autonomousInfo.isFinished = (*command125).isFinished;
				break;
			case(4):
				driveToWP(command126);

				autonomousInfo.isFinished = (*command126).isFinished;
				break;
			case(5):
				autoDumper(command127);

				autonomousInfo.isFinished = (*command127).isFinished;
				break;
			case(6):
				autoClaw(command128);
				timeout(command129);
				autonomousInfo.isFinished = (*command128).isFinished && (*command129).isFinished;
				break;
			case(7):
				driveToWP(command130);
				timeout(command131);
				autonomousInfo.isFinished = (*command130).isFinished || (*command131).isFinished;
				break;
			case(8):
				autoClaw(command132);

				autonomousInfo.isFinished = (*command132).isFinished;
				break;
			case(9):
				timeout(command133);

				autonomousInfo.isFinished = (*command133).isFinished;
				break;
			case(10):
				autoDumper(command134);

				autonomousInfo.isFinished = (*command134).isFinished;
				break;
			case(11):
				driveToWP(command135);
				timeout(command136);
				autonomousInfo.isFinished = (*command135).isFinished || (*command136).isFinished;
				break;
			case(12):
				driveToWP(command137);

				autonomousInfo.isFinished = (*command137).isFinished;
				break;
			case(13):
				driveToWP(command138);
				timeout(command139);
				autonomousInfo.isFinished = (*command138).isFinished || (*command139).isFinished;
				break;
			case(14):
				autoDumper(command140);

				autonomousInfo.isFinished = (*command140).isFinished;
				break;
			case(15):
				autoClaw(command141);

				autonomousInfo.isFinished = (*command141).isFinished;
				break;
			case(16):
				timeout(command142);

				autonomousInfo.isFinished = (*command142).isFinished;
				break;
			case(17):
				autoDumper(command143);

				autonomousInfo.isFinished = (*command143).isFinished;
				break;
			case(18):
				timeout(command144);

				autonomousInfo.isFinished = (*command144).isFinished;
				break;
			case(19):
				driveToWP(command145);

				autonomousInfo.isFinished = (*command145).isFinished;
				break;
			case(20):
				autoDumper(command146);

				autonomousInfo.isFinished = (*command146).isFinished;
				break;
			case(21):
				autoClaw(command147);
				timeout(command148);
				autonomousInfo.isFinished = (*command147).isFinished && (*command148).isFinished;
				break;
			case(22):
				driveToWP(command149);

				autonomousInfo.isFinished = (*command149).isFinished;
				break;
			case(23):
				timeout(command150);

				autonomousInfo.isFinished = (*command150).isFinished;
				break;
			case(24):
				driveToWP(command151);

				autonomousInfo.isFinished = (*command151).isFinished;
				break;
			case(25):
				timeout(command152);

				autonomousInfo.isFinished = (*command152).isFinished;
				break;
			case(26):
				autoClaw(command153);

				autonomousInfo.isFinished = (*command153).isFinished;
				break;
			case(27):
				timeout(command154);

				autonomousInfo.isFinished = (*command154).isFinished;
				break;
			case(28):
				autoDumper(command155);

				autonomousInfo.isFinished = (*command155).isFinished;
				break;
			case(29):
				driveToWP(command156);

				autonomousInfo.isFinished = (*command156).isFinished;
				break;
			case(30):
				timeout(command157);

				autonomousInfo.isFinished = (*command157).isFinished;
				break;
			case(31):
				driveToWP(command158);
				timeout(command159);
				autonomousInfo.isFinished = (*command158).isFinished || (*command159).isFinished;
				break;
			case(32):
				autoDumper(command160);

				autonomousInfo.isFinished = (*command160).isFinished;
				break;
			case(33):
				autoClaw(command161);

				autonomousInfo.isFinished = (*command161).isFinished;
				break;
			case(34):
				timeout(command162);

				autonomousInfo.isFinished = (*command162).isFinished;
				break;
			case(35):
				autoDumper(command163);

				autonomousInfo.isFinished = (*command163).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(FENCE_1ST_L_4):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command164);

				autonomousInfo.isFinished = (*command164).isFinished;
				break;
			case(2):
				driveToWP(command165);
				autoDumper(command166);
				autonomousInfo.isFinished = (*command165).isFinished || (*command166).isFinished;
				break;
			case(3):
				driveToWP(command167);
				timeout(command168);
				autonomousInfo.isFinished = (*command167).isFinished || (*command168).isFinished;
				break;
			case(4):
				autoDumper(command169);

				autonomousInfo.isFinished = (*command169).isFinished;
				break;
			case(5):
				driveToWP(command170);
				timeout(command171);
				autonomousInfo.isFinished = (*command170).isFinished || (*command171).isFinished;
				break;
			case(6):
				timeout(command172);

				autonomousInfo.isFinished = (*command172).isFinished;
				break;
			case(7):
				driveToWP(command173);

				autonomousInfo.isFinished = (*command173).isFinished;
				break;
			case(8):
				autoClaw(command174);
				timeout(command175);
				autonomousInfo.isFinished = (*command174).isFinished && (*command175).isFinished;
				break;
			case(9):
				autoDumper(command176);

				autonomousInfo.isFinished = (*command176).isFinished;
				break;
			case(10):
				driveToWP(command177);

				autonomousInfo.isFinished = (*command177).isFinished;
				break;
			case(11):
				autoClaw(command178);

				autonomousInfo.isFinished = (*command178).isFinished;
				break;
			case(12):
				timeout(command179);

				autonomousInfo.isFinished = (*command179).isFinished;
				break;
			case(13):
				autoDumper(command180);

				autonomousInfo.isFinished = (*command180).isFinished;
				break;
			case(14):
				driveToWP(command181);
				driveToWP(command182);
				autonomousInfo.isFinished = (*command181).isFinished && (*command182).isFinished;
				break;
			case(15):
				driveToWP(command183);
				timeout(command184);
				autonomousInfo.isFinished = (*command183).isFinished || (*command184).isFinished;
				break;
			case(16):
				autoDumper(command185);

				autonomousInfo.isFinished = (*command185).isFinished;
				break;
			case(17):
				autoClaw(command186);

				autonomousInfo.isFinished = (*command186).isFinished;
				break;
			case(18):
				timeout(command187);

				autonomousInfo.isFinished = (*command187).isFinished;
				break;
			case(19):
				autoDumper(command188);

				autonomousInfo.isFinished = (*command188).isFinished;
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
				autoClaw(command189);

				autonomousInfo.isFinished = (*command189).isFinished;
				break;
			case(2):
				driveToWP(command190);
				autoDumper(command191);
				autonomousInfo.isFinished = (*command190).isFinished || (*command191).isFinished;
				break;
			case(3):
				driveToWP(command192);
				timeout(command193);
				autonomousInfo.isFinished = (*command192).isFinished || (*command193).isFinished;
				break;
			case(4):
				driveToWP(command194);

				autonomousInfo.isFinished = (*command194).isFinished;
				break;
			case(5):
				driveToWP(command195);

				autonomousInfo.isFinished = (*command195).isFinished;
				break;
			case(6):
				autoDumper(command196);

				autonomousInfo.isFinished = (*command196).isFinished;
				break;
			case(7):
				autoClaw(command197);
				timeout(command198);
				autonomousInfo.isFinished = (*command197).isFinished && (*command198).isFinished;
				break;
			case(8):
				driveToWP(command199);
				timeout(command200);
				autonomousInfo.isFinished = (*command199).isFinished || (*command200).isFinished;
				break;
			case(9):
				autoClaw(command201);

				autonomousInfo.isFinished = (*command201).isFinished;
				break;
			case(10):
				timeout(command202);

				autonomousInfo.isFinished = (*command202).isFinished;
				break;
			case(11):
				autoDumper(command203);

				autonomousInfo.isFinished = (*command203).isFinished;
				break;
			case(12):
				driveToWP(command204);
				timeout(command205);
				autonomousInfo.isFinished = (*command204).isFinished || (*command205).isFinished;
				break;
			case(13):
				driveToWP(command206);

				autonomousInfo.isFinished = (*command206).isFinished;
				break;
			case(14):
				driveToWP(command207);
				timeout(command208);
				autonomousInfo.isFinished = (*command207).isFinished || (*command208).isFinished;
				break;
			case(15):
				autoDumper(command209);

				autonomousInfo.isFinished = (*command209).isFinished;
				break;
			case(16):
				autoClaw(command210);

				autonomousInfo.isFinished = (*command210).isFinished;
				break;
			case(17):
				timeout(command211);

				autonomousInfo.isFinished = (*command211).isFinished;
				break;
			case(18):
				autoDumper(command212);

				autonomousInfo.isFinished = (*command212).isFinished;
				break;
			case(19):
				timeout(command213);

				autonomousInfo.isFinished = (*command213).isFinished;
				break;
			case(20):
				autoClaw(command214);

				autonomousInfo.isFinished = (*command214).isFinished;
				break;
			case(21):
				timeout(command215);

				autonomousInfo.isFinished = (*command215).isFinished;
				break;
			case(22):
				driveToWP(command216);

				autonomousInfo.isFinished = (*command216).isFinished;
				break;
			case(23):
				autoDumper(command217);

				autonomousInfo.isFinished = (*command217).isFinished;
				break;
			case(24):
				driveToWP(command218);
				timeout(command219);
				autonomousInfo.isFinished = (*command218).isFinished || (*command219).isFinished;
				break;
			case(25):
				driveToWP(command220);
				timeout(command221);
				autonomousInfo.isFinished = (*command220).isFinished || (*command221).isFinished;
				break;
			case(26):
				autoDumper(command222);

				autonomousInfo.isFinished = (*command222).isFinished;
				break;
			case(27):
				autoClaw(command223);

				autonomousInfo.isFinished = (*command223).isFinished;
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
				driveToWP(command224);
				autoDumper(command225);
				autonomousInfo.isFinished = (*command224).isFinished || (*command225).isFinished;
				break;
			case(2):
				driveToWP(command226);
				timeout(command227);
				autonomousInfo.isFinished = (*command226).isFinished || (*command227).isFinished;
				break;
			case(3):
				driveToWP(command228);

				autonomousInfo.isFinished = (*command228).isFinished;
				break;
			case(4):
				driveToWP(command229);

				autonomousInfo.isFinished = (*command229).isFinished;
				break;
			case(5):
				autoDumper(command230);

				autonomousInfo.isFinished = (*command230).isFinished;
				break;
			case(6):
				autoClaw(command231);
				timeout(command232);
				autonomousInfo.isFinished = (*command231).isFinished && (*command232).isFinished;
				break;
			case(7):
				driveToWP(command233);
				timeout(command234);
				autonomousInfo.isFinished = (*command233).isFinished || (*command234).isFinished;
				break;
			case(8):
				autoClaw(command235);

				autonomousInfo.isFinished = (*command235).isFinished;
				break;
			case(9):
				timeout(command236);

				autonomousInfo.isFinished = (*command236).isFinished;
				break;
			case(10):
				autoDumper(command237);

				autonomousInfo.isFinished = (*command237).isFinished;
				break;
			case(11):
				driveToWP(command238);
				timeout(command239);
				autonomousInfo.isFinished = (*command238).isFinished || (*command239).isFinished;
				break;
			case(12):
				driveToWP(command240);

				autonomousInfo.isFinished = (*command240).isFinished;
				break;
			case(13):
				driveToWP(command241);
				timeout(command242);
				autonomousInfo.isFinished = (*command241).isFinished || (*command242).isFinished;
				break;
			case(14):
				autoDumper(command243);

				autonomousInfo.isFinished = (*command243).isFinished;
				break;
			case(15):
				autoClaw(command244);

				autonomousInfo.isFinished = (*command244).isFinished;
				break;
			case(16):
				timeout(command245);

				autonomousInfo.isFinished = (*command245).isFinished;
				break;
			case(17):
				autoDumper(command246);

				autonomousInfo.isFinished = (*command246).isFinished;
				break;
			case(18):
				autoClaw(command247);

				autonomousInfo.isFinished = (*command247).isFinished;
				break;
			case(19):
				timeout(command248);

				autonomousInfo.isFinished = (*command248).isFinished;
				break;
			case(20):
				driveToWP(command249);

				autonomousInfo.isFinished = (*command249).isFinished;
				break;
			case(21):
				autoClaw(command250);

				autonomousInfo.isFinished = (*command250).isFinished;
				break;
			case(22):
				timeout(command251);

				autonomousInfo.isFinished = (*command251).isFinished;
				break;
			case(23):
				autoDumper(command252);

				autonomousInfo.isFinished = (*command252).isFinished;
				break;
			case(24):
				driveToWP(command253);
				timeout(command254);
				autonomousInfo.isFinished = (*command253).isFinished || (*command254).isFinished;
				break;
			case(25):
				autoDumper(command255);

				autonomousInfo.isFinished = (*command255).isFinished;
				break;
			case(26):
				timeout(command256);

				autonomousInfo.isFinished = (*command256).isFinished;
				break;
			case(27):
				autoClaw(command257);

				autonomousInfo.isFinished = (*command257).isFinished;
				break;
			case(28):
				timeout(command258);

				autonomousInfo.isFinished = (*command258).isFinished;
				break;
			case(29):
				autoDumper(command259);

				autonomousInfo.isFinished = (*command259).isFinished;
				break;
			case(30):
				driveToWP(command260);
				timeout(command261);
				autonomousInfo.isFinished = (*command260).isFinished || (*command261).isFinished;
				break;
			case(31):
				autoClaw(command262);

				autonomousInfo.isFinished = (*command262).isFinished;
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
				autoClaw(command263);

				autonomousInfo.isFinished = (*command263).isFinished;
				break;
			case(2):
				driveToWP(command264);

				autonomousInfo.isFinished = (*command264).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(SKILLS_L):
		switch(autonomousInfo.step)
		{
			case(1):
				driveToWP(command265);
				autoClaw(command266);
				autonomousInfo.isFinished = (*command265).isFinished && (*command266).isFinished;
				break;
			case(2):
				driveToWP(command267);
				autoDumper(command268);
				autonomousInfo.isFinished = (*command267).isFinished && (*command268).isFinished;
				break;
			case(3):
				timeout(command269);

				autonomousInfo.isFinished = (*command269).isFinished;
				break;
			case(4):
				autoClaw(command270);
				timeout(command271);
				autonomousInfo.isFinished = (*command270).isFinished && (*command271).isFinished;
				break;
			case(5):
				driveToWP(command272);

				autonomousInfo.isFinished = (*command272).isFinished;
				break;
			case(6):
				autoClaw(command273);
				autoDumper(command274);
				autonomousInfo.isFinished = (*command273).isFinished && (*command274).isFinished;
				break;
			case(7):
				timeout(command275);

				autonomousInfo.isFinished = (*command275).isFinished;
				break;
			case(8):
				autoDumper(command276);
				driveToWP(command277);
				autonomousInfo.isFinished = (*command276).isFinished && (*command277).isFinished;
				break;
			case(9):
				timeout(command278);

				autonomousInfo.isFinished = (*command278).isFinished;
				break;
			case(10):
				autoClaw(command279);
				timeout(command280);
				autonomousInfo.isFinished = (*command279).isFinished && (*command280).isFinished;
				break;
			case(11):
				driveToWP(command281);

				autonomousInfo.isFinished = (*command281).isFinished;
				break;
			case(12):
				autoClaw(command282);
				autoDumper(command283);
				autonomousInfo.isFinished = (*command282).isFinished && (*command283).isFinished;
				break;
			case(13):
				autoDumper(command284);

				autonomousInfo.isFinished = (*command284).isFinished;
				break;
			case(14):
				timeout(command285);

				autonomousInfo.isFinished = (*command285).isFinished;
				break;
			case(15):
				driveToWP(command286);

				autonomousInfo.isFinished = (*command286).isFinished;
				break;
			case(16):
				driveToWP(command287);
				autoDumper(command288);
				autonomousInfo.isFinished = (*command287).isFinished && (*command288).isFinished;
				break;
			case(17):
				driveToWP(command289);

				autonomousInfo.isFinished = (*command289).isFinished;
				break;
			case(18):
				autoClaw(command290);
				timeout(command291);
				autonomousInfo.isFinished = (*command290).isFinished && (*command291).isFinished;
				break;
			case(19):
				autoDumper(command292);
				driveToWP(command293);
				autonomousInfo.isFinished = (*command292).isFinished && (*command293).isFinished;
				break;
			case(20):
				driveToWP(command294);

				autonomousInfo.isFinished = (*command294).isFinished;
				break;
			case(21):
				driveToWP(command295);

				autonomousInfo.isFinished = (*command295).isFinished;
				break;
			case(22):
				autoClaw(command296);
				autoDumper(command297);
				autonomousInfo.isFinished = (*command296).isFinished && (*command297).isFinished;
				break;
			case(23):
				timeout(command298);

				autonomousInfo.isFinished = (*command298).isFinished;
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

