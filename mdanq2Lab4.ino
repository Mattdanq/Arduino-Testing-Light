/*
  Matthew Danque mdanq2@uic.edu 653044344
  Lab 4 - Photoresistor
  Kaz 8 am Tuesday
  This lab is supposed to use the photoresistor to detech the light level in the room, displaying the result on the LCD board
  I assume that the sensor would be more sensitive to open room light but it just isnt as good as the second sensor i have
  References:
  https://playground.arduino.cc/Learning/PhotoResistor/
  https://www.allaboutcircuits.com/projects/using-the-arduinos-analog-io/#:~:text=as%20digital%20signals.-,The%20Arduino%20can%20input%20and%20output%20analog%20signals%20as%20well,%2Ddigital%20converter%20(ADC)
  https://forum.arduino.cc/t/problems-with-light-sensor/324626
*/

// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

String result;
int photoSensValues;

void setup() {
  pinMode(A0, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {
  photoSensValues = analogRead(A0); //reads in the from the photosensor attached to analog pin a0
  Serial.println(photoSensValues);
  lcd.setCursor(0, 0); //makes sure it starts top row 
  //if cases based off whatt values come in for the lab room
  if (photoSensValues <= 200) {
    result = "dark";
  } else if (photoSensValues <= 380) {
    result = "partially dark";
  } else if (photoSensValues <= 570) {
    result = "medium";
  } else if (photoSensValues < 830 ) {
    result = "fully lit";
  } else if (photoSensValues >= 830) {
    result = "brightly lit";
  }
  lcd.print(result);
  delay(1000); //so the LCD doesnt spazz out
  lcd.clear(); //makes sure the result always refreshes
}