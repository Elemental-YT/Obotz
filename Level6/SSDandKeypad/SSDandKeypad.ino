#include<avr/io.h>                              
#include<util/delay.h>                      
#define setbit(x,y)(x|=y)
#define clearbit(x,y)(x&=~y)
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int number[] = {0b11110110, 0b01100000, 0b11010101, 0b11110001, 0b0110001, 0b10110011, 0b10110111, 0b11100000, 0b11110111, 0b11110011}
int i=0;
long result, average;
int main (void)
{
  PORTC = 0xFF
      
 while(1)
  {
    ADMUX = 0x44;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bitn(ASSC)));
    result = result+ADCW;
    i++;

        
    if(i>99)
    {
      average = result/100;
      Serial.println(avarage)
      result = 0;
      i = 0;
    }
    
    if(avarage == 455)                         // If 1th Keycode was recived 
    {
        PORTC = number[2];
        _delay_ms(500);
    }
        
    if(avarage == 690)                            // If 2th Keycode was recived 
    {
        PORTC = number[3];
        _delay_ms(500);
    } 

     if(avarage == 701)               // If 3th Keycode was recived 
    {
        PORTC = number[4];
        _delay_ms(500);
    }    

     if((avarage == 435)                 // If 4th Keycode was recived 
    {
        PORTC = number[5];
        _delay_ms(500);
    }

     if(avarage == 638)               // If 5th Keycode was recived 
    {
        PORTC = number[6];
        _delay_ms(500);
    }

     if(avarage == 644)                 // If 6th Keycode was recived 
    {
        PORTC = number[7];
        _delay_ms(500);
    }

     if(avarage == 418)                    // If 7th Keycode was recived 
    {
        PORTC = number[8];
        _delay_ms(500);
    }

     if(avarage == 612)   // If 8th Keycode was recived 
    {
        PORTC = number[9];
        _delay_ms(500);
    }

     if(avarage == 618 )      // If 9th Keycode was recived       
    {
        PORTC = number[10];
        _delay_ms(500);
    }

     if(avarage == 592)            // If 0th Keycode was recived 
    {
        PORTC = number[1];
        _delay_ms(500);
    }
 }
} 