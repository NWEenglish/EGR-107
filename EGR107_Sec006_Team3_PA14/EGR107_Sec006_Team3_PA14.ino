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
QTRSensorsRC qtr((char[]) {LINE_PIN1,LINE_PIN2,LINE_PIN3,LINE_PIN4,LINE_PIN5}, 5);

/* Gate positions */
#define OPENED 90
#define CLOSED 0

/* Function Declaration(s) */
/*
void stopMotors();
void moveForward();
void reverseMotors();
void turnRight();
void turnLeft();
*/

/* Creates an object of type Robot */
struct Robot robot;

/* Global Variable(s) */
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
  servo.attach(SERVO_PIN);
  servo.write(CLOSED);

  // Setup ultrasonic sensor
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  // Setup IR disance sensor
  pinMode(A0, INPUT);

  // Setup line following array
  pinMode(LINE_PIN1, INPUT);
  pinMode(LINE_PIN2, INPUT);
  pinMode(LINE_PIN3, INPUT);
  pinMode(LINE_PIN4, INPUT);
  pinMode(LINE_PIN5, INPUT);
  

  // Delay before movement
  delay(2000);

  // Open gate
  servo.write(OPENED);

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
  servo1.write(OPENED);
  delay(1000);

  // Move back
  reverseMotors();
  delay(1000);

  // Stop
  stopMotors();
  delay(500);

  // Close gate
  servo1.write(CLOSED);
  delay(1000);

  // Move forward
  moveForward();
  delay(1000);

  // Idea: move forward untill all line follower sensors read black.
  
}



