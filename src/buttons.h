#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>
#include "LED.h"

#define BUTTON_PIN  (2)

extern volatile uint8_t gCurrentPatternNumber;

//Initialize Buttons
void initButtons(void);

//Button ISR
void buttonISR(void);

#endif //BUTTONS_H
