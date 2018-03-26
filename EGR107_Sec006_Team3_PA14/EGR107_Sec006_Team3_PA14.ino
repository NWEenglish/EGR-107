/*********************************************************************
* Author: Team 3
* Course: EGR-107-006
* Date of Completion: IN_PROGRESS
* Program Name: EGR107_Sec006_Team3_PA14.h
* Inputs: None.
* Outputs: None.
* Description: The main file for running the robot in the final
*   competition.
*********************************************************************/

/* Function Declaration(s) */
void stopMotors();
void moveForward();
void reverseMotors();
void turnRight();
void turnLeft();

/* Global Variable(s) */
int LMSpeed = 200;
int RMSpeed = 200;
int rightPWM = 6;
int right1 = 7;
int right2 = 8;
int left1 = 9;
int left2 = 10;
int leftPWM = 11;

void setup() {

  /* Initialize serial communication */
  Serial.begin(9600);

  // Setup for right motor
  pinMode(rightPWM, OUTPUT);
  pinMode(right1, OUTPUT);
  pinMode(right2, OUTPUT);

  // Setup for left motor
  pinMode(left1, OUTPUT);
  pinMode(left2, OUTPUT);
  pinMode(leftPWM, OUTPUT);

  // Delay before movement
  delay(2000);

}

void loop() {

}
