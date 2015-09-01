#include "pRNG.h"
pRNG prng; //new istance of the class pRNG
int randomNumber;
int ch,a1,a2,cal;

//setup
void setup() {
    Serial.begin(9600); //let's open the serial
    delay(2000);
}

//main loop
void loop() 
{
  for(int i=0;i<5;i++)
  {
    a1=analogRead(A1);
    randomNumber=prng.getRndByte(); //print a byte random number
    analogWrite(3,randomNumber );
    analogWrite(5,(randomNumber/8));
    delay(120);
    //analogWrite(6,19); 
    a2=analogRead(A1);
    ch=1;
   Serial.println(a2-a1);
   cal=cal+(a2-a1);
  }
   a1=analogRead(A1);
    randomNumber=prng.getRndByte(); //print a byte random number
       analogWrite(3,randomNumber );
       analogWrite(5,(randomNumber/8));
        delay(120);
    //analogWrite(6,19); 
        a2=analogRead(A1);
    ch=1;
    cal=cal/5;
   Serial.println("cal");
   Serial.println(cal);
    
  
    if((a2-a1)-cal>1)
    {
        while(ch==1)
        {
          analogWrite(3,0);
          analogWrite(5,0);
          
        }
    } 
    
}
