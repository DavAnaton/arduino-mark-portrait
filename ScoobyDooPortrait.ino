#include <Stepper.h>

#define MOTION_SENSOR 12
//#define JOYSTICK_X A4
//#define JOYSTICK_Y A5
#define STEP_PER_MINUTE 15
#define STEPS_PER_REVOLUTION 2048
#define SWITCH A0

Stepper stepperX(STEPS_PER_REVOLUTION, 8, 10, 9, 11);
Stepper stepperY(STEPS_PER_REVOLUTION, 4, 6, 5, 7);

bool isMoving = false;

void setup() {
  pinMode(MOTION_SENSOR, INPUT);
//  pinMode(JOYSTICK_X, INPUT);
//  pinMode(JOYSTICK_Y, INPUT);
  stepperX.setSpeed(STEP_PER_MINUTE);
  stepperY.setSpeed(STEP_PER_MINUTE);
  Serial.begin(9600);
}

void loop() {
//  int stepLength = 100;
//  if(analogRead(JOYSTICK_X) > 800){
//    stepperX.step(stepLength);
//  }
//  if(analogRead(JOYSTICK_X) < 200){
//    stepperX.step(-stepLength);
//  }
//  if(analogRead(JOYSTICK_Y) > 800){
//    stepperY.step(stepLength);
//  }
//  if(analogRead(JOYSTICK_Y) < 200){
//    stepperY.step(-stepLength);
//  }
  int motionDetected = digitalRead(MOTION_SENSOR);
  if(motionDetected){
    Serial.println("Motion Detected!");
    isMoving = true;  
  }else{
    if(isMoving){
      Serial.println("Motion ended!");
      isMoving = false;
      glanceLeftRight();
    }
  }
}

void glanceLeftRight(){
  int amplitude = 400;
  stepperX.step(amplitude);
  stepperX.step(-2 * amplitude);
  stepperX.step(amplitude);
}
