// Motors should occupuy 2 ports for fwd bwd left and right movements

#include<avr/io.h>                                  // Include avr/io.h library
#include<util/delay.h>                              // Include Delay library
#define checkbit(x,y) ((x) & (y))                   // Create checkbit macro 
#define bitn(p) (0x01 << (p))                       // Create bitn macro
#define setbit(x,y) (x|=y)                          // Create Setbit Macro
#define clearbit(x,y) (x&=~y)                       // Create Clearbit Macro
int main(void)                                      // Begin Code 
{
    int x;                                          // Create Local Variable X
    int y;                                          // Create Local Variable Y
    Serial.begin(2000000);                          // Begin Serial Moniter
    DDRC = 0xFF;                                    // Set Port C as Output
    DDRD = 0xFF;                                    // Set Port D as Output
    DDRB = 0x00;                                    // Set Port B as Input
    while(1)                                        // Begin Endless Loop
    {
        ADMUX = 0x42;                               // Analog to Digital Converter Pin to A2
        ADCSRA = 0xC7;                              // Begin Analog to Digatal Conversion
        while((ADCSRA& (1<<ADSC)));                 // Wait Until Conversion is Completed
        y=ADCW;                                     // Save A2 Digatal Input to Variable Y
        ADMUX=0x43;                                 // Analog to Digital Converter Pin to A3
        ADCSRA = 0xC7;                              // Begin Analog to Digital Conversion
        while((ADCSRA& (1<<ADSC)));                 // Wait Until Conversion is Completed
        x=ADCW;                                     // Save A3 Digital Input to Variable Z
        Serial.print("X-axis: ");                   // Print X-axis: onto serial moniter 
        Serial.print(x);                            // Print Variable X to the right of X-axis onto the serial moniter
        Serial.print(" Y-axis: ");                  // Print Y-Axis On the same line Where X-Axis is printed 
        Serial.println(y);                          // Print Variable Y onto the right of Y-Axis then create new line 

        if (y > 800)                                // If Y is greater than 800 ( Up ) 
        { 
            setbit(PORTD,bitn(5));                  // Set PORTD Pin 5 to High ( Positive ) 
            clearbit(PORTD,bitn(6));                // Set PORTD Pin 6 To Low ( Negative )
        }

        if(y< 100)                                  // If X is less than 100 ( Down )
        { 
            setbit(PORTD,bitn(6));                  // Set PORTD Pin 6 to High ( Positive ) 
            clearbit(PORTD,bitn(5));                // Set PORTD Pin 5 To Low ( Negative )
        } 

        else                                        // Else
        {
          PORTD = 0x00;                             // Set PORTD to Low ( Negative )
        }
    }
}