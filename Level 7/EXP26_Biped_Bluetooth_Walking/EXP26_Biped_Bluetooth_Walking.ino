#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define setbit(x,y) (x|= y)
#define clearbit(x,y) (x&= ~y)
#define bitn(p) (0x01 << (p))

char data;
int a = 1;
int count = 0;
int right_hip,right_foot,right_hand,left_hip,left_foot,left_hand,neck,count_angle,count_angle1,count_angle2,count_angle3,count_angle4,count_angle5,count_angle6;
int main(void)
{
  DDRD = 0xFC;
  DDRB = 0xFF;
  UCSR0A = 0x00;
  UCSR0B = 0x10;
  UCSR0C = 0x06;
  UBRR0H = 0x00;
  UBRR0L = (16000000UL / (16UL * 9600)) - 1;
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
   while (!(UCSR0A & (1 << RXC0)));
   data = UDR0;
   if (data == '1')
   {
     FWD();
   } 

   if (data == '2')
   {
     BWD();
   } 

   if (data == '3')
   {
     LFT();
   } 

   if (data == '4')
   {
     RGT();
   } 

   if (data == '5')
   {
     SLDLEFT();
   } 

  if (data == '6')
  {
    SLDRGT();
  }

   if (data == '0')
   {
     HP();
     CT();
   } 
   

    
  }
}

void EX1()
{
  right_hand = 140;
  left_hand = 40;
  CT();
  _delay_ms(100)
  right_hand = 40;
  left_hand = 140;
  CT();
  _delay_ms(100);
}

void BWD()
{
  for(right_foot = 90; right_foot <= 130; right_foot++)
    {
      CT();
    }
    for(left_foot = 90; left_foot <= 100; left_foot++)
    {
      CT();
    }
    for(int c = 1; c <= 20; c++)
    { 
      left_hip--;
      right_hip--;
      left_hand--;
      right_hand--;
      CT();
    }
    
    for(left_foot = 100; left_foot <= 90; left_foot--)
    {
      CT();
    }

    for(right_foot = 130; right_foot <= 90; right_foot--)
    {
      CT();
    }
     for(int c = 1; c <= 20; c++)
    { 
      left_hip++;
      right_hip++;
      left_hand++;
      right_hand++;
      CT();
    }
    for(left_foot = 90; left_foot <= 50; left_foot--)
    {
      CT();
    }
    for(right_foot = 90; right_foot <= 80; right_foot--)
    {
      CT();
    }

    for(int c = 1; c <= 20; c++)
    { 
      left_hip++;
      right_hip++;
      left_hand++;
      right_hand++;
      CT();
    }

    HP();
}

void LFT()
{
      for(right_foot = 90; right_foot <= 130; right_foot++)
    {
      CT();
    }
    for(left_foot = 90; left_foot <= 100; left_foot++)
    {
      CT();
    }
    for(int c = 1; c <= 30; c++)
    { 
      left_hip++;
      right_hip++;
      left_hand--;
      right_hand--;
      CT();
    }
    
   

    HP();
}

void RGT()
{
   for(right_foot = 90; right_foot <= 50; right_foot--)
    {
      CT();
    }
    for(left_foot = 90; left_foot <= 80; left_foot--)
    {
      CT();
    }
    for(int c = 1; c <= 30; c++)
    { 
      left_hip--;
      right_hip--;
      left_hand++;
      right_hand++;
      CT();
    }
    
   

    HP();
}


void SLDLEFT()
{
   for(right_foot = 90; right_foot <= 50; right_foot--)
    {
      CT();
    }
    for(left_foot = 90; left_foot <= 80; left_foot--)
    {
      CT();
    }
    for(int c = 1; c <= 30; c++)
    { 
      left_hip--;
      right_hip--;
      left_hand++;
      right_hand++;
      CT();
    }
    HP();
}

void SLDRGT()
{
  for(right_foot = 90; right_foot <= 110; right_foot++)
    {
      CT();
    }
    for(left_foot = 90; left_foot <= 50; left_foot--)
    {
      CT();
    }
    for(right_foot = 110; right_foot <= 90; right_foot--)
    {
      CT();
    }
    for(left_foot = 50; left_foot <= 90; left_foot++)
    {
      CT();
    }
}

void HP()
{
  right_hip = 90;
  right_foot = 90;
  right_hand = 40;
  left_hip = 90;
  left_foot = 90;
  left_hand = 140;
  neck = 90;
}



void CT()
{
  count_angle = right_hip + 46;
  count_angle1 = right_foot + 46;
  count_angle2 = right_hand + 46;
  count_angle3 = left_hip + 46;
  count_angle4 = left_foot + 46;
  count_angle5 = left_hand + 46;
  count_angle6 = neck + 46;
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
  
  if(count <= count_angle4) 
  {
    setbit(PORTD, bitn(3));
  } 

  if ((count > count_angle4) && (count < 1818)) {
    clearbit(PORTD, bitn(3));
  }  
  
  if(count <= count_angle5) 
  {
    setbit(PORTD, bitn(2));
  } 

  if ((count > count_angle5) && (count < 1818)) {
    clearbit(PORTD, bitn(2));
  }

  if(count <= count_angle6) 
  {
    setbit(PORTD, bitn(0));
  } 

  if ((count > count_angle6) && (count < 1818)) {
    clearbit(PORTD, bitn(0));
  }
}




