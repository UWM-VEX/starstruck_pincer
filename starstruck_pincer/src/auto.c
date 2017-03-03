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
AutoClaw * command10;

DriveToWP * command11;
DriveToWP * command12;
AutoClaw * command13;
Timeout * command14;

AutoDumper * command15;
DriveToWP * command16;
DriveToWP * command17;
Timeout * command18;

AutoDumper * command19;
AutoClaw * command20;
AutoClaw * command21;
Timeout * command22;

DriveToWP * command23;
DriveToWP * command24;
AutoDumper * command25;

DriveToWP * command26;
DriveToWP * command27;
DriveToWP * command28;
AutoClaw * command29;
Timeout * command30;

DriveToWP * command31;
Timeout * command32;

DriveToWP * command33;
Timeout * command34;

DriveToWP * command35;
Timeout * command36;

AutoClaw * command37;
AutoClaw * command38;
Timeout * command39;

DriveToWP * command40;
Timeout * command41;

AutoClaw * command42;
Timeout * command43;

AutoDumper * command44;
DriveToWP * command45;
DriveToWP * command46;
Timeout * command47;

AutoDumper * command48;
AutoClaw * command49;
AutoClaw * command50;
Timeout * command51;


AutoClaw * command52;
DriveToWP * command53;
AutoDumper * command54;

DriveToWP * command55;
Timeout * command56;

DriveToWP * command57;
DriveToWP * command58;
AutoDumper * command59;
AutoClaw * command60;
Timeout * command61;

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
Timeout * command99;

AutoClaw * command100;
DriveToWP * command101;
Timeout * command102;

AutoClaw * command103;
Timeout * command104;
AutoDumper * command105;
DriveToWP * command106;
Timeout * command107;

DriveToWP * command108;
DriveToWP * command109;
Timeout * command110;

AutoDumper * command111;
AutoClaw * command112;
Timeout * command113;
AutoDumper * command114;
AutoClaw * command115;
Timeout * command116;
DriveToWP * command117;
AutoClaw * command118;
Timeout * command119;
AutoDumper * command120;
DriveToWP * command121;
Timeout * command122;

AutoDumper * command123;
Timeout * command124;
AutoClaw * command125;
Timeout * command126;
AutoDumper * command127;
DriveToWP * command128;
Timeout * command129;

AutoClaw * command130;

AutoClaw * command131;
DriveToWP * command132;
AutoDumper * command133;

DriveToWP * command134;
Timeout * command135;

DriveToWP * command136;
DriveToWP * command137;
AutoDumper * command138;
AutoClaw * command139;
Timeout * command140;

AutoClaw * command141;
DriveToWP * command142;
Timeout * command143;

AutoClaw * command144;
Timeout * command145;
AutoDumper * command146;
DriveToWP * command147;
Timeout * command148;

DriveToWP * command149;
DriveToWP * command150;
Timeout * command151;

AutoDumper * command152;
AutoClaw * command153;
Timeout * command154;
AutoDumper * command155;
Timeout * command156;
DriveToWP * command157;
AutoDumper * command158;
AutoClaw * command159;
Timeout * command160;

AutoClaw * command161;
DriveToWP * command162;
Timeout * command163;
DriveToWP * command164;
Timeout * command165;
AutoClaw * command166;
Timeout * command167;
AutoDumper * command168;
DriveToWP * command169;
Timeout * command170;
DriveToWP * command171;
Timeout * command172;

AutoDumper * command173;
AutoClaw * command174;
Timeout * command175;
AutoDumper * command176;

AutoClaw * command177;
DriveToWP * command178;
AutoDumper * command179;

DriveToWP * command180;
Timeout * command181;

AutoDumper * command182;
DriveToWP * command183;
Timeout * command184;

Timeout * command185;
DriveToWP * command186;
AutoClaw * command187;
Timeout * command188;

AutoDumper * command189;
DriveToWP * command190;
AutoClaw * command191;
Timeout * command192;
AutoDumper * command193;
DriveToWP * command194;
DriveToWP * command195;

DriveToWP * command196;
Timeout * command197;

AutoDumper * command198;
AutoClaw * command199;
Timeout * command200;
AutoDumper * command201;

AutoClaw * command202;
DriveToWP * command203;
AutoDumper * command204;

DriveToWP * command205;
Timeout * command206;

DriveToWP * command207;
DriveToWP * command208;
AutoDumper * command209;
AutoClaw * command210;
Timeout * command211;

AutoClaw * command212;
DriveToWP * command213;
Timeout * command214;

AutoClaw * command215;
Timeout * command216;
AutoDumper * command217;
DriveToWP * command218;
Timeout * command219;

DriveToWP * command220;
DriveToWP * command221;
Timeout * command222;

AutoDumper * command223;
AutoClaw * command224;
Timeout * command225;
AutoDumper * command226;
Timeout * command227;
AutoClaw * command228;
AutoClaw * command229;
Timeout * command230;
DriveToWP * command231;
AutoClaw * command232;
AutoDumper * command233;
DriveToWP * command234;
Timeout * command235;

DriveToWP * command236;
Timeout * command237;

AutoDumper * command238;
AutoClaw * command239;

AutoClaw * command240;
DriveToWP * command241;
AutoDumper * command242;

DriveToWP * command243;
Timeout * command244;

DriveToWP * command245;
DriveToWP * command246;
AutoDumper * command247;
AutoClaw * command248;
Timeout * command249;

AutoClaw * command250;
DriveToWP * command251;
Timeout * command252;

AutoClaw * command253;
Timeout * command254;
AutoDumper * command255;
DriveToWP * command256;
Timeout * command257;

DriveToWP * command258;
DriveToWP * command259;
Timeout * command260;

AutoDumper * command261;
AutoClaw * command262;
Timeout * command263;
AutoDumper * command264;
AutoClaw * command265;
Timeout * command266;
DriveToWP * command267;
AutoClaw * command268;
Timeout * command269;
AutoDumper * command270;
DriveToWP * command271;
Timeout * command272;

AutoDumper * command273;
Timeout * command274;
AutoClaw * command275;
Timeout * command276;
AutoDumper * command277;
DriveToWP * command278;
Timeout * command279;

AutoClaw * command280;

AutoClaw * command281;
AutoClaw * command282;
DriveToWP * command283;

DriveToWP * command284;
AutoClaw * command285;

DriveToWP * command286;
AutoDumper * command287;

Timeout * command288;
AutoClaw * command289;
Timeout * command290;

DriveToWP * command291;
AutoClaw * command292;
AutoDumper * command293;

AutoClaw * command294;
Timeout * command295;
AutoDumper * command296;
DriveToWP * command297;

Timeout * command298;
AutoClaw * command299;
Timeout * command300;

DriveToWP * command301;
AutoClaw * command302;
AutoDumper * command303;

AutoClaw * command304;
AutoDumper * command305;
Timeout * command306;
DriveToWP * command307;
DriveToWP * command308;
AutoDumper * command309;

DriveToWP * command310;
AutoClaw * command311;
Timeout * command312;

AutoDumper * command313;
DriveToWP * command314;

DriveToWP * command315;
DriveToWP * command316;
AutoClaw * command317;
AutoDumper * command318;

AutoClaw * command319;
Timeout * command320;

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
	command2 = initAutoClaw(robotClaw, CLAW_FIRST_OPEN);
	command3 = initDriveToWP(defaultProps, 0, 90);

	command4 = initAutoClaw(robotClaw, CLAW_STOP);
	command5 = initDriveToWP(defaultProps,36,0);
	command6 = initDriveToWP(defaultProps,0,-20);
	command7 = initDriveToWP(defaultProps,36,0);
	command8 = initAutoClaw(robotClaw, CLAW_CLOSE);
}
if(autonomousSelection == CUBE_FIRST)
{
	command9 = initDriveToWP(defaultProps,24,0);
	command10 = initAutoClaw(robotClaw, CLAW_FIRST_OPEN);

	command11 = initDriveToWP(defaultProps,0,90);
	command12 = initDriveToWP(defaultProps,20,0);
	command13 = initAutoClaw(robotClaw,CLAW_CLOSE);
	command14 = initTimeout(1000);

	command15 = initAutoDumper(robotDumper,DUMPER_TRAVEL);
	command16 = initDriveToWP(defaultProps,0,90);
	command17 = initDriveToWP(defaultProps,-24,0);
	command18 = initTimeout(10000);

	command19 = initAutoDumper(robotDumper,DUMPER_HIGH);
	command20 = initAutoClaw(robotClaw, CLAW_OPEN);
	command21 = initAutoClaw(robotClaw, CLAW_STOP);
	command22 = initTimeout(1000);

	command23 = initDriveToWP(defaultProps,18,0);
	command24 = initDriveToWP(defaultProps,0,90);
	command25 = initAutoDumper(robotDumper,DUMPER_LOW);

	command26 = initDriveToWP(defaultProps,-78,0);
	command27 = initDriveToWP(defaultProps,0,-90);
	command28 = initDriveToWP(defaultProps,12,0);
	command29 = initAutoClaw(robotClaw,CLAW_CLOSE);
	command30 = initTimeout(1000);

	command31 = initDriveToWP(defaultProps,0,90);
	command32 = initTimeout(10000);

	command33 = initDriveToWP(defaultProps,0,0);
	command34 = initTimeout(10000);

	command35 = initDriveToWP(defaultProps,0,-20);
	command36 = initTimeout(10000);

	command37 = initAutoClaw(robotClaw, CLAW_OPEN);
	command38 = initAutoClaw(robotClaw, CLAW_STOP);
	command39 = initTimeout(1000);

	command40 = initDriveToWP(defaultProps,62,0);
	command41 = initTimeout(10000);

	command42 = initAutoClaw(robotClaw,CLAW_CLOSE);
	command43 = initTimeout(1000);

	command44 = initAutoDumper(robotDumper,DUMPER_TRAVEL);
	command45 = initDriveToWP(defaultProps,0,-90);
	command46 = initDriveToWP(defaultProps,-36,0);
	command47 = initTimeout(10000);

	command48 = initAutoDumper(robotDumper,DUMPER_HIGH);
	command49 = initAutoClaw(robotClaw, CLAW_OPEN);
	command50 = initAutoClaw(robotClaw, CLAW_STOP);
	command51 = initTimeout(1000);

}
if(autonomousSelection == FENCE_1ST_L_1)
{
	command52 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command53 = initDriveToWP(defaultProps,20,0);
	command54 = initAutoDumper(robotDumper, DUMPER_FRONT_SIDE_FENCE);

	command55 = initDriveToWP(defaultProps,26,0);
	command56 = initTimeout(2500);

	command57 = initDriveToWP(defaultProps,-24,0);
	command58 = initDriveToWP(defaultProps,0,85);
	command59 = initAutoDumper(robotDumper, DUMPER_LOW);
	command60 = initAutoClaw(robotClaw, CLAW_OPEN);
	command61 = initTimeout(1500);

	command62 = initAutoClaw(robotClaw, CLAW_STOP);
	command63 = initDriveToWP(defaultProps,26,0);
	command64 = initTimeout(5000);

	command65 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command66 = initTimeout(1000);
	command67 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command68 = initDriveToWP(defaultProps,8,0);
	command69 = initTimeout(2500);

	command70 = initDriveToWP(defaultProps,0,85);
	command71 = initDriveToWP(defaultProps,-34,0);
	command72 = initTimeout(2500);

	command73 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command74 = initAutoClaw(robotClaw, CLAW_OPEN);
	command75 = initTimeout(2500);
	command76 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command77 = initTimeout(2500);
	command78 = initAutoClaw(robotClaw,CLAW_OPEN);
	command79 = initAutoClaw(robotClaw,CLAW_STOP);
	command80 = initTimeout(1000);
	command81 = initDriveToWP(defaultProps,20,0);
	command82 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command83 = initAutoDumper(robotDumper, DUMPER_MIDDLE_FENCE);
	command84 = initDriveToWP(defaultProps,-34,0);
	command85 = initTimeout(2500);

	command86 = initDriveToWP(defaultProps,16,0);
	command87 = initTimeout(2500);

	command88 = initAutoDumper(robotDumper, DUMPER_LOW);
	command89 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == FENCE_1ST_L_2)
{
	command90 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command91 = initDriveToWP(defaultProps,24,0);
	command92 = initAutoDumper(robotDumper, DUMPER_FRONT_SIDE_FENCE);

	command93 = initDriveToWP(defaultProps,26,0);
	command94 = initTimeout(2500);

	command95 = initDriveToWP(defaultProps,-24,0);
	command96 = initDriveToWP(defaultProps,0,85);
	command97 = initAutoDumper(robotDumper, DUMPER_LOW);
	command98 = initAutoClaw(robotClaw, CLAW_OPEN);
	command99 = initTimeout(1500);

	command100 = initAutoClaw(robotClaw, CLAW_STOP);
	command101 = initDriveToWP(defaultProps,26,0);
	command102 = initTimeout(5000);

	command103 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command104 = initTimeout(2000);
	command105 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command106 = initDriveToWP(defaultProps,8,0);
	command107 = initTimeout(2500);

	command108 = initDriveToWP(defaultProps,0,85);
	command109 = initDriveToWP(defaultProps,-34,0);
	command110 = initTimeout(2500);

	command111 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command112 = initAutoClaw(robotClaw, CLAW_OPEN);
	command113 = initTimeout(2500);
	command114 = initAutoDumper(robotDumper, DUMPER_LOW);
	command115 = initAutoClaw(robotClaw,CLAW_FULL_OPEN);
	command116 = initTimeout(1000);
	command117 = initDriveToWP(defaultProps,20,0);
	command118 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command119 = initTimeout(2500);
	command120 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command121 = initDriveToWP(defaultProps,-30,0);
	command122 = initTimeout(2500);

	command123 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command124 = initTimeout(1000);
	command125 = initAutoClaw(robotClaw, CLAW_OPEN);
	command126 = initTimeout(1000);
	command127 = initAutoDumper(robotDumper, DUMPER_LOW);
	command128 = initDriveToWP(defaultProps,24,0);
	command129 = initTimeout(2500);

	command130 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == FENCE_1ST_L_3)
{
	command131 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command132 = initDriveToWP(defaultProps,24,0);
	command133 = initAutoDumper(robotDumper, DUMPER_FRONT_SIDE_FENCE);

	command134 = initDriveToWP(defaultProps,26,0);
	command135 = initTimeout(2500);

	command136 = initDriveToWP(defaultProps,-24,0);
	command137 = initDriveToWP(defaultProps,0,85);
	command138 = initAutoDumper(robotDumper, DUMPER_LOW);
	command139 = initAutoClaw(robotClaw, CLAW_OPEN);
	command140 = initTimeout(1500);

	command141 = initAutoClaw(robotClaw, CLAW_STOP);
	command142 = initDriveToWP(defaultProps,20,0);
	command143 = initTimeout(5000);

	command144 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command145 = initTimeout(2000);
	command146 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command147 = initDriveToWP(defaultProps,44,0);
	command148 = initTimeout(5000);

	command149 = initDriveToWP(defaultProps,0,85);
	command150 = initDriveToWP(defaultProps,-26,0);
	command151 = initTimeout(5000);

	command152 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command153 = initAutoClaw(robotClaw, CLAW_OPEN);
	command154 = initTimeout(1000);
	command155 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command156 = initTimeout(1000);
	command157 = initDriveToWP(defaultProps, 12,0);
	command158 = initAutoDumper(robotDumper, DUMPER_LOW);
	command159 = initAutoClaw(robotClaw, CLAW_OPEN);
	command160 = initTimeout(2000);

	command161 = initAutoClaw(robotClaw, CLAW_STOP);
	command162 = initDriveToWP(defaultProps,0,90);
	command163 = initTimeout(500);
	command164 = initDriveToWP(defaultProps,20,0);
	command165 = initTimeout(500);
	command166 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command167 = initTimeout(2000);
	command168 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command169 = initDriveToWP(defaultProps,0,-90);
	command170 = initTimeout(500);
	command171 = initDriveToWP(defaultProps,-26,0);
	command172 = initTimeout(2500);

	command173 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command174 = initAutoClaw(robotClaw, CLAW_OPEN);
	command175 = initTimeout(500);
	command176 = initAutoDumper(robotDumper,DUMPER_LOW);
}
if(autonomousSelection == FENCE_1ST_L_4)
{
	command177 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command178 = initDriveToWP(defaultProps,20,0);
	command179 = initAutoDumper(robotDumper, DUMPER_FRONT_SIDE_FENCE);

	command180 = initDriveToWP(defaultProps,26,0);
	command181 = initTimeout(2500);

	command182 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command183 = initDriveToWP(defaultProps,-36,0);
	command184 = initTimeout(2500);

	command185 = initTimeout(3000);
	command186 = initDriveToWP(defaultProps, 0,90);
	command187 = initAutoClaw(robotClaw, CLAW_OPEN);
	command188 = initTimeout(1500);

	command189 = initAutoDumper(robotDumper, DUMPER_LOW);
	command190 = initDriveToWP(defaultProps, 56,0);
	command191 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command192 = initTimeout(1500);
	command193 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command194 = initDriveToWP(defaultProps,0,0);
	command195 = initDriveToWP(defaultProps,0,90);

	command196 = initDriveToWP(defaultProps,-24,0);
	command197 = initTimeout(2500);

	command198 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command199 = initAutoClaw(robotClaw, CLAW_OPEN);
	command200 = initTimeout(1000);
	command201 = initAutoDumper(robotDumper, DUMPER_LOW);
}
if(autonomousSelection == FENCE_1ST_R_1)
{
	command202 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command203 = initDriveToWP(defaultProps,20,0);
	command204 = initAutoDumper(robotDumper, DUMPER_FRONT_SIDE_FENCE);

	command205 = initDriveToWP(defaultProps,22,0);
	command206 = initTimeout(2500);

	command207 = initDriveToWP(defaultProps,-24,0);
	command208 = initDriveToWP(defaultProps,0,-85);
	command209 = initAutoDumper(robotDumper, DUMPER_LOW);
	command210 = initAutoClaw(robotClaw, CLAW_OPEN);
	command211 = initTimeout(1500);

	command212 = initAutoClaw(robotClaw, CLAW_STOP);
	command213 = initDriveToWP(defaultProps,26,0);
	command214 = initTimeout(5000);

	command215 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command216 = initTimeout(1000);
	command217 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command218 = initDriveToWP(defaultProps,8,0);
	command219 = initTimeout(2500);

	command220 = initDriveToWP(defaultProps,0,-85);
	command221 = initDriveToWP(defaultProps,-34,0);
	command222 = initTimeout(2500);

	command223 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command224 = initAutoClaw(robotClaw, CLAW_OPEN);
	command225 = initTimeout(2500);
	command226 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command227 = initTimeout(2500);
	command228 = initAutoClaw(robotClaw,CLAW_OPEN);
	command229 = initAutoClaw(robotClaw,CLAW_STOP);
	command230 = initTimeout(1000);
	command231 = initDriveToWP(defaultProps,20,0);
	command232 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command233 = initAutoDumper(robotDumper, DUMPER_MIDDLE_FENCE);
	command234 = initDriveToWP(defaultProps,-34,0);
	command235 = initTimeout(2500);

	command236 = initDriveToWP(defaultProps,16,0);
	command237 = initTimeout(2500);

	command238 = initAutoDumper(robotDumper, DUMPER_LOW);
	command239 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == FENCE_1ST_R_2)
{
	command240 = initAutoClaw(robotClaw, CLAW_FULL_OPEN);
	command241 = initDriveToWP(defaultProps,24,0);
	command242 = initAutoDumper(robotDumper, DUMPER_FRONT_SIDE_FENCE);

	command243 = initDriveToWP(defaultProps,36,0);
	command244 = initTimeout(2500);

	command245 = initDriveToWP(defaultProps,-24,0);
	command246 = initDriveToWP(defaultProps,0,-90);
	command247 = initAutoDumper(robotDumper, DUMPER_LOW);
	command248 = initAutoClaw(robotClaw, CLAW_OPEN);
	command249 = initTimeout(1500);

	command250 = initAutoClaw(robotClaw, CLAW_STOP);
	command251 = initDriveToWP(defaultProps,30,0);
	command252 = initTimeout(5000);

	command253 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command254 = initTimeout(2000);
	command255 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command256 = initDriveToWP(defaultProps,16,0);
	command257 = initTimeout(2500);

	command258 = initDriveToWP(defaultProps,0,-90);
	command259 = initDriveToWP(defaultProps,-34,0);
	command260 = initTimeout(2500);

	command261 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command262 = initAutoClaw(robotClaw, CLAW_OPEN);
	command263 = initTimeout(2500);
	command264 = initAutoDumper(robotDumper, DUMPER_LOW);
	command265 = initAutoClaw(robotClaw,CLAW_FULL_OPEN);
	command266 = initTimeout(1000);
	command267 = initDriveToWP(defaultProps,24,0);
	command268 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command269 = initTimeout(2500);
	command270 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command271 = initDriveToWP(defaultProps,-30,0);
	command272 = initTimeout(2500);

	command273 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command274 = initTimeout(1000);
	command275 = initAutoClaw(robotClaw, CLAW_OPEN);
	command276 = initTimeout(1000);
	command277 = initAutoDumper(robotDumper, DUMPER_LOW);
	command278 = initDriveToWP(defaultProps,24,0);
	command279 = initTimeout(2500);

	command280 = initAutoClaw(robotClaw, CLAW_OPEN);
}
if(autonomousSelection == TEST_AUTO)
{
	command281 = initAutoClaw(robotClaw, CLAW_FIRST_OPEN);
	command282 = initAutoClaw(robotClaw, CLAW_STOP);
	command283 = initDriveToWP(defaultProps, 24, 0);
}
if(autonomousSelection == SKILLS_L)
{
	command284 = initDriveToWP(defaultProps, -24,0);
	command285 = initAutoClaw(robotClaw, CLAW_FIRST_OPEN);

	command286 = initDriveToWP(defaultProps, 12, 0);
	command287 = initAutoDumper(robotDumper, DUMPER_TRAVEL);

	command288 = initTimeout(1000);
	command289 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command290 = initTimeout(1000);

	command291 = initDriveToWP(defaultProps, -30, 0);
	command292 = initAutoClaw(robotClaw, CLAW_OPEN);
	command293 = initAutoDumper(robotDumper, DUMPER_HIGH);

	command294 = initAutoClaw(robotClaw, CLAW_STOP);
	command295 = initTimeout(500);
	command296 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command297 = initDriveToWP(defaultProps, 30, 0);

	command298 = initTimeout(1000);
	command299 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command300 = initTimeout(1000);

	command301 = initDriveToWP(defaultProps, -30, 0);
	command302 = initAutoClaw(robotClaw, CLAW_OPEN);
	command303 = initAutoDumper(robotDumper, DUMPER_HIGH);

	command304 = initAutoClaw(robotClaw, CLAW_STOP);
	command305 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command306 = initTimeout(500);
	command307 = initDriveToWP(defaultProps, 20, 0);
	command308 = initDriveToWP(defaultProps, 0, -90);
	command309 = initAutoDumper(robotDumper, DUMPER_LOW);

	command310 = initDriveToWP(defaultProps, 18, 0);
	command311 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command312 = initTimeout(2000);

	command313 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command314 = initDriveToWP(defaultProps, 48, 0);

	command315 = initDriveToWP(defaultProps, 0, 90);
	command316 = initDriveToWP(defaultProps, -20, 0);
	command317 = initAutoClaw(robotClaw, CLAW_OPEN);
	command318 = initAutoDumper(robotDumper, DUMPER_HIGH);

	command319 = initAutoClaw(robotClaw, CLAW_STOP);
	command320 = initTimeout(500);
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


			default:
				isAuto = 0;
				break;
		}
		break;
		case(CUBE_FIRST):
		switch(autonomousInfo.step)
		{
			case(1):
				driveToWP(command9);
				autoClaw(command10);
				autonomousInfo.isFinished = (*command9).isFinished && (*command10).isFinished;
				break;
			case(2):
				driveToWP(command11);

				autonomousInfo.isFinished = (*command11).isFinished;
				break;
			case(3):
				driveToWP(command12);

				autonomousInfo.isFinished = (*command12).isFinished;
				break;
			case(4):
				autoClaw(command13);
				timeout(command14);
				autonomousInfo.isFinished = (*command13).isFinished && (*command14).isFinished;
				break;
			case(5):
				autoDumper(command15);

				autonomousInfo.isFinished = (*command15).isFinished;
				break;
			case(6):
				driveToWP(command16);

				autonomousInfo.isFinished = (*command16).isFinished;
				break;
			case(7):
				driveToWP(command17);
				timeout(command18);
				autonomousInfo.isFinished = (*command17).isFinished || (*command18).isFinished;
				break;
			case(8):
				autoDumper(command19);

				autonomousInfo.isFinished = (*command19).isFinished;
				break;
			case(9):
				autoClaw(command20);

				autonomousInfo.isFinished = (*command20).isFinished;
				break;
			case(10):
				autoClaw(command21);
				timeout(command22);
				autonomousInfo.isFinished = (*command21).isFinished && (*command22).isFinished;
				break;
			case(11):
				driveToWP(command23);

				autonomousInfo.isFinished = (*command23).isFinished;
				break;
			case(12):
				driveToWP(command24);
				autoDumper(command25);
				autonomousInfo.isFinished = (*command24).isFinished && (*command25).isFinished;
				break;
			case(13):
				driveToWP(command26);

				autonomousInfo.isFinished = (*command26).isFinished;
				break;
			case(14):
				driveToWP(command27);

				autonomousInfo.isFinished = (*command27).isFinished;
				break;
			case(15):
				driveToWP(command28);

				autonomousInfo.isFinished = (*command28).isFinished;
				break;
			case(16):
				autoClaw(command29);
				timeout(command30);
				autonomousInfo.isFinished = (*command29).isFinished && (*command30).isFinished;
				break;
			case(17):
				driveToWP(command31);
				timeout(command32);
				autonomousInfo.isFinished = (*command31).isFinished || (*command32).isFinished;
				break;
			case(18):
				driveToWP(command33);
				timeout(command34);
				autonomousInfo.isFinished = (*command33).isFinished || (*command34).isFinished;
				break;
			case(19):
				driveToWP(command35);
				timeout(command36);
				autonomousInfo.isFinished = (*command35).isFinished || (*command36).isFinished;
				break;
			case(20):
				autoClaw(command37);

				autonomousInfo.isFinished = (*command37).isFinished;
				break;
			case(21):
				autoClaw(command38);
				timeout(command39);
				autonomousInfo.isFinished = (*command38).isFinished && (*command39).isFinished;
				break;
			case(22):
				driveToWP(command40);
				timeout(command41);
				autonomousInfo.isFinished = (*command40).isFinished || (*command41).isFinished;
				break;
			case(23):
				autoClaw(command42);
				timeout(command43);
				autonomousInfo.isFinished = (*command42).isFinished && (*command43).isFinished;
				break;
			case(24):
				autoDumper(command44);

				autonomousInfo.isFinished = (*command44).isFinished;
				break;
			case(25):
				driveToWP(command45);

				autonomousInfo.isFinished = (*command45).isFinished;
				break;
			case(26):
				driveToWP(command46);
				timeout(command47);
				autonomousInfo.isFinished = (*command46).isFinished || (*command47).isFinished;
				break;
			case(27):
				autoDumper(command48);

				autonomousInfo.isFinished = (*command48).isFinished;
				break;
			case(28):
				autoClaw(command49);

				autonomousInfo.isFinished = (*command49).isFinished;
				break;
			case(29):
				autoClaw(command50);
				timeout(command51);
				autonomousInfo.isFinished = (*command50).isFinished && (*command51).isFinished;
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
				autoClaw(command52);

				autonomousInfo.isFinished = (*command52).isFinished;
				break;
			case(2):
				driveToWP(command53);
				autoDumper(command54);
				autonomousInfo.isFinished = (*command53).isFinished || (*command54).isFinished;
				break;
			case(3):
				driveToWP(command55);
				timeout(command56);
				autonomousInfo.isFinished = (*command55).isFinished || (*command56).isFinished;
				break;
			case(4):
				driveToWP(command57);

				autonomousInfo.isFinished = (*command57).isFinished;
				break;
			case(5):
				driveToWP(command58);

				autonomousInfo.isFinished = (*command58).isFinished;
				break;
			case(6):
				autoDumper(command59);

				autonomousInfo.isFinished = (*command59).isFinished;
				break;
			case(7):
				autoClaw(command60);
				timeout(command61);
				autonomousInfo.isFinished = (*command60).isFinished && (*command61).isFinished;
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
				timeout(command99);
				autonomousInfo.isFinished = (*command98).isFinished && (*command99).isFinished;
				break;
			case(8):
				autoClaw(command100);

				autonomousInfo.isFinished = (*command100).isFinished;
				break;
			case(9):
				driveToWP(command101);
				timeout(command102);
				autonomousInfo.isFinished = (*command101).isFinished || (*command102).isFinished;
				break;
			case(10):
				autoClaw(command103);

				autonomousInfo.isFinished = (*command103).isFinished;
				break;
			case(11):
				timeout(command104);

				autonomousInfo.isFinished = (*command104).isFinished;
				break;
			case(12):
				autoDumper(command105);

				autonomousInfo.isFinished = (*command105).isFinished;
				break;
			case(13):
				driveToWP(command106);
				timeout(command107);
				autonomousInfo.isFinished = (*command106).isFinished || (*command107).isFinished;
				break;
			case(14):
				driveToWP(command108);

				autonomousInfo.isFinished = (*command108).isFinished;
				break;
			case(15):
				driveToWP(command109);
				timeout(command110);
				autonomousInfo.isFinished = (*command109).isFinished || (*command110).isFinished;
				break;
			case(16):
				autoDumper(command111);

				autonomousInfo.isFinished = (*command111).isFinished;
				break;
			case(17):
				autoClaw(command112);

				autonomousInfo.isFinished = (*command112).isFinished;
				break;
			case(18):
				timeout(command113);

				autonomousInfo.isFinished = (*command113).isFinished;
				break;
			case(19):
				autoDumper(command114);

				autonomousInfo.isFinished = (*command114).isFinished;
				break;
			case(20):
				autoClaw(command115);

				autonomousInfo.isFinished = (*command115).isFinished;
				break;
			case(21):
				timeout(command116);

				autonomousInfo.isFinished = (*command116).isFinished;
				break;
			case(22):
				driveToWP(command117);

				autonomousInfo.isFinished = (*command117).isFinished;
				break;
			case(23):
				autoClaw(command118);

				autonomousInfo.isFinished = (*command118).isFinished;
				break;
			case(24):
				timeout(command119);

				autonomousInfo.isFinished = (*command119).isFinished;
				break;
			case(25):
				autoDumper(command120);

				autonomousInfo.isFinished = (*command120).isFinished;
				break;
			case(26):
				driveToWP(command121);
				timeout(command122);
				autonomousInfo.isFinished = (*command121).isFinished || (*command122).isFinished;
				break;
			case(27):
				autoDumper(command123);

				autonomousInfo.isFinished = (*command123).isFinished;
				break;
			case(28):
				timeout(command124);

				autonomousInfo.isFinished = (*command124).isFinished;
				break;
			case(29):
				autoClaw(command125);

				autonomousInfo.isFinished = (*command125).isFinished;
				break;
			case(30):
				timeout(command126);

				autonomousInfo.isFinished = (*command126).isFinished;
				break;
			case(31):
				autoDumper(command127);

				autonomousInfo.isFinished = (*command127).isFinished;
				break;
			case(32):
				driveToWP(command128);
				timeout(command129);
				autonomousInfo.isFinished = (*command128).isFinished || (*command129).isFinished;
				break;
			case(33):
				autoClaw(command130);

				autonomousInfo.isFinished = (*command130).isFinished;
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
				autoClaw(command131);

				autonomousInfo.isFinished = (*command131).isFinished;
				break;
			case(2):
				driveToWP(command132);
				autoDumper(command133);
				autonomousInfo.isFinished = (*command132).isFinished || (*command133).isFinished;
				break;
			case(3):
				driveToWP(command134);
				timeout(command135);
				autonomousInfo.isFinished = (*command134).isFinished || (*command135).isFinished;
				break;
			case(4):
				driveToWP(command136);

				autonomousInfo.isFinished = (*command136).isFinished;
				break;
			case(5):
				driveToWP(command137);

				autonomousInfo.isFinished = (*command137).isFinished;
				break;
			case(6):
				autoDumper(command138);

				autonomousInfo.isFinished = (*command138).isFinished;
				break;
			case(7):
				autoClaw(command139);
				timeout(command140);
				autonomousInfo.isFinished = (*command139).isFinished && (*command140).isFinished;
				break;
			case(8):
				autoClaw(command141);

				autonomousInfo.isFinished = (*command141).isFinished;
				break;
			case(9):
				driveToWP(command142);
				timeout(command143);
				autonomousInfo.isFinished = (*command142).isFinished || (*command143).isFinished;
				break;
			case(10):
				autoClaw(command144);

				autonomousInfo.isFinished = (*command144).isFinished;
				break;
			case(11):
				timeout(command145);

				autonomousInfo.isFinished = (*command145).isFinished;
				break;
			case(12):
				autoDumper(command146);

				autonomousInfo.isFinished = (*command146).isFinished;
				break;
			case(13):
				driveToWP(command147);
				timeout(command148);
				autonomousInfo.isFinished = (*command147).isFinished || (*command148).isFinished;
				break;
			case(14):
				driveToWP(command149);

				autonomousInfo.isFinished = (*command149).isFinished;
				break;
			case(15):
				driveToWP(command150);
				timeout(command151);
				autonomousInfo.isFinished = (*command150).isFinished || (*command151).isFinished;
				break;
			case(16):
				autoDumper(command152);

				autonomousInfo.isFinished = (*command152).isFinished;
				break;
			case(17):
				autoClaw(command153);

				autonomousInfo.isFinished = (*command153).isFinished;
				break;
			case(18):
				timeout(command154);

				autonomousInfo.isFinished = (*command154).isFinished;
				break;
			case(19):
				autoDumper(command155);

				autonomousInfo.isFinished = (*command155).isFinished;
				break;
			case(20):
				timeout(command156);

				autonomousInfo.isFinished = (*command156).isFinished;
				break;
			case(21):
				driveToWP(command157);

				autonomousInfo.isFinished = (*command157).isFinished;
				break;
			case(22):
				autoDumper(command158);

				autonomousInfo.isFinished = (*command158).isFinished;
				break;
			case(23):
				autoClaw(command159);
				timeout(command160);
				autonomousInfo.isFinished = (*command159).isFinished && (*command160).isFinished;
				break;
			case(24):
				autoClaw(command161);

				autonomousInfo.isFinished = (*command161).isFinished;
				break;
			case(25):
				driveToWP(command162);

				autonomousInfo.isFinished = (*command162).isFinished;
				break;
			case(26):
				timeout(command163);

				autonomousInfo.isFinished = (*command163).isFinished;
				break;
			case(27):
				driveToWP(command164);

				autonomousInfo.isFinished = (*command164).isFinished;
				break;
			case(28):
				timeout(command165);

				autonomousInfo.isFinished = (*command165).isFinished;
				break;
			case(29):
				autoClaw(command166);

				autonomousInfo.isFinished = (*command166).isFinished;
				break;
			case(30):
				timeout(command167);

				autonomousInfo.isFinished = (*command167).isFinished;
				break;
			case(31):
				autoDumper(command168);

				autonomousInfo.isFinished = (*command168).isFinished;
				break;
			case(32):
				driveToWP(command169);

				autonomousInfo.isFinished = (*command169).isFinished;
				break;
			case(33):
				timeout(command170);

				autonomousInfo.isFinished = (*command170).isFinished;
				break;
			case(34):
				driveToWP(command171);
				timeout(command172);
				autonomousInfo.isFinished = (*command171).isFinished || (*command172).isFinished;
				break;
			case(35):
				autoDumper(command173);

				autonomousInfo.isFinished = (*command173).isFinished;
				break;
			case(36):
				autoClaw(command174);

				autonomousInfo.isFinished = (*command174).isFinished;
				break;
			case(37):
				timeout(command175);

				autonomousInfo.isFinished = (*command175).isFinished;
				break;
			case(38):
				autoDumper(command176);

				autonomousInfo.isFinished = (*command176).isFinished;
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
				autoClaw(command177);

				autonomousInfo.isFinished = (*command177).isFinished;
				break;
			case(2):
				driveToWP(command178);
				autoDumper(command179);
				autonomousInfo.isFinished = (*command178).isFinished || (*command179).isFinished;
				break;
			case(3):
				driveToWP(command180);
				timeout(command181);
				autonomousInfo.isFinished = (*command180).isFinished || (*command181).isFinished;
				break;
			case(4):
				autoDumper(command182);

				autonomousInfo.isFinished = (*command182).isFinished;
				break;
			case(5):
				driveToWP(command183);
				timeout(command184);
				autonomousInfo.isFinished = (*command183).isFinished || (*command184).isFinished;
				break;
			case(6):
				timeout(command185);

				autonomousInfo.isFinished = (*command185).isFinished;
				break;
			case(7):
				driveToWP(command186);

				autonomousInfo.isFinished = (*command186).isFinished;
				break;
			case(8):
				autoClaw(command187);
				timeout(command188);
				autonomousInfo.isFinished = (*command187).isFinished && (*command188).isFinished;
				break;
			case(9):
				autoDumper(command189);

				autonomousInfo.isFinished = (*command189).isFinished;
				break;
			case(10):
				driveToWP(command190);

				autonomousInfo.isFinished = (*command190).isFinished;
				break;
			case(11):
				autoClaw(command191);

				autonomousInfo.isFinished = (*command191).isFinished;
				break;
			case(12):
				timeout(command192);

				autonomousInfo.isFinished = (*command192).isFinished;
				break;
			case(13):
				autoDumper(command193);

				autonomousInfo.isFinished = (*command193).isFinished;
				break;
			case(14):
				driveToWP(command194);
				driveToWP(command195);
				autonomousInfo.isFinished = (*command194).isFinished && (*command195).isFinished;
				break;
			case(15):
				driveToWP(command196);
				timeout(command197);
				autonomousInfo.isFinished = (*command196).isFinished || (*command197).isFinished;
				break;
			case(16):
				autoDumper(command198);

				autonomousInfo.isFinished = (*command198).isFinished;
				break;
			case(17):
				autoClaw(command199);

				autonomousInfo.isFinished = (*command199).isFinished;
				break;
			case(18):
				timeout(command200);

				autonomousInfo.isFinished = (*command200).isFinished;
				break;
			case(19):
				autoDumper(command201);

				autonomousInfo.isFinished = (*command201).isFinished;
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
				autoClaw(command202);

				autonomousInfo.isFinished = (*command202).isFinished;
				break;
			case(2):
				driveToWP(command203);
				autoDumper(command204);
				autonomousInfo.isFinished = (*command203).isFinished || (*command204).isFinished;
				break;
			case(3):
				driveToWP(command205);
				timeout(command206);
				autonomousInfo.isFinished = (*command205).isFinished || (*command206).isFinished;
				break;
			case(4):
				driveToWP(command207);

				autonomousInfo.isFinished = (*command207).isFinished;
				break;
			case(5):
				driveToWP(command208);

				autonomousInfo.isFinished = (*command208).isFinished;
				break;
			case(6):
				autoDumper(command209);

				autonomousInfo.isFinished = (*command209).isFinished;
				break;
			case(7):
				autoClaw(command210);
				timeout(command211);
				autonomousInfo.isFinished = (*command210).isFinished && (*command211).isFinished;
				break;
			case(8):
				autoClaw(command212);

				autonomousInfo.isFinished = (*command212).isFinished;
				break;
			case(9):
				driveToWP(command213);
				timeout(command214);
				autonomousInfo.isFinished = (*command213).isFinished || (*command214).isFinished;
				break;
			case(10):
				autoClaw(command215);

				autonomousInfo.isFinished = (*command215).isFinished;
				break;
			case(11):
				timeout(command216);

				autonomousInfo.isFinished = (*command216).isFinished;
				break;
			case(12):
				autoDumper(command217);

				autonomousInfo.isFinished = (*command217).isFinished;
				break;
			case(13):
				driveToWP(command218);
				timeout(command219);
				autonomousInfo.isFinished = (*command218).isFinished || (*command219).isFinished;
				break;
			case(14):
				driveToWP(command220);

				autonomousInfo.isFinished = (*command220).isFinished;
				break;
			case(15):
				driveToWP(command221);
				timeout(command222);
				autonomousInfo.isFinished = (*command221).isFinished || (*command222).isFinished;
				break;
			case(16):
				autoDumper(command223);

				autonomousInfo.isFinished = (*command223).isFinished;
				break;
			case(17):
				autoClaw(command224);

				autonomousInfo.isFinished = (*command224).isFinished;
				break;
			case(18):
				timeout(command225);

				autonomousInfo.isFinished = (*command225).isFinished;
				break;
			case(19):
				autoDumper(command226);

				autonomousInfo.isFinished = (*command226).isFinished;
				break;
			case(20):
				timeout(command227);

				autonomousInfo.isFinished = (*command227).isFinished;
				break;
			case(21):
				autoClaw(command228);

				autonomousInfo.isFinished = (*command228).isFinished;
				break;
			case(22):
				autoClaw(command229);

				autonomousInfo.isFinished = (*command229).isFinished;
				break;
			case(23):
				timeout(command230);

				autonomousInfo.isFinished = (*command230).isFinished;
				break;
			case(24):
				driveToWP(command231);

				autonomousInfo.isFinished = (*command231).isFinished;
				break;
			case(25):
				autoClaw(command232);

				autonomousInfo.isFinished = (*command232).isFinished;
				break;
			case(26):
				autoDumper(command233);

				autonomousInfo.isFinished = (*command233).isFinished;
				break;
			case(27):
				driveToWP(command234);
				timeout(command235);
				autonomousInfo.isFinished = (*command234).isFinished || (*command235).isFinished;
				break;
			case(28):
				driveToWP(command236);
				timeout(command237);
				autonomousInfo.isFinished = (*command236).isFinished || (*command237).isFinished;
				break;
			case(29):
				autoDumper(command238);

				autonomousInfo.isFinished = (*command238).isFinished;
				break;
			case(30):
				autoClaw(command239);

				autonomousInfo.isFinished = (*command239).isFinished;
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
				autoClaw(command240);

				autonomousInfo.isFinished = (*command240).isFinished;
				break;
			case(2):
				driveToWP(command241);
				autoDumper(command242);
				autonomousInfo.isFinished = (*command241).isFinished || (*command242).isFinished;
				break;
			case(3):
				driveToWP(command243);
				timeout(command244);
				autonomousInfo.isFinished = (*command243).isFinished || (*command244).isFinished;
				break;
			case(4):
				driveToWP(command245);

				autonomousInfo.isFinished = (*command245).isFinished;
				break;
			case(5):
				driveToWP(command246);

				autonomousInfo.isFinished = (*command246).isFinished;
				break;
			case(6):
				autoDumper(command247);

				autonomousInfo.isFinished = (*command247).isFinished;
				break;
			case(7):
				autoClaw(command248);
				timeout(command249);
				autonomousInfo.isFinished = (*command248).isFinished && (*command249).isFinished;
				break;
			case(8):
				autoClaw(command250);

				autonomousInfo.isFinished = (*command250).isFinished;
				break;
			case(9):
				driveToWP(command251);
				timeout(command252);
				autonomousInfo.isFinished = (*command251).isFinished || (*command252).isFinished;
				break;
			case(10):
				autoClaw(command253);

				autonomousInfo.isFinished = (*command253).isFinished;
				break;
			case(11):
				timeout(command254);

				autonomousInfo.isFinished = (*command254).isFinished;
				break;
			case(12):
				autoDumper(command255);

				autonomousInfo.isFinished = (*command255).isFinished;
				break;
			case(13):
				driveToWP(command256);
				timeout(command257);
				autonomousInfo.isFinished = (*command256).isFinished || (*command257).isFinished;
				break;
			case(14):
				driveToWP(command258);

				autonomousInfo.isFinished = (*command258).isFinished;
				break;
			case(15):
				driveToWP(command259);
				timeout(command260);
				autonomousInfo.isFinished = (*command259).isFinished || (*command260).isFinished;
				break;
			case(16):
				autoDumper(command261);

				autonomousInfo.isFinished = (*command261).isFinished;
				break;
			case(17):
				autoClaw(command262);

				autonomousInfo.isFinished = (*command262).isFinished;
				break;
			case(18):
				timeout(command263);

				autonomousInfo.isFinished = (*command263).isFinished;
				break;
			case(19):
				autoDumper(command264);

				autonomousInfo.isFinished = (*command264).isFinished;
				break;
			case(20):
				autoClaw(command265);

				autonomousInfo.isFinished = (*command265).isFinished;
				break;
			case(21):
				timeout(command266);

				autonomousInfo.isFinished = (*command266).isFinished;
				break;
			case(22):
				driveToWP(command267);

				autonomousInfo.isFinished = (*command267).isFinished;
				break;
			case(23):
				autoClaw(command268);

				autonomousInfo.isFinished = (*command268).isFinished;
				break;
			case(24):
				timeout(command269);

				autonomousInfo.isFinished = (*command269).isFinished;
				break;
			case(25):
				autoDumper(command270);

				autonomousInfo.isFinished = (*command270).isFinished;
				break;
			case(26):
				driveToWP(command271);
				timeout(command272);
				autonomousInfo.isFinished = (*command271).isFinished || (*command272).isFinished;
				break;
			case(27):
				autoDumper(command273);

				autonomousInfo.isFinished = (*command273).isFinished;
				break;
			case(28):
				timeout(command274);

				autonomousInfo.isFinished = (*command274).isFinished;
				break;
			case(29):
				autoClaw(command275);

				autonomousInfo.isFinished = (*command275).isFinished;
				break;
			case(30):
				timeout(command276);

				autonomousInfo.isFinished = (*command276).isFinished;
				break;
			case(31):
				autoDumper(command277);

				autonomousInfo.isFinished = (*command277).isFinished;
				break;
			case(32):
				driveToWP(command278);
				timeout(command279);
				autonomousInfo.isFinished = (*command278).isFinished || (*command279).isFinished;
				break;
			case(33):
				autoClaw(command280);

				autonomousInfo.isFinished = (*command280).isFinished;
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
				autoClaw(command281);

				autonomousInfo.isFinished = (*command281).isFinished;
				break;
			case(2):
				autoClaw(command282);

				autonomousInfo.isFinished = (*command282).isFinished;
				break;
			case(3):
				driveToWP(command283);

				autonomousInfo.isFinished = (*command283).isFinished;
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
				driveToWP(command284);
				autoClaw(command285);
				autonomousInfo.isFinished = (*command284).isFinished && (*command285).isFinished;
				break;
			case(2):
				driveToWP(command286);
				autoDumper(command287);
				autonomousInfo.isFinished = (*command286).isFinished && (*command287).isFinished;
				break;
			case(3):
				timeout(command288);

				autonomousInfo.isFinished = (*command288).isFinished;
				break;
			case(4):
				autoClaw(command289);
				timeout(command290);
				autonomousInfo.isFinished = (*command289).isFinished && (*command290).isFinished;
				break;
			case(5):
				driveToWP(command291);

				autonomousInfo.isFinished = (*command291).isFinished;
				break;
			case(6):
				autoClaw(command292);
				autoDumper(command293);
				autonomousInfo.isFinished = (*command292).isFinished && (*command293).isFinished;
				break;
			case(7):
				autoClaw(command294);

				autonomousInfo.isFinished = (*command294).isFinished;
				break;
			case(8):
				timeout(command295);

				autonomousInfo.isFinished = (*command295).isFinished;
				break;
			case(9):
				autoDumper(command296);
				driveToWP(command297);
				autonomousInfo.isFinished = (*command296).isFinished && (*command297).isFinished;
				break;
			case(10):
				timeout(command298);

				autonomousInfo.isFinished = (*command298).isFinished;
				break;
			case(11):
				autoClaw(command299);
				timeout(command300);
				autonomousInfo.isFinished = (*command299).isFinished && (*command300).isFinished;
				break;
			case(12):
				driveToWP(command301);

				autonomousInfo.isFinished = (*command301).isFinished;
				break;
			case(13):
				autoClaw(command302);
				autoDumper(command303);
				autonomousInfo.isFinished = (*command302).isFinished && (*command303).isFinished;
				break;
			case(14):
				autoClaw(command304);

				autonomousInfo.isFinished = (*command304).isFinished;
				break;
			case(15):
				autoDumper(command305);

				autonomousInfo.isFinished = (*command305).isFinished;
				break;
			case(16):
				timeout(command306);

				autonomousInfo.isFinished = (*command306).isFinished;
				break;
			case(17):
				driveToWP(command307);

				autonomousInfo.isFinished = (*command307).isFinished;
				break;
			case(18):
				driveToWP(command308);
				autoDumper(command309);
				autonomousInfo.isFinished = (*command308).isFinished && (*command309).isFinished;
				break;
			case(19):
				driveToWP(command310);

				autonomousInfo.isFinished = (*command310).isFinished;
				break;
			case(20):
				autoClaw(command311);
				timeout(command312);
				autonomousInfo.isFinished = (*command311).isFinished && (*command312).isFinished;
				break;
			case(21):
				autoDumper(command313);
				driveToWP(command314);
				autonomousInfo.isFinished = (*command313).isFinished && (*command314).isFinished;
				break;
			case(22):
				driveToWP(command315);

				autonomousInfo.isFinished = (*command315).isFinished;
				break;
			case(23):
				driveToWP(command316);

				autonomousInfo.isFinished = (*command316).isFinished;
				break;
			case(24):
				autoClaw(command317);
				autoDumper(command318);
				autonomousInfo.isFinished = (*command317).isFinished && (*command318).isFinished;
				break;
			case(25):
				autoClaw(command319);

				autonomousInfo.isFinished = (*command319).isFinished;
				break;
			case(26):
				timeout(command320);

				autonomousInfo.isFinished = (*command320).isFinished;
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

