
/*
 * Modified by gmerdan
 * to include new patterns
 * 
 * Christmas tree by designer2k2.at
 * Stephan Martin 2016
 * http://www.designer2k2.at
 * https://github.com/designer2k2/xmas-tree
 * 
 * This code is made to run on a Digispark
 * Feeding Neopixel Rings, stacked to a tree.
 * 
 * Brightness is reduced as there is only USB power supply.
 * 
 */

#include <Adafruit_NeoPixel.h>
#include <avr/pgmspace.h>

#define PIN 1
#define BRIGHTNESS 10 // set max brightness


//Lookups for the X-M-A-S:
 const unsigned int charX[] PROGMEM = 
 { 
   4,27,54,61,58,35,16,10,31,56,60,39,22
 };
 const unsigned int charM[] PROGMEM = 
 { 
   4,26,25,40,22,39,60,61,58,35,16,34,33,32,10
 };
  const unsigned int charA[] PROGMEM = 
 { 
   4,27,42,53,60,51,37,19,49,58,57,61,46,31,10
 };
  const unsigned int charS[] PROGMEM = 
 { 
  22,38,37,36,35,34,47,57,61,53,41,26,27,28,29,30,10
 };

 const unsigned int candles[] PROGMEM = 
 { 
  15,10,48,45,36,19,59,29,5,43,41,39,24,3,61
 };

 
  const unsigned int L1[] PROGMEM = 
 { 
  0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23
 };
 const unsigned int L2[] PROGMEM = 
 { 
  24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40
 };
  const unsigned int L3[] PROGMEM = 
 { 
  41,42,43,44,45,46,47,48,49,50,51,52
 };
  const unsigned int L4[] PROGMEM = 
 { 
53,54,55,56,57,58,59,60
};
   const unsigned int L5[] PROGMEM = 
 { 
61
};

//Vertical Lines
const unsigned int VL1[] PROGMEM = 
 { 
 60,52,40,24,0
};
const unsigned int VL2[] PROGMEM = 
 { 
 60,53,41,25,1
};
const unsigned int VL3[] PROGMEM = 
 { 
 60,53,42,26,3
};
const unsigned int VL4[] PROGMEM = 
 { 
 60,53,42,27,4
};


// Parameter 1 = number of pixels in strip
// Parameter 2 = Arduino pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(61, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

void setup() {
  pinMode(PIN, OUTPUT);
  strip.begin();
  strip.setBrightness(BRIGHTNESS); // set brightness
  strip.show(); // Initialize all pixels to 'off'
  
}

void loop() {
//vertStripes (WIP)
//vertStrips();

// Layers fade (WIP)
layers ();

//blinkinglights
blinkingLights();

//blinkinglights now with color!
blinkingLightsColors();

//rainbow and cycle:
rainbow();
rainbowCycle();
  
//Tree light:
  tree();
  delay(10000);

//Color crazy:
  colorcrazy();
  delay(1000);
  

  /*
  // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
  // Send a theater pixel chase in...
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127,   0,   0), 50); // Red
  theaterChase(strip.Color(  0,   0, 127), 50); // Blue
  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
*/
}

//Sub-----------------------------------------------------------------------

void colorcrazy(){
  colorWipe(strip.Color(255, 0, 0), 25); // Red
  colorWipe(strip.Color(0, 255, 0), 25); // Green
  colorWipe(strip.Color(0, 0, 255), 25); // Blue
  theaterChaseRainbow(0);
  theaterChaseRainbow(0);
  theaterChaseRainbow(0);
  colorWipe(strip.Color(0, 0, 0), 0); // Green
}

void tree(){

  colorWipe(strip.Color(0, 50, 0), 50); // Green

  //light "candles"
  //Show the S:
  for (int i = 0; i < 16; i++)
  {
    strip.setPixelColor(pgm_read_word(&candles[i])-1,strip.Color(255, 255, 255));
    strip.show();
    delay(50);
  }

}

void rainbow(){

 rainbow(20);
 delay(1000);

}
void rainbowCycle(){

  rainbowCycle(20);
  delay(1000);

}

void layers(){
  for (int i = 0; i<24; i++){
    strip.setPixelColor(i,strip.Color(0, 255, 0));
    strip.show();
  }
for (int i = 24; i<40; i++){
    strip.setPixelColor(i,strip.Color(255, 0, 0));
    strip.show();
  }
for (int i = 40; i<52; i++){
    strip.setPixelColor(i,strip.Color(0, 0, 255));
    strip.show();
  }
for (int i = 52; i<60; i++){
    strip.setPixelColor(i,strip.Color(255, 0, 255));
    strip.show();
}

    strip.setPixelColor(60,strip.Color(0, 255, 0));
    strip.show();

  
  delay(1000);
  colorWipe(strip.Color(0, 0, 0), 0); // blank
}

void blinkingLights(){
 for (int i=0; i<61; i++){
  strip.setPixelColor(i, strip.Color(0,255,0));
  strip.show();
 }
 for (int i=0; i<20; i++){
  int x = random(0,61);
  strip.setPixelColor(x, strip.Color(255,255,255));
  strip.setPixelColor(x+7, strip.Color(255,255,255));
  strip.setPixelColor(x+15, strip.Color(255,255,255));
  strip.setPixelColor(x+19, strip.Color(255,255,255));
  strip.setPixelColor(x+22, strip.Color(255,255,255));

  strip.show();
  delay(50);
  strip.setPixelColor(x, strip.Color(0,255, 0));
  strip.setPixelColor(x+7, strip.Color(0,255, 0));
  strip.setPixelColor(x+15, strip.Color(0,255, 0));
  strip.setPixelColor(x+19, strip.Color(0,255, 0));
  strip.setPixelColor(x+22, strip.Color(0,255, 0));
  delay(10);
 }
}

void blinkingLightsColors(){
 for (int i=0; i<61; i++){
  strip.setPixelColor(i, strip.Color(0,255,0));
  strip.show();
 }
 for (int i=0; i<200; i++){
  int x = random(0,61);
  strip.setPixelColor(x, strip.Color(255,255,0));
  strip.setPixelColor(x+7, strip.Color(0,255,255));
  strip.setPixelColor(x+15, strip.Color(255,0,255));
  strip.setPixelColor(x+19, strip.Color(255,255,0));
  strip.setPixelColor(x+22, strip.Color(0,0,255));

  strip.show();
  delay(50);
  strip.setPixelColor(x, strip.Color(0,255, 0));
  strip.setPixelColor(x+7, strip.Color(0,255, 0));
  strip.setPixelColor(x+15, strip.Color(0,255, 0));
  strip.setPixelColor(x+19, strip.Color(0,255, 0));
  strip.setPixelColor(x+22, strip.Color(0,255, 0));
  delay(10);
 }
}


void vertStrips(){

//set all green
 for (int i=0; i<61; i++){
  strip.setPixelColor(i, strip.Color(0,255,0));
  strip.show();
 }

//set top led to white for duration
  strip.setPixelColor(60, strip.Color(255,255,255));

//draw vertical lines

//then turn off vertical lines
 

}



void xmas(){

  colorWipe(strip.Color(0, 0, 0), 0); // blank

  //Show the X:
  for (int i = 0; i < 13; i++)
  {
    strip.setPixelColor(pgm_read_word(&charX[i])-1,strip.Color(255, 0, 0));
        strip.show();
    delay(50);
  }
  delay(1000);
  colorWipe(strip.Color(0, 0, 0), 0); // blank

  //Show the M:
  for (int i = 0; i < 15; i++)
  {
    strip.setPixelColor(pgm_read_word(&charM[i])-1,strip.Color(0, 255, 0));
    strip.show();
    delay(50);
  }
  delay(1000);
  colorWipe(strip.Color(0, 0, 0), 0); // blank

  //Show the A:
  for (int i = 0; i < 15; i++)
  {
    strip.setPixelColor(pgm_read_word(&charA[i])-1,strip.Color(0, 0, 255));
    strip.show();
    delay(50);
  }
  delay(1000);
  colorWipe(strip.Color(0, 0, 0), 0); // blank

  //Show the S:
  for (int i = 0; i < 17; i++)
  {
    strip.setPixelColor(pgm_read_word(&charS[i])-1,strip.Color(125, 125, 125));
    strip.show();
    delay(50);
  }
  delay(1000);
  colorWipe(strip.Color(0, 0, 0), 0); // blank
  
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<10; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();
     
      delay(wait);
     
      for (int i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
        }
        strip.show();
       
        delay(wait);
       
        for (int i=0; i < strip.numPixels(); i=i+3) {
          strip.setPixelColor(i+q, 0);        //turn every third pixel off
        }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else if(WheelPos < 170) {
    WheelPos -= 85;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
}
