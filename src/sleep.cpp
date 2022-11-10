#include "sleep.h"
#include <Arduino.h>
#include <avr/sleep.h>

void goToSleep(void){
  sleep_enable();
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_cpu();
  sleep_disable();
}
