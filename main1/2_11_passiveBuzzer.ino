int long SonChrono = millis();


int melodyJaune[]={

  NOTE_E3, 0, 0, NOTE_G3, NOTE_F3, 0, NOTE_E3};

  int noteDurationsJaune[]={
    2, 2, 2, 4, 8, 2, 2, 0};

int melodyRed[] = {
  NOTE_E4, NOTE_D4, NOTE_A3, NOTE_F3, NOTE_E4, 0, NOTE_D4, NOTE_A3, NOTE_F3, NOTE_C4
};

int noteDurationsRed[] = {
  2, 4, 2, 2, 2, 8, 4, 2, 2, 1
};

// int melodyGreen[] = {
//   NOTE_A4, NOTE_E5, NOTE_FS5, NOTE_E5, NOTE_FS5, NOTE_A5
// };

// int noteDurationsGreen[] = {
//   16, 16, 16, 16, 16, 2, 2, 2
// };

int melodyGreen[] = {
  NOTE_E7, NOTE_A7, NOTE_A7, NOTE_A7, NOTE_E6, NOTE_A6, 0, NOTE_E5,
};

int noteDurationsGreen[] = {
  8,
  16,
  16,
  8,
  8,
  4,
  4,
};

int melodyPurple[] = {
  NOTE_GS5, NOTE_GS5, NOTE_B5, 0, NOTE_GS5, NOTE_GS5, NOTE_B5, 0, NOTE_GS5, NOTE_B5, NOTE_E6, NOTE_DS6, 0, NOTE_CS6, NOTE_CS6, NOTE_B5
};

int noteDurationsPurple[] = {
  4,
  4,
  2,
  4,
  4,
  4,
  2,
  4,
  4,
  4,
  2,
  2,
  4,
  4,
  2,
  2,
};

int melodyOrange[] = {
  NOTE_E3, NOTE_E7, NOTE_F7, NOTE_E7, NOTE_F7, NOTE_E7, NOTE_F7, NOTE_E7, NOTE_F7, NOTE_E7, 0
};

int noteDurationsOrange[] = {
  8,
  2,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
  16,
};

int melodyBlue[] = {
  NOTE_E2, NOTE_A2, NOTE_A2, NOTE_E2, NOTE_E3, NOTE_A2, 0
};

int noteDurationsBlue[] = {
  4, 4, 2, 2, 2, 2
};

int melodyPick[] = {
  NOTE_E2,
  NOTE_A7,
  NOTE_C4,
  NOTE_E2,
  NOTE_FS7,
  NOTE_A2,
  NOTE_B6,
  NOTE_E2,
  NOTE_A7,
  NOTE_C4,
  NOTE_E2,
  NOTE_FS7,
  NOTE_A2,
  NOTE_B6,
};

int noteDurationsPick[] = {
  16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16, 16
};

//if blabla then swagmusic()
//void swagmusic()


void playMelodyJaune() {
  // Calculate note duration based on tempo
  int noteDurationJaune = 1000 / noteDurationsJaune[thisNoteJaune];

  // Check if it's time to play a new note
  if (millis() - noteStartTimeJaune >= noteDurationJaune) {
    noTone(9);  // Stop the previous note
    Serial.println("Jaune Note OFF");

    // Move to the next note
    thisNoteJaune++;
    if (thisNoteJaune >= 7) {
      thisNoteJaune = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimeJaune = millis();
    tone(9, melodyJaune[thisNoteJaune], noteDurationJaune);
    Serial.println("Jaune Note ON");

    // Start the timer for the pause
    pauseStartTimeJaune = millis();
  }

  // Check if it's time to end the pause and move to the next note
  if (millis() - pauseStartTimeJaune >= noteDurationJaune * noteDurationMultiplierJaune / 100) {
    noTone(9);  // Stop the previous note
    Serial.println("Jaune Note OFF");

    // Move to the next note
    thisNoteJaune++;
    if (thisNoteJaune >= 10) {
      thisNoteJaune = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimeJaune = millis();
    tone(9, melodyJaune[thisNoteJaune], noteDurationJaune);
    Serial.println("Jaune Note ON");

    // Start the timer for the pause
    pauseStartTimeJaune = millis();
  }
}


// void playMelodyJaune() {
//   //int sonTimer = millis()
//   //first note

//  int timer = millis();  // Initialize the timer outside the loop
//   int thisNote = 0;  // Initialize thisNote before the loop

//   while (thisNote < 10) {
//     int noteDurationJaune = 1000 / noteDurationsJaune[thisNote];
//     tone(9, melodyJaune[thisNote], noteDurationJaune);
//     Serial.print("Note ON");
//     int pauseBetweenNotes = noteDurationJaune* 1.30;

//     // Check if the elapsed time is greater than the pause between notes
//     if (millis() - timer > noteDurationJaune * 1.30) {
//       noTone(9);
//       timer = millis();  // Reset the timer for the next iteration
//       thisNote++;  // Increment thisNote after the pause
//     }
//   }
// }



void playMelodyRed() {
  // Calculate note duration based on tempo
  int noteDurationRed = 1000 / noteDurationsRed[thisNoteRed];

  // Check if it's time to play a new note
  if (millis() - noteStartTimeRed >= noteDurationRed) {
    noTone(9);  // Stop the previous note
    Serial.println("Red Note OFF");

    // Move to the next note
    thisNoteRed++;
    if (thisNoteRed >= 10) {
      thisNoteRed = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimeRed = millis();
    tone(9, melodyRed[thisNoteRed], noteDurationRed);
    Serial.println("Red Note ON");

    // Start the timer for the pause
    pauseStartTimeRed = millis();
  }

  // Check if it's time to end the pause and move to the next note
  if (millis() - pauseStartTimeRed >= noteDurationRed * noteDurationMultiplierRed / 100) {
    noTone(9);  // Stop the previous note
    Serial.println("Red Note OFF");

    // Move to the next note
    thisNoteRed++;
    if (thisNoteRed >= 10) {
      thisNoteRed = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimeRed = millis();
    tone(9, melodyRed[thisNoteRed], noteDurationRed);
    Serial.println("Red Note ON");

    // Start the timer for the pause
    pauseStartTimeRed = millis();
  }
}

// void playMelodyRed() {
//   int timer = millis();  // Initialize the timer outside the loop
//   int thisNote = 0;  // Initialize thisNote before the loop

//   while (thisNote < 10) {
//     int noteDurationRed = 1000 / noteDurationsRed[thisNote];
//     tone(9, melodyRed[thisNote], noteDurationRed);
//     Serial.print("Note ON");
//     int pauseBetweenNotes = noteDurationRed* 1.30;

//     // Check if the elapsed time is greater than the pause between notes
//     if (millis() - timer > noteDurationRed * 1.30) {
//       noTone(9);
//       timer = millis();  // Reset the timer for the next iteration
//       thisNote++;  // Increment thisNote after the pause
// }}}

void playMelodyGreen() {
  // Calculate note duration based on tempo
  int noteDurationGreen = 1000 / noteDurationsGreen[thisNoteGreen];

  // Check if it's time to play a new note
  if (millis() - noteStartTimeGreen >= noteDurationGreen) {
    noTone(9);  // Stop the previous note
    Serial.println("Green Note OFF");

    // Move to the next note
    thisNoteGreen++;
    if (thisNoteGreen >= 20) {
      thisNoteGreen = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimeGreen = millis();
    tone(9, melodyGreen[thisNoteGreen], noteDurationGreen);
    Serial.println("Green Note ON");

    // Start the timer for the pause
    pauseStartTimeGreen = millis();
  }

  // Check if it's time to end the pause and move to the next note
  if (millis() - pauseStartTimeGreen >= noteDurationGreen * noteDurationMultiplierGreen / 100) {
    noTone(9);  // Stop the previous note
    Serial.println("Green Note OFF");

    // Move to the next note
    thisNoteGreen++;
    if (thisNoteGreen >= 20) {
      thisNoteGreen = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimeGreen = millis();
    tone(9, melodyGreen[thisNoteGreen], noteDurationGreen);
    Serial.println("Green Note ON");

    // Start the timer for the pause
    pauseStartTimeGreen = millis();
  }
}


// void playMelodyGreen() {
//  int timer = millis();  // Initialize the timer outside the loop
//   int thisNote = 0;  // Initialize thisNote before the loop

//   while (thisNote < 20) {
//     int noteDurationGreen = 1000 / noteDurationsGreen[thisNote];
//     tone(9, melodyGreen[thisNote], noteDurationGreen);
//     Serial.print("Note ON");
//     int pauseBetweenNotes = noteDurationGreen* 1.30;

//     // Check if the elapsed time is greater than the pause between notes
//     if (millis() - timer > noteDurationGreen * 1.30) {
//       noTone(9);
//       timer = millis();  // Reset the timer for the next iteration
//       thisNote++;  // Increment thisNote after the pause
//     }
//   }
// }

void playMelodyPurple() {
  // Calculate note duration based on tempo
  int noteDurationPurple = 1000 / noteDurationsPurple[thisNotePurple];

  // Check if it's time to play a new note
  if (millis() - noteStartTimePurple >= noteDurationPurple) {
    noTone(9);  // Stop the previous note
    Serial.println("Purple Note OFF");

    // Move to the next note
    thisNotePurple++;
    if (thisNotePurple >= 200) { //dont want to reset 
      thisNotePurple = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimePurple = millis();
    tone(9, melodyPurple[thisNotePurple], noteDurationPurple);
    Serial.println("Purple Note ON");

    // Start the timer for the pause
    pauseStartTimePurple = millis();
  }

  // Check if it's time to end the pause and move to the next note
  if (millis() - pauseStartTimePurple >= noteDurationPurple * noteDurationMultiplierPurple / 100) {
    noTone(9);  // Stop the previous note
    Serial.println("Purple Note OFF");

    // Move to the next note
    thisNotePurple++;
    if (thisNotePurple >= 20) {
      thisNotePurple = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimePurple = millis();
    tone(9, melodyPurple[thisNotePurple], noteDurationPurple);
    Serial.println("Purple Note ON");

    // Start the timer for the pause
    pauseStartTimePurple = millis();
  }
}


// void playMelodyPurple() {
//   int timer = millis();  // Initialize the timer outside the loop
//   int thisNote = 0;  // Initialize thisNote before the loop

//   while (thisNote < 20) {
//     int noteDurationPurple = 1000 / noteDurationsPurple[thisNote];
//     tone(9, melodyPurple[thisNote], noteDurationPurple);
//     Serial.print("Note ON");
//     int pauseBetweenNotes = noteDurationPurple * 1.30;

//     // Check if the elapsed time is greater than the pause between notes
//     if (millis() - timer > noteDurationPurple * 1.30) {
//       noTone(9);
//       timer = millis();  // Reset the timer for the next iteration
//       thisNote++;  // Increment thisNote after the pause
//     }
//   }
// }

void playMelodyOrange() {
  // Calculate note duration based on tempo
  int noteDurationOrange = 1000 / noteDurationsOrange[thisNoteOrange];

  // Check if it's time to play a new note
  if (millis() - noteStartTimeOrange >= noteDurationOrange) {
    noTone(9);  // Stop the previous note
    Serial.println("Orange Note OFF");

    // Move to the next note
    thisNoteOrange++;
    if (thisNoteOrange >= 11) {
      thisNoteOrange = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimeOrange = millis();
    tone(9, melodyOrange[thisNoteOrange], noteDurationOrange);
    Serial.println("Orange Note ON");

    // Start the timer for the pause
    pauseStartTimeOrange = millis();
  }

  // Check if it's time to end the pause and move to the next note
  if (millis() - pauseStartTimeOrange >= noteDurationOrange * noteDurationMultiplierOrange / 100) {
    noTone(9);  // Stop the previous note
    Serial.println("Orange Note OFF");

    // Move to the next note
    thisNoteOrange++;
    if (thisNoteOrange >=20) {
      thisNoteOrange = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimeOrange = millis();
    tone(9, melodyOrange[thisNoteOrange], noteDurationOrange);
    Serial.println("Orange Note ON");

    // Start the timer for the pause
    pauseStartTimeOrange = millis();
  }
}


// void playMelodyOrange() {
//   int timer = millis();  // Initialize the timer outside the loop
//   int thisNote = 0;  // Initialize thisNote before the loop

//   while (thisNote < 20) {
//     int noteDurationOrange = 1000 / noteDurationsOrange[thisNote];
//     tone(9, melodyOrange[thisNote], noteDurationOrange);
//     Serial.print("Note ON");
//     int pauseBetweenNotes = noteDurationOrange * 1.30;

//     // Check if the elapsed time is greater than the pause between notes
//     if (millis() - timer > noteDurationOrange * 1.30) {
//       noTone(9);
//       timer = millis();  // Reset the timer for the next iteration
//       thisNote++;  // Increment thisNote after the pause
//     }
//   }
// }

void playMelodyBlue() {
  // Calculate note duration based on tempo
  int noteDurationBlue = 1000 / noteDurationsBlue[thisNoteBlue];

  // Check if it's time to play a new note
  if (millis() - noteStartTimeBlue >= noteDurationBlue) {
    noTone(9);  // Stop the previous note
    Serial.println("Blue Note OFF");

    // Move to the next note
    thisNoteBlue++;
    if (thisNoteBlue >= 10) {
      thisNoteBlue = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimeBlue = millis();
    tone(9, melodyBlue[thisNoteBlue], noteDurationBlue);
    Serial.println("Blue Note ON");

    // Start the timer for the pause
    pauseStartTimeBlue = millis();
  }

  // Check if it's time to end the pause and move to the next note
  if (millis() - pauseStartTimeBlue >= noteDurationBlue * noteDurationMultiplierBlue / 100) {
    noTone(9);  // Stop the previous note
    Serial.println("Blue Note OFF");

    // Move to the next note
    thisNoteBlue++;
    if (thisNoteBlue >= 7) {
      thisNoteBlue = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimeBlue = millis();
    tone(9, melodyBlue[thisNoteBlue], noteDurationBlue);
    Serial.println("Blue Note ON");

    // Start the timer for the pause
    pauseStartTimeBlue = millis();
  }
}


// void playMelodyBlue() {
//   //int sonTimer = millis()
//   //first note

//  int timer = millis();  // Initialize the timer outside the loop
//   int thisNote = 0;  // Initialize thisNote before the loop

//   while (thisNote < 10) {
//     int noteDurationBlue = 1000 / noteDurationsBlue[thisNote];
//     tone(9, melodyBlue[thisNote], noteDurationBlue);
//     Serial.print("Note ON");
//     int pauseBetweenNotes = noteDurationBlue* 1.30;

//     // Check if the elapsed time is greater than the pause between notes
//     if (millis() - timer > noteDurationBlue * 1.30) {
//       noTone(9);
//       timer = millis();  // Reset the timer for the next iteration
//       thisNote++;  // Increment thisNote after the pause
//     }
//   }
// }

void playMelodyPick() {
  // Calculate note duration based on tempo
  int noteDurationPick = 1000 / noteDurationsPick[thisNotePick];

  // Check if it's time to play a new note
  if (millis() - noteStartTimePick >= noteDurationPick) {
    noTone(9);  // Stop the previous note
    Serial.println("Note OFF");

    // Move to the next note
    thisNotePick++;
    if (thisNotePick >= 10) {
      thisNotePick = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimePick = millis();
    tone(9, melodyPick[thisNotePick]*abs((AcYCalibrate+AcXCalibrate+1)), noteDurationPick);
    Serial.println("Note ON");

    // Start the timer for the pause
    pauseStartTimePick = millis();
  }

  // Check if it's time to end the pause and move to the next note
  if (millis() - pauseStartTimePick >= noteDurationPick * noteDurationMultiplierPick / 100) {
    noTone(9);  // Stop the previous note
    Serial.println("Note OFF");

    // Move to the next note
    thisNotePick++;
    if (thisNotePick >= 10) {
      thisNotePick = 0; // Reset to the beginning of the melody
    }

    // Start the timer for the next note
    noteStartTimePick = millis();
    tone(9, melodyPick[thisNotePick], noteDurationPick);
    Serial.println("Note ON");

    // Start the timer for the pause
    pauseStartTimePick = millis();
  }
}



// void playMelodyPick() {
//   int timer = millis();  // Initialize the timer outside the loop
//   int thisNote = 0;  // Initialize thisNote before the loop

//   while (thisNote < 10) {
//     int noteDurationPick = 1000 / noteDurationsPick[thisNote];
//     tone(9, melodyPick[thisNote], noteDurationPick);
//     Serial.print("Note ON");
//     int pauseBetweenNotes = noteDurationPick* 1.30;

//     // Check if the elapsed time is greater than the pause between notes
//     if (millis() - timer > noteDurationPick * 1.30) {
//       noTone(9);
//       timer = millis();  // Reset the timer for the next iteration
//       thisNote++;  // Increment thisNote after the pause
// }}}
