#include <Adafruit_NeoPixel.h>

#define LED_PIN 2

// How many NeoPixels are attached to the Arduino?
#define LED_COUNT 51

// Declare NeoPixel strip object:
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
// Argument 1 = Number of pixels in NeoPixel strip
// Argument 2 = Arduino pin number (most are valid)
// Argument 3 = Pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
//   NEO_RGBW    Pixels are wired for RGBW bitstream (NeoPixel RGBW products)

// vars for dodoLED //

float brightness = 4;
float speed = 0.2;

// setup() function -- runs once at startup --------------------------------
void setup() {
  Serial.begin(115200);
  strip.begin();             // INITIALIZE NeoPixel strip object (REQUIRED)
  strip.show();              // Turn OFF all pixels ASAP
  strip.setBrightness(100);  // Set BRIGHTNESS to about 1/5 (max = 255)
}

// loop() function -- runs repeatedly as long as board is on ---------------
void loop() {

  dodoLED(3400);
}

void dodoLED(int hue) {
  uint32_t color;
  if (brightness < 0) {
    speed = -speed;
  } else if (brightness > 230) {
    speed = -speed;
  }

  brightness += speed;

  strip.fill(strip.ColorHSV(hue, 255, brightness));
  strip.show();
  Serial.println(brightness);
}

// exemple de fonction pour display colors????

/*void displayLEDColors() {
  switch (colorAlgo(sR, sG, sB)) {
    case "YELLOW":  // neutral
      break;
    case "GREEN":  // happy
      break;
    case "RED":  //scared?
      break;
    case "BLUE": // water?
      dodoLED(3400);
      break;
    case "CYAN": // sleep?

      break;
    case "MAGENTA": // love?
      break;
    default:
      break;
  }
}
*/
