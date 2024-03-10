#include<avr/io.h>                                  // Include avr/io.h library
#include<util/delay.h>                              // Include Delay library
#define checkbit(x,y) ((x) & (y))                   // Create the Checkbit macro 
#define bitn(p) (0x01 << (p))                       // Create the Bitn macro
#define setbit(x,y)(x|=y)                          // Create the Setbit Macro
#define clearbit(x,y) (x&=~y)                       // Create the Clearbit Macro
int timer;
int main(void)                                      // Begin Code
{
  DDRD = 0x3F;                                       // Set PORTD to High
  Serial.begin(2000000);
  // TCCR0 = 0x03;
  while(1)                                          // Begin Inf Loop
  {
    // if(TCCR0 == 25)
    // {
    //   TCCR0 = 0;
    //   timer = timer + 100;
    // }
    if(checkbit(PIND,bitn(6)))                     // Check if PORTD Pin 6 is High 
    {
            // Serial.println("PORTD Pin 6 activated at " timer "Milliseconds");
            setbit(PORTD,bitn(2));                  // Set PORTD Pin 2 to High ( Positive ) 
            setbit(PORTD,bitn(4));                  // Set PORTD Pin 4 to High ( Positive )
            clearbit(PORTD,bitn(3));                // Set PORTD Pin 3 to Low ( Negative )
            clearbit(PORTD,bitn(5));                // Set PORTD Pin 5 to Low ( Negative )
    }

    if(checkbit(PIND,bitn(7)))                     // Check if PORTD Pin 7 is High 
    {
            // Serial.println("PORTD Pin 7 activated at " timer "Milliseconds");  
            setbit(PORTD,bitn(5));                  // Set PORTD Pin 5 to High ( Positive ) 
            setbit(PORTD,bitn(3));                  // Set PORTD Pin 3 to High ( Positive )
            clearbit(PORTD,bitn(4));                // Set PORTD Pin 4 to Low ( Negative )
            clearbit(PORTD,bitn(2));                // Set PORTD Pin 2 to Low ( Negative )
    }
  }
}
