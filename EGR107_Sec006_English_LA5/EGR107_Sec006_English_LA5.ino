/***********************************************************************
Author: Nicholas English
Course: EGR-107-006
Assignment: Learning Activity 5
Date of Completion: 2/19/2018
Program Name: EGR107_Sec006_English_LA5
Inputs: N/A
Outputs: Temperature, distance (using Ultrasonic AND Sharp IR), and if
  a reflective object is detected.
Description: This software makes use of four different sensors to
  measure temperature, distance, and if a reflective sensor has been
  detected.
***********************************************************************/

/* Include statements */
#include <QTRSensors.h>

/* Max distance (400 cm) */
const unsigned int MAX_DIST = 23200;

/* Pins */
const int ULTRA_TRIG_PIN = 7;
const int ULTRA_ECHO_PIN = 8;

const int IR_sensorPin = A5;
const int LEDPin = 13;

// Uses analog inputs 2 or digital pins 16.
QTRSensorsRC qtr((char[]) {2}, 1);


/* Setup Function */
void setup() {
  
  /* Variable(s) */
  int i;  // Used for a for loop.
  
  Serial.begin(9600);
  
  pinMode(ULTRA_TRIG_PIN, OUTPUT);
  digitalWrite(ULTRA_TRIG_PIN, LOW);

  pinMode(LEDPin, OUTPUT);

  /* Calibration for Tracker Sensor. */
  for(i = 5; i > 0; i--) {
    Serial.print("Please be ready to begin inital calibration in ");
    Serial.print(i);
    Serial.print(" seconds.\n");
    delay(1000);
  }

  Serial.print("Beginning calibration!\n");
  Serial.print("Please allow up to 5 seconds for calibration to complete!\n\n");

  for (i = 0; i < 250; i++) {
    qtr.calibrate();
    delay(20);
  }

  Serial.print("\nCalibration complete!\n\n");
}

/* Loop Function */
void loop() {

  /*********************************************************************
   *  Tracker Sensor
   ********************************************************************/
   /* Variable(s) */
   int isDetected;
   
   isDetected = trackerDetection();

   if( isDetected == 1 ) {
    Serial.print("\nTracker Sensor has detected something!");
    
   } else if ( isDetected == 0 ) {
    Serial.print("\nTracker Sensor has NOT detected anything!");
    
   } else {
    Serial.print("\nSomething has gone wrong with the Tracker Sensor!");
    Serial.print("Please see IT/developer for assistance if problem persists.");
   }




  /*********************************************************************
   *  Sharp IR Sensor
   ********************************************************************/

  /* Variable(s) */
  float cm_distance;

  cm_distance = find_IR_distance();

  Serial.print("\nIR DISTANCE = ");
  Serial.print(cm_distance);
  Serial.print(" cm");

  /*********************************************************************
   *  Ultrasonic Sensor
   ********************************************************************/

  /* Variable(s) */
  float cm;
  float inches;
  
  cm = findDistance();
  inches = cm * 0.3937;

  if( cm == -1 ) {
    Serial.print("\nUltrasonic Distance is out of range!");
    
  } else {
    Serial.print("\nUltrasonic Distance = ");
    Serial.print(cm);
    Serial.print(" cm = ");
    Serial.print(inches);
    Serial.print(" in");
  }


  /*********************************************************************
   *  LM35 Temp Sensor
   ********************************************************************/
  
  /* Variable(s) */
  float celsius;
  float fahrenheit;

  /* Finds the temperature in celsius. */
  celsius = findTemp();
  Serial.print("\nTEMPERATURE = ");
  Serial.print(celsius); // display temperature value
  Serial.print("*C = ");

  /* Finds the temperature in fahrenheit. */
  fahrenheit = convertTemp( celsius );
  Serial.print(fahrenheit);
  Serial.print("*F\n");


  /*********************************************************************
   *  End of code reached in loop
   ********************************************************************/
  Serial.print("\n\n");
  delay(1000);
}

/*********************************************************************
 *  Functions for Tracker Sensor
 ********************************************************************/
int trackerDetection() {

  /* Variable(s) */
  unsigned int TS_sensors[1];
  
  //int position = qtr.readLine(TS_sensors);

  if ( !digitalRead(9) )
    return 0;

  else
    return 1;
}

/*********************************************************************
 *  Functions for Sharp IR Sensor
 ********************************************************************/
float find_IR_distance() {
  float IR_sensorValue = analogRead (IR_sensorPin);
  digitalWrite (LEDPin, HIGH);
  delay (100);
  digitalWrite (LEDPin, LOW);
  delay (100);

  return ( ( 6787 / ( IR_sensorValue - 3) ) - 4 );
}

/*********************************************************************
 *  Functions for Ultrasonic Sensor
 ********************************************************************/

/* Finds the distance in centimeters. */
float findDistance() {

  /* Variable(s) */
  unsigned long t1;
  unsigned long t2;
  unsigned long pulse_width;

  
  // Hold the trigger pin high for at least 10 us
  digitalWrite(ULTRA_TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(ULTRA_TRIG_PIN, LOW);

  // Wait for pulse on echo pin
  while ( digitalRead(ULTRA_ECHO_PIN) == 0 );

  // Measure how long the echo pin was held high (pulse width)
  // Note: the micros() counter will overflow after ~70 min
  t1 = micros();
  while ( digitalRead(ULTRA_ECHO_PIN) == 1 );
  t2 = micros();
  pulse_width = t2 - t1;

  // Print out results
  if ( pulse_width > MAX_DIST ) {
    return -1;
  } else {
    
  return ( pulse_width / 58.0 );

  }

}

/*********************************************************************
 *  Function for LM35 Temp Sensor
 ********************************************************************/

/* Finds the temperature in Celsius. */
float findTemp() {
  float tempReading = analogRead(A0);
  return tempReading * 0.48828125; // convert the analog volt to its temperature equivalent
}

/* Conversion Function from Celsius to Fahrenheit. */
/* Accepts the temperature in celsius and converts it to fahrenheit. */
float convertTemp( float celsius) {
  float fahrenheit = ( ( celsius * 9 ) / 5) + 32;
  return fahrenheit;
}

