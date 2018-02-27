
/* Global variable(s) */
int LMSpeed = 50;
int RMSpeed = 75;

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
  delay(1500);
}

/* Loop function */
void loop() {
  moveForward();
  delay(2000);
  stopMotor();
  delay(5000);
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

