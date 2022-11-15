#include "timer.h"
#include "RTCS.h"

void Init_Timer(uint32_t freq){
  TCCR1 |= (1<<CTC1);
  OCR0A = (OCR_BASE * (1/freq)) - 1;
  TIMSK |= (1<<OCIE1A);
  sei();
  TCCR1 |= (1<<CS12);
  TCCR1 |= (1<<CS11);
  TCCR1 |= (1<<CS10);
}

ISR(TIMER1_COMPA_vect){
  RTCS_Timer_Tick();
}
