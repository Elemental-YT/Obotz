// This Section is to Create Global Variables, Define Objects, and Include library's
#include<avr/io.h>                                  // Include library avr/io.h 
#include<util/delay.h>                              // Include delay library
#define checkbit(x,y) ((x) &(y))                    // Create Macro checkbit
#define bitn(p) (0x01 << (p))                       // Create Macro bitn
int main(void)                                      // Begin code
{
  // This Section is to Create Local Variables, Start serial moniter and set Serial Moniter's Baud Rate to 2000000, and finally set the Input Output Ports
  Serial.begin (2000000);                           // Start serial moniter and set BAUD RATE to 2000000
  int Data;                                         // Create Variable Val to store the IR Sensor's Value.
  int Recab = 100;                                  // Create Variable Recab to store Recalibration data
  DDR? = 0x?? 
  while(1)                                        // Begin Infinite Loop
    {                            
       // This section is to fetch the IR sensor's Value
       ADMUX = 0x40;                                // Set the Analog to Digital Converter to Port A Pin 0
       ADCSRA = 0xC7;                               // Begin the Analog to Digital Conversion
       while (checkbit(ADCSRA, bitn(ADSC)));        // Wait until the Analog to Digial Conversion is Complete
       Data = ADCW;                                  // Set Port A Pin 0's Digital Value to Variable VAL
       Serial.print("Sensor's Val: ");               // Print "Sensor's Val: " on to the Serial Moniter
       Serial.println(Data);                          // Print Variable val's Value on to the Serial Moniter
       if(checkbit(PORT?, bitn(?)))                   // If Switch 1 is pressed
        {
          Recab = Data;                               // Set Recab's Value to Data's Value
        }

        if(Data = Recab)                              // If Data equals Recab           
        {
          setbit(PORT?, bitn(?));                     // Start Moter ALERT!
          clearbit(PORT?, bitn(?));                   // Retract Moter Quiet
        }

        else
        {
          setbit(PORT?, bitn(?));                    // Start Moter Quiet
          clearbit(PORT?, bitn(?));                  // Stop Moter ALERT!
        }
    } 
}