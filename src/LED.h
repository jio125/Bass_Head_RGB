#ifndef LED_H
#define LED_H

#include <FastLED.h>

#define DATA_PIN  3
#define LED_TYPE  WS2811
#define COLOR_ORDER GRB
#define NUM_LEDS  100
#define MIN_BRIGHTNESS  32
#define MAX_BRIGHTNESS  128
#define FRAMES_PER_SECOND 120
#define NUM_PATTERNS  5

#define ARRAY_SIZE(A) (sizeof(A) / sizeof((A)[0])) //find the size of an array

typedef void (*PatternList[])(void);

extern CRGB leds[NUM_LEDS];
extern volatile uint8_t gCurrentPatternNumber;

//initialize LED strip
void initLEDs(void);

//Update LED strip periodically
void task_Update_LEDs(void);

//Animation function prototypes
void white(void);
void red(void);
void fillRandom(void);
void christmas(void);
void rainbow(void);
void rainbowWithGlitter(void);
void addGlitter(fract8 chanceOfGlitter);
void confetti(void);
void sinelon(void);
void bpm(void);
void juggle(void);


#endif //LED_H
