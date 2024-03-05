#include<avr/io.h>                                  // Include avr/io.h library
#include<util/delay.h>                              // Include Delay library
#define checkbit(x,y) ((x) & (y))                   // Create the Checkbit macro 
#define bitn(p) (0x01 << (p))                       // Create the Bitn macro
#define setbit(x,y) (x|=y)                          // Create the Setbit Macro
#define clearbit(x,y) (x&=~y)                       // Create the Clearbit Macro
int main(void)                                      // Begin Code
{
  DDRD = 0xF0                                       // Set PORTD to High
  while(1)                                          // Begin Inf Loop
  {
    if(checkbit(PORTD,bitn(6)))                     // Check if PORTD Pin ? is High 
    {
            setbit(PORTD,bitn(2));                  // Set PORTD Pin 2 to High ( Positive ) 
            setbit(PORTD,bitn(4));                  // Set PORTD Pin 4 to High ( Positive )
            clearbit(PORTD,bitn(3));                // Set PORTD Pin 3 to Low ( Negative )
            clearbit(PORTD,bitn(5));                // Set PORTD Pin 5 to Low ( Negative )
    }

    if(checkbit(PORTD,bitn(7)))
    {
            setbit(PORTD,bitn(5);                  // Set PORTD Pin 5 to High ( Positive ) 
            setbit(PORTD,bitn(3));                  // Set PORTD Pin 3 to High ( Positive )
            clearbit(PORTD,bitn(4));                // Set PORTD Pin 4 to Low ( Negative )
            clearbit(PORTD,bitn(2));                // Set PORTD Pin 2 to Low ( Negative )
    }
  }
}

