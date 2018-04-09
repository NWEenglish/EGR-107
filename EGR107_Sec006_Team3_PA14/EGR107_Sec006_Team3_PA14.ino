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

#include "EGR107_Sec006_Team3_PA14.h"

/* Used for Calibration */
#include <Servo.h>
#include <QTRSensors.h>
Servo servo;
QTRSensorsRC qtr((char[]) {linePin1,linePin2,linePin3,linePin4,linePin5}, 5);

/* Gate positions */
#define opened 90
#define closed 0

/* Function Declaration(s) */
void stopMotors();
void moveForward();
void reverseMotors();
void turnRight();
void turnLeft();

/* Creates an object of type Robot */
struct Robot robot;

/* Global Variable(s) */
int rightPWM = 6;
int right1 = 7;
int right2 = 8;
int left1 = 9;
int left2 = 10;
int leftPWM = 11;
bool haveBall = false;

/********************************************************************
*  Setup function
********************************************************************/
void setup() {

  // Initialize serial communication
  Serial.begin(9600);

  // Setup for right motor
  pinMode(RIGHT_PWM_PIN, OUTPUT);
  pinMode(RIGHT_IN1_PIN, OUTPUT);
  pinMode(RIGHT_IN2_PIN, OUTPUT);

  // Setup for left motor
  pinMode(LEFT_IN1_PIN, OUTPUT);
  pinMode(LEFT_IN2_PIN, OUTPUT);
  pinMode(LEFT_PWM_PIN, OUTPUT);



  // Setup servo (starts closed)
  servo.attach(A0);
  servo.write(closed);

  // Setup ultrasonic sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Setup IR disance sensor
  pinMode(A0, INPUT);

  // Setup line following array
  pinMode(linePin1, INPUT);
  pinMode(linePin2, INPUT);
  pinMode(linePin3, INPUT);
  pinMode(linePin4, INPUT);

  

  // Delay before movement
  delay(2000);

  // Open gate
  servo.write(opened);

}

/********************************************************************
*  Loop function
********************************************************************/
void loop() {


  /***********************
  * FIND_BALL     - X
  * DETECT_OBJ    - X
  * IS_BALL       - X
  * AVD_OBJ       - DONE
  * FIND_GOAL     - X
  * SCR_BALL      - DONE
  ***********************/
  switch(robot.currentState) {
    case FIND_BALL:

    break;
    case DETECT_OBJ:

    break;
    case IS_BALL:
    
      if(isBall() == true)
        robot.currentState = FIND_GOAL;

      else
        robot.currentState = AVD_OBJ;

    break;
    case AVD_OBJ:
      reverseMotors();
      turnRight();
      robot.currentState = FIND_BALL;

    break;
    case FIND_GOAL:

      findGoal();

      if(isGoal() == true)
        robot.currentState = SCR_BALL;

    break;
    case SCR_BALL:
      scoreBall();
      reverseMotors();
      turnRight();
      turnRight();
      robot.currentState = FIND_BALL;

  }
}

/********************************************************************
*  isBall function
********************************************************************/

/********************************************************************
*  Score ball function
********************************************************************/
void scoreBall() {
  // Open gate
  servo1.write(opened);
  delay(1000);

  // Move back
  reverseMotors();
  delay(1000);

  // Stop
  stopMotors();
  delay(500);

  // Close gate
  servo1.write(closed);
  delay(1000);

  // Move forward
  moveForward();
  delay(1000);

  // Idea: move forward untill all line follower sensors read black.
  
}



