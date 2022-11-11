#include "buttons.h"
#include "LED.h"
#include "RTCS.h"
#include <Arduino.h>

extern volatile uint8_t gCurrentPatternNumber;

void initButtons(void){
  pinMode(BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonISR, FALLING);
}

void buttonISR(void){
  detachInterrupt(digitalPinToInterrupt(BUTTON_PIN)); //Disable interrupt to debounce the switch
  gCurrentPatternNumber = (gCurrentPatternNumber + 1) % NUM_PATTERNS;
  RTCS_Enable_Task(task_Debounce, 1); //Enable debounce task to mask switch bounce
}

void task_Debounce(void){
  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN), buttonISR, FALLING); //reenable interrupt
  RTCS_Enable_Task(task_Debounce, 0); //Disable task after debouncing
}
