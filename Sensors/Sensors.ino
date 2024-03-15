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
       
       // This next section is all the IF statments
       if(checkbit(PORTD, bitn(2)))                   // If Switch 1 is pressed
        {
          Serial.println("Entered Recab State");
          Recab = Data;                               // Set Recab's Value to Data's Value
          Serial.print("Recab's Val: ");               // Print "Sensor's Val: " on to the Serial Moniter
          Serial.println(Recab);                          // Print Variable Data's Value on to the Serial Moniter
        }
        
        if(checkbit(PORTD, bitn(3)))                   // If Switch 2 is pressed
        {
          Serial.print("Sensor's Val: ");               // Print "Sensor's Val: " on to the Serial Moniter
          Serial.println(Data);                          // Print Variable Data's Value on to the Serial Moniter
        }
        if(Data = Recab)                              // If Data equals Recab           
        {
          Serial.println("Entered Data State");
          angle = 180;                                // Set Angle to 180 ( Start the Servo Moter to start Function Alert)
          angle2 = 0;                                 // Set Angle1 to 0; ( Retract the Servo Moter to start Function Quiet)
          convert();                                  // Head over to the convert function
        }

        else
        {
          Serial.println("Entered Else State");
          angle2 = 180;                                // Set Angle to 180 ( Start the Servo Moter to start Function Quiet)
          angle = 0;                                   // Set Angle1 to 0; ( Retract the Servo Moter to start Function Alert)
          convert();                                  // Head over to the convert function
        }
    } 
}


// Function CONVERT section
void convert()    // Function "Convert"
{
  for(int i = 0; i<20; i++)         // Repeat 20 times
  {
  while(!(PIND & 0x04)|| (PIND & 0x08))
  {
    int tem = (5 + angle/10);  // Create Variable tem and set it's value to angle divided by 10 then add 5
    int tem2 = (5 + angle2/10); // Create Variable tem2 and set it's value to angle2 divided by 10 then add 5
    TCNT0 = 0;        // Reset timer
    while (var < 200)       // Every 20 milliseconds run this code ( I think? )
    {
      if(TCNT0 == 25)       // If the Timer reaches 25 ticks ( 100 milliseconds )
      {
        var++;              // Increase Var by 1
        TCNT0 = 0;          // Reset timer
      }
      if(var == tem)        // If var equals tem
      {
        PORTB = 0x00;       // Turn off PORTB
      }
    }
    if (var == 200)         // If var equals 200
    {
      PORTB = 0xFB;         // Turn on PORTB exept for PIN 2
      var = 0;              // Set var to 0
    }
  }
 } 
}