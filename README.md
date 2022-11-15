# Bass_Head_RGB

## WS2812 LED controller using arduino nano and FastLED library

### System overview
- Strip of approx. 150 LEDs connected to pin 3 of the arduino. 
- Tactile switch connected to pin 2 to trigger an interrupt that changes the displayed pattern
- Potentiometer read by A1 to set LED brightness
- Powered by external 5V 2.5A power supply

### Scheduler info
Runs a non-preemtive scheduler to control LED refresh rate and read a potentiometer to set the LED brightness.
If there are no tasks ready to be run by the scheduler then the arduino enters into sleep mode unti the next time the scheduler has to run or the button interrupt is triggered

Internal timer triggers "Timer Tick" every 1ms, updating the time until the next release for every task. 


### Current Development goala
- Transition from Arduino Nano to bare ATtiny85
  - Current problem with amount of SRAM availible.
    - May be limited too far on number of LEDs
    - Most likely have to remove scheduler for this to be feasible
    - May not be possible to implement due to these limitations
        - Still working toward this goal as the ATtiny85 is a much smaller package
- Add more LED patterns as wanted
  - Basic patterns already implemented. Just looking at finishing touches