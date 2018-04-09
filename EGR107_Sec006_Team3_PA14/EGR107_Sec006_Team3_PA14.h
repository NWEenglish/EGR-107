/*********************************************************************
* Author: Team3
* Course: EGR-107-006
* Date of Completion: IN_PROGRESS
* Program Name: EGR107_Sec006_Team3_PA14.h
* Inputs: None.
* Outputs: None.
* Description: This is the .h file used by the main .ino file to
*   control the robot's movements.
*********************************************************************/

/* #define speeds */
#define NORMAL_SPEED 150
#define RMSpeed 150
#define LMSpeed 150

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

// Ultrasonic sensor
#define trigPin 0
#define echoPin 1

// Line following array
#define linePin1 2
#define linePin2 3
#define linePin3 4
#define linePin4 5
#define linePin5 6

/* Function Declarations */
// Movement
void stopMotors();
void moveForward();
void reverseMotors();
void turnRight();
void turnLeft();
void slightRight();
void slightLeft();


// Sensors
double ultrasonic();
double IRdistance();

/////////////////////////////////////////////////////////////////////
//////////////////////// Robot Functions ////////////////////////////
/////////////////////////////////////////////////////////////////////

/********************************************************************
*  All states for the robot
********************************************************************/
enum states {
  FIND_BALL,
  DETECT_OBJ,
  IS_BALL,
  AVD_OBJ,
  FIND_GOAL,
  SCR_BALL
};

/********************************************************************
*  Structure of the robot
********************************************************************/
struct Robot {
  enum states currentState = FIND_BALL;
};


/////////////////////////////////////////////////////////////////////
//////////////////////// Movement Functions /////////////////////////
/////////////////////////////////////////////////////////////////////

/********************************************************************
*  Stop motors function
********************************************************************/
void stopMotors() {

  Serial.println("Stopping motor!");

  // Right Motor
  analogWrite(RIGHT_PWM_PIN,0); //Controls a PWM signal on pin 6
  digitalWrite(RIGHT_IN1_PIN, LOW);
  digitalWrite(RIGHT_IN2_PIN, LOW);

  // Left Motor
  analogWrite(LEFT_PWM_PIN,0); //Controls a PWM signal on pin 6
  digitalWrite(LEFT_IN1_PIN, LOW);
  digitalWrite(LEFT_IN2_PIN, LOW);

  delay(500);
}

/*********************************************************************
 *  Move forward function
 ********************************************************************/
void moveForward() {

    Serial.println("Moving Forwards!");

    // Right Motor
    analogWrite(RIGHT_PWM_PIN, RMSpeed );
    digitalWrite(RIGHT_IN1_PIN, LOW);
    digitalWrite(RIGHT_IN2_PIN, HIGH);

    // Left Motor
    analogWrite(LEFT_PWM_PIN, LMSpeed );
    digitalWrite(LEFT_IN1_PIN, HIGH);
    digitalWrite(LEFT_IN2_PIN, LOW);
}

/*********************************************************************
 *  Reverse motors function
 ********************************************************************/
void reverseMotors() {

    Serial.println("Reversing!");

    // Right Motor
    analogWrite(RIGHT_PWM_PIN, RMSpeed);
    digitalWrite(RIGHT_IN1_PIN, HIGH);
    digitalWrite(RIGHT_IN2_PIN, LOW);

    // Left Motor
    analogWrite(LEFT_PWM_PIN, LMSpeed);
    digitalWrite(LEFT_IN1_PIN, LOW);
    digitalWrite(LEFT_IN2_PIN, HIGH);
}

/*********************************************************************
 *  Turn right function
 ********************************************************************/
 void turnRight() {

    Serial.println("Turning Right!");

    // Right motor
    analogWrite(RIGHT_PWM_PIN, 0);
    digitalWrite(RIGHT_IN1_PIN, LOW);
    digitalWrite(RIGHT_IN2_PIN, HIGH);

    // Left motor
    analogWrite(LEFT_PWM_PIN, LMSpeed);
    digitalWrite(LEFT_IN1_PIN, HIGH);
    digitalWrite(LEFT_IN2_PIN, LOW);
 }

/*********************************************************************
 *  Turn left function
 ********************************************************************/
 void turnLeft() {

    Serial.println("Turning Left!");

    // Right motor
    analogWrite(RIGHT_PWM_PIN, RMSpeed);
    digitalWrite(RIGHT_IN1_PIN, LOW);
    digitalWrite(RIGHT_IN2_PIN, HIGH);

    // Left motor
    analogWrite(LEFT_PWM_PIN, 0);
    digitalWrite(LEFT_IN1_PIN, HIGH);
    digitalWrite(LEFT_IN2_PIN, LOW);
 }

/*********************************************************************
 *  Slight right turn function
 ********************************************************************/
void slightRight() {

    Serial.println("Slight Right Turn!");

    // Right motor
    analogWrite(RIGHT_PWM_PIN, 0.25*RMSpeed);
    digitalWrite(RIGHT_IN1_PIN, LOW);
    digitalWrite(RIGHT_IN2_PIN, HIGH);

    // Left motor
    analogWrite(LEFT_PWM_PIN, 0.5*LMSpeed);
    digitalWrite(LEFT_IN1_PIN, HIGH);
    digitalWrite(LEFT_IN2_PIN, LOW);
}

/*********************************************************************
 *  Slight left turn function
 ********************************************************************/
void slightLeft() {

    Serial.println("Slight left Turn!");

    // Right motor
    analogWrite(RIGHT_PWM_PIN, 0.5*RMSpeed);
    digitalWrite(RIGHT_IN1_PIN, LOW);
    digitalWrite(RIGHT_IN2_PIN, HIGH);

    // Left motor
    analogWrite(LEFT_PWM_PIN, 0.25*LMSpeed);
    digitalWrite(LEFT_IN1_PIN, HIGH);
    digitalWrite(LEFT_IN2_PIN, LOW);
}

//////////////////////////////////////////////////////////////////////
//////////////////////// Sensor Functions ////////////////////////////
//////////////////////////////////////////////////////////////////////

/*********************************************************************
 *  Ultrasonic distance function
 ********************************************************************/
double ultrasonic() {
    unsigned long time1;
    unsigned long time2;
    unsigned long tempTime;
    unsigned long pulseWidth;
    double dist = 0;

    // send out ultra sonic wave
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    time1 = micros();

    // wait for echo
    while(digitalRead(echoPin) == 0){

        //timeout of loop if no objects are detected in range
        tempTime = micros();
        if(tempTime - time1 > 23200){
            dist = -1;
            break;
        }
    }

    // measure how long echo pin was HIGH for
    time1 = micros();
    while(digitalRead(echoPin) == 1){

    }
    time2 = micros();

    // calulate dist if echo returned in an amount of time to indecate object in range
    pulseWidth = time2 - time1;
    if(dist != -1){
        dist = pulseWidth / 58.0;
    }

    // set dist to -1 if pulse width indecates no objects in range
    if(pulseWidth > 23200){
      dist = -1;
    }


    // return dist in cm if an object was in range
    // if there was no object in range, -1 is returned
    return dist;
}

/*********************************************************************
 *  IR distance function
 ********************************************************************/
double IRdistance() {
    // read value from IR sensor
    double volt = analogRead(A1);

    // linearize and convert voltage to distance in cm
    double dist = (6787.0/(volt - 3.0)) - 4.0;

    // return distance in cm
    return dist;
}







