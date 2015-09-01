#include <LiquidCrystal.h>
#include <Wire.h>
#include <Rtc_Pcf8563.h>
Rtc_Pcf8563 rtc;
LiquidCrystal lcd(9, 10, 13, 12, 4, 7);
int sw=A2;
int mode;
int hrs=0,mins=0,dt=0,mn=0,yr=0;
  int month();
  int hours();
  int minutes();
  int date();
  int year();
void setup() 
{
  Serial.begin(9600);
//  rtc.initClock();
  lcd.begin(16, 2);
  mode=1;
}
  int hours()
     { 
       delay(1500);
        while(analogRead(sw)>790||analogRead(sw)<730)
        {
        while(analogRead(sw)>790&&analogRead(sw)<900&&hrs!=24)              
         {
           hrs++;
           lcd.clear();
           lcd.print(hrs);
           delay(200);
         }
         while(analogRead(sw)>650&&analogRead(sw)<700 && hrs!=0)
        {
           hrs--;
           lcd.clear();
           lcd.print(hrs);
           delay(200);
        }
       }
        
       return hrs;
     }
     int minutes()
     {  
         delay(1500);
         while(analogRead(sw)>790||analogRead(sw)<730)
         {
           while(analogRead(sw)>790 && analogRead(sw)<900&& mins!=60)               
           {
              mins++;
              lcd.clear();
              lcd.print(mins);
              delay(200);
           }
          while(analogRead(sw)>650&&analogRead(sw)<700 && mins!=0)
           {
              mins--;
              lcd.clear();
              lcd.print(mins);
              delay(200);
           }
         }
         return mins;
      } 
     int date()
      {
        delay(1500);
        while(analogRead(sw)>790 || analogRead(sw)<730)
        {
          while(analogRead(sw)>790 && analogRead(sw)<900 && dt!=31)               
           {
              dt++;
              lcd.clear();
              lcd.print(dt);
             delay(200);
           }
           while((analogRead(sw)>650&&analogRead(sw)<700) && dt!=0)
           {
              dt--;
              lcd.clear();
              lcd.print(dt);
              delay(200);
           }
        }
        return dt;
     }
     
     
     int month()
     {
       delay(1500);
         while(analogRead(sw)>790||analogRead(sw)<730)
         {
            while((analogRead(sw)>790&&analogRead(sw)<900)&&mn!=12)
            {
              mn++;
              lcd.clear();
              lcd.print(mn);
              delay(200);
            }
            while((analogRead(sw)>650&&analogRead(sw)<700)&&mn!=0)
           {
             mn--;
             lcd.clear();
             lcd.print(mn);
             delay(200);
           }
        }
        return mn;
     }
     
     
     int year()
      {
        delay(1500);
         while(analogRead(sw)>790||analogRead(sw)<730)
         {
            while((analogRead(sw)>790&&analogRead(sw)<900))
            {
              yr++;
              lcd.clear();
              lcd.print(yr);
             delay(200);
            }
            while((analogRead(sw)>650&&analogRead(sw)<700)&&yr!=0)
            {
              yr--;
              lcd.clear();
              lcd.print(yr);
             delay(200);
            }
         }
         return yr ;
      }  

void loop()
{
  
  switch (mode)
  {
    case 1:
    while(analogRead(sw)>790 || analogRead(sw)<730)
    { 
       lcd.clear();
       lcd.setCursor(0, 0);
       lcd.print(rtc.formatTime());
       lcd.setCursor(0, 1);
       lcd.print(rtc.formatDate());
       delay(1000);
       
    }
     delay(50);
     mode=2;
     //hrs1=0;
     
    case 2: 
     lcd.clear();
     lcd.print("change hours");
     delay(500);
     if(analogRead(sw)>800&&analogRead(sw)<830)
     {
     delay(50);
     hrs= hours();
     lcd.clear();
     lcd.print("hours=");
     lcd.print(hrs);
     delay(2000);  
     }
     if(analogRead(sw)>480 && analogRead(sw)<530)
     {
        mode=3;
     }
     break;
     case 3:
     lcd.clear();
     lcd.print("change minutes");
     delay(500);
     if(analogRead(sw)>730&&analogRead(sw)<790)
      {
        mins= minutes();
        lcd.clear();
        lcd.print("minutes=");
        lcd.print(mins);
        delay(2000);
      }
     if(analogRead(sw)>480&&analogRead(sw)<530)
     {
       mode=4;

     }
     if(analogRead(sw)>840&&analogRead(sw)<880)
     {
       mode=2;
     }
     break;
     
     case 4:
     lcd.clear();
     lcd.print("change date");
     delay(500);
     if(analogRead(sw)>730&&analogRead(sw)<790)
     {
     dt= date();
     lcd.clear();
     lcd.print("Date=");
     lcd.print(dt);
     delay(2000);
     }
     if(analogRead(sw)>480&&analogRead(sw)<530)
     {
       mode=5;
     }
     if(analogRead(sw)>820&&analogRead(sw)<880)
     {
       mode=3;
     }
     break;
     case 5:
     lcd.clear();
     lcd.print("change month");
     delay(500);
     lcd.clear();
     if(analogRead(sw)>730&&analogRead(sw)<790)
     {
       mn= month();
       lcd.clear();
       lcd.print("month=");
       lcd.print(mn);
       delay(2000);
     }
     if(analogRead(sw)>480&&analogRead(sw)<530)
     {
       mode=6;
     }
     if(analogRead(sw)>820&&analogRead(sw)<880)
     {
       mode=4;
     }
     break;
     case 6:
     lcd.clear();
     lcd.print("change year");
     delay(500);
     if(analogRead(sw)>730&&analogRead(sw)<790)
     {
       yr=year();
       lcd.clear();
       lcd.print("years=");
       lcd.print(yr);
       delay(2000);
     }
    if(analogRead(sw)>480&&analogRead(sw)<530)
     {
         mode=7;
     }
    if(analogRead(sw)>820&&analogRead(sw)<880)
     {
         mode=5;
     }
     break;
 
     
     case 7:
     lcd.clear();
     lcd.print("all set!!!");
     delay(500);
     if(analogRead(sw)>730&&analogRead(sw)<790)
     {
              
           rtc.setDate(dt, 6, mn, 0, yr);
           rtc.setTime(hrs, mins, 0);
           lcd.clear();
           lcd.print("wait");
           delay(2000);
           mode=1;
     }
     if(analogRead(sw)>820&&analogRead(sw)<880)
     {
         mode=6;
     }
     break;
     

  }
}
   
     
     

     
     
    
