#include <SevSeg.h>

byte num=123;
 SevSeg sevseg; //Instantiate a seven segment object
 
 void setup() {
   byte numDigits = 4;
   byte digitPins[] = {5 , 4 , 3 ,2 };
   byte segmentPins[] = {6, 7, 8,9, 10,11,12, 13};
   sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
 }

 void loop() {
  sevseg.setNumber(num,2); // ...ber( number , decimal point )
  //sevseg.refreshDisplay();
  
 
  
 }

