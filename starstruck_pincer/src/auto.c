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
Timeout * command2;
DriveToWP * command3;
DriveToWP * command4;
Timeout * command5;

DriveToWP * command6;
Timeout * command7;

AutoClaw * command8;
AutoDumper * command9;

AutoDumper * command10;
DriveToWP * command11;

AutoDumper * command12;
DriveToWP * command13;
Timeout * command14;

AutoDumper * command15;
AutoDumper * command16;
AutoClaw * command17;

AutoDumper * command18;
DriveToWP * command19;
AutoDumper * command20;

DriveToWP * command21;
AutoDumper * command22;

DriveToWP * command23;
AutoDumper * command24;
Timeout * command25;

DriveToWP * command26;
Timeout * command27;

AutoClaw * command28;
AutoDumper * command29;
AutoDumper * command30;
DriveToWP * command31;

AutoDumper * command32;
DriveToWP * command33;
Timeout * command34;

AutoDumper * command35;
AutoDumper * command36;
AutoClaw * command37;

AutoDumper * command38;

AutoClaw * command39;
Timeout * command40;
DriveToWP * command41;
Timeout * command42;

DriveToWP * command43;
Timeout * command44;

AutoClaw * command45;
AutoDumper * command46;
Timeout * command47;

DriveToWP * command48;
AutoDumper * command49;
Timeout * command50;

DriveToWP * command51;
AutoDumper * command52;
Timeout * command53;

AutoDumper * command54;
Timeout * command55;

AutoDumper * command56;
AutoClaw * command57;
Timeout * command58;

AutoDumper * command59;
Timeout * command60;

AutoDumper * command61;
Timeout * command62;

DriveToWP * command63;
Timeout * command64;

DriveToWP * command65;
Timeout * command66;

DriveToWP * command67;
Timeout * command68;

AutoClaw * command69;
AutoDumper * command70;
Timeout * command71;

DriveToWP * command72;
AutoDumper * command73;
Timeout * command74;

DriveToWP * command75;
AutoDumper * command76;
Timeout * command77;

AutoDumper * command78;
Timeout * command79;

AutoDumper * command80;
AutoClaw * command81;
Timeout * command82;

AutoDumper * command83;
Timeout * command84;

DriveToWP * command85;
AutoDumper * command86;
Timeout * command87;

DriveToWP * command88;
AutoDumper * command89;
Timeout * command90;

DriveToWP * command91;
AutoDumper * command92;
Timeout * command93;

DriveToWP * command94;
Timeout * command95;

AutoClaw * command96;
AutoDumper * command97;
Timeout * command98;

DriveToWP * command99;
AutoDumper * command100;
Timeout * command101;

DriveToWP * command102;
AutoDumper * command103;
Timeout * command104;

DriveToWP * command105;
AutoDumper * command106;
Timeout * command107;

AutoDumper * command108;
AutoClaw * command109;
Timeout * command110;

AutoDumper * command111;
Timeout * command112;


AutoClaw * command113;
Timeout * command114;
DriveToWP * command115;
DriveToWP * command116;
Timeout * command117;

AutoClaw * command118;
AutoDumper * command119;
Timeout * command120;

DriveToWP * command121;
AutoDumper * command122;
Timeout * command123;

DriveToWP * command124;
AutoDumper * command125;
Timeout * command126;

AutoDumper * command127;
Timeout * command128;

AutoDumper * command129;
AutoClaw * command130;
Timeout * command131;

AutoDumper * command132;
Timeout * command133;

AutoDumper * command134;
Timeout * command135;

DriveToWP * command136;
Timeout * command137;

DriveToWP * command138;
Timeout * command139;

DriveToWP * command140;
Timeout * command141;

AutoClaw * command142;
AutoDumper * command143;
Timeout * command144;

DriveToWP * command145;
AutoDumper * command146;
Timeout * command147;

DriveToWP * command148;
AutoDumper * command149;
Timeout * command150;

AutoDumper * command151;
Timeout * command152;

AutoDumper * command153;
AutoClaw * command154;
Timeout * command155;

AutoDumper * command156;
Timeout * command157;

DriveToWP * command158;
AutoDumper * command159;
Timeout * command160;

DriveToWP * command161;
AutoDumper * command162;
Timeout * command163;

DriveToWP * command164;
AutoDumper * command165;
Timeout * command166;

DriveToWP * command167;
Timeout * command168;

AutoClaw * command169;
AutoDumper * command170;
Timeout * command171;

DriveToWP * command172;
AutoDumper * command173;
Timeout * command174;

DriveToWP * command175;
AutoDumper * command176;
Timeout * command177;

DriveToWP * command178;
AutoDumper * command179;
Timeout * command180;

AutoDumper * command181;
AutoClaw * command182;
Timeout * command183;

AutoDumper * command184;
Timeout * command185;


AutoClaw * command186;
DriveToWP * command187;
Timeout * command188;

DriveToWP * command189;
Timeout * command190;

DriveToWP * command191;
Timeout * command192;

AutoClaw * command193;
DriveToWP * command194;
AutoDumper * command195;
Timeout * command196;

DriveToWP * command197;
AutoDumper * command198;

DriveToWP * command199;
AutoDumper * command200;

DriveToWP * command201;
AutoDumper * command202;
Timeout * command203;

AutoDumper * command204;
AutoDumper * command205;
AutoClaw * command206;

AutoDumper * command207;
DriveToWP * command208;
DriveToWP * command209;
Timeout * command210;

DriveToWP * command211;
Timeout * command212;

AutoClaw * command213;
DriveToWP * command214;
Timeout * command215;

AutoDumper * command216;
DriveToWP * command217;
AutoDumper * command218;
Timeout * command219;

DriveToWP * command220;
AutoDumper * command221;
Timeout * command222;

AutoDumper * command223;
AutoClaw * command224;
AutoDumper * command225;

AutoDumper * command226;
DriveToWP * command227;
Timeout * command228;

DriveToWP * command229;
Timeout * command230;

AutoClaw * command231;
DriveToWP * command232;
Timeout * command233;

AutoDumper * command234;
Timeout * command235;

DriveToWP * command236;
AutoDumper * command237;
Timeout * command238;

DriveToWP * command239;
AutoDumper * command240;
Timeout * command241;

AutoDumper * command242;
AutoClaw * command243;
AutoDumper * command244;

AutoDumper * command245;

AutoClaw * command246;
DriveToWP * command247;
Timeout * command248;

DriveToWP * command249;
Timeout * command250;

DriveToWP * command251;
Timeout * command252;

AutoClaw * command253;
DriveToWP * command254;
AutoDumper * command255;
Timeout * command256;

DriveToWP * command257;
AutoDumper * command258;

DriveToWP * command259;
AutoDumper * command260;

DriveToWP * command261;
AutoDumper * command262;
Timeout * command263;

AutoDumper * command264;
AutoDumper * command265;
AutoClaw * command266;

AutoDumper * command267;
DriveToWP * command268;
DriveToWP * command269;
Timeout * command270;

DriveToWP * command271;
Timeout * command272;

AutoClaw * command273;
DriveToWP * command274;
Timeout * command275;

AutoDumper * command276;
DriveToWP * command277;
AutoDumper * command278;
Timeout * command279;

DriveToWP * command280;
AutoDumper * command281;
Timeout * command282;

AutoDumper * command283;
AutoClaw * command284;
AutoDumper * command285;

AutoDumper * command286;
DriveToWP * command287;
Timeout * command288;

DriveToWP * command289;
Timeout * command290;

AutoClaw * command291;
DriveToWP * command292;
Timeout * command293;

AutoDumper * command294;
Timeout * command295;

DriveToWP * command296;
AutoDumper * command297;
Timeout * command298;

DriveToWP * command299;
AutoDumper * command300;
Timeout * command301;

AutoDumper * command302;
AutoClaw * command303;
AutoDumper * command304;

AutoDumper * command305;

AutoClaw * command306;
DriveToWP * command307;
DriveToWP * command308;
AutoClaw * command309;
AutoDumper * command310;
AutoDumper * command311;
DriveToWP * command312;
Timeout * command313;

AutoDumper * command314;
AutoClaw * command315;
AutoDumper * command316;

AutoDumper * command317;
DriveToWP * command318;
Timeout * command319;

AutoClaw * command320;
AutoDumper * command321;
AutoDumper * command322;
DriveToWP * command323;
Timeout * command324;

AutoDumper * command325;
AutoClaw * command326;
AutoDumper * command327;

AutoDumper * command328;
DriveToWP * command329;
DriveToWP * command330;
Timeout * command331;

AutoDumper * command332;
DriveToWP * command333;
Timeout * command334;

AutoClaw * command335;
DriveToWP * command336;
AutoDumper * command337;
Timeout * command338;

DriveToWP * command339;
AutoDumper * command340;
Timeout * command341;

DriveToWP * command342;
AutoDumper * command343;
Timeout * command344;

AutoDumper * command345;
Timeout * command346;
AutoDumper * command347;
AutoClaw * command348;
Timeout * command349;

AutoDumper * command350;
DriveToWP * command351;
Timeout * command352;

AutoClaw * command353;
DriveToWP * command354;
AutoDumper * command355;
Timeout * command356;

AutoDumper * command357;
Timeout * command358;
AutoDumper * command359;
AutoClaw * command360;
Timeout * command361;

DriveToWP * command362;
AutoDumper * command363;
Timeout * command364;

DriveToWP * command365;
AutoDumper * command366;
Timeout * command367;

DriveToWP * command368;
AutoDumper * command369;
Timeout * command370;

DriveToWP * command371;
Timeout * command372;

AutoClaw * command373;
AutoDumper * command374;
DriveToWP * command375;
AutoDumper * command376;
Timeout * command377;

DriveToWP * command378;
AutoDumper * command379;
Timeout * command380;

AutoDumper * command381;
AutoClaw * command382;
Timeout * command383;

AutoDumper * command384;
Timeout * command385;

DriveToWP * command386;
AutoDumper * command387;
Timeout * command388;

DriveToWP * command389;
AutoDumper * command390;
Timeout * command391;

DriveToWP * command392;
AutoDumper * command393;
Timeout * command394;

DriveToWP * command395;
Timeout * command396;

AutoClaw * command397;
AutoDumper * command398;
Timeout * command399;

DriveToWP * command400;
AutoDumper * command401;
Timeout * command402;

DriveToWP * command403;
AutoDumper * command404;
Timeout * command405;

AutoDumper * command406;
Timeout * command407;

AutoDumper * command408;
AutoClaw * command409;

AutoDumper * command410;

DriveToWP * command411;
DriveToWP * command412;
AutoDumper * command413;
AutoClaw * command414;
AutoDumper * command415;
Timeout * command416;


// END OF DECLARATIONS

void autonomousInit()
{
	/**
	 * Here, the different steps are instantiated and details are
	 * given about them. By hovering over the function name, you can see a
	 * list of the arguments to pass in.
	 */

	defaultProps = initDriveToWPProperties(robotDrive,
			0.5, 18, 1000, 127, 40, // MAG
			2, 10, 70, 35, 3.25, 1, 250); //ROT

	// START OF INSTANTIATIONS
if(autonomousSelection == DO_NOTHING)
{
}
if(autonomousSelection == CUBE_FIRST)
{
	command1 = initAutoClaw(robotClaw, CLAW_OPEN);
	command2 = initTimeout(1000);
	command3 = initDriveToWP(defaultProps, -20, 0);
	command4 = initDriveToWP(defaultProps, 0, red_(-20));
	command5 = initTimeout(2000);

	command6 = initDriveToWP(defaultProps, 99, 0);
	command7 = initTimeout(6000);

	command8 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command9 = initAutoDumper(robotDumper, DUMPER_TRAVEL);

	command10 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command11 = initDriveToWP(defaultProps, 0, blue_(110));

	command12 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command13 = initDriveToWP(defaultProps, -15, 0);
	command14 = initTimeout(2000);

	command15 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command16 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command17 = initAutoClaw(robotClaw, CLAW_OPEN);

	command18 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command19 = initDriveToWP(defaultProps, 42, 0);
	command20 = initAutoDumper(robotDumper, DUMPER_TRAVEL);

	command21 = initDriveToWP(defaultProps, 0, always_(90));
	command22 = initAutoDumper(robotDumper, DUMPER_TRAVEL);

	command23 = initDriveToWP(defaultProps, -12, 0);
	command24 = initAutoDumper(robotDumper, DUMPER_LOW);
	command25 = initTimeout(2000);

	command26 = initDriveToWP(defaultProps, 91, 0);
	command27 = initTimeout(6000);

	command28 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command29 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command30 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command31 = initDriveToWP(defaultProps, 0, -90);

	command32 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command33 = initDriveToWP(defaultProps, -48, 0);
	command34 = initTimeout(3000);

	command35 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command36 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command37 = initAutoClaw(robotClaw, CLAW_OPEN);

	command38 = initAutoDumper(robotDumper, DUMPER_LOW);
}
if(autonomousSelection == MODE_1L)
{
	command39 = initAutoClaw(robotClaw, CLAW_OPEN);
	command40 = initTimeout(1000);
	command41 = initDriveToWP(defaultProps, -18, 0);
	command42 = initTimeout(3000);

	command43 = initDriveToWP(defaultProps, 96, 0);
	command44 = initTimeout(6000);

	command45 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command46 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command47 = initTimeout(2000);

	command48 = initDriveToWP(defaultProps, 0, 90);
	command49 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command50 = initTimeout(5000);

	command51 = initDriveToWP(defaultProps, -44, 0);
	command52 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command53 = initTimeout(5000);

	command54 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command55 = initTimeout(3000);

	command56 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command57 = initAutoClaw(robotClaw, CLAW_OPEN);
	command58 = initTimeout(3000);

	command59 = initAutoDumper(robotDumper, DUMPER_LOW);
	command60 = initTimeout(3000);

	command61 = initAutoDumper(robotDumper, DUMPER_STOP);
	command62 = initTimeout(3000);

	command63 = initDriveToWP(defaultProps, 20, 0);
	command64 = initTimeout(3000);

	command65 = initDriveToWP(defaultProps, 0, 90);
	command66 = initTimeout(5000);

	command67 = initDriveToWP(defaultProps, 33, 0);
	command68 = initTimeout(3000);

	command69 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command70 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command71 = initTimeout(2000);

	command72 = initDriveToWP(defaultProps, 0, -90);
	command73 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command74 = initTimeout(5000);

	command75 = initDriveToWP(defaultProps, -20, 0);
	command76 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command77 = initTimeout(5000);

	command78 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command79 = initTimeout(3000);

	command80 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command81 = initAutoClaw(robotClaw, CLAW_OPEN);
	command82 = initTimeout(3000);

	command83 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command84 = initTimeout(3000);

	command85 = initDriveToWP(defaultProps, 12, 0);
	command86 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command87 = initTimeout(3000);

	command88 = initDriveToWP(defaultProps, 0, 80);
	command89 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command90 = initTimeout(5000);

	command91 = initDriveToWP(defaultProps, -12, 0);
	command92 = initAutoDumper(robotDumper, DUMPER_LOW);
	command93 = initTimeout(3000);

	command94 = initDriveToWP(defaultProps, 48, 0);
	command95 = initTimeout(3000);

	command96 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command97 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command98 = initTimeout(3000);

	command99 = initDriveToWP(defaultProps, -36, 0);
	command100 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command101 = initTimeout(3000);

	command102 = initDriveToWP(defaultProps, 0, -80);
	command103 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command104 = initTimeout(5000);

	command105 = initDriveToWP(defaultProps, -24, 0);
	command106 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command107 = initTimeout(2000);

	command108 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command109 = initAutoClaw(robotClaw, CLAW_OPEN);
	command110 = initTimeout(3000);

	command111 = initAutoDumper(robotDumper, DUMPER_LOW);
	command112 = initTimeout(3000);

}
if(autonomousSelection == MODE_1R)
{
	command113 = initAutoClaw(robotClaw, CLAW_OPEN);
	command114 = initTimeout(1000);
	command115 = initDriveToWP(defaultProps, -18, 0);
	command116 = initDriveToWP(defaultProps, 96, 0);
	command117 = initTimeout(6000);

	command118 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command119 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command120 = initTimeout(2000);

	command121 = initDriveToWP(defaultProps, 0, -90);
	command122 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command123 = initTimeout(5000);

	command124 = initDriveToWP(defaultProps, -44, 0);
	command125 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command126 = initTimeout(3000);

	command127 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command128 = initTimeout(3000);

	command129 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command130 = initAutoClaw(robotClaw, CLAW_OPEN);
	command131 = initTimeout(3000);

	command132 = initAutoDumper(robotDumper, DUMPER_LOW);
	command133 = initTimeout(3000);

	command134 = initAutoDumper(robotDumper, DUMPER_STOP);
	command135 = initTimeout(3000);

	command136 = initDriveToWP(defaultProps, 20, 0);
	command137 = initTimeout(3000);

	command138 = initDriveToWP(defaultProps, 0, -80);
	command139 = initTimeout(5000);

	command140 = initDriveToWP(defaultProps, 33, 0);
	command141 = initTimeout(3000);

	command142 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command143 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command144 = initTimeout(2000);

	command145 = initDriveToWP(defaultProps, 0, 90);
	command146 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command147 = initTimeout(5000);

	command148 = initDriveToWP(defaultProps, -20, 0);
	command149 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command150 = initTimeout(5000);

	command151 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command152 = initTimeout(3000);

	command153 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command154 = initAutoClaw(robotClaw, CLAW_OPEN);
	command155 = initTimeout(3000);

	command156 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command157 = initTimeout(3000);

	command158 = initDriveToWP(defaultProps, 12, 0);
	command159 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command160 = initTimeout(3000);

	command161 = initDriveToWP(defaultProps, 0, -80);
	command162 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command163 = initTimeout(5000);

	command164 = initDriveToWP(defaultProps, -12, 0);
	command165 = initAutoDumper(robotDumper, DUMPER_LOW);
	command166 = initTimeout(3000);

	command167 = initDriveToWP(defaultProps, 48, 0);
	command168 = initTimeout(3000);

	command169 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command170 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command171 = initTimeout(3000);

	command172 = initDriveToWP(defaultProps, -36, 0);
	command173 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command174 = initTimeout(3000);

	command175 = initDriveToWP(defaultProps, 0, 80);
	command176 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command177 = initTimeout(5000);

	command178 = initDriveToWP(defaultProps, -24, 0);
	command179 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command180 = initTimeout(2000);

	command181 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command182 = initAutoClaw(robotClaw, CLAW_OPEN);
	command183 = initTimeout(3000);

	command184 = initAutoDumper(robotDumper, DUMPER_LOW);
	command185 = initTimeout(3000);

}
if(autonomousSelection == L_CUBENEAR)
{
	command186 = initAutoClaw(robotClaw, CLAW_OPEN);
	command187 = initDriveToWP(defaultProps, -18, 0);
	command188 = initTimeout(2000);

	command189 = initDriveToWP(defaultProps, 0, -30);
	command190 = initTimeout(1000);

	command191 = initDriveToWP(defaultProps, 50, 0);
	command192 = initTimeout(2000);

	command193 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command194 = initDriveToWP(defaultProps, 0, 30);
	command195 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command196 = initTimeout(2000);

	command197 = initDriveToWP(defaultProps, -40, 0);
	command198 = initAutoDumper(robotDumper, DUMPER_TRAVEL);

	command199 = initDriveToWP(defaultProps, 0, 90);
	command200 = initAutoDumper(robotDumper, DUMPER_TRAVEL);

	command201 = initDriveToWP(defaultProps, -30, 0);
	command202 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command203 = initTimeout(2000);

	command204 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command205 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command206 = initAutoClaw(robotClaw, CLAW_OPEN);

	command207 = initAutoDumper(robotDumper, DUMPER_LOW);
	command208 = initDriveToWP(defaultProps, 12, 0);
	command209 = initDriveToWP(defaultProps, 0, -45);
	command210 = initTimeout(2000);

	command211 = initDriveToWP(defaultProps, 62, 0);
	command212 = initTimeout(3000);

	command213 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command214 = initDriveToWP(defaultProps, -12, 0);
	command215 = initTimeout(2000);

	command216 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command217 = initDriveToWP(defaultProps, 0, 54);
	command218 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command219 = initTimeout(3000);

	command220 = initDriveToWP(defaultProps, -38, 0);
	command221 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command222 = initTimeout(3000);

	command223 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command224 = initAutoClaw(robotClaw, CLAW_OPEN);
	command225 = initAutoDumper(robotDumper, DUMPER_HIGH);

	command226 = initAutoDumper(robotDumper, DUMPER_LOW);
	command227 = initDriveToWP(defaultProps, 0, 55);
	command228 = initTimeout(2000);

	command229 = initDriveToWP(defaultProps, 36, 0);
	command230 = initTimeout(2000);

	command231 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command232 = initDriveToWP(defaultProps, -6, 0);
	command233 = initTimeout(2000);

	command234 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command235 = initTimeout(2000);

	command236 = initDriveToWP(defaultProps, -30, 0);
	command237 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command238 = initTimeout(2000);

	command239 = initDriveToWP(defaultProps, 0, -55);
	command240 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command241 = initTimeout(2000);

	command242 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command243 = initAutoClaw(robotClaw, CLAW_OPEN);
	command244 = initAutoDumper(robotDumper, DUMPER_HIGH);

	command245 = initAutoDumper(robotDumper, DUMPER_LOW);
}
if(autonomousSelection == R_CUBENEAR)
{
	command246 = initAutoClaw(robotClaw, CLAW_OPEN);
	command247 = initDriveToWP(defaultProps, -18, 0);
	command248 = initTimeout(2000);

	command249 = initDriveToWP(defaultProps, 0, 30);
	command250 = initTimeout(1000);

	command251 = initDriveToWP(defaultProps, 50, 0);
	command252 = initTimeout(2000);

	command253 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command254 = initDriveToWP(defaultProps, 0, -30);
	command255 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command256 = initTimeout(2000);

	command257 = initDriveToWP(defaultProps, -40, 0);
	command258 = initAutoDumper(robotDumper, DUMPER_TRAVEL);

	command259 = initDriveToWP(defaultProps, 0, -90);
	command260 = initAutoDumper(robotDumper, DUMPER_TRAVEL);

	command261 = initDriveToWP(defaultProps, -30, 0);
	command262 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command263 = initTimeout(2000);

	command264 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command265 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command266 = initAutoClaw(robotClaw, CLAW_OPEN);

	command267 = initAutoDumper(robotDumper, DUMPER_LOW);
	command268 = initDriveToWP(defaultProps, 12, 0);
	command269 = initDriveToWP(defaultProps, 0, 45);
	command270 = initTimeout(2000);

	command271 = initDriveToWP(defaultProps, 62, 0);
	command272 = initTimeout(3000);

	command273 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command274 = initDriveToWP(defaultProps, -12, 0);
	command275 = initTimeout(2000);

	command276 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command277 = initDriveToWP(defaultProps, 0, -54);
	command278 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command279 = initTimeout(3000);

	command280 = initDriveToWP(defaultProps, -38, 0);
	command281 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command282 = initTimeout(3000);

	command283 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command284 = initAutoClaw(robotClaw, CLAW_OPEN);
	command285 = initAutoDumper(robotDumper, DUMPER_HIGH);

	command286 = initAutoDumper(robotDumper, DUMPER_LOW);
	command287 = initDriveToWP(defaultProps, 0, -55);
	command288 = initTimeout(2000);

	command289 = initDriveToWP(defaultProps, 36, 0);
	command290 = initTimeout(2000);

	command291 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command292 = initDriveToWP(defaultProps, -6, 0);
	command293 = initTimeout(2000);

	command294 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command295 = initTimeout(2000);

	command296 = initDriveToWP(defaultProps, -30, 0);
	command297 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command298 = initTimeout(2000);

	command299 = initDriveToWP(defaultProps, 0, 55);
	command300 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command301 = initTimeout(2000);

	command302 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command303 = initAutoClaw(robotClaw, CLAW_OPEN);
	command304 = initAutoDumper(robotDumper, DUMPER_HIGH);

	command305 = initAutoDumper(robotDumper, DUMPER_LOW);
}
if(autonomousSelection == PROG_SKILLS)
{
	command306 = initAutoClaw(robotClaw, CLAW_OPEN);
	command307 = initDriveToWP(defaultProps, -36, 0);
	command308 = initDriveToWP(defaultProps, 18, 0);
	command309 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command310 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command311 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command312 = initDriveToWP(defaultProps, -36, 0);
	command313 = initTimeout(3000);

	command314 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command315 = initAutoClaw(robotClaw, CLAW_OPEN);
	command316 = initAutoDumper(robotDumper, DUMPER_HIGH);

	command317 = initAutoDumper(robotDumper, DUMPER_LOW);
	command318 = initDriveToWP(defaultProps, 32, 0);
	command319 = initTimeout(3000);

	command320 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command321 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command322 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command323 = initDriveToWP(defaultProps, -36, 0);
	command324 = initTimeout(3000);

	command325 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command326 = initAutoClaw(robotClaw, CLAW_OPEN);
	command327 = initAutoDumper(robotDumper, DUMPER_HIGH);

	command328 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command329 = initDriveToWP(defaultProps, 22, 0);
	command330 = initDriveToWP(defaultProps, 0, -80);
	command331 = initTimeout(3000);

	command332 = initAutoDumper(robotDumper, DUMPER_LOW);
	command333 = initDriveToWP(defaultProps, 34, 0);
	command334 = initTimeout(3000);

	command335 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command336 = initDriveToWP(defaultProps, 50, 0);
	command337 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command338 = initTimeout(4000);

	command339 = initDriveToWP(defaultProps, 0, 90);
	command340 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command341 = initTimeout(4000);

	command342 = initDriveToWP(defaultProps, -24, 0);
	command343 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command344 = initTimeout(4000);

	command345 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command346 = initTimeout(1000);
	command347 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command348 = initAutoClaw(robotClaw, CLAW_OPEN);
	command349 = initTimeout(4000);

	command350 = initAutoDumper(robotDumper, DUMPER_LOW);
	command351 = initDriveToWP(defaultProps, 24, 0);
	command352 = initTimeout(2000);

	command353 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command354 = initDriveToWP(defaultProps, -28, 0);
	command355 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command356 = initTimeout(4000);

	command357 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command358 = initTimeout(1000);
	command359 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command360 = initAutoClaw(robotClaw, CLAW_OPEN);
	command361 = initTimeout(4000);

	command362 = initDriveToWP(defaultProps, 6, 0);
	command363 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command364 = initTimeout(2000);

	command365 = initDriveToWP(defaultProps, 0, 90);
	command366 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command367 = initTimeout(4000);

	command368 = initDriveToWP(defaultProps, -6, 0);
	command369 = initAutoDumper(robotDumper, DUMPER_LOW);
	command370 = initTimeout(4000);

	command371 = initDriveToWP(defaultProps, 100, 0);
	command372 = initTimeout(6000);

	command373 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command374 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command375 = initDriveToWP(defaultProps, 0, -90);
	command376 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command377 = initTimeout(4000);

	command378 = initDriveToWP(defaultProps, -6, 0);
	command379 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command380 = initTimeout(4000);

	command381 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command382 = initAutoClaw(robotClaw, CLAW_OPEN);
	command383 = initTimeout(4000);

	command384 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command385 = initTimeout(4000);

	command386 = initDriveToWP(defaultProps, 40, 0);
	command387 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command388 = initTimeout(4000);

	command389 = initDriveToWP(defaultProps, 0, -90);
	command390 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command391 = initTimeout(4000);

	command392 = initDriveToWP(defaultProps, -12, 0);
	command393 = initAutoDumper(robotDumper, DUMPER_LOW);
	command394 = initTimeout(4000);

	command395 = initDriveToWP(defaultProps, 84, 0);
	command396 = initTimeout(6000);

	command397 = initAutoClaw(robotClaw, CLAW_CLOSE);
	command398 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command399 = initTimeout(4000);

	command400 = initDriveToWP(defaultProps, 0, 90);
	command401 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command402 = initTimeout(4000);

	command403 = initDriveToWP(defaultProps, -48, 0);
	command404 = initAutoDumper(robotDumper, DUMPER_TRAVEL);
	command405 = initTimeout(4000);

	command406 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command407 = initTimeout(4000);

	command408 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command409 = initAutoClaw(robotClaw, CLAW_OPEN);

	command410 = initAutoDumper(robotDumper, DUMPER_LOW);
}
if(autonomousSelection == TEST)
{
	command411 = initDriveToWP(defaultProps, 24, 0);
	command412 = initDriveToWP(defaultProps, 0, -90);
	command413 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command414 = initAutoClaw(robotClaw, CLAW_OPEN);
	command415 = initAutoDumper(robotDumper, DUMPER_HIGH);
	command416 = initTimeout(1000);

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
				timeout(command2);

				autonomousInfo.isFinished = (*command2).isFinished;
				break;
			case(3):
				driveToWP(command3);

				autonomousInfo.isFinished = (*command3).isFinished;
				break;
			case(4):
				driveToWP(command4);
				timeout(command5);
				autonomousInfo.isFinished = (*command4).isFinished || (*command5).isFinished;
				break;
			case(5):
				driveToWP(command6);
				timeout(command7);
				autonomousInfo.isFinished = (*command6).isFinished || (*command7).isFinished;
				break;
			case(6):
				autoClaw(command8);
				autoDumper(command9);
				autonomousInfo.isFinished = (*command8).isFinished && (*command9).isFinished;
				break;
			case(7):
				autoDumper(command10);
				driveToWP(command11);
				autonomousInfo.isFinished = (*command10).isFinished && (*command11).isFinished;
				break;
			case(8):
				autoDumper(command12);
				driveToWP(command13);
				timeout(command14);
				autonomousInfo.isFinished = (*command12).isFinished && (*command13).isFinished || (*command14).isFinished;
				break;
			case(9):
				autoDumper(command15);

				autonomousInfo.isFinished = (*command15).isFinished;
				break;
			case(10):
				autoDumper(command16);
				autoClaw(command17);
				autonomousInfo.isFinished = (*command16).isFinished && (*command17).isFinished;
				break;
			case(11):
				autoDumper(command18);

				autonomousInfo.isFinished = (*command18).isFinished;
				break;
			case(12):
				driveToWP(command19);
				autoDumper(command20);
				autonomousInfo.isFinished = (*command19).isFinished && (*command20).isFinished;
				break;
			case(13):
				driveToWP(command21);
				autoDumper(command22);
				autonomousInfo.isFinished = (*command21).isFinished && (*command22).isFinished;
				break;
			case(14):
				driveToWP(command23);
				autoDumper(command24);
				timeout(command25);
				autonomousInfo.isFinished = (*command23).isFinished && (*command24).isFinished || (*command25).isFinished;
				break;
			case(15):
				driveToWP(command26);
				timeout(command27);
				autonomousInfo.isFinished = (*command26).isFinished || (*command27).isFinished;
				break;
			case(16):
				autoClaw(command28);

				autonomousInfo.isFinished = (*command28).isFinished;
				break;
			case(17):
				autoDumper(command29);

				autonomousInfo.isFinished = (*command29).isFinished;
				break;
			case(18):
				autoDumper(command30);
				driveToWP(command31);
				autonomousInfo.isFinished = (*command30).isFinished && (*command31).isFinished;
				break;
			case(19):
				autoDumper(command32);
				driveToWP(command33);
				timeout(command34);
				autonomousInfo.isFinished = (*command32).isFinished && (*command33).isFinished || (*command34).isFinished;
				break;
			case(20):
				autoDumper(command35);

				autonomousInfo.isFinished = (*command35).isFinished;
				break;
			case(21):
				autoDumper(command36);
				autoClaw(command37);
				autonomousInfo.isFinished = (*command36).isFinished && (*command37).isFinished;
				break;
			case(22):
				autoDumper(command38);

				autonomousInfo.isFinished = (*command38).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(MODE_1L):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command39);

				autonomousInfo.isFinished = (*command39).isFinished;
				break;
			case(2):
				timeout(command40);

				autonomousInfo.isFinished = (*command40).isFinished;
				break;
			case(3):
				driveToWP(command41);
				timeout(command42);
				autonomousInfo.isFinished = (*command41).isFinished || (*command42).isFinished;
				break;
			case(4):
				driveToWP(command43);
				timeout(command44);
				autonomousInfo.isFinished = (*command43).isFinished || (*command44).isFinished;
				break;
			case(5):
				autoClaw(command45);

				autonomousInfo.isFinished = (*command45).isFinished;
				break;
			case(6):
				autoDumper(command46);
				timeout(command47);
				autonomousInfo.isFinished = (*command46).isFinished || (*command47).isFinished;
				break;
			case(7):
				driveToWP(command48);
				autoDumper(command49);
				timeout(command50);
				autonomousInfo.isFinished = (*command48).isFinished && (*command49).isFinished || (*command50).isFinished;
				break;
			case(8):
				driveToWP(command51);
				autoDumper(command52);
				timeout(command53);
				autonomousInfo.isFinished = (*command51).isFinished && (*command52).isFinished || (*command53).isFinished;
				break;
			case(9):
				autoDumper(command54);
				timeout(command55);
				autonomousInfo.isFinished = (*command54).isFinished || (*command55).isFinished;
				break;
			case(10):
				autoDumper(command56);
				autoClaw(command57);
				timeout(command58);
				autonomousInfo.isFinished = (*command56).isFinished && (*command57).isFinished || (*command58).isFinished;
				break;
			case(11):
				autoDumper(command59);
				timeout(command60);
				autonomousInfo.isFinished = (*command59).isFinished || (*command60).isFinished;
				break;
			case(12):
				autoDumper(command61);
				timeout(command62);
				autonomousInfo.isFinished = (*command61).isFinished || (*command62).isFinished;
				break;
			case(13):
				driveToWP(command63);
				timeout(command64);
				autonomousInfo.isFinished = (*command63).isFinished || (*command64).isFinished;
				break;
			case(14):
				driveToWP(command65);
				timeout(command66);
				autonomousInfo.isFinished = (*command65).isFinished || (*command66).isFinished;
				break;
			case(15):
				driveToWP(command67);
				timeout(command68);
				autonomousInfo.isFinished = (*command67).isFinished || (*command68).isFinished;
				break;
			case(16):
				autoClaw(command69);

				autonomousInfo.isFinished = (*command69).isFinished;
				break;
			case(17):
				autoDumper(command70);
				timeout(command71);
				autonomousInfo.isFinished = (*command70).isFinished || (*command71).isFinished;
				break;
			case(18):
				driveToWP(command72);
				autoDumper(command73);
				timeout(command74);
				autonomousInfo.isFinished = (*command72).isFinished && (*command73).isFinished || (*command74).isFinished;
				break;
			case(19):
				driveToWP(command75);
				autoDumper(command76);
				timeout(command77);
				autonomousInfo.isFinished = (*command75).isFinished && (*command76).isFinished || (*command77).isFinished;
				break;
			case(20):
				autoDumper(command78);
				timeout(command79);
				autonomousInfo.isFinished = (*command78).isFinished || (*command79).isFinished;
				break;
			case(21):
				autoDumper(command80);
				autoClaw(command81);
				timeout(command82);
				autonomousInfo.isFinished = (*command80).isFinished && (*command81).isFinished || (*command82).isFinished;
				break;
			case(22):
				autoDumper(command83);
				timeout(command84);
				autonomousInfo.isFinished = (*command83).isFinished || (*command84).isFinished;
				break;
			case(23):
				driveToWP(command85);
				autoDumper(command86);
				timeout(command87);
				autonomousInfo.isFinished = (*command85).isFinished && (*command86).isFinished || (*command87).isFinished;
				break;
			case(24):
				driveToWP(command88);
				autoDumper(command89);
				timeout(command90);
				autonomousInfo.isFinished = (*command88).isFinished && (*command89).isFinished || (*command90).isFinished;
				break;
			case(25):
				driveToWP(command91);
				autoDumper(command92);
				timeout(command93);
				autonomousInfo.isFinished = (*command91).isFinished && (*command92).isFinished || (*command93).isFinished;
				break;
			case(26):
				driveToWP(command94);
				timeout(command95);
				autonomousInfo.isFinished = (*command94).isFinished || (*command95).isFinished;
				break;
			case(27):
				autoClaw(command96);

				autonomousInfo.isFinished = (*command96).isFinished;
				break;
			case(28):
				autoDumper(command97);
				timeout(command98);
				autonomousInfo.isFinished = (*command97).isFinished || (*command98).isFinished;
				break;
			case(29):
				driveToWP(command99);
				autoDumper(command100);
				timeout(command101);
				autonomousInfo.isFinished = (*command99).isFinished && (*command100).isFinished || (*command101).isFinished;
				break;
			case(30):
				driveToWP(command102);
				autoDumper(command103);
				timeout(command104);
				autonomousInfo.isFinished = (*command102).isFinished && (*command103).isFinished || (*command104).isFinished;
				break;
			case(31):
				driveToWP(command105);
				autoDumper(command106);
				timeout(command107);
				autonomousInfo.isFinished = (*command105).isFinished && (*command106).isFinished || (*command107).isFinished;
				break;
			case(32):
				autoDumper(command108);
				autoClaw(command109);
				timeout(command110);
				autonomousInfo.isFinished = (*command108).isFinished && (*command109).isFinished || (*command110).isFinished;
				break;
			case(33):
				autoDumper(command111);
				timeout(command112);
				autonomousInfo.isFinished = (*command111).isFinished || (*command112).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(MODE_1R):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command113);

				autonomousInfo.isFinished = (*command113).isFinished;
				break;
			case(2):
				timeout(command114);

				autonomousInfo.isFinished = (*command114).isFinished;
				break;
			case(3):
				driveToWP(command115);

				autonomousInfo.isFinished = (*command115).isFinished;
				break;
			case(4):
				driveToWP(command116);
				timeout(command117);
				autonomousInfo.isFinished = (*command116).isFinished || (*command117).isFinished;
				break;
			case(5):
				autoClaw(command118);

				autonomousInfo.isFinished = (*command118).isFinished;
				break;
			case(6):
				autoDumper(command119);
				timeout(command120);
				autonomousInfo.isFinished = (*command119).isFinished || (*command120).isFinished;
				break;
			case(7):
				driveToWP(command121);
				autoDumper(command122);
				timeout(command123);
				autonomousInfo.isFinished = (*command121).isFinished && (*command122).isFinished || (*command123).isFinished;
				break;
			case(8):
				driveToWP(command124);
				autoDumper(command125);
				timeout(command126);
				autonomousInfo.isFinished = (*command124).isFinished && (*command125).isFinished || (*command126).isFinished;
				break;
			case(9):
				autoDumper(command127);
				timeout(command128);
				autonomousInfo.isFinished = (*command127).isFinished || (*command128).isFinished;
				break;
			case(10):
				autoDumper(command129);
				autoClaw(command130);
				timeout(command131);
				autonomousInfo.isFinished = (*command129).isFinished && (*command130).isFinished || (*command131).isFinished;
				break;
			case(11):
				autoDumper(command132);
				timeout(command133);
				autonomousInfo.isFinished = (*command132).isFinished || (*command133).isFinished;
				break;
			case(12):
				autoDumper(command134);
				timeout(command135);
				autonomousInfo.isFinished = (*command134).isFinished || (*command135).isFinished;
				break;
			case(13):
				driveToWP(command136);
				timeout(command137);
				autonomousInfo.isFinished = (*command136).isFinished || (*command137).isFinished;
				break;
			case(14):
				driveToWP(command138);
				timeout(command139);
				autonomousInfo.isFinished = (*command138).isFinished || (*command139).isFinished;
				break;
			case(15):
				driveToWP(command140);
				timeout(command141);
				autonomousInfo.isFinished = (*command140).isFinished || (*command141).isFinished;
				break;
			case(16):
				autoClaw(command142);

				autonomousInfo.isFinished = (*command142).isFinished;
				break;
			case(17):
				autoDumper(command143);
				timeout(command144);
				autonomousInfo.isFinished = (*command143).isFinished || (*command144).isFinished;
				break;
			case(18):
				driveToWP(command145);
				autoDumper(command146);
				timeout(command147);
				autonomousInfo.isFinished = (*command145).isFinished && (*command146).isFinished || (*command147).isFinished;
				break;
			case(19):
				driveToWP(command148);
				autoDumper(command149);
				timeout(command150);
				autonomousInfo.isFinished = (*command148).isFinished && (*command149).isFinished || (*command150).isFinished;
				break;
			case(20):
				autoDumper(command151);
				timeout(command152);
				autonomousInfo.isFinished = (*command151).isFinished || (*command152).isFinished;
				break;
			case(21):
				autoDumper(command153);
				autoClaw(command154);
				timeout(command155);
				autonomousInfo.isFinished = (*command153).isFinished && (*command154).isFinished || (*command155).isFinished;
				break;
			case(22):
				autoDumper(command156);
				timeout(command157);
				autonomousInfo.isFinished = (*command156).isFinished || (*command157).isFinished;
				break;
			case(23):
				driveToWP(command158);
				autoDumper(command159);
				timeout(command160);
				autonomousInfo.isFinished = (*command158).isFinished && (*command159).isFinished || (*command160).isFinished;
				break;
			case(24):
				driveToWP(command161);
				autoDumper(command162);
				timeout(command163);
				autonomousInfo.isFinished = (*command161).isFinished && (*command162).isFinished || (*command163).isFinished;
				break;
			case(25):
				driveToWP(command164);
				autoDumper(command165);
				timeout(command166);
				autonomousInfo.isFinished = (*command164).isFinished && (*command165).isFinished || (*command166).isFinished;
				break;
			case(26):
				driveToWP(command167);
				timeout(command168);
				autonomousInfo.isFinished = (*command167).isFinished || (*command168).isFinished;
				break;
			case(27):
				autoClaw(command169);

				autonomousInfo.isFinished = (*command169).isFinished;
				break;
			case(28):
				autoDumper(command170);
				timeout(command171);
				autonomousInfo.isFinished = (*command170).isFinished || (*command171).isFinished;
				break;
			case(29):
				driveToWP(command172);
				autoDumper(command173);
				timeout(command174);
				autonomousInfo.isFinished = (*command172).isFinished && (*command173).isFinished || (*command174).isFinished;
				break;
			case(30):
				driveToWP(command175);
				autoDumper(command176);
				timeout(command177);
				autonomousInfo.isFinished = (*command175).isFinished && (*command176).isFinished || (*command177).isFinished;
				break;
			case(31):
				driveToWP(command178);
				autoDumper(command179);
				timeout(command180);
				autonomousInfo.isFinished = (*command178).isFinished && (*command179).isFinished || (*command180).isFinished;
				break;
			case(32):
				autoDumper(command181);
				autoClaw(command182);
				timeout(command183);
				autonomousInfo.isFinished = (*command181).isFinished && (*command182).isFinished || (*command183).isFinished;
				break;
			case(33):
				autoDumper(command184);
				timeout(command185);
				autonomousInfo.isFinished = (*command184).isFinished || (*command185).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(L_CUBENEAR):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command186);

				autonomousInfo.isFinished = (*command186).isFinished;
				break;
			case(2):
				driveToWP(command187);
				timeout(command188);
				autonomousInfo.isFinished = (*command187).isFinished || (*command188).isFinished;
				break;
			case(3):
				driveToWP(command189);
				timeout(command190);
				autonomousInfo.isFinished = (*command189).isFinished || (*command190).isFinished;
				break;
			case(4):
				driveToWP(command191);
				timeout(command192);
				autonomousInfo.isFinished = (*command191).isFinished || (*command192).isFinished;
				break;
			case(5):
				autoClaw(command193);

				autonomousInfo.isFinished = (*command193).isFinished;
				break;
			case(6):
				driveToWP(command194);
				autoDumper(command195);
				timeout(command196);
				autonomousInfo.isFinished = (*command194).isFinished && (*command195).isFinished || (*command196).isFinished;
				break;
			case(7):
				driveToWP(command197);
				autoDumper(command198);
				autonomousInfo.isFinished = (*command197).isFinished && (*command198).isFinished;
				break;
			case(8):
				driveToWP(command199);
				autoDumper(command200);
				autonomousInfo.isFinished = (*command199).isFinished && (*command200).isFinished;
				break;
			case(9):
				driveToWP(command201);
				autoDumper(command202);
				timeout(command203);
				autonomousInfo.isFinished = (*command201).isFinished && (*command202).isFinished || (*command203).isFinished;
				break;
			case(10):
				autoDumper(command204);

				autonomousInfo.isFinished = (*command204).isFinished;
				break;
			case(11):
				autoDumper(command205);
				autoClaw(command206);
				autonomousInfo.isFinished = (*command205).isFinished && (*command206).isFinished;
				break;
			case(12):
				autoDumper(command207);

				autonomousInfo.isFinished = (*command207).isFinished;
				break;
			case(13):
				driveToWP(command208);

				autonomousInfo.isFinished = (*command208).isFinished;
				break;
			case(14):
				driveToWP(command209);
				timeout(command210);
				autonomousInfo.isFinished = (*command209).isFinished || (*command210).isFinished;
				break;
			case(15):
				driveToWP(command211);
				timeout(command212);
				autonomousInfo.isFinished = (*command211).isFinished || (*command212).isFinished;
				break;
			case(16):
				autoClaw(command213);

				autonomousInfo.isFinished = (*command213).isFinished;
				break;
			case(17):
				driveToWP(command214);
				timeout(command215);
				autonomousInfo.isFinished = (*command214).isFinished || (*command215).isFinished;
				break;
			case(18):
				autoDumper(command216);

				autonomousInfo.isFinished = (*command216).isFinished;
				break;
			case(19):
				driveToWP(command217);
				autoDumper(command218);
				timeout(command219);
				autonomousInfo.isFinished = (*command217).isFinished && (*command218).isFinished || (*command219).isFinished;
				break;
			case(20):
				driveToWP(command220);
				autoDumper(command221);
				timeout(command222);
				autonomousInfo.isFinished = (*command220).isFinished && (*command221).isFinished || (*command222).isFinished;
				break;
			case(21):
				autoDumper(command223);

				autonomousInfo.isFinished = (*command223).isFinished;
				break;
			case(22):
				autoClaw(command224);
				autoDumper(command225);
				autonomousInfo.isFinished = (*command224).isFinished && (*command225).isFinished;
				break;
			case(23):
				autoDumper(command226);

				autonomousInfo.isFinished = (*command226).isFinished;
				break;
			case(24):
				driveToWP(command227);
				timeout(command228);
				autonomousInfo.isFinished = (*command227).isFinished || (*command228).isFinished;
				break;
			case(25):
				driveToWP(command229);
				timeout(command230);
				autonomousInfo.isFinished = (*command229).isFinished || (*command230).isFinished;
				break;
			case(26):
				autoClaw(command231);

				autonomousInfo.isFinished = (*command231).isFinished;
				break;
			case(27):
				driveToWP(command232);
				timeout(command233);
				autonomousInfo.isFinished = (*command232).isFinished || (*command233).isFinished;
				break;
			case(28):
				autoDumper(command234);
				timeout(command235);
				autonomousInfo.isFinished = (*command234).isFinished || (*command235).isFinished;
				break;
			case(29):
				driveToWP(command236);
				autoDumper(command237);
				timeout(command238);
				autonomousInfo.isFinished = (*command236).isFinished && (*command237).isFinished || (*command238).isFinished;
				break;
			case(30):
				driveToWP(command239);
				autoDumper(command240);
				timeout(command241);
				autonomousInfo.isFinished = (*command239).isFinished && (*command240).isFinished || (*command241).isFinished;
				break;
			case(31):
				autoDumper(command242);

				autonomousInfo.isFinished = (*command242).isFinished;
				break;
			case(32):
				autoClaw(command243);
				autoDumper(command244);
				autonomousInfo.isFinished = (*command243).isFinished && (*command244).isFinished;
				break;
			case(33):
				autoDumper(command245);

				autonomousInfo.isFinished = (*command245).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(R_CUBENEAR):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command246);

				autonomousInfo.isFinished = (*command246).isFinished;
				break;
			case(2):
				driveToWP(command247);
				timeout(command248);
				autonomousInfo.isFinished = (*command247).isFinished || (*command248).isFinished;
				break;
			case(3):
				driveToWP(command249);
				timeout(command250);
				autonomousInfo.isFinished = (*command249).isFinished || (*command250).isFinished;
				break;
			case(4):
				driveToWP(command251);
				timeout(command252);
				autonomousInfo.isFinished = (*command251).isFinished || (*command252).isFinished;
				break;
			case(5):
				autoClaw(command253);

				autonomousInfo.isFinished = (*command253).isFinished;
				break;
			case(6):
				driveToWP(command254);
				autoDumper(command255);
				timeout(command256);
				autonomousInfo.isFinished = (*command254).isFinished && (*command255).isFinished || (*command256).isFinished;
				break;
			case(7):
				driveToWP(command257);
				autoDumper(command258);
				autonomousInfo.isFinished = (*command257).isFinished && (*command258).isFinished;
				break;
			case(8):
				driveToWP(command259);
				autoDumper(command260);
				autonomousInfo.isFinished = (*command259).isFinished && (*command260).isFinished;
				break;
			case(9):
				driveToWP(command261);
				autoDumper(command262);
				timeout(command263);
				autonomousInfo.isFinished = (*command261).isFinished && (*command262).isFinished || (*command263).isFinished;
				break;
			case(10):
				autoDumper(command264);

				autonomousInfo.isFinished = (*command264).isFinished;
				break;
			case(11):
				autoDumper(command265);
				autoClaw(command266);
				autonomousInfo.isFinished = (*command265).isFinished && (*command266).isFinished;
				break;
			case(12):
				autoDumper(command267);

				autonomousInfo.isFinished = (*command267).isFinished;
				break;
			case(13):
				driveToWP(command268);

				autonomousInfo.isFinished = (*command268).isFinished;
				break;
			case(14):
				driveToWP(command269);
				timeout(command270);
				autonomousInfo.isFinished = (*command269).isFinished || (*command270).isFinished;
				break;
			case(15):
				driveToWP(command271);
				timeout(command272);
				autonomousInfo.isFinished = (*command271).isFinished || (*command272).isFinished;
				break;
			case(16):
				autoClaw(command273);

				autonomousInfo.isFinished = (*command273).isFinished;
				break;
			case(17):
				driveToWP(command274);
				timeout(command275);
				autonomousInfo.isFinished = (*command274).isFinished || (*command275).isFinished;
				break;
			case(18):
				autoDumper(command276);

				autonomousInfo.isFinished = (*command276).isFinished;
				break;
			case(19):
				driveToWP(command277);
				autoDumper(command278);
				timeout(command279);
				autonomousInfo.isFinished = (*command277).isFinished && (*command278).isFinished || (*command279).isFinished;
				break;
			case(20):
				driveToWP(command280);
				autoDumper(command281);
				timeout(command282);
				autonomousInfo.isFinished = (*command280).isFinished && (*command281).isFinished || (*command282).isFinished;
				break;
			case(21):
				autoDumper(command283);

				autonomousInfo.isFinished = (*command283).isFinished;
				break;
			case(22):
				autoClaw(command284);
				autoDumper(command285);
				autonomousInfo.isFinished = (*command284).isFinished && (*command285).isFinished;
				break;
			case(23):
				autoDumper(command286);

				autonomousInfo.isFinished = (*command286).isFinished;
				break;
			case(24):
				driveToWP(command287);
				timeout(command288);
				autonomousInfo.isFinished = (*command287).isFinished || (*command288).isFinished;
				break;
			case(25):
				driveToWP(command289);
				timeout(command290);
				autonomousInfo.isFinished = (*command289).isFinished || (*command290).isFinished;
				break;
			case(26):
				autoClaw(command291);

				autonomousInfo.isFinished = (*command291).isFinished;
				break;
			case(27):
				driveToWP(command292);
				timeout(command293);
				autonomousInfo.isFinished = (*command292).isFinished || (*command293).isFinished;
				break;
			case(28):
				autoDumper(command294);
				timeout(command295);
				autonomousInfo.isFinished = (*command294).isFinished || (*command295).isFinished;
				break;
			case(29):
				driveToWP(command296);
				autoDumper(command297);
				timeout(command298);
				autonomousInfo.isFinished = (*command296).isFinished && (*command297).isFinished || (*command298).isFinished;
				break;
			case(30):
				driveToWP(command299);
				autoDumper(command300);
				timeout(command301);
				autonomousInfo.isFinished = (*command299).isFinished && (*command300).isFinished || (*command301).isFinished;
				break;
			case(31):
				autoDumper(command302);

				autonomousInfo.isFinished = (*command302).isFinished;
				break;
			case(32):
				autoClaw(command303);
				autoDumper(command304);
				autonomousInfo.isFinished = (*command303).isFinished && (*command304).isFinished;
				break;
			case(33):
				autoDumper(command305);

				autonomousInfo.isFinished = (*command305).isFinished;
				break;


			default:
				isAuto = 0;
				break;
		}
		break;
		case(PROG_SKILLS):
		switch(autonomousInfo.step)
		{
			case(1):
				autoClaw(command306);

				autonomousInfo.isFinished = (*command306).isFinished;
				break;
			case(2):
				driveToWP(command307);

				autonomousInfo.isFinished = (*command307).isFinished;
				break;
			case(3):
				driveToWP(command308);

				autonomousInfo.isFinished = (*command308).isFinished;
				break;
			case(4):
				autoClaw(command309);

				autonomousInfo.isFinished = (*command309).isFinished;
				break;
			case(5):
				autoDumper(command310);

				autonomousInfo.isFinished = (*command310).isFinished;
				break;
			case(6):
				autoDumper(command311);
				driveToWP(command312);
				timeout(command313);
				autonomousInfo.isFinished = (*command311).isFinished && (*command312).isFinished || (*command313).isFinished;
				break;
			case(7):
				autoDumper(command314);

				autonomousInfo.isFinished = (*command314).isFinished;
				break;
			case(8):
				autoClaw(command315);
				autoDumper(command316);
				autonomousInfo.isFinished = (*command315).isFinished && (*command316).isFinished;
				break;
			case(9):
				autoDumper(command317);

				autonomousInfo.isFinished = (*command317).isFinished;
				break;
			case(10):
				driveToWP(command318);
				timeout(command319);
				autonomousInfo.isFinished = (*command318).isFinished || (*command319).isFinished;
				break;
			case(11):
				autoClaw(command320);

				autonomousInfo.isFinished = (*command320).isFinished;
				break;
			case(12):
				autoDumper(command321);

				autonomousInfo.isFinished = (*command321).isFinished;
				break;
			case(13):
				autoDumper(command322);
				driveToWP(command323);
				timeout(command324);
				autonomousInfo.isFinished = (*command322).isFinished && (*command323).isFinished || (*command324).isFinished;
				break;
			case(14):
				autoDumper(command325);

				autonomousInfo.isFinished = (*command325).isFinished;
				break;
			case(15):
				autoClaw(command326);
				autoDumper(command327);
				autonomousInfo.isFinished = (*command326).isFinished && (*command327).isFinished;
				break;
			case(16):
				autoDumper(command328);

				autonomousInfo.isFinished = (*command328).isFinished;
				break;
			case(17):
				driveToWP(command329);

				autonomousInfo.isFinished = (*command329).isFinished;
				break;
			case(18):
				driveToWP(command330);
				timeout(command331);
				autonomousInfo.isFinished = (*command330).isFinished || (*command331).isFinished;
				break;
			case(19):
				autoDumper(command332);

				autonomousInfo.isFinished = (*command332).isFinished;
				break;
			case(20):
				driveToWP(command333);
				timeout(command334);
				autonomousInfo.isFinished = (*command333).isFinished || (*command334).isFinished;
				break;
			case(21):
				autoClaw(command335);

				autonomousInfo.isFinished = (*command335).isFinished;
				break;
			case(22):
				driveToWP(command336);
				autoDumper(command337);
				timeout(command338);
				autonomousInfo.isFinished = (*command336).isFinished && (*command337).isFinished || (*command338).isFinished;
				break;
			case(23):
				driveToWP(command339);
				autoDumper(command340);
				timeout(command341);
				autonomousInfo.isFinished = (*command339).isFinished && (*command340).isFinished || (*command341).isFinished;
				break;
			case(24):
				driveToWP(command342);
				autoDumper(command343);
				timeout(command344);
				autonomousInfo.isFinished = (*command342).isFinished && (*command343).isFinished || (*command344).isFinished;
				break;
			case(25):
				autoDumper(command345);

				autonomousInfo.isFinished = (*command345).isFinished;
				break;
			case(26):
				timeout(command346);

				autonomousInfo.isFinished = (*command346).isFinished;
				break;
			case(27):
				autoDumper(command347);
				autoClaw(command348);
				timeout(command349);
				autonomousInfo.isFinished = (*command347).isFinished && (*command348).isFinished || (*command349).isFinished;
				break;
			case(28):
				autoDumper(command350);

				autonomousInfo.isFinished = (*command350).isFinished;
				break;
			case(29):
				driveToWP(command351);
				timeout(command352);
				autonomousInfo.isFinished = (*command351).isFinished || (*command352).isFinished;
				break;
			case(30):
				autoClaw(command353);

				autonomousInfo.isFinished = (*command353).isFinished;
				break;
			case(31):
				driveToWP(command354);
				autoDumper(command355);
				timeout(command356);
				autonomousInfo.isFinished = (*command354).isFinished && (*command355).isFinished || (*command356).isFinished;
				break;
			case(32):
				autoDumper(command357);

				autonomousInfo.isFinished = (*command357).isFinished;
				break;
			case(33):
				timeout(command358);

				autonomousInfo.isFinished = (*command358).isFinished;
				break;
			case(34):
				autoDumper(command359);
				autoClaw(command360);
				timeout(command361);
				autonomousInfo.isFinished = (*command359).isFinished && (*command360).isFinished || (*command361).isFinished;
				break;
			case(35):
				driveToWP(command362);
				autoDumper(command363);
				timeout(command364);
				autonomousInfo.isFinished = (*command362).isFinished && (*command363).isFinished || (*command364).isFinished;
				break;
			case(36):
				driveToWP(command365);
				autoDumper(command366);
				timeout(command367);
				autonomousInfo.isFinished = (*command365).isFinished && (*command366).isFinished || (*command367).isFinished;
				break;
			case(37):
				driveToWP(command368);
				autoDumper(command369);
				timeout(command370);
				autonomousInfo.isFinished = (*command368).isFinished && (*command369).isFinished || (*command370).isFinished;
				break;
			case(38):
				driveToWP(command371);
				timeout(command372);
				autonomousInfo.isFinished = (*command371).isFinished || (*command372).isFinished;
				break;
			case(39):
				autoClaw(command373);

				autonomousInfo.isFinished = (*command373).isFinished;
				break;
			case(40):
				autoDumper(command374);

				autonomousInfo.isFinished = (*command374).isFinished;
				break;
			case(41):
				driveToWP(command375);
				autoDumper(command376);
				timeout(command377);
				autonomousInfo.isFinished = (*command375).isFinished && (*command376).isFinished || (*command377).isFinished;
				break;
			case(42):
				driveToWP(command378);
				autoDumper(command379);
				timeout(command380);
				autonomousInfo.isFinished = (*command378).isFinished && (*command379).isFinished || (*command380).isFinished;
				break;
			case(43):
				autoDumper(command381);
				autoClaw(command382);
				timeout(command383);
				autonomousInfo.isFinished = (*command381).isFinished && (*command382).isFinished || (*command383).isFinished;
				break;
			case(44):
				autoDumper(command384);
				timeout(command385);
				autonomousInfo.isFinished = (*command384).isFinished || (*command385).isFinished;
				break;
			case(45):
				driveToWP(command386);
				autoDumper(command387);
				timeout(command388);
				autonomousInfo.isFinished = (*command386).isFinished && (*command387).isFinished || (*command388).isFinished;
				break;
			case(46):
				driveToWP(command389);
				autoDumper(command390);
				timeout(command391);
				autonomousInfo.isFinished = (*command389).isFinished && (*command390).isFinished || (*command391).isFinished;
				break;
			case(47):
				driveToWP(command392);
				autoDumper(command393);
				timeout(command394);
				autonomousInfo.isFinished = (*command392).isFinished && (*command393).isFinished || (*command394).isFinished;
				break;
			case(48):
				driveToWP(command395);
				timeout(command396);
				autonomousInfo.isFinished = (*command395).isFinished || (*command396).isFinished;
				break;
			case(49):
				autoClaw(command397);

				autonomousInfo.isFinished = (*command397).isFinished;
				break;
			case(50):
				autoDumper(command398);
				timeout(command399);
				autonomousInfo.isFinished = (*command398).isFinished || (*command399).isFinished;
				break;
			case(51):
				driveToWP(command400);
				autoDumper(command401);
				timeout(command402);
				autonomousInfo.isFinished = (*command400).isFinished && (*command401).isFinished || (*command402).isFinished;
				break;
			case(52):
				driveToWP(command403);
				autoDumper(command404);
				timeout(command405);
				autonomousInfo.isFinished = (*command403).isFinished && (*command404).isFinished || (*command405).isFinished;
				break;
			case(53):
				autoDumper(command406);
				timeout(command407);
				autonomousInfo.isFinished = (*command406).isFinished || (*command407).isFinished;
				break;
			case(54):
				autoDumper(command408);
				autoClaw(command409);
				autonomousInfo.isFinished = (*command408).isFinished && (*command409).isFinished;
				break;
			case(55):
				autoDumper(command410);

				autonomousInfo.isFinished = (*command410).isFinished;
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
				driveToWP(command411);

				autonomousInfo.isFinished = (*command411).isFinished;
				break;
			case(2):
				driveToWP(command412);

				autonomousInfo.isFinished = (*command412).isFinished;
				break;
			case(3):
				autoDumper(command413);

				autonomousInfo.isFinished = (*command413).isFinished;
				break;
			case(4):
				autoClaw(command414);
				autoDumper(command415);
				timeout(command416);
				autonomousInfo.isFinished = (*command414).isFinished && (*command415).isFinished && (*command416).isFinished;
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
