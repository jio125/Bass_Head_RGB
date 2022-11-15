#ifndef TIMER_H
#define TIMER_H

#include <Arduino.h>
#include <stdint.h>

#define OCR_BASE (125000) //multiply by desired period

//Initialize Timer 1
void Init_Timer(uint32_t freq);

#endif //TIMER_H
