#include "LED.h"
#include <FastLED.h>

CRGB leds[NUM_LEDS];

volatile uint8_t gCurrentPatternNumber = 0;
uint8_t gHue = 0;

void initLEDs(void){
  FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
  FastLED.setBrightness(MAX_BRIGHTNESS);
}

void task_Update_LEDs(void){
  static PatternList gPatterns = {white, christmas, rainbow, rainbowWithGlitter, confetti, sinelon, juggle, bpm };

  gPatterns[gCurrentPatternNumber]();
  FastLED.show();
}

void white(){
  for(int i = 0; i < NUM_LEDS; i++){
    leds[i] = CRGB::White;
  }
}

void christmas(){
  for(int i = 0; i < NUM_LEDS; i++){
    if(i%2){
      if(leds[i] == CRGB(255,0,0)) leds[i] = CRGB::Green;
      else leds[i] = CRGB::Red;
    }
    else{
      if(leds[i] == CRGB(0,255,0)) leds[i] = CRGB::Red;
      else leds[i] = CRGB::Green;
    }
  }
}

void rainbow() 
{
  // FastLED's built-in rainbow generator
  fill_rainbow( leds, NUM_LEDS, gHue, 7);
  gHue += 7;
}

void rainbowWithGlitter() 
{
  // built-in FastLED rainbow, plus some random sparkly glitter
  rainbow();
  addGlitter(80);
}

void addGlitter( fract8 chanceOfGlitter) 
{
  if( random8() < chanceOfGlitter) {
    leds[ random16(NUM_LEDS) ] += CRGB::White;
  }
}

void confetti() 
{
  // random colored speckles that blink in and fade smoothly
  fadeToBlackBy( leds, NUM_LEDS, 10);
  int pos = random16(NUM_LEDS);
  leds[pos] += CHSV( gHue + random8(64), 200, 255);
}

void sinelon()
{
  // a colored dot sweeping back and forth, with fading trails
  fadeToBlackBy( leds, NUM_LEDS, 20);
  int pos = beatsin16( 13, 0, NUM_LEDS-1 );
  leds[pos] += CHSV( gHue, 255, 192);
}

void bpm()
{
  // colored stripes pulsing at a defined Beats-Per-Minute (BPM)
  uint8_t BeatsPerMinute = 62;
  CRGBPalette16 palette = PartyColors_p;
  uint8_t beat = beatsin8( BeatsPerMinute, 64, 255);
  for( int i = 0; i < NUM_LEDS; i++) { //9948
    leds[i] = ColorFromPalette(palette, gHue+(i*2), beat-gHue+(i*10));
  }
}

void juggle() {
  // eight colored dots, weaving in and out of sync with each other
  fadeToBlackBy( leds, NUM_LEDS, 20);
  byte dothue = 0;
  for( int i = 0; i < 8; i++) {
    leds[beatsin16( i+7, 0, NUM_LEDS-1 )] |= CHSV(dothue, 200, 255);
    dothue += 32;
  }
}
