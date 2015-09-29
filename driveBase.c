#pragma config(Motor,  port1,           HC,            tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port3,           BL,            tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port4,           FR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           BR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           HL,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           HR,            tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port9,           FL,            tmotorVex393_MC29, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX)

//Competition Control and Duration Settings
#pragma competitionControl(Competition)
#pragma autonomousDuration(20)
#pragma userControlDuration(120)

#include "Vex_Competition_Includes.c"   //Main competition background code...do not modify!

/////////////////////////////////////////////////////////////////////////////////////////
//
//                          Pre-Autonomous Functions
//
// You may want to perform some actions before the competition starts. Do them in the
// following function.
//
/////////////////////////////////////////////////////////////////////////////////////////

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks running between
  // Autonomous and Tele-Op modes. You will need to manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// All activities that occur before the competition starts
	// Example: clearing encoders, setting servo positions, ...
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 Autonomous Task
//
// This task is used to control your robot during the autonomous phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task autonomous()
{
  // .....................................................................................
  // Insert user code here.
  // .....................................................................................

	AutonomousCodePlaceholderForTesting();  // Remove this function call once you have "real" code.
}

/////////////////////////////////////////////////////////////////////////////////////////
//
//                                 User Control Task
//
// This task is used to control your robot during the user control phase of a VEX Competition.
// You must modify the code to add your own robot specific commands here.
//
/////////////////////////////////////////////////////////////////////////////////////////

task usercontrol()
{
	// User control code here, inside the loop

	while (true)
	{
	  // This is the main execution loop for the user control program. Each time through the loop
	  // your program should update motor + servo values based on feedback from the joysticks.

	  // .............................2x........................................................
	  // Insert user code here. This is where you use the joystick values to update your motors, etc.
	  // .....................................................................................
		//motor[BR] = motor[FR] = (vexRT[Ch3] - vexRT[Ch1]); //Right side of the drive
	//	motor[BL] = motor[FL] = (vexRT[Ch3] + vexRT[Ch1]); //Left side of the drive;
		motor[FR] = abs(vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4]) > 24 ? vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4] : 0;
    motor[BR] =  abs(vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4]) > 24 ? vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4]: 0;
    motor[FL] = abs(vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch4]) > 24 ? vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch4]: 0;
    motor[BL] =  abs(vexRT[Ch3] + vexRT[Ch1] - vexRT[Ch4]) > 24 ? vexRT[Ch3] + vexRT[Ch1] - vexRT[Ch4]: 0;
		//motor[port9] = vexRT[ChCh2
	motor[port1] = motor[port10] = vexRT[Ch2];

		if (vexRT[Btn8U]) {
			motor[HL] = motor [HR] = 50;
	  }
	  else if (vexRT[Btn8D]) {
			motor[HL] = motor [HR] = -50;
	  }
	  else {
	  	motor[HL] = motor [HR] = 0;
	  }
	  if (vexRT[Btn7U]) {
	  	motor[HC] = 100;
	  }
	  else if (vexRT[Btn7D]) {
	  	motor[HC] = -100;
	  }
	  else {
	  	motor[HC] = 0;
	  }
	 // if (vexRT[
//		motor[HL] = motor [HR] = vexRT[Btn8U];
//		motor[HL] = motor [HR] = -(vexRT[Btn8D]);
	  UserControlCodePlaceholderForTesting(); // Remove this function call once you have "real" code.
	}
}
