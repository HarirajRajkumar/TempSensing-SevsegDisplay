# The-duino

This Following program uses Arduino Uno to read the surrounding room temperature using a LM35 in celcius and
prints the final value on both the Serial monitor through serial port and 4 Digit Seven Segment Multiplexed display (COMMON ANODE).

Pin Connections :
-LM35 data pin to A0 ( it's not hardcoded you can replace it ).
-2 , 3 , 4 , 5 digitalPins of arduino to base of 4 transistors (BC547)
-6 , 7 , 8 , 9 , 10 , 11 , 12 , 13 to the Seven segment Multiplexed display 
 ( 7 starting pins is given to seven segment and remaining one is Decimal point )
 
Setup all the connections and start the Serial monitor at 9600 badu rate (or bits per second)
