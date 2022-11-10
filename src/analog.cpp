
#include "analog.h"

void task_Read_Analog(void){
  int currentBrightness = FastLED.getBrightness();
  int analogVal = analogRead(A1);
  int mapVal = map(analogVal, 0, 1024, MIN_BRIGHTNESS, MAX_BRIGHTNESS);
  if(mapVal != currentBrightness) FastLED.setBrightness(mapVal);
}
