#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>
#include "LED.h"

#define BUTTON_PIN  (2)

extern volatile uint8_t gCurrentPatternNumber;

//Initialize Buttons
void initButtons(void);

//Debounce task to prevent multiple interrupts per switch press
void task_Debounce(void);

//Button ISR
void buttonISR(void);

#endif //BUTTONS_H
