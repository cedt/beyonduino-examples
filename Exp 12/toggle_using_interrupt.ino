#include <TimerOne.h>
 
void setup() 
{
  pinMode(3, OUTPUT);    
  Timer1.initialize(1000000); 
  Timer1.attachInterrupt( timerIsr ); 
}
 
void loop()
{
 
}
void timerIsr()
{
   digitalWrite( 3, digitalRead( 3 ) ^ 1 );
}
