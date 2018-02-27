int LMSpeed = 55;
int RMSpeed = 60;

int postDelay = 41;
int turn = 1;         // 0 = left, 1 = right

int trackerDetection();
void stopMotor();
void moveMotor();
int checkLeftFWD();
int checkRightFWD();

/* Setup function */
void setup() {

  // Initialize serial communication at 9600 bps
  Serial.begin(9600);

  // Setup for right side motor
  pinMode(6,OUTPUT);  // Speed
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  // Setup for left side motor
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT); // Speed

  // Delay before moving
  delay(2000);
}

/* Loop function */
void loop() {
  
  if( trackerDetection() ) {
    Serial.print("\nTracker Sensor has detected something!\n");
    moveForward();    
  } 
  
  else if ( !trackerDetection() ) {
    Serial.print("\nTracker Sensor has NOT detected anything!\n");
    
    if(turn == 1) {
      if(checkLeftFWD());
      //else if(checkRightBack());
      else if(checkRightFWD());
      //else if(checkLeftBack());
      //else
        //reverseMotor();
      turn = 0;
    }

    else if (turn == 0) {
      if(checkRightFWD());
      //else if(checkLeftBack());
      else if(checkLeftFWD());
      //else if(checkRightBack());
      //else
        //reverseMotor();
      turn = 1;
    }

    stopMotor();
  } 
  
  else {
    Serial.print("\nSomething has gone wrong with the Tracker Sensor!");
    Serial.print("Please see IT/developer for assistance if problem persists.");
  }
  
  delay(100);
}
/*********************************************************************
 *  Move forward function
 ********************************************************************/
void moveForward() {
    int i;
  
  Serial.println("Moving Forwards!");

    // Right Motor
    analogWrite(6, RMSpeed );
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);

    // Left Motor
    analogWrite(11, LMSpeed );
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
}

/********************************************************************
*  Stop motor function
********************************************************************/
void stopMotor() {
  
  Serial.println("Stopping motor!");
  analogWrite(6,0); //Controls a PWM signal on pin 6

  // Right Motor
  analogWrite(6,0); //Controls a PWM signal on pin 6
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);

  // Left Motor
  analogWrite(11,0); //Controls a PWM signal on pin 6
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);

  delay(1000);
}

/*********************************************************************
 *  Functions for Tracker Sensor
 ********************************************************************/
int trackerDetection() {

  //Serial.println(digitalRead(12));

  if ( digitalRead(12) == HIGH )
    return 0;   // Has not detected

  else if(digitalRead(12) == LOW)
    return 1;   // Has detected

  else
    return 2;
}

/*********************************************************************
 *  Move backward function
 ********************************************************************/

void reverseMotor() {

  Serial.println("Beacking up");

  while( !trackerDetection() ) {

    // Right Motor
    analogWrite(6,RMSpeed + 10); //Controls a PWM signal on pin 6
    digitalWrite(7, HIGH);
    digitalWrite(8, LOW);
  
    // Left Motor
    analogWrite(11,LMSpeed); //Controls a PWM signal on pin 6
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
  
    delay(20);
    
    stopMotor();

    if(checkLeftFWD());
    else if(checkRightFWD());
   }

   delay(postDelay);
}

/*********************************************************************
 *  Check left forwards function
 ********************************************************************/
int checkLeftFWD() {

  Serial.println("Turning Left");

  /* Variable(s) */
  int i = 0;
  while( !trackerDetection() && i < 65 ) {

    /* Movement */
    // Right Motor
    analogWrite(6,  RMSpeed + 20);
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  
    // Left Motor
    analogWrite(11, 0);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    
    delay(50);
    i++;
  }
  delay(postDelay);
  stopMotor();

  if ( i < 65 )
    return 1;
  else
    return 0;
}

 /*********************************************************************
 *  Check right forwards function
 ********************************************************************/
int checkRightFWD() {

    Serial.println("Turning Right");
  
  /* Variable(s) */
  int i = 0;
  
  while( !trackerDetection() && i < 65 ) {
    
    /* Movement */
    // Right Motor 
    analogWrite(6, 0);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);

    // Left Motor
    analogWrite(11, LMSpeed + 15);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    
    delay(50);
    i++;
    
  }

  delay(postDelay);

  stopMotor();

  if ( i < 65 )
    return 1;
  else
    return 0;
}
 
