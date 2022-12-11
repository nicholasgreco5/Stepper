// This #include statement was automatically added by the Particle IDE.
#include "String.h"

// This #include statement was automatically added by the Particle IDE.
#include <Stepper.h>

// Import the necessary libraries
#include <Particle.h>

// Allows the code to run when cloud is not connected
SYSTEM_THREAD(ENABLED);

// Set up the stepper motor
const int stepsPerRevolution = 2083;  // Change this to match your stepper motor
const int stepperPin1 = D2;
const int stepperPin2 = D3;
const int stepperPin3 = D4;
const int stepperPin4 = D5;

Stepper stepper(stepsPerRevolution, stepperPin1, stepperPin2, stepperPin3, stepperPin4);

void setup() {
  // Set the stepper motor's speed
  stepper.setSpeed(15);  // 15 RPM

  // Set up a function to receive the countdown timer value from the website
    Particle.function("setTimer", onSetTimer);
    Particle.function("closeBlinds", onCloseBlinds);
}

// Set up a variable to hold the countdown timer value
int onSetTimer(const String time) {
    String hours = time.substring(0,2);
    String minutes = time.substring(2,2);
    int seconds = (hours.toInt() * 60 * 60) + (minutes.toInt() * 60);
    int i = 0;
    int x = 0;
    
    // Check if the countdown timer has expired
  if (x != seconds) {
      delay(1000);
      x++;
  }
      
  while (i != 40) {
    stepper.step(stepsPerRevolution);
    i++;
  }
   return 0; 
}

  int onCloseBlinds(const String command) {
      if (command == "Y") {
        stepper.step(-stepsPerRevolution * 40);
        return 1;
      }
    return 0;
  }


void loop() {

}