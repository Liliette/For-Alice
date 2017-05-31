/*
  Melody

 Plays a melody

 circuit:
 * 8-ohm speaker on digital pin 8

 created 21 Jan 2010
 modified 30 Aug 2011
 by Tom Igoe

This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/Tone

 */
#include "pitches.h"

// notes in the melody:
int melody[] = {
  NOTE_E6, NOTE_DS6, NOTE_E6, NOTE_DS6, NOTE_E6, NOTE_B5, NOTE_DS6, NOTE_C6, NOTE_A5,NOTE_C5,NOTE_GS5,NOTE_A5,NOTE_B5,NOTE_E5,NOTE_E5,NOTE_B5,NOTE_C6,NOTE_E5,NOTE_E6,NOTE_DS6,
  NOTE_E6, NOTE_DS6, NOTE_E6, NOTE_B5, NOTE_DS6, NOTE_C6, NOTE_A5,NOTE_C5,NOTE_E5,NOTE_A5,NOTE_B5,NOTE_E5,NOTE_C6,NOTE_B5,NOTE_A5,0,NOTE_E6, NOTE_DS6, NOTE_E6, NOTE_DS6, NOTE_E6, NOTE_B5, NOTE_DS6, NOTE_C6, NOTE_A5,NOTE_C5,NOTE_GS5,NOTE_A5,NOTE_B5,NOTE_E5,NOTE_E5,NOTE_B5,NOTE_C6,
  NOTE_E6, NOTE_DS6, NOTE_E6, NOTE_DS6, NOTE_E6, NOTE_B5, NOTE_DS6, NOTE_C6, NOTE_A5,NOTE_C5,NOTE_GS5,NOTE_A5,NOTE_B5,NOTE_E5,NOTE_E5,NOTE_B5,NOTE_C6,NOTE_B5,NOTE_C6,NOTE_D6,
  NOTE_E6,NOTE_G5,NOTE_F6,NOTE_E6,NOTE_D6,NOTE_F5,NOTE_E6,NOTE_D6,NOTE_C6,NOTE_E5,NOTE_D6,NOTE_C6,NOTE_B5,NOTE_E5,NOTE_E6,NOTE_E5,NOTE_E6,NOTE_E6,NOTE_E7,NOTE_DS6,NOTE_E6,NOTE_D6,
  NOTE_E6, NOTE_DS6, NOTE_E6, NOTE_B5, NOTE_DS6, NOTE_C6, NOTE_A5,NOTE_C5,NOTE_GS5,NOTE_A5,NOTE_B5,NOTE_E5,NOTE_E5,NOTE_B5,NOTE_C6
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4,4,4,4,4,4,4,4,2,4,4,4,2,4,4,4,2,4,4,4,4,4,4,4,4,4,2,4,4,4,2,4,4,4,2,
  4,4,4,4,4,4,4,4,4,2,4,4,4,2,4,4,4,2,4,4,4,4,4,4,4,4,2,4,4,4,2,4,4,4,2,
  4,4,4,
  2,4,4,4,2,4,4,4,2,4,4,4,2,4,4,4,4,4,4,4,4,4,
  4,4,4,4,4,4,4,4,2,4,4,4,2,4,4,4,2,
};

int greenPin = 6;
int redPin = 9;
int bluePin = 5;
int counter = 0;//狀態切換


void setup() {
  // iterate over the notes of the melody:
  pinMode(greenPin,OUTPUT);
  pinMode(redPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  for (int thisNote = 0; thisNote < 112; thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);

          counter++;
  if(counter == 1){//點亮綠色
    analogWrite(greenPin,255);
    analogWrite(redPin,0);
    analogWrite(bluePin,0);
  }
  else if(counter == 2){//點亮紅色
    analogWrite(greenPin,0);
    analogWrite(redPin,255);
    analogWrite(bluePin,0);
  }
  else if(counter == 3){//點亮藍色
    analogWrite(greenPin,0);
    analogWrite(redPin,0);
    analogWrite(bluePin,255);
  }
      else if(counter == 4){//點亮藍色
    analogWrite(greenPin,255);
    analogWrite(redPin,0);
    analogWrite(bluePin,255);
      }
      else if(counter == 5){//點亮藍色
    analogWrite(greenPin,255);
    analogWrite(redPin,225);
    analogWrite(bluePin,0);
      }
      else if(counter == 6){//點亮藍色
    analogWrite(greenPin,0);
    analogWrite(redPin,225);
    analogWrite(bluePin,225);
    counter = 0;//歸零
  }
 
  }



  
}

void loop() {
  // no need to repeat the melody.



}
