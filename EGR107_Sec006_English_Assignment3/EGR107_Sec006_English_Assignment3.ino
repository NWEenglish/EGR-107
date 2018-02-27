/***********************************************************************

Author: Nicholas English
Course: EGR-107-006
Assignment: Assignment 3
Date of Completion: 1/31/2018
Program Name: EGR107_Sec006_English_Assignment3
Inputs: None.
Outputs: Builtin LED lights up each time the ditMark or dahMark is
  called. Each time of the print_ functions is called, it prints the
  letter to the monitor. The code also does a one time call to the
  printLogo function which prints Nicholas English's ASCII art logo to
  the monitor.
Description: The code lights up the builtin LED light and prints
  letters to the monitor. The LED lights up to follows a morse code
  patters. Each time the next letter begins to be signaled in morse
  code, the letter is printed to the monitor. N-W-E is being signaled
  in morse code.
  
***********************************************************************/

/* This function runs once when you press reset or power the board. */
void setup() {
  
  // Initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(9600);

  printLogo();
}

/* This function runs over and over again forever. */
void loop() {
  
  printN();
  delay(1000);    // Delay in between letters.
  printW(); 
  delay(1000);    // Delay in between letters.
  printE();
  delay(3000);    // Delay in between words.
  
}

/* Prints the logo used by Nicholas English's code */
void printLogo() {

  Serial.println(" _   ___        _______    ____          _      ");
  Serial.println("| \\ | \\ \\      / / ____|  / ___|___   __| | ___");
  Serial.println("|  \\| |\\ \\ /\\ / /|  _|   | |   / _ \\ / _` |/ _ \\");
  Serial.println("| |\\  | \\ V  V / | |___  | |__| (_) | (_| |  __/");
  Serial.println("|_| \\_|  \\_/\\_/  |_____|  \\____\\___/ \\__,_|\\___|\n");
  
}

/* Prints the letter N in morse code and as text. */
void printN() {

  Serial.println("N\n");

  dahMark();                // Calls the ditMakr function.
  ditMark();                // Calls the ditMark function.
  
}

/* Prints the letter W in morse code and as text. */
void printW() {

  Serial.println("W\n");

  ditMark();                // Calls the ditMark function.
  dahMark();                // Calls the dahMark function.
  dahMark();                // Calls the dahMark function.
  
}

/* Prints the letter E in morse code and as text. */
void printE() {

  Serial.println("E\n");      // Prints 'N' to the monitor.

  ditMark();                  // Calls the ditMark function.
  
}

/* "Dot Duration" that runs for 0.5 second. */
void ditMark() {

  digitalWrite(LED_BUILTIN, HIGH);   // Turns the LED on.
  delay(500);                        // Waits for half second.
  digitalWrite(LED_BUILTIN, LOW);    // Turns the LED off.
  delay(500);                        // Waits for a half second.
  
}

/* "Dash Duration" that runs for 1.5 seconds. */
void dahMark() {

  digitalWrite(LED_BUILTIN, HIGH);   // Turns the LED on.
  delay(1500);                       // Waits for 1.5 Seconds.
  digitalWrite(LED_BUILTIN, LOW);    // Turns the LED off.
  delay(500);                        // Waits for 0.5 seconds.
  
}

