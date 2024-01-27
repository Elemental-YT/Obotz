#include<avr/io.h>
#include<util/delay.h>
#include<LCD.h>
#define checkbit(x,y) ((x) & (y))
#define bitn(p) (0x01 << (p))
#define B1 0x1FE50AF
#define B2 0x1FED827
#define B3 0x1FEF807
#define B4 0x1FE30CF
#define B5 0x1FEB04F
#define B6 0x1FE708F
#define B7 0x1FE00FF
#define B8 0x1FEF00F
#define B9 0x1FE9867
#define power 0x1FE48B7
long buttonsave = 0;
int on_time = 0;
int off_time = 0;
int bit_position = -2;
long keycode = 0;
int main(void)
{
  DDRB = 0xFB;
  Serial.begin(2000000);
  while(1)
  {
    IRCP()
    while(!(checkbit(PINB,bitn(2))))
    {
      on_time++;
      if (on_time == 1)
      {
        bit_position++;
        if(bit_position>= 1 && bit_position<= 32)
        {
          if(off_time > 700 )
          {
            keycode |= (long)1<<(32 - bit_position);
          }
        }
        if(bit_position>=32)
        {
          CP();
          Serial.println(keycode,HEX);
          bit_position = -2;
          keycode = 0;
        }
      }
    
    off_time = 0;   
    }
  while((checkbit(PINB,bitn(2))))
  {
   off_time++;
   on_time = 0;
   if (off_time > 6000)
   {
    off_time = 0;
    bit_position = -2;
   }
}
}
}

void CP()
{
  LCD lcd;
  lcd.init();

  if (keycode = B1)
  {
    lcd.string("Volume = 1");
    buttonsave = keycode;
  }

  if (keycode = B2)
  {
    lcd.string("B2 was pressed");
    buttonsave = keycode;
  }

  if (keycode = B3)
  {
    lcd.string("B3 was pressed");
    buttonsave = keycode;
  }

  if (keycode = B4)
  {
    lcd.string("B4 was pressed");
    buttonsave = keycode;
  }

  if (keycode = B5)
  {
    lcd.string("B5 was pressed");
    buttonsave = keycode;
  }

  if (keycode = B6)
  {
    lcd.string("B6 was pressed");
    buttonsave = keycode;
  }

  if (keycode = B7)
  {
    lcd.string("B7 was pressed");
    buttonsave = keycode;
  }

  if (keycode = B8)
  {
    lcd.string("B8 was pressed");
    buttonsave = keycode;
  }

  if (keycode = B9)
  {
    lcd.string("B9 was pressed");
    buttonsave = keycode;
  }

  if (keycode = power)
  {
    lcd.string("BP was pressed");
    buttonsave = keycode;
  }


}

void IRCP()
{
  LCD lcd;
  lcd.init();

  if (keycobuttonsavede = B1)
  {
    lcd.string("Alert!");
    
  }

  if (buttonsave = B2)
  {
    lcd.string("Alert!");
    
  }

  if (buttonsave = B3)
  {
    lcd.string("Alert!");
   
  }

  if (buttonsave = B4)
  {
    lcd.string("Alert!");
   
  }

  if (buttonsave = B5)
  {
    lcd.string("Alert!");

  }

  if (keycode = B6)
  {
    lcd.string("Alert!");

  }

  if (buttonsave = B7)
  {
    lcd.string("Alert!");

  }

  if (buttonsave = B8)
  {
    lcd.string("Alert!");
   
  }

  if (buttonsave = B9)
  {
    lcd.string("B9 was pressed");
    
  }
+
  if (buttonsave = power)
  {
  }
}