#ifndef RTCS_H
#define RTCS_H

//Run to Completion scheduler
#include <stdint.h>
#include "timer.h"

#define NUM_TASKS (10)

extern volatile uint32_t RTCS_Num_Ticks;

typedef struct {
  void (*Task)(void);
  uint32_t Period;
  uint32_t TicksToNextRelease;
  uint32_t ReleasesPending;
  char Enabled;
} RTCS_TASK_ENTRY;

extern volatile RTCS_TASK_ENTRY RTCS_Task_Table[NUM_TASKS];

//Runs the scheduler. This call will never return and the task table must have at least one task
void RTCS_Run_Scheduler(void);

//Initialize task table. Initialize timers if possible
void RTCS_Init(uint32_t freq);

//update ticks to next release
void RTCS_Timer_Tick(void);

//Add task to task table. Overwrites the task in that priority slot
int RTCS_Add_Task(void (*task)(void), uint32_t priority, uint32_t period);

//look up priority for given task
int RTCS_Find_Task_Priority(void (*task)(void));

//Update given task's Enable flag based on enable parameter 
int RTCS_Enable_Task_i(int i, uint32_t enable);
int RTCS_Enable_Task(void (*task)(void), uint32_t enable);

//Increment number of releases for given task 
int RTCS_Release_Task_i(int i);
int RTCS_Release_Task(void (*task)(void));

//Update task period, and reload TicksToNextRelease with period.
//If release_now is > 0, increment releases pending.
int RTCS_Set_Task_Period(void (*task)(void), uint16_t period, int release_now);
int RTCS_Set_Task_Period_i(int i, uint16_t period, int release_now);

#endif //RTCS_H
