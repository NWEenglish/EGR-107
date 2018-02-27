

void setup() {
  // Initialize serial communications at 9600 bps:
  Serial.begin(9600); 

  // Left Side
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);

  // Right side
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
}

void loop() {

  int i;

  delay(5000);  // Waits 5 seconds after being powered on.

  // First lap
  for(i = 0; i < 2; i++) {
    moveForward();
    stopMotor();
    turn240();
    stopMotor();
    delay(2000);
  }

  // Turns around and last line segment.
  moveForward();
  stopMotor();
  turn180();
  stopMotor();
  delay(2000);

  // Second lap
  for(i = 0; i < 2; i++) {
    moveForward();
    stopMotor();
    turn60();
    stopMotor();
    delay(2000);
  }

  // Last line segment
  moveForward();
  stopMotor();

  
}

void moveForward() {
  int i;
  
  Serial.println("Moving Forwards!");

  // Speeds up
  Serial.println("Speeding up!");
  for(i = 1; i <= 3; i++) {

    // Left Motor
    analogWrite(6, (220 / 3) * i );
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);

    // Right Motor
    analogWrite(11, (250 / 3) * i );
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    
    delay(500);
  }

  // Slows down
  Serial.println("Slowing down!");
  for(i = 1; i <= 3; i++) {

    // Left Motor
    analogWrite(6, 220 - ( (220 / 3) * i ) );
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);

    // Right Motor
    analogWrite(11, 250 - ( (250/ 3) * i ) );
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    
    delay(500);
  }
}

void turn240() {
  Serial.println("Rotating 240*!");

  // Left Motor
  analogWrite(6, 150);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  
  // Right Motor
  analogWrite(11, 150);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  delay(6000);
}

void turn180() {
  Serial.println("Rotating 180*!");

  // Left Motor
  analogWrite(6, 150);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  
  // Right Motor
  analogWrite(11, 150);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  delay(3125);
}

void turn60() {
  Serial.println("Rotating 60*!");

  // Left Motor
  analogWrite(6, 150);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);

  // Right Motor
  analogWrite(11, 150);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  
  delay(1312);
}

void stopMotor() {
  delay(500);
  
  Serial.println("Stopping motor!");
  analogWrite(6,0); //Controls a PWM signal on pin 6

  // Left Motor
  analogWrite(6,0); //Controls a PWM signal on pin 6
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);

  // Right Motor
  analogWrite(11,0); //Controls a PWM signal on pin 6
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);

  delay(4000);
}

