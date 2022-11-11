
#include "sketch.h"



int main(){
  init(); //system initialization
  initButtons(); //initialize selector button
  initLEDs();
  
  RTCS_Init(TIMER_TICK_FREQ); //Initialize scheduler table and set timer tick frequency
  
  //Add task to drive the LED strip
  RTCS_Add_Task(task_Update_LEDs, 0, 5);
  RTCS_Enable_Task(task_Update_LEDs, 1);

  //Add task to update brightness according to potentiometer value
  RTCS_Add_Task(task_Read_Analog, 1, 50);
  RTCS_Enable_Task(task_Read_Analog, 1);

  //Add task to debounce switch
  //Task is disabled to start
  RTCS_Add_Task(task_Debounce, 2, 2);
  RTCS_Enable_Task(task_Debounce, 0);

  //Hand off control to scheduler
  RTCS_Run_Scheduler();

  return 0;
}
