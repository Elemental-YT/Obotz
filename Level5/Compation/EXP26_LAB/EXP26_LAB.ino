#include<avr/io.h>
#include<util/delay.h>
#define checkbit(x,y) ((x) &(y))
#define bitn(p) (0x01 << (p))
#define Power  0x1FE48B7
#define Mute   0x1FE7887
#include <LCD.h>
int main(void)
{
  LCD lcd;                                    // Creating an object of class LCD
  lcd.init();                                 // Initializig the LCD
  int LED;                                    // Variable for LED 
  int BUZZ;                                   // Variable for Buzzer
  int power;                                  // Variable for power           
  DDRD = 0xFF;                                // Int Output as port D
  DDRB = 0xFF;      
  Serial.begin(2000000);                      // Initialize serial communication at baud rate of 2000000 bps 
  while(1)                                    // Start the Forever Loop
{
    ADMUX = 0x40;                             // Set A0 As the ADC conversion pin
    ADCSRA = 0xC7;                            // Start the ADC conversion
    while(checkbit(ADCSRA, bitn(ADSC)));      // Wait until the ADC conversion is done
    Serial.println(ADCW);                     // Print the output onto the Serial Moniter
    LED = ADCW;                               // Save the output into the Variable LED
    _delay_ms(500);                           // Wait for 500 miliseconds
    ADMUX = 0x41;                             // Set A1 As the ADC conversion pin
    ADCSRA = 0xC7;                            // Start the ADC conversion
    while(checkbit(ADCSRA, bitn(ADSC)));      // Wait until the ADC conversion is done
    Serial.println(ADCW);                     // Print the output onto the Serial Moniter
    BUZZ = ADCW;                              // Save the output into the Variable BUZZ
    if((BUZZ <  350) && (LED >  350))                             // If LED is greater than 350
    {
      lcd.string("Alert! ");                  // Print on the LCD Alert!
      PORTD = 0b00100000;                     // Set PD5 as High and everything else Low
    }
    
    if((BUZZ >  350) && (LED <  350))                           // If BUZZ is greater than 350
    {
      lcd.string("Alert! ");                  // Print on the LCD Alert!
      PORTD = 0b01000000;                     // Set PD6 as High and everything else Low
    }
    
    if((LED > 350) && (BUZZ > 350))           // If LED & BUZZ are greater than 350 
    {
      PORTD = 0b00000000;   
      lcd.cmd(0x01);                          // Turn Everything off
    }
    }
    if(PIND & 0x04 )                          // If Button 1 is Pressed 
    {
      lcd.cmd(0x01);                          // Clear LCD screen
    }
}   
