// This Section is to Create Global Variables, Define Objects, and Include library's
#include<avr/io.h>                                  // Include library avr/io.h 
#include<util/delay.h>                              // Include delay library
#define checkbit(x,y) ((x) &(y))                    // Create Macro checkbit
#define bitn(p) (0x01 << (p))                       // Create Macro bitn
int angle,count,count_angle,count_angle2,angle2;    // Create Global Variables angle,count,count_angle
int var = 0;                                        // Create Global Variable Var and set it to 0
int main(void)                                      // Begin code
{
  // This Section is to Create Local Variables, Start serial moniter and set Serial Moniter's Baud Rate to 2000000, and finally set the Input Output Ports
  Serial.begin (2000000);                           // Start serial moniter and set BAUD RATE to 2000000
  int Data;                                         // Create Variable Val to store the IR Sensor's Value.
  int Recab = 100;                                  // Create Variable Recab to store Recalibration data
  DDRD = 0xFB;                                      // Set PORTD Pin 2 to Input Rest as Output
  TCCR0 = 0x03; 
  while(1)                                        // Begin Infinite Loop
    {                            
       // This section is to fetch the IR sensor's Value
       ADMUX = 0x40;                                // Set the Analog to Digital Converter to Port A Pin 0
       ADCSRA = 0xC7;                               // Begin the Analog to Digital Conversion
       while (checkbit(ADCSRA, bitn(ADSC)));        // Wait until the Analog to Digial Conversion is Complete
       Data = ADCW;                                  // Set Port A Pin 0's Digital Value to Variable VAL
       Serial.print("Sensor's Val: ");               // Print "Sensor's Val: " on to the Serial Moniter
       Serial.println(Data);                          // Print Variable val's Value on to the Serial Moniter
       if(checkbit(PORTD, bitn(2)))                   // If Switch 1 is pressed
        {
          Recab = Data;                               // Set Recab's Value to Data's Value
        }

        if(Data = Recab)                              // If Data equals Recab           
        {
          angle = 180;                                // Set Angle to 180 ( Start the Servo Moter to start Function Alert)
          angle2 = 0;                                 // Set Angle1 to 0; ( Retract the Servo Moter to start Function Quiet)
          convert();                                  // Head over to the convert function
        }

        else
        {
          angle2 = 180;                                // Set Angle to 180 ( Start the Servo Moter to start Function Quiet)
          angle = 0;                                   // Set Angle1 to 0; ( Retract the Servo Moter to start Function Alert)
          convert();                                  // Head over to the convert function
        }
    } 
}



void convert()    // Function "Convert"
{
  while(!(PIND & 0x04)|| (PIND & 0x08))
  {
    int tem = (5 + angle/10)
    int tem2 = (5 = angle2/10)
    TCNT0 = 0;
    while (var < 200)
    {
      if(TCNT0 == 25)
      {
        var++;
        TCNT0 = 0;
      }
      if(var == tem)
      {
        PORTB = 0x00;
      }
    }
    if (var == 200)
    {
      PORTB = 0xFB;
      var = 0;
    }
  }
}