//Pins
int s0 = 3, s1 = 4, s2 = 5, s3 = 6;
int led = 10;
int out = 2;

byte diodeCounter = 0;

//Low mem vars
byte pulsesCounter = 0;

byte countR = 0, countG = 0, countB = 0; //Raw RGB

byte delta = 4; //RGB scaling factor
byte sR = 0, sG = 0, sB = 0; //Scaled RGB
void setup() {
  Serial.begin(115200);
  pinMode(s0, OUTPUT);
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(led, OUTPUT);
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

//colorScan function: Initiates sensor settings, inits timer2
void colorScan() {
  //
  diodeCounter = 0;

  //Initial and Permanent Frequency Scaling Setting: 100%
  digitalWrite(s0, HIGH);
  digitalWrite(s1, HIGH);

  //Initial Photodiode Type: RED
  digitalWrite(s2, LOW);
  digitalWrite(s3, LOW);

  //LEDS ON or OFF: OFF
  digitalWrite(led, LOW);

  //Attach pulsesCounter++ to out interrupt to increment color pulses on each out change (Color sensor)
  attachInterrupt(digitalPinToInterrupt(out), addPulse, CHANGE);
  timer2_init();
}

void addPulse() {
  pulsesCounter++;
}

//Hardware Timer2: Supports Interruption Routines
void timer2_init(void) {
  //In Hex
  TCCR2A = 0x00;  //Null
  TCCR2B = 0x07;  //Clock Ticks: 1024
  TCNT2 = 100;    //10 ms (overflow)
  TIMSK2 = 0x01;  //Allow interrupt
}

//Interrupt Service Routine: Function executed on Timer2 overflow
//Continuously swap between diodes for max accuracy of each colors
ISR(TIMER2_OVF_vect) {
  TCNT2 = 100; //Directly set timer2 in overflow
  diodeCounter++; //next Diode

  if (diodeCounter == 1) { //If red diode
    countR = pulsesCounter;
    sR = countR * delta;
    Serial.print("red=");
    Serial.println(countR, DEC);

    //Next (green) pin settings
    digitalWrite(s2, HIGH);
    digitalWrite(s3, HIGH);
  } else if (diodeCounter == 2) { //If green diode
    countG = pulsesCounter;
    sG = countG * delta;
    Serial.print("green=");
    Serial.println(countG, DEC);

    //Next (blue) pin settings
    digitalWrite(s2, LOW);
    digitalWrite(s3, HIGH);
  } else if (diodeCounter == 3) { //If blue diode
    countB = pulsesCounter;
    sB = countB * delta;
    Serial.print("blue=");
    Serial.println(countB, DEC);
    Serial.println("\n");

    //Next (red) pin settings
    digitalWrite(s2, LOW);
    digitalWrite(s3, LOW);

  } else if (diodeCounter == 4) {
    diodeCounter = 0; //Reset counter if at 4
  }
  pulsesCounter = 0; //Reset pulsesCounter after an if iteration
}

//colorAlgo
String colorAlgo(int R, int G, int B) {
  // Color recognition per deduction; use delta var to scale accordingly (or mixing with color sensor calibration)
  if ((R >= 140 && R <= 200) && (G >= 120 && G <= 180) && (B >= 90 && B <= 130)) {
    return "YELLOW";
  } else if ((R >= 250 && R <= 255) && (G >= 250 && G <= 255) && (B >= 0 && B <= 50)) {
    return "BLACK";
  } else if ((R >= 190 && R <= 220) && (G >= 200 && G <= 230) && (B >= 250 && B <= 255)) {
    return "WHITE";
  } else if ((R >= 200 && R <= 255) && (G >= 0 && G <= 60) && (B >= 0 && B <= 60)) {
    return "RED";
  } else if ((R >= 0 && R <= 60) && (G >= 200 && G <= 255) && (B >= 0 && B <= 60)) {
    return "GREEN";
  } else if ((R >= 0 && R <= 60) && (G >= 0 && G <= 60) && (B >= 200 && B <= 255)) {
    return "BLUE";
  } else if ((R >= 170 && R <= 230) && (G >= 0 && G <= 40) && (B >= 170 && B <= 230)) {
    return "MAGENTA";
  } else if ((R >= 0 && R <= 40) && (G >= 170 && G <= 230) && (B >= 170 && B <= 230)) {
    return "CYAN";
  } else {
    return "UNKNOWN";
  }
}

void loop() {
  colorScan();
  //To add: if values are fluctuating too quickly, skip colorAlgo, override with *disoriented*
  Serial.print(colorAlgo(sR, sG, sB));
  while (1); //While true
}