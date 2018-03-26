/*********************************************************************
*
* Author: Nicholas English
* Course: EGR-107-006
* Date of Completion: 3/14/2018
* Program Name: EGR107_Sec006_English_Assignment4.h
* Inputs: None.
* Outputs: None.
* Description: Part one of three requirements for the assignment. This
*	program holds the necessary information to control the motors of
*	the robot.
*
*********************************************************************/

/* #define speeds */
#define NORMAL_SPEED 110

/* #define times */
#define TURN_240_NORM_TIME	// Normal 240* turn
#define TURN_240_RVRS_TIME	// Reversed 240* turn.

/* #define for right motor */
#define RIGHT_PWM_PIN 6
#define RIGHT_IN1_PIN 7
#define RIGHT_IN2_PIN 8

/* #define for left motor */
#define LEFT_PWM_PIN 11
#define LEFT_IN1_PIN 9
#define LEFT_IN2_PIN 10

/* All information needed for motors */
struct robotMotors {
	int leftPWM;
	int rightPWM;
};

/* All states for the robot */
enum states {
	START,
	FORWARD,
	TURN_240_NORM_STATE,
	TURN_240_RVRS_STATE,
  TURN_180_STATE,
	END
};

/* Structure of the robot */
struct Robot {
	struct robotMotors motors;
	enum states currentState = START;
};




