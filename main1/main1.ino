
// Global variables for melody player - Jaune
int thisNoteJaune = 0;
unsigned long noteStartTimeJaune = 0;
unsigned long pauseStartTimeJaune = 0;
const int noteDurationMultiplierJaune = 130;  // Adjust this multiplier as needed

// Global variables for melody player - Red
int thisNoteRed = 0;
unsigned long noteStartTimeRed = 0;
unsigned long pauseStartTimeRed = 0;
const int noteDurationMultiplierRed = 130;  // Adjust this multiplier as needed


// Global variables for melody player - Green
int thisNoteGreen = 0;
unsigned long noteStartTimeGreen = 0;
unsigned long pauseStartTimeGreen = 0;
const int noteDurationMultiplierGreen = 130;  // Adjust this multiplier as needed


// Global variables for melody player - Purple
int thisNotePurple = 0;
unsigned long noteStartTimePurple = 0;
unsigned long pauseStartTimePurple = 0;
const int noteDurationMultiplierPurple = 130;  // Adjust this multiplier as needed


// Global variables for melody player - Orange
int thisNoteOrange = 0;
unsigned long noteStartTimeOrange = 0;
unsigned long pauseStartTimeOrange = 0;
const int noteDurationMultiplierOrange = 130;  // Adjust this multiplier as needed


// Global variables for melody player - Blue
int thisNoteBlue = 0;
unsigned long noteStartTimeBlue = 0;
unsigned long pauseStartTimeBlue = 0;
const int noteDurationMultiplierBlue = 130;  // Adjust this multiplier as needed



// Variables for melody player
int thisNotePick = 0;
unsigned long noteStartTimePick = 0;
unsigned long pauseStartTimePick = 0;
const int noteDurationMultiplierPick = 260;  // Adjust this multiplier as needed


//Accel
#define ACCELE_RANGE 2
#define GYROSC_RANGE 500

#include <Wire.h>

#include "LedControl.h"
#include "pitches.h"


#include <tcs3200.h>

int red, green, blue, white;
// Define pin connections
#define S0_PIN 3
#define S1_PIN 4
#define S2_PIN 5
#define S3_PIN 6
#define OUT_PIN 2
#define colLED_PIN 10

tcs3200 tcs(S0_PIN, S1_PIN, S2_PIN, S3_PIN, OUT_PIN);


const int MPU_addr = 0x68;  // I2C address of the MPU-6050

///// VARIABLES /////
/////////////////////

// VALUES //

//mpu6050
float AcX, AcY, AcZ, Tmp, GyX, GyY, GyZ;
float AcXCalibrate, AcYCalibrate, AcZCalibrate, GyXCalibrate, GyYCalibrate, GyZCalibrate;

//stopWatch
unsigned long stopWatch = millis();


unsigned long colortime;

LedControl matrix1 = LedControl(52, 48, 50, 1);
LedControl matrix2 = LedControl(46, 42, 44, 1);


#include <Adafruit_NeoPixel.h>

#define LED_PIN 8
#define LED_COUNT 51  //number of pixels on strip

// Declare NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

// vars for LEDS //
///////////////////

int pixelQueue = 0;                // Pattern Pixel Queue
uint16_t pixelCurrent = 0;         // Pattern Current Pixel Number
int pixelCycle = 0;                // Pattern Pixel Cycle
uint16_t pixelNumber = LED_COUNT;  // Total Number of Pixels
unsigned long chronoPixel = 0;     // Previous Pixel Millis
unsigned long sequenceChrono;
int pixelInterval = 500;
int LEDCursor = 0;
int sequenceIndex;
uint32_t hueChange;

int oldAlgoColor;
int currentAlgoColor;

// colors
uint32_t redHue = -400; //actually pink
uint32_t orangeHue = 0; //actually red
uint32_t yellowHue = 5500;
uint32_t greenHue = 18000;
uint32_t cyanHue = 25000;
uint32_t blueHue = 40000;
uint32_t purpleHue = 47000;
uint32_t pinkHue = 56000;
uint32_t disorientedHue;

// sleep
float brightness = 4;
float speedSleepLED = 0.25;

//love
int heartbeatCursor = 0;

// happy

int hueCursor = 0;
int brightnessCursor = 0;



long chronoEyes;

byte sR = 0, sG = 0, sB = 0;  //Scaled RGB
void setup() {
  //COLORSCANNER
  

  //ACCEL SETUP
  Wire.begin();
  Wire.beginTransmission(MPU_addr);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);

  Serial.begin(115200);
  //LED INIT
  strip.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();   // Turn OFF all pixels ASAP
  strip.setBrightness(100);
  //colorScan();

  //EYES INIT
  matrix1.shutdown(0, false);
  matrix1.setIntensity(0, 5);
  matrix1.clearDisplay(0);

  matrix2.shutdown(0, false);
  matrix2.setIntensity(0, 5);
  matrix2.clearDisplay(0);

  chronoEyes = millis();
  currentAlgoColor = 0;
  pinMode(colLED_PIN, OUTPUT);
  digitalWrite(colLED_PIN, HIGH);
}

/* ========================================
 S0	S1	OUTPUT FREQUENCY SCALING (fo)
L	L	Power down
L	H	2%
H	L	20%
H	H	100%

  S2	S3	PHOTODIODE TYPE
L	L	RED
L	H	BLUE
H	L	Clear (no filter)
H	H	GREEN
========================================= */


//colorAlgo
String colorAlgo(int R, int G, int B) {
  oldAlgoColor = currentAlgoColor;
  // Color recognition per deduction; use delta var to scale accordingly (or mixing with color sensor calibration)
//   if ((R >= 130 && R <= 155) && (G >= 100 && G <= 130) && (B >= 45 && B <= 70)) {
//     currentAlgoColor = 0;
//     return "YELLOW";
//   } else if ((R >= 35 && R <= 80) && (G >= 70 && G <= 90) && (B >= 135 && B <= 170)) {
//     currentAlgoColor = 3;
//     return "BLUE";
//   } else if ((R >= 55 && R <= 80) && (G >= 10 && G <= 25) && (B >= 10 && B <= 25)) {
//     currentAlgoColor = 2;
//     return "ORANGE";
//   } else if ((R >= 150 && R <= 200) && (G >= 50 && G <= 80) && (B >= 100 && B <= 140)) {
//     currentAlgoColor = 5;
//     return "ROSE";
//   } else if ((R >= 15 && R <= 35) && (G >= 15 && G <= 35) && (B >= 40 && B <= 70)) {
//     currentAlgoColor = 4;
//     return "MAUVE";
//   } else if ((R >= 20 && R <= 35) && (G >= 40 && G <= 55) && (B >= 35 && B <= 55)) {
//     currentAlgoColor = 1;
//     return "GREEN";
//   } else {
//     currentAlgoColor = 999;
//     return "UNKNOWN";
//   }
// }

  if ((R >= 160 && R <= 200) && (G >= 140 && G <= 170) && (B >= 70 && B <= 100)) {
    currentAlgoColor = 0;
    return "YELLOW";
  } else if ((R >= 60 && R <= 80) && (G >= 100 && G <= 125) && (B >= 200 && B <= 250)) {
    currentAlgoColor = 3;
    return "BLUE";
  } else if ((R >= 70 && R <= 110) && (G >= 10 && G <= 40) && (B >= 10 && B <= 40)) {
    currentAlgoColor = 2;
    return "ORANGE"; //actually red
  } else if ((R >= 150 && R <= 200) && (G >= 50 && G <= 80) && (B >= 100 && B <= 140)) {
    currentAlgoColor = 5;
    return "ROSE";
  } else if ((R >= 30 && R <= 60) && (G >= 30 && G <= 60) && (B >= 70 && B <= 115)) {
    currentAlgoColor = 4;
    return "MAUVE";
  } else if ((R >= 30 && R <= 55) && (G >= 70 && G <=100) && (B >= 45 && B <= 85)) {
    currentAlgoColor = 1;
    return "GREEN";
  } else {
    currentAlgoColor = 999;
    return "UNKNOWN";
  }
}

void effects() {
  // switch(currentAlgoColor) {

  switch (currentAlgoColor) {

    //Yellow
    case 0:
      displayLEDColors(currentAlgoColor);
      displayYellowEyes();
      playMelodyJaune();
      break;

    //GREEN
    case 1:
      displayLEDColors(currentAlgoColor);
      displayGreenEyes();
      playMelodyGreen();
      break;

    //ORANGE
    case 2:
      displayLEDColors(currentAlgoColor);
      displayOrangeEyes();
      playMelodyOrange();
      break;

    //BLUE
    case 3:
      playMelodyBlue();
      displayLEDColors(currentAlgoColor);
      displayBlueEyes();
      break;
    //MAUVE
    case 4:
      displayLEDColors(currentAlgoColor);
      displayPurpleEyes();
      playMelodyPurple();
      break;
    //ROSE
    case 5:
      displayLEDColors(currentAlgoColor);
      displayRedEyes();  //(Actually pink)
      playMelodyRed();
      break;
    case 999:
      displayLEDColors(currentAlgoColor);
      displayOrangeEyes();
      playMelodyPick();
      break;
  }
}

void loop() {
  //tcs3200.loop();
  if (isMoving()) {
    resetMelodies();
    currentAlgoColor = 999;
  } else {
    if (currentAlgoColor > 7) {
        red = tcs.colorRead('r');
        green = tcs.colorRead('g');
        blue = tcs.colorRead('b'); 
        Serial.println(colorAlgo(red, green, blue));
    }
  }
  Serial.println("-----------------------------------");
          red = tcs.colorRead('r');
        green = tcs.colorRead('g');
        blue = tcs.colorRead('b'); 
   //reads color value for red
  Serial.print("R= ");
  Serial.print(red);
  Serial.print("    ");
  
   //reads color value for green
  Serial.print("G= ");
  Serial.print(green);
  Serial.print("    ");

     //reads color value for blue
  Serial.print("B= ");
  Serial.print(blue);
  Serial.print("    ");
  effects();
  stopWatch = millis();
  readMpu6050Values();
  //   colorScan();
  //   while(1);
}

// Function to reset all melodies
void resetMelodies() {
  // Reset Pick melody
  // thisNotePick = 0;
  // noteStartTimePick = millis();
  // pauseStartTimePick = millis();

  // Reset Jaune melody
  thisNoteJaune = 0;
  noteStartTimeJaune = millis();
  pauseStartTimeJaune = millis();

  // Reset Red melody
  thisNoteRed = 0;
  noteStartTimeRed = millis();
  pauseStartTimeRed = millis();

  // Reset Green melody
  thisNoteGreen = 0;
  noteStartTimeGreen = millis();
  pauseStartTimeGreen = millis();

  // Reset Purple melody
  thisNotePurple = 0;
  noteStartTimePurple = millis();
  pauseStartTimePurple = millis();

  // Reset Orange melody
  thisNoteOrange = 0;
  noteStartTimeOrange = millis();
  pauseStartTimeOrange = millis();

  // Reset Blue melody
  thisNoteBlue = 0;
  noteStartTimeBlue = millis();
  pauseStartTimeBlue = millis();
}

