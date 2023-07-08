#include<avr/io.h>                              
#include<util/delay.h>                      
#define setbit(x,y)(x|=y)
#define clearbit(x,y)(x&=~y)
#define checkbit(x,y)((x)&(y))
#define bitn(p)(0x01<<(p))
int d = 0;
int count = 0;
int count_angle1,count_angle2;
int main(void)
{

    DDRB = 0b00111111;
    DDRD = 0xFF;  
    OCR1A = 21;
    TCCR1A = 0x00;
    TCCR1B = 0x0A;
    TIMSK1 = 0x02;
    SREG = 0x80;
    while(1)
    {
      if(checkbit(PINB, bitn(PB0)))
      {
        d++;
        stepper();
        
      }

      if(checkbit(PINB, bitn(PB1)))
      {
        d = d - 1 ;
        stepper();
       
      }    
      PORT = 0b00100000;
      PORT = 0b01000000;      
      PORT = 0b10000000;
      PORT = 0b10010000;
      PORT = 0b11000000;
      PORT = 0b01010000;
      PORT = 0b01100000;
      PORT = 0b00110000;
      PORT = 0b10100000;

      
      angle1(60);
      angle2(60);
      angle1(180);
      angle2(180);                    
    }
}

void angle1(int a)
{
  count_angle1 = a + 46;            
}
void angle2(int b)
{
  count_angle2 = b + 46;            
}


ISR(TIMER1_COMPA_vect)                                                                                                                                                                                                                  // When Tact Switch 1 is pressed, the Tree should rotate clockwise on the stepper motor ( Latch Control ) 
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

    if(count <= count_angle2)
    {
      setbit(PORTB, bitn(6));  
    }

    else if ((count <= count_angle2) && (count < 1818)) 
    {
      clearbit(PORTB, bitn(6));  
    }

    else if (count < 1818) 
    {
    count = 0;
    }

}           

void stepper()
{
  if (d == 0)
  {
    d = 4;
  }

  if (d == 1)
  {
    PORTD = 0b01110000;     
  }   

  if (d == 2)
  {
    PORTD = 0b10110000;     
  } 

  if (d == 3)
  {
    PORTD = 0b11010000;     
  }   

  if (d == 4)
  {
    PORTD = 0b11100000;     
  }
  
  if (d == 5)
  {
    d = 1
  }       
}                                                                                                                                                                                                                             // When Tact Switch 2 is pressed, the tree should rotate counter clockwise on the stepper motor ( Latch Control )
// Set up the LEDs to blink in a random pattern to act as Christmas lights                                                                                                                                                    and find a way to implement 2 servo motors
