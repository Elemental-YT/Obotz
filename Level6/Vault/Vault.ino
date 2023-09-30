    // Passcode is 1056               
#include<avr/io.h>                              
#include<util/delay.h>                      
#define setbit(x,y)(x|=y)
#define clearbit(x,y)(x&=~y)
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int number[] = {0b11110110, 0b01100000, 0b11010101, 0b11110001, 0b0110001, 0b10110011, 0b10110111, 0b11100000, 0b11110111, 0b11110011};
int i=0;
long result;
long avarage;
int pas1,pas2,pas3,pas4;
int Errors;
int count = 0;
int count_angle1;
int press;
int main (void)
{
  DDRD = 0xFF;
  DDRB = 0xFF;
  DDRC = 0xFF;
  OCR1A = 21;
    TCCR1A = 0x00;
    TCCR1B = 0x0A;
    TIMSK1 = 0x02;
    SREG = 0x80;    
 while(1)
  {
    ADMUX = 0x44;
    ADCSRA = 0xC7;
    while (checkbit(ADCSRA, bitn(ADSC)));
    result = result+ADCW;
    i++;

        
    if(i>99)
    {
      average = result/100;
      result = 0;
      i = 0;
    }
    
    If((avarage < 1021) && avarage > 1011)
    {
      press++; 
      _delay_ms(500);     
    }    

    if(press == 0)
    {
      PORTD == 11000000;
    }  

    if(press == 1)
    {
      PORTD == 0x00;
      comparea();
    }  

    if(press == 2)
    {
      compareaa();
    }

    if(press == 3)
    {
      compareaaa();
    }

    if(press == 4)
    {
      compareaaaa();
    }

    if(press == 5)
    {
      press == 0;
    }

    if (avarage == 410) {                // IF * WAS PRESSED
   
    If((pas1 !== 1) && pas2 !== 0 && pas3 !== 5 && pas4 !== 6) 
    {
      Errors = Errors + 1;      
    }
    
    If(Errors == 1)
    {
      PORTD = 01000000;                 //GREEN LED IS  ON
      Passcode = 0;      
    }
    If(Errors == 2)
    {
      PORTD = 01100000;               //  GREEN & BLUE LED 
      Passcode = 0;      
    }
    If(Errors == 3)
    {
      PORTD = 01110000;               // GREEN & BLUE & YELLOW LED IS ON
      Passcode = 0;      
    }
    If(Errors == 4)
    {
      PORTD = 11110000;               // GREEN & BLUE & YELLOW & RED LED IS ON
      Passcode = 0;      
    }
    

    If(Errors == 5)                  // GREEN & BLUE & YELLOW & RED & BUZZER ARE TURNING OFF AND ON
    {
      PORTC = 00010000;               
      PORTD = 11110000;
      _delay_ms(500);
      PORTC = 00000000;
      PORTD = 00000000;      
      if(avarage == 817)           // If D is Pressed
      {
        Passcode = 0;
        Errors = 0;        
        PORTC = 00000000;           
        PORTD = 00000000;     
      }      
    }




   if((pas1 == 1) && pas2 == 0 && pas3 == 5 && pas4 == 6)   
   {
     angle1(180)
     if(avarage == 817)
      {
        Passcode = 0;
        Errors = 0;        
        PORTC = 00000000;                
      }
   }
 }
}
}

void angle1(int a)
{
  count_angle1 = a + 46;            
}


ISR(TIMER1_COMPA_vect)                                                                                                                                                                                                                   
{
  count++;  
    
    if(count <= count_angle1)
    {
      setbit(PORTB, bitn(5));  
    }

    else if ((count <= count_angle1) && (count < 1818)) 
    {
      clearbit(PORTB, bitn(5));  
    }

    else if (count < 1818) 
    {
    count = 0;
    }


} 

void comparea()
{
  if((avarage < 460) && avarage > 450)                         // If 1th Keycode was recived 
    {
        PORTC = number[2];
        _delay_ms(500);
        pas1 == 1;
    }
        
    if((avarage < 695) && avarage > 685)                            // If 2th Keycode was recived 
    {
        PORTC = number[3];
        _delay_ms(500);
        pas1 == 2;
    } 

     if((avarage < 701) && avarage > 696)               // If 3th Keycode was recived 
    {
        PORTC = number[4];
        _delay_ms(500);
        pas1 == 3;
    }    

     if((avarage < 440) && avarage > 430)                 // If 4th Keycode was recived 
    {
        PORTC = number[5];
        _delay_ms(500);
        pas1 == 4;
    }

     if((avarage < 643) && avarage > 633)               // If 5th Keycode was recived 
    {
        PORTC = number[6];
        _delay_ms(500);
        pas1 == 5;
    }

     if((avarage < 649) && avarage > 639)                 // If 6th Keycode was recived 
    {
        PORTC = number[7];
        _delay_ms(500);
        pas1 == 6;
    }

     if((avarage < 423) && avarage > 413)                    // If 7th Keycode was recived 
    {
        PORTC = number[8];
        _delay_ms(500);
        pas1 == 7;
    }

     if((avarage < 617) && avarage > 607)   // If 8th Keycode was recived 
    {
        PORTC = number[9];
        _delay_ms(500);
       pas1 == 8;
    }

     if((avarage < 623) && avarage > 613)      // If 9th Keycode was recived       
    {
        PORTC = number[10];
        _delay_ms(500);
        pas1 == 9;
    }

     if((avarage < 597) && avarage > 587)            // If 0th Keycode was recived 
    {
        PORTC = number[1];
        _delay_ms(500);
        pas1 == 0;
    }
}








void compareaa()
{
  if((avarage < 460) && avarage > 450)                         // If 1th Keycode was recived 
    {
        PORTC = number[2];
        _delay_ms(500);
        pas2 == 1;
    }
        
    if((avarage < 695) && avarage > 685)                            // If 2th Keycode was recived 
    {
        PORTC = number[3];
        _delay_ms(500);
        pas2 == 2;
    } 

     if((avarage < 701) && avarage > 696)               // If 3th Keycode was recived 
    {
        PORTC = number[4];
        _delay_ms(500);
        pas2 == 3;
    }    

     if((avarage < 440) && avarage > 430)                 // If 4th Keycode was recived 
    {
        PORTC = number[5];
        _delay_ms(500);
        pas2 == 4;
    }

     if((avarage < 643) && avarage > 633)               // If 5th Keycode was recived 
    {
        PORTC = number[6];
        _delay_ms(500);
        pas2 == 5;
    }

     if((avarage < 649) && avarage > 639)                 // If 6th Keycode was recived 
    {
        PORTC = number[7];
        _delay_ms(500);
        pas2 == 6;
    }

     if((avarage < 423) && avarage > 413)                    // If 7th Keycode was recived 
    {
        PORTC = number[8];
        _delay_ms(500);
        pas2 == 7;
    }

     if((avarage < 617) && avarage > 607)   // If 8th Keycode was recived 
    {
        PORTC = number[9];
        _delay_ms(500);
       pas2 == 8;
    }

     if((avarage < 623) && avarage > 613)      // If 9th Keycode was recived       
    {
        PORTC = number[10];
        _delay_ms(500);
        pas1 == 9;
    }

     if((avarage < 597) && avarage > 587)            // If 0th Keycode was recived 
    {
        PORTC = number[1];
        _delay_ms(500);
        pas2 == 0;
    }
}







void compareaaa()
{
  if((avarage < 460) && avarage > 450)                         // If 1th Keycode was recived 
    {
        PORTC = number[2];
        _delay_ms(500);
        pas3 == 1;
    }
        
    if((avarage < 695) && avarage > 685)                            // If 2th Keycode was recived 
    {
        PORTC = number[3];
        _delay_ms(500);
        pas3 == 2;
    } 

     if((avarage < 701) && avarage > 696)               // If 3th Keycode was recived 
    {
        PORTC = number[4];
        _delay_ms(500);
        pas3 == 3;
    }    

     if((avarage < 440) && avarage > 430)                 // If 4th Keycode was recived 
    {
        PORTC = number[5];
        _delay_ms(500);
        pas3 == 4;
    }

     if((avarage < 643) && avarage > 633)               // If 5th Keycode was recived 
    {
        PORTC = number[6];
        _delay_ms(500);
        pas3 == 5;
    }

     if((avarage < 649) && avarage > 639)                 // If 6th Keycode was recived 
    {
        PORTC = number[7];
        _delay_ms(500);
        pas3 == 6;
    }

     if((avarage < 423) && avarage > 413)                    // If 7th Keycode was recived 
    {
        PORTC = number[8];
        _delay_ms(500);
        pas3 == 7;
    }

     if((avarage < 617) && avarage > 607)        // If 8th Keycode was recived 
    {
        PORTC = number[9];
        _delay_ms(500);
       pas3 == 8;
    }

     if((avarage < 623) && avarage > 613)      // If 9th Keycode was recived       
    {
        PORTC = number[10];
        _delay_ms(500);
        pas3 == 9;
    }

     if((avarage < 597) && avarage > 587)           // If 0th Keycode was recived 
    {
        PORTC = number[1];
        _delay_ms(500);
        pas3 == 0;
    }
}







void compareaaaa()
{
  if((avarage < 460) && avarage > 450)                         // If 1th Keycode was recived 
    {
        PORTC = number[2];
        _delay_ms(500);
        pas4 == 1;
    }
        
    if((avarage < 695) && avarage > 685)                            // If 2th Keycode was recived 
    {
        PORTC = number[3];
        _delay_ms(500);
        pas4 == 2;
    } 

     if((avarage < 701) && avarage > 696)               // If 3th Keycode was recived 
    {
        PORTC = number[4];
        _delay_ms(500);
        pas4 == 3;
    }    

     if((avarage < 440) && avarage > 430)                 // If 4th Keycode was recived 
    {
        PORTC = number[5];
        _delay_ms(500);
        pas4 == 4;
    }

     if((avarage < 643) && avarage > 633)               // If 5th Keycode was recived 
    {
        PORTC = number[6];
        _delay_ms(500);
        pas4 == 5;
    }

     if((avarage < 649) && avarage > 639)                 // If 6th Keycode was recived 
    {
        PORTC = number[7];
        _delay_ms(500);
        pas4 == 6;
    }

     if(((avarage < 423) && avarage > 413)                    // If 7th Keycode was recived 
    {
        PORTC = number[8];
        _delay_ms(500);
        pas4 == 7;
    }

     if((avarage < 617) && avarage > 607)   // If 8th Keycode was recived 
    {
        PORTC = number[9];
        _delay_ms(500);
       pas4 == 8;
    }

     if((avarage < 623) && avarage > 613)      // If 9th Keycode was recived       
    {
        PORTC = number[10];
        _delay_ms(500);
        pas4 == 9;
    }

     if((avarage < 597) && avarage > 587)            // If 0th Keycode was recived 
    {
        PORTC = number[1];
        _delay_ms(500);
        pas4 == 0;
    }
}