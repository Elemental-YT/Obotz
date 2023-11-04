#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define setbit(x,y) (x|= y)
#define clearbit(x,y) (x&= ~y)
#define bitn(p) (0x01 << (p))
int count = 0;
int right_fore,right_hind,left_fore,left_hind,count_angle,count_angle1,count_angle2,count_angle3;
int main(void)
{
  DDRD = 0xFF;
  TCNT1 = 0x00;
  OCR1A = 21;
  TCCR1A = 0x00;
  TCCR1B = 0x0A;
  TIMSK1 = 0x02;
  SREG = 0x80;
  HP();
  CT();
  while(1)
  {
   for (int i = 1; i<= 20; i++)
   {
     right_fore++;
     left_hind--;
     CT();
   }

  for (int i = 1; i<= 10; i++)
   {
     right_fore--;
     left_hind++;
     CT();
   }
  
  for (int i = 1; i<= 20; i++)
   {
     right_fore++;
     left_hind--;
     CT();
   }

  for (int i = 1; i<= 10; i++)
   {
     right_fore--;
     left_hind++;
     CT();
   }

  for (int i = 1; i<= 20; i++)
   {
     right_fore++;
     left_hind--;
     CT();
   }

  for (int i = 1; i<= 10; i++)
   {
     right_fore--;
     left_hind++;
     CT();
   }

   for (int i = 1; i<= 20; i++)
   {
     right_fore++;
     left_hind--;
     CT();
   }

  for (int i = 1; i<= 10; i++)
   {
     right_fore--;
     left_hind++;
     CT();
   }
  }
    
  }





void HP()
{
  right_fore = 90;
  right_hind = 90;
  
  left_fore = 90;
  left_hind = 90;
  
  
}



void CT()
{
  count_angle = right_fore + 46;
  count_angle1 = right_hind + 46;
  count_angle2 = left_fore + 46;
  count_angle3 = left_hind + 46;
  
  
}



ISR(TIMER1_COMPA_vect)
{
  count++;
  if(count <= count_angle) 
  {
    setbit(PORTD, bitn(4));
  } 

  if ((count > count_angle) && (count < 1818)) {
    clearbit(PORTD, bitn(4));
  }  

  if(count > 1818)
  {
  count = 0;
  }
  
  if(count <= count_angle1) 
  {
    setbit(PORTD, bitn(5));
  } 

  if ((count > count_angle1) && (count < 1818)) {
    clearbit(PORTD, bitn(5));
  }
  
  if(count <= count_angle2) 
  {
    setbit(PORTD, bitn(6));
  } 

  if ((count > count_angle2) && (count < 1818)) {
    clearbit(PORTD, bitn(6));  
  }
  
  if(count <= count_angle3) 
  {
    setbit(PORTD, bitn(7));
  } 

  if ((count > count_angle3) && (count < 1818)) {
    clearbit(PORTD, bitn(7));  
  }
  
  


}