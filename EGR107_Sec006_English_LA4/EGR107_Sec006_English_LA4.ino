/***********************************************************************

Author: Nicholas English
Course: EGR-107-006
Assignment: Learning Activity 4
Date of Completion: 2/14/2018
Program Name: EGR107_Sec006_English_LA4
Inputs: Equipment, Direction, Speed
Outputs: Moves the motor/servos in a particular direction and at a
  specified speed.
Description: The user input what type of equipment he/she is using, the
  desired direction, and the desired speed. The program then runs the
  hardware accordingly to what the user specified.
  
***********************************************************************/

#include <Servo.h>

/* Global variable(s) */
Servo servo;
char Direction;
int Speed;

void setup() {
  // Initialize serial communications at 9600 bps:
  Serial.begin(9600); 
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  servo.attach(8);
  
}

void loop() {

  /* Gets user input. */
  Serial.println("What are you running?");
  Serial.println("Enter 1 for DC Motor.");
  Serial.println("Enter 2 for Continuous Servo.");
  Serial.println("Enter 3 for Postionion Servo.\n");

  int choice = Serial.parseInt();

  /* Checks for valid user input. */
  if(choice != 1 && choice != 2 && choice != 3) {
    Serial.println("\nInvalid choice! Defaulting to DC Motor.\n");
    choice = 1;
  }

  /* Cases run depending on what chouce was selected. */
  switch( choice ) {
    case 1:
      dcMotor;
      break;

    case 2:
      contServo();
      break;

    case 3:
      posServo;
      break;

    default:      // Only here if code some how fails and reaches it.
      dcMotor();
      Serial.println("ERROR 01 - See developer/IT if you see this statement!");
      break;
  }
}

void getDirectionAndSpeed() {
    /* Gets the direction of the motor from the user. */
  Serial.println("Enter 'F' for forwards OR enter 'B' for backwards:\t");
  Direction = Serial.read();

  if(Direction == 'f')
    Direction = 'F';

  if(Direction == 'b');
    Direction = 'B';

  /* Checks for valid user input. */
  if( Direction != 'F' && Direction != 'B' ) {
    Serial.println("Input was invalid! Setting direction to forward.");
    Direction = 'F';
  }

  /* Gets the speed of the motor from the user. */
  Serial.println("Please enter a value 0-9 for the speed:\t");
  int Speed = Serial.parseInt();

  /* Checks for valid user input. */
  if( Speed < 0 || Speed > 9) {
    Serial.println("Input was invalid! Setting speed to 4.");
    Speed = 4;
  }
  
  Speed = ( 28 * Speed);
}

void dcMotor() {
  getDirectionAndSpeed();
  dcMotor_DirectionAndSpeed( Direction, Speed );
}

void contServo() {
  getDirectionAndSpeed();

  int incSpeed = Speed / 5;
  int i;

  for(i = 1; i <= 5; i++) {
    if(Direction == 'F')
      Speed = 90 + ( incSpeed * i );

    if(Direction == 'B')
      Speed = 90 - ( incSpeed * i );

    servo.write(Speed);
  }  
}

void posServo() {
  int angle;
  int i;

  /* Gets user input. */
  Serial.println("What angle would you like this Servo to run to?");
  Serial.println("Please select an angle between 0 and 180, and that is a mutliple of 10:\t");

  angle = Serial.parseInt();

  /* Checks user input. */
  if( angle < 0 || angle > 180 ) {
    Serial.println("\nInvalid input. Defaulting 90*");
    angle = 90;
  }

  /* Increments 10* until it reaches the desired angle. */
  for(i = 0; i <= 180; i = i + 10) {
    servo.write(i);
    delay(500);
  }  
}

void dcMotor_DirectionAndSpeed( char Direction, int currentSpeed ) {
  
  if(Direction == 'F' ) {

    // Speeds up the motor
    analogWrite(6, (255 - currentSpeed) ); //Controls a PWM signal on pin 6
    digitalWrite(13,LOW);
    //Set direction "Forward"
    Serial.println("Moving forwards!");
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
  }
  
  else if(Direction == 'B' ) {
    analogWrite(6, currentSpeed); //Controls a PWM signal on pin 6
    Serial.println("Moving backwards!");
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
  }
  
  else {
    Serial.println("ERROR! SOMETHING HAS GONE WRONG! EMERGENCY STOP!");
    stopMotor();
  }
}

void stopMotor() {
  Serial.println("Stopping motor!");
  analogWrite(6,0); //Controls a PWM signal on pin 6
  digitalWrite(7,LOW); 
  digitalWrite(8,LOW);
}
