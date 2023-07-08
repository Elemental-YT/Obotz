#include<avr/io.h>                              
#include<util/delay.h> 
#include<LCD.h>                     
#define setbit(x,y)(x|=y)
#define clearbit(x,y)(x&=~y)
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int i=0;
long result;
long avarage;
int num;
int num1,num2,num3,num4;
int Function;
int Answer;
int Press;
int c1;
int c2;
int main(void)
{
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  lcd.init()
  LCD.lcd;
  lcd.cmd(0x00);      
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

    if((avarage < 1000) && avarage > 995)                         // If # Keycode was recived 
    {
        Press++;
        _delay_ms(500);
    } 
       
    if(Press == 1)
    {
      NuM();
     num1 = num * 10; 
    }

    if(Press== 2)
    {
      NuM();
      num2 = num;
    } 

    if(Press == 3)
    {
      FuN();                
    }  

    if(Press == 4)  
     {
        NuM();
        num3 = num * 10;        
     }

    if(Press == 5)
    {
      NuM();
      num4 = num;            
    }

     if (Press == 6) {
     num1 + num2 = c1;
     num3 + num4 = c2;
     if(Function == 1)
     {     
     lcd.string(c1 '+' c2 '=' c1 + c2);  
     }

     if(Function == 2)
     {     
     lcd.string(c1 '-' c2 '=' c1 - c2);  
     }

     if(Function == 3)
     {     
     lcd.string(c1 '*' c2 '=' c1 * c2);  
     }    

     if(Function == 4)
     {     
     lcd.string(c1 '/' c2 '=' c1 / c2);  
     }
    }

    if((avarage < 415) && avarage > 405)                         // If * Keycode was recived 
    {
        
        num = 0;
        num1 = 0;
        num2 = 0;
        num3 = 0;
        num4 = 0;
        c1 = 0;
        c2 = 0;
        Function = 0
        lcd.string("CLEARED QUESTION");   
        _delay_ms(500);
        lcd.cmd(0x00);                     
    }
     
  }
}


void FuN()
{
    if((avarage < 1026) && avarage > 1006)                         // If 1th Keycode was recived 
    {  
        Function == 1;
      _delay_ms(500);
    } 
    
         
    if((avarage < 897) && avarage > 917)                         // If 1th Keycode was recived 
    {  
        Function == 2;
      _delay_ms(500);
    }
    if((avarage < 865) && avarage > 845)                         // If 1th Keycode was recived 
    {  
        Function == 3;
      _delay_ms(500);
    }
    if((avarage < 827) && avarage > 807)                         // If 1th Keycode was recived 
    {  
        Function == 4;
      _delay_ms(500);
    }
}


void NuM()
{
    if((avarage < 460) && avarage > 450)                         // If 1th Keycode was recived 
    {
        
        _delay_ms(500);
        num == 1;
    }
        
    if((avarage < 695) && avarage > 685)                            // If 2th Keycode was recived 
    {
        
        _delay_ms(500);
        num == 2;
    } 

     if((avarage < 701) && avarage > 696)               // If 3th Keycode was recived 
    {
         = number[3];
        _delay_ms(500);
        num == 3;
    }    

     if((avarage < 440) && avarage > 430)                 // If 4th Keycode was recived 
    {

        _delay_ms(500);
        num == 4;
    }

     if((avarage < 643) && avarage > 633)               // If 5th Keycode was recived 
    {
        
        _delay_ms(500);
        num == 5;
    }

     if((avarage < 649) && avarage > 639)                 // If 6th Keycode was recived 
    {
        
        _delay_ms(500);
        num == 6;
    }

     if((avarage < 423) && avarage > 413)                    // If 7th Keycode was recived 
    {
       
        _delay_ms(500);
        num == 7;
    }

     if((avarage < 617) && avarage > 607)   // If 8th Keycode was recived 
    {
        
        _delay_ms(500);
       num == 8;
    }

     if((avarage < 623) && avarage > 613)      // If 9th Keycode was recived       
    {
        
        _delay_ms(500);
        num == 9;
    }

     if((avarage < 597) && avarage > 587)            // If 0th Keycode was recived 
    {
        
        _delay_ms(500);
        num == 0;
    }
}


