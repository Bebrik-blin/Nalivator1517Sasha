//#include <MultiStepper.h>
#include <AccelStepper.h>
#include "topa.h"
AccelStepper stepper;
#define LED_PIN 2
/*
void firstZak(){
  const int steps_per_ml = 100;
  stepper.setMaxSpeed(150);
  stepper.moveTo(500);
  delay(100);
  stepper.moveTo(100);
}

void secondZak(){
  const int steps_per_ml = 100;
  stepper.setMaxSpeed(1000);
  stepper.moveTo(100);
  delay(100);
  stepper.moveTo(500);
}

void thirdZak(){
  const int steps_per_ml = 100;
  stepper.setMaxSpeed(1000);
  stepper.moveTo(500);
  delay(100);
  stepper.moveTo(1000);
}

void fourZak(){
  const int steps_per_ml = 100;
  stepper.setMaxSpeed(1000);
  stepper.moveTo(500);
  delay(100);
  stepper.moveTo(100);
  delay(100);
  stepper.moveTo(500);
}
*/

void waiting_state(){
  Serial.println("Waiting...");
  //firstZak();
}

void setap_state(){
  Serial.println("Ready for work.");
  delay(10);
  waiting_state();
  //secondZak();
}

void service_mode_state(){
  Serial.println("Service mode in process...");
  digitalWrite(LED_PIN, 1);
  //thirdZak();
}

void cooking_state(){
  Serial.println("Cooking...");
  digitalWrite(LED_PIN, 0);
  //fourZak();
}

void give_out_state(){
  Serial.println("Take out.");
}
