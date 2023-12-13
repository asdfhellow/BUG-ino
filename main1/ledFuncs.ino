


// setup() function -- runs once at startup --------------------------------

// loop() function -- runs repeatedly as long as board is on ---------------

void sleepLED(uint32_t hue) {  //sequence when sleeping
  uint32_t color;
  if (brightness < 0) {
    speedSleepLED = -speedSleepLED;
  } else if (brightness > 230) {
    speedSleepLED = -speedSleepLED;
  }

  brightness += speedSleepLED;

  strip.fill(strip.ColorHSV(hue, 255, brightness));
  strip.show();
}

void disorientedLED() {
  int brightnessSequence[3] = { 255, 180, 0 };
 hueChange += 200;
  disorientedHue = 0+100000*(AcYCalibrate+AcXCalibrate)+hueChange;
  if (millis() - chronoPixel >= 50) {  //  Check for expired time
    chronoPixel = millis();
    for (int i = 0; i < pixelNumber; i++) {
      strip.setPixelColor(i + pixelQueue, strip.ColorHSV(disorientedHue + pixelQueue * 20, 255, brightnessSequence[pixelQueue]));  //  Set pixel's color to brightness sequence
    }
    for (int i = 0; i < pixelNumber; i += 3) {
      strip.setPixelColor(i + pixelQueue, strip.ColorHSV(disorientedHue, 0, 0));  //  Set pixel's color to zero on every third pixel
    }
    strip.show();  //  Update strip to match
    pixelQueue++;  //  Advance current pixel
    if (pixelQueue >= 3)
      pixelQueue = 0;  //  Loop
  }
}

void scaredLED(uint32_t hue) {  //sequence when scared
  int brightnessSequence[3] = { 255, 180, 0 };
  if (millis() - chronoPixel >= 50) {  //  Check for expired time
    chronoPixel = millis();
    for (int i = 0; i < pixelNumber; i++) {
      strip.setPixelColor(i + pixelQueue, strip.ColorHSV(hue, 255, brightnessSequence[pixelQueue]));  //  Set pixel's color to brightness sequence
    }
    for (int i = 0; i < pixelNumber; i += 3) {
      strip.setPixelColor(i + pixelQueue, strip.ColorHSV(hue, 0, 0));  //  Set pixel's color to zero on every third pixel
    }
    strip.show();  //  Update strip to match
    pixelQueue++;  //  Advance current pixel
    if (pixelQueue >= 3)
      pixelQueue = 0;  //  Loop
  }
}

void swimmingLED(uint32_t hue) {
  if (millis() - chronoPixel >= 50) {  //  Check for expired time
    chronoPixel = millis();
    strip.fill(strip.ColorHSV(hue, 255, 255));
    pixelQueue++;
    if (pixelQueue >= pixelNumber) {
      pixelQueue = 0;
    }
    for (int i = 0; i < 4; i++) {
      strip.setPixelColor(pixelQueue + i, strip.ColorHSV(hue, 255, 0));
    }
  }
  strip.show();
}

void loveLED(uint32_t hue) {
  int heartbeatSequence[19] = { 255, 255, 255, 255, 255, 0, 255, 0, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255 };
  if (millis() - chronoPixel >= 150) {  //  Check for expired time
    chronoPixel = millis();

    strip.fill(strip.ColorHSV(hue, 255, heartbeatSequence[heartbeatCursor]));

    for (int i = 0; i < pixelNumber; i += 5) {

      strip.setPixelColor(i + pixelQueue, strip.ColorHSV(hue - 800, 255, heartbeatSequence[heartbeatCursor]));  //  Set pixel's color to zero on every third pixel
    }

    pixelQueue++;
    heartbeatCursor++;
    if (pixelQueue >= 5) {
      pixelQueue = 0;
    }
    if (heartbeatCursor >= 18)
      heartbeatCursor = 0;
    strip.show();
  }
}

void happyLED(uint32_t hue) {
  //variables
  int pixelTime;
  int hueInterval = 400;
  int hueSequence[20]{ hue, hue - hueInterval * 1, hue - hueInterval * 2, hue - hueInterval * 3, hue - hueInterval * 4, hue - hueInterval * 5, hue - hueInterval * 4, hue - hueInterval * 3, hue - hueInterval * 2, hue - hueInterval * 1, hue, hue + hueInterval * 1, hue + hueInterval * 2, hue + hueInterval * 3, hue + hueInterval * 4, hue + hueInterval * 5, hue + hueInterval * 4, hue + hueInterval * 3, hue + hueInterval * 2, hue + hueInterval * 1 };
  int brightnessSequence[12] = { 50, 75, 100, 50, 140, 120, 100, 10, 50, 70, 100, 125 };

  // change sequence
  if (millis() - sequenceChrono >= 3000) {
    sequenceChrono = millis();
    sequenceIndex++;
    if (sequenceIndex >= 3) {
      sequenceIndex = 0;
    } else {
    }
  }


  switch (sequenceIndex) {
    case 0:                                //green wheel
      if (millis() - chronoPixel >= 50) {  //  Check for expired time
        chronoPixel = millis();
        strip.fill(strip.ColorHSV(hueSequence[hueCursor], 255, 100));
        for (int i = 0; i < pixelNumber; i += 5) {
          strip.setPixelColor(i + pixelQueue, strip.ColorHSV(hue, 255, 255));  //  Set pixel's color to zero on every third pixel
        }

        //update cursors//
        //hue
        hueCursor++;
        if (hueCursor > 19) {
          hueCursor = 0;
        }

        // pixel
        pixelQueue++;
        if (pixelQueue >= 5) {
          pixelQueue = 0;
        }
        Serial.println(hueCursor);
      }
      strip.show();  //show strip
      break;
    case 1:                                // flashing lights
      if (millis() - chronoPixel >= 50) {  //  Check for expired time
        chronoPixel = millis();
        strip.fill(strip.ColorHSV(hueSequence[hueCursor - 1], 255, brightnessSequence[brightnessCursor]));
        for (int i = 0; i < pixelNumber; i += 5) {
          strip.setPixelColor(i + pixelQueue, strip.ColorHSV(hue, 255, 255));  //  Set pixel's color to zero on every third pixel
        }
        //update cursors//
        //hue
        hueCursor++;
        if (hueCursor >= 20) {
          hueCursor = 0;
        }
        //brightness
        brightnessCursor++;
        if (brightnessCursor >= 20)
          brightnessCursor = 0;
        // pixel
        pixelQueue++;
        if (pixelQueue >= 5) {
          pixelQueue = 0;
        }
        strip.show();
        break;
      }
    case 2:                                //green wheel
      if (millis() - chronoPixel >= 50) {  //  Check for expired time
        chronoPixel = millis();
        strip.fill(strip.ColorHSV(hueSequence[hueCursor], 255, 100));
        for (int i = pixelNumber; i > 0; i -= 5) {
          strip.setPixelColor(i + pixelQueue, strip.ColorHSV(hue, 255, 255));  //  Set pixel's color to zero on every third pixel
        }

        //update cursors//
        //hue
        hueCursor--;
        if (hueCursor <= 0) {
          hueCursor = 19;
        }

        // pixel
        pixelQueue--;
        if (pixelQueue <= 0) {
          pixelQueue = 5;
        }
        Serial.println(hueCursor);
      }
      strip.show();  //show strip
      break;
  }
}

void neutralLED(uint32_t hue) {
  int hueInterval = 150;
  int hueSequence[20]{ hue, hue - hueInterval * 1, hue - hueInterval * 2, hue - hueInterval * 3, hue - hueInterval * 4, hue - hueInterval * 5, hue - hueInterval * 4, hue - hueInterval * 3, hue - hueInterval * 2, hue - hueInterval * 1, hue, hue + hueInterval * 1, hue + hueInterval * 2, hue + hueInterval * 3, hue + hueInterval * 4, hue + hueInterval * 5, hue + hueInterval * 4, hue + hueInterval * 3, hue + hueInterval * 2, hue + hueInterval * 1 };

  if (millis() - chronoPixel >= 70) {  //  Check for expired time
    chronoPixel = millis();
    strip.fill(strip.ColorHSV(hueSequence[hueCursor], 255, 100));
    for (int i = 0; i < pixelNumber; i += 15) {
      strip.setPixelColor(i + pixelQueue, strip.ColorHSV(hue, 255, 255));  //  Set pixel's color to zero on every third pixel
    }

    //update cursors//
    //hue
    hueCursor++;
    if (hueCursor > 19) {
      hueCursor = 0;
    }

    // pixel
    pixelQueue++;
    if (pixelQueue >= 15) {
      pixelQueue = 0;
    }
    Serial.println(hueCursor);
  }
  strip.show();  //show strip
}

void displayLEDColors(int ledIndex) {
  switch (ledIndex) {
    case 0:  // neutral
      neutralLED(yellowHue);
      break;
    case 1:  // hasppy
      happyLED(greenHue);
      break;
    case 2:  //scared?
      scaredLED(orangeHue);
      break;
    case 3:  // water?
      swimmingLED(blueHue);
      break;
    case 4:  // sleep?
      sleepLED(purpleHue);
      break;
    case 5:  // love?
      loveLED(redHue);
      break;
    case 999:  //disoriented
      disorientedLED();
      break;
  }
}

// exemple de fonction pour display colors????
