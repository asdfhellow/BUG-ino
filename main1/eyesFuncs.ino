byte yellowEyesL[5][8] = {
  { B00000000,
    B00000000,
    B00011000,
    B00111100,
    B00111100,
    B00011000,
    B00000000,
    B00000000 },

  { B00000000,
    B00000000,
    B00000000,
    B01111110,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B00001100,
    B00001100,
    B01111110,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B00011000,
    B00011000,
    B01111110,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B00011000,
    B00011000,
    B01111110,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },
};

byte yellowEyesR[5][8] = {
  { B00000000,
    B00000000,
    B00011000,
    B00111100,
    B00111100,
    B00011000,
    B00000000,
    B00000000 },

  { B00000000,
    B00000000,
    B00000000,
    B01111110,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B00001100,
    B00001100,
    B01111110,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B00011000,
    B00011000,
    B01111110,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B00110000,
    B00110000,
    B01111110,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },
};
/******************** YELLOW ***********************/
int sequenceYellowEyesL[5];
int sequenceYellowEyesR[5];
int cursorYellowEyes = 0;

void displayYellowEyes() {

  // Frame 1
  if (cursorYellowEyes == 0) {
    if (millis() - chronoEyes > 1000) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, yellowEyesL[cursorYellowEyes][col]);
        matrix2.setColumn(0, col, yellowEyesR[cursorYellowEyes][col]);
      }
      cursorYellowEyes++;
    }
  }

  // Frame 2
  if (cursorYellowEyes == 1) {
    if (millis() - chronoEyes > 1000) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, yellowEyesL[cursorYellowEyes][col]);
        matrix2.setColumn(0, col, yellowEyesR[cursorYellowEyes][col]);
      }
      cursorYellowEyes++;
    }
  }

  // Frame 3
  if (cursorYellowEyes == 2) {
    if (millis() - chronoEyes > 300) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, yellowEyesL[cursorYellowEyes][col]);
        matrix2.setColumn(0, col, yellowEyesR[cursorYellowEyes][col]);
      }
      cursorYellowEyes++;
    }
  }

  // Frame 4
  if (cursorYellowEyes == 3) {
    if (millis() - chronoEyes > 300) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, yellowEyesL[cursorYellowEyes][col]);
        matrix2.setColumn(0, col, yellowEyesR[cursorYellowEyes][col]);
      }
      cursorYellowEyes++;
    }
  }

  // Frame 5
  if (cursorYellowEyes == 4) {
    if (millis() - chronoEyes > 300) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, yellowEyesL[cursorYellowEyes][col]);
        matrix2.setColumn(0, col, yellowEyesR[cursorYellowEyes][col]);
      }
      cursorYellowEyes = 0;
    }
  }
}

/******** ANITMATION FRAMES : ORANGE ************/

byte orangeEyesL[3][8] = {
  { B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00011000,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B00000000,
    B00011000,
    B00100100,
    B00100100,
    B00011000,
    B00000000,
    B00000000 },

  { B00000000,
    B00111100,
    B01000010,
    B01011010,
    B01011010,
    B01000010,
    B00111100,
    B00000000 },
};

byte orangeEyesR[3][8] = {
  { B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00011000,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B00000000,
    B00011000,
    B00100100,
    B00100100,
    B00011000,
    B00000000,
    B00000000 },

  { B00000000,
    B00111100,
    B01000010,
    B01011010,
    B01011010,
    B01000010,
    B00111100,
    B00000000 },

};

/******************* ORANGE *********************/
int sequenceOrangeEyesL[5];
int sequenceOrangeEyesR[5];
int cursorOrangeEyes = 0;

void displayOrangeEyes() {

  // Frame 1
  if (cursorOrangeEyes == 0) {
    if (millis() - chronoEyes > 500) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, orangeEyesL[cursorOrangeEyes][col]);
        matrix2.setColumn(0, col, orangeEyesR[cursorOrangeEyes][col]);
      }
      cursorOrangeEyes++;
    }
  }

  // Frame 2
  if (cursorOrangeEyes == 1) {
    if (millis() - chronoEyes > 500) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, orangeEyesL[cursorOrangeEyes][col]);
        matrix2.setColumn(0, col, orangeEyesR[cursorOrangeEyes][col]);
      }
      cursorOrangeEyes++;
    }
  }

  // Frame 3
  if (cursorOrangeEyes == 2) {
    if (millis() - chronoEyes > 700) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, orangeEyesL[cursorOrangeEyes][col]);
        matrix2.setColumn(0, col, orangeEyesR[cursorOrangeEyes][col]);
      }
      cursorOrangeEyes = 0;
    }
  }
}

/********* ANITMATION FRAMES : GREEN *************/

byte greenEyesL[3][8] = {
  { B00000000,
    B00000000,
    B00000000,
    B10000001,
    B01000010,
    B00100100,
    B00011000,
    B00000000 },

  { B00000000,
    B00011000,
    B00111100,
    B00111100,
    B00111100,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B00000000,
    B00000000,
    B10000001,
    B01000010,
    B00100100,
    B00011000,
    B00000000 },
};

byte greenEyesR[3][8] = {
  { B00000000,
    B00000000,
    B00000000,
    B10000001,
    B01000010,
    B00100100,
    B00011000,
    B00000000 },

  { B00000000,
    B00011000,
    B00111100,
    B00111100,
    B00111100,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B00000000,
    B00000000,
    B10000001,
    B01000010,
    B00100100,
    B00011000,
    B00000000 },

};
/********************* GREEN ***********************/
int sequenceGreenEyesL[5];
int sequenceGreenEyesR[5];
int cursorGreenEyes = 0;

void displayGreenEyes() {

  // Frame 1
  if (cursorGreenEyes == 0) {
    if (millis() - chronoEyes > 1000) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, greenEyesL[cursorGreenEyes][col]);
        matrix2.setColumn(0, col, greenEyesR[cursorGreenEyes][col]);
      }
      cursorGreenEyes++;
    }
  }
  // Frame 2
  if (cursorGreenEyes == 1) {
    if (millis() - chronoEyes > 1000) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, greenEyesL[cursorGreenEyes][col]);
        matrix2.setColumn(0, col, greenEyesR[cursorGreenEyes][col]);
      }
      cursorGreenEyes++;
    }
  }

  // Frame 3
  if (cursorGreenEyes == 2) {
    if (millis() - chronoEyes > 1000) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, greenEyesL[cursorGreenEyes][col]);
        matrix2.setColumn(0, col, greenEyesR[cursorGreenEyes][col]);
      }
      cursorGreenEyes = 0;
    }
  }
}
/******* ANITMATION FRAMES : RED *************/

byte redEyesL[5][8] = {
  { B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00100100,
    B00000000 },

  { B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B10011001,
    B01100110,
    B00000000 },

  { B00000000,
    B00000000,
    B00000000,
    B01000010,
    B10000001,
    B10011001,
    B01100110,
    B00000000 },

  { B00000000,
    B00011000,
    B00100100,
    B01000010,
    B10000001,
    B10011001,
    B01100110,
    B00000000 },

  { B00000000,
    B00011000,
    B00111100,
    B01111110,
    B11111111,
    B11111111,
    B01100110,
    B00000000 },
};

byte redEyesR[5][8] = {
  { B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00011000,
    B00100100,
    B00000000 },

  { B00000000,
    B00000000,
    B00000000,
    B00000000,
    B00000000,
    B10011001,
    B01100110,
    B00000000 },

  { B00000000,
    B00000000,
    B00000000,
    B01000010,
    B10000001,
    B10011001,
    B01100110,
    B00000000 },

  { B00000000,
    B00011000,
    B00100100,
    B01000010,
    B10000001,
    B10011001,
    B01100110,
    B00000000 },

  { B00000000,
    B00011000,
    B00111100,
    B01111110,
    B11111111,
    B11111111,
    B01100110,
    B00000000 },
};

/*********************** RED **************************/
int sequenceRedEyesL[5];
int sequenceRedEyesR[5];
int cursorRedEyes = 0;

void displayRedEyes() {

  // Frame 1
  if (cursorRedEyes == 0) {
    if (millis() - chronoEyes > 300) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, redEyesL[cursorRedEyes][col]);
        matrix2.setColumn(0, col, redEyesR[cursorRedEyes][col]);
      }
      cursorRedEyes++;
    }
  }

  // Frame 2
  if (cursorRedEyes == 1) {
    if (millis() - chronoEyes > 300) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, redEyesL[cursorRedEyes][col]);
        matrix2.setColumn(0, col, redEyesR[cursorRedEyes][col]);
      }
      cursorRedEyes++;
    }
  }

  // Frame 3
  if (cursorRedEyes == 2) {
    if (millis() - chronoEyes > 300) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, redEyesL[cursorRedEyes][col]);
        matrix2.setColumn(0, col, redEyesR[cursorRedEyes][col]);
      }
      cursorRedEyes++;
    }
  }

  // Frame 4
  if (cursorRedEyes == 3) {
    if (millis() - chronoEyes > 300) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, redEyesL[cursorRedEyes][col]);
        matrix2.setColumn(0, col, redEyesR[cursorRedEyes][col]);
      }
      cursorRedEyes++;
    }
  }

  // Frame 5
  if (cursorRedEyes == 4) {
    if (millis() - chronoEyes > 2000) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, redEyesL[cursorRedEyes][col]);
        matrix2.setColumn(0, col, redEyesR[cursorRedEyes][col]);
      }
      cursorRedEyes = 0;
    }
  }
}

/********* ANITMATION FRAMES : PURPLE *************/

byte purpleEyesL[4][8] = {
  { B00000000,
    B00000000,
    B00000000,
    B01111110,
    B10000001,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B00000000,
    B00000000,
    B11111111,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },

  { B00001111,
    B00000010,
    B00000100,
    B00001111,
    B11110000,
    B00100000,
    B01000000,
    B11110000 },

  { B11110000,
    B01000000,
    B00100000,
    B11110000,
    B00001111,
    B00000100,
    B00000010,
    B00001111 },
};

byte purpleEyesR[4][8] = {
  { B00000000,
    B00000000,
    B00000000,
    B01111110,
    B10000001,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B00000000,
    B00000000,
    B11111111,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },

  { B11110000,
    B01000000,
    B00100000,
    B11110000,
    B00001111,
    B00000100,
    B00000010,
    B00001111 },

  { B00001111,
    B00000010,
    B00000100,
    B00001111,
    B11110000,
    B00100000,
    B01000000,
    B11110000 },
};

/********************* GREEN ***********************/
int sequencePurpleEyesL[5];
int sequencePurpleEyesR[5];
int cursorPurpleEyes = 0;

void displayPurpleEyes() {

  // Frame 1
  if (cursorPurpleEyes == 0) {
    if (millis() - chronoEyes > 500) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, purpleEyesL[cursorPurpleEyes][col]);
        matrix2.setColumn(0, col, purpleEyesR[cursorPurpleEyes][col]);
      }
      cursorPurpleEyes++;
    }
  }

  // Frame 2
  if (cursorPurpleEyes == 1) {
    if (millis() - chronoEyes > 1000) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, purpleEyesL[cursorPurpleEyes][col]);
        matrix2.setColumn(0, col, purpleEyesR[cursorPurpleEyes][col]);
      }
      cursorPurpleEyes++;
    }
  }

  // Frame 3
  if (cursorPurpleEyes == 2) {
    if (millis() - chronoEyes > 1200) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, purpleEyesL[cursorPurpleEyes][col]);
        matrix2.setColumn(0, col, purpleEyesR[cursorPurpleEyes][col]);
      }
      cursorPurpleEyes++;
    }
  }

  // Frame 4
  if (cursorPurpleEyes == 3) {
    if (millis() - chronoEyes > 1200) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, purpleEyesL[cursorPurpleEyes][col]);
        matrix2.setColumn(0, col, purpleEyesR[cursorPurpleEyes][col]);
      }
      cursorPurpleEyes = 0;
    }
  }
}

/******** ANITMATION FRAMES : ORANGE ************/

byte blueEyesL[4][8] = {
  { B10000000,
    B00010000,
    B00101000,
    B00010000,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B01100000,
    B01100000,
    B00001100,
    B00010010,
    B00010010,
    B00001100,
    B00000000 },

  { B00000000,
    B00100000,
    B01001110,
    B00010001,
    B00010001,
    B00010001,
    B00101110,
    B00000000 },

  { B00000000,
    B01000000,
    B00100000,
    B00001100,
    B00010010,
    B01010010,
    B00001100,
    B00000000 },
};

byte blueEyesR[4][8] = {

  { B10000000,
    B00010000,
    B00101000,
    B00010000,
    B00000000,
    B00000000,
    B00000000,
    B00000000 },

  { B00000000,
    B01100000,
    B01100000,
    B00001100,
    B00010010,
    B00010010,
    B00001100,
    B00000000 },

  { B00000000,
    B00100000,
    B01001110,
    B00010001,
    B00010001,
    B00010001,
    B00101110,
    B00000000 },

  { B00000000,
    B01000000,
    B00100000,
    B00001100,
    B00010010,
    B01010010,
    B00001100,
    B00000000 },
};

/********************* BLUE ***********************/
int sequenceBlueEyesL[5];
int sequenceBlueEyesR[5];
int cursorBlueEyes = 0;

void displayBlueEyes() {

  // Frame 1
  if (cursorBlueEyes == 0) {
    if (millis() - chronoEyes > 300) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, blueEyesL[cursorBlueEyes][col]);
        matrix2.setColumn(0, col, blueEyesR[cursorBlueEyes][col]);
      }
      cursorBlueEyes++;
    }
  }

  // Frame 2
  if (cursorBlueEyes == 1) {
    if (millis() - chronoEyes > 300) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, blueEyesL[cursorBlueEyes][col]);
        matrix2.setColumn(0, col, blueEyesR[cursorBlueEyes][col]);
      }
      cursorBlueEyes++;
    }
  }

  // Frame 3
  if (cursorBlueEyes == 2) {
    if (millis() - chronoEyes > 300) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, blueEyesL[cursorBlueEyes][col]);
        matrix2.setColumn(0, col, blueEyesR[cursorBlueEyes][col]);
      }
      cursorBlueEyes++;
    }
  }

  // Frame 4
  if (cursorBlueEyes == 3) {
    if (millis() - chronoEyes > 300) {
      chronoEyes = millis();
      matrix1.clearDisplay(0);
      matrix2.clearDisplay(0);

      for (int col = 0; col < 8; col++) {
        matrix1.setColumn(0, col, blueEyesL[cursorBlueEyes][col]);
        matrix2.setColumn(0, col, blueEyesR[cursorBlueEyes][col]);
      }
      cursorBlueEyes = 0;
    }
  }
}
