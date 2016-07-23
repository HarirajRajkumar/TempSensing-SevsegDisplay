/* This program reads the surrounding room temperature (using a LM35)
 *  and shows the output through the Serial monitor + Multiplexed Display ( 7 seg )
 *
 *  It uses 2 user defined functions 
 *  1 . MyTemp() <= Reads the temperature 
 *  2 . SevDisplay() <= To print the temperature to Multiplexed Display ( 7 seg )
 * 
 * Pin Connections :
 *  Connect LM35 data pin to the A0 pin
 *  2, 3, 4, 5 pins to the SevSeg Transistor pins (NPN)
 *  6, 7, 8, 9, 10, 11, 12, 13 pins to Sevseg LED Common anone pins
 *  
 *  Programmer : Hariaj .R
 *  Date : 23-Jul-2016
 *  
 */



/* I used user defined funcn for the first time.
 *  In case if you find something wrong please feel free to correct me
 *  Thank you..
 *  An arduino startup ;-)
 */


#include <SevSeg.h>  

SevSeg sevseg;  // Class Object

 //  Pin Declaration Section
 const byte TempPin = A0;
 
 void setup()  // Runs only one time
 {
  // Setting up sevseg display

  byte NumOfDig = 4;   // Total no of digits used in the sevseg
  byte digitPins[] = {5, 4 ,3 , 2};  // for the transistors
  byte SegmentPins[] = { 6 , 7, 8, 9, 10, 11, 12, 13};  // SevSeg pins + 1 decimal point
  sevseg.begin(COMMON_ANODE , NumOfDig , digitPins , SegmentPins);
  // Refer sevseg library 
    
  
   pinMode(TempPin , INPUT);  // Setting up analog pin A0 as input
   
   Serial.begin(9600);  // Setting up Serial monitor at 9600 baud rate
   
 } // Close Setup

 void loop()
 {

  
  float Temp = Mytemp();  // stores the value from the MyTemp funcn to the Temp
  
  Serial.print(Temp);  // Prints Temperature in *C
  Serial.println("  in C");  //

  SevDisplay(Temp);  // This funcn displays the Temp to the SEVSEG display
 }// close loop
 
 // Funcn to calculate the Surrounding temperature
  float Mytemp() { 
  float finalTemp_inC = (5.0 *  analogRead(TempPin) * 100.0) / 1024; // Standard formula to calculate the temperature in *C
  return finalTemp_inC;  // Returns the Calculated value to the loop funcn in float data type
  }// Close Mytemp

// funcn to display the temperature on to the sevseg display
 int SevDisplay(float Temp2)  
 {
  sevseg.setNumber(Temp2,2);
  sevseg.refreshDisplay(); 
 }
 

