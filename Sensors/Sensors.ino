#include<avr/io.h>                                  // Include library avr/io.h 
#include<util/delay.h>                              // Include delay library
#define checkbit(x,y) ((x) &(y))                    // Create Macro checkbit
#define bitn(p) (0x01 << (p))                       // Create Macro bitn

int main(void)                                      // Begin code
{
  Serial.begin (2000000);                           // Start serial moniter and set BAUD RATE to 2000000
  int xval, yval, zval, val;                        // Create Variables Xval for X-axis( Left & Right ) , Yval for  Y-axis (Up & Down) , Zval for Z-axis ( Depth ), And Val to store the IR Sensor's Value.
    
    while(1)                                        // Begin Infinite Loop
    {
      // This Whole Section is to fetch the Accelerometer's Value 
       ADMUX = 0x45;                                // Set the Analog to Digatal Converter to Port A (Analog) Pin 5  
       ADCSRA = 0xC7;                               // Begin the Analog to Digatal Conversion to Port A Pin 5 
       while (checkbit(ADCSRA, bitn(ADSC)));        // Wait until Analog to Digatal Converter is complete 
       xval =ADCW;                                  // Save Port A Pin 5's Digatal Value on to Variable xval               
       Serial.print("X-axis: ");                    // Print "X-axis: " on to the Serial Moniter 
       Serial.print(xval);                          // Print Variable xval's Value on to the Serial Moniter  
       
       ADMUX = 0x46;                                // Set the Analog to Digatal Converter to Port A (Analog) Pin 6  
       ADCSRA = 0xC7;                               // Begin the Analog to Digatal Conversion         
       while(checkbit(ADCSRA, bitn(ADSC)));         // Wait until the Analog to Digatal Converter is complete
       yval = ADCW;                                 // Save Port A Pin 6's Digital Value on to Variable yval
       Serial.print(" Y-axis ");                    // Print " Y-axis " on to the Serial Moniter 
       Serial.print(yval);                          // Print Variable yval's Value on to the Serial Moniter 
       
       ADMUX = 0x47;                                // Set theAnalog to Digatal Converter to Port A Pin 7
       ADCSRA = 0xC7;                               // Begin the Analog to Digatal Converter     
       while(checkbit(ADCSRA, bitn(ADSC)));         // Wait until the Analog to Digatal Convertesion is Complete
       zval = ADCW;                                 // Save Port A Pin 7's Digital Value on to Variable zval
       Serial.print(" Z-axis ");                    // Print " Z-axis " on to the Serial Moniter 
       Serial.println(zval);                        // Print Variable zval's Value on to the Serial Moniter then create a new line                             
       // This next section is to fetch the IR sensor's Value
       ADMUX = 0x40;                                // Set the Analog to Digital Converter to Port A Pin 0
       ADCSRA = 0xC7;                               // Begin the Analog to Digital Conversion
       while (checkbit(ADCSRA, bitn(ADSC)));        // Wait until the Analog to Digial Conversion is Complete
       val = ADCW;                                  // Set Port A Pin 0's Digital Value to Variable VAL
       Serial.print("Sensor's Val: ");               // Print "Sensor's Val: " on to the Serial Moniter
       Serial.println(val);                          // Print Variable val's Value on to the Serial Moniter
       _delay_ms(600);                               // Wait 600 Milliseconds
    } 
}