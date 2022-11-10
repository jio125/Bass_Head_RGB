#include "timer.h"
#include "RTCS.h"

void Init_Timer(uint32_t freq){
  TCCR1A |= (1<<WGM01);
  OCR1A = (OCR_BASE * (1/freq)) - 1;
  TIMSK1 |= (1<<OCIE1A);
  sei();
  TCCR1B |= (1<<CS11);
  TCCR1B |= (1<<CS10);
}

ISR(TIMER1_COMPA_vect){
  RTCS_Timer_Tick();
}
