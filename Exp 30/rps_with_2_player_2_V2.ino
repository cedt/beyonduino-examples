#include <LiquidCrystal.h>
LiquidCrystal lcd(9, 10, 13, 12, 4, 7);
int plchoice1,plchoice2,sw=A2,swValue1,swValue2;
int i=0,j,k,loopEntered=0,win[2]={0,0};

void setup()
{  Serial.begin(9600);
  lcd.begin(16, 2);
  pinMode(sw,INPUT);
  lcd.print("ROCK-PAPER-");
  lcd.setCursor(0,1);
  lcd.print("SCISSOR");
  delay(2000);
  lcd.clear();
  lcd.print("Slave");
  delay(2000);
  lcd.clear();
  lcd.print("R-ROCK P-PAPER");
  lcd.setCursor(0,1);
  lcd.print("S-SCISSOR");
  delay(3000);
  lcd.clear();
  lcd.setCursor(0,0);
  loopEntered=0;
}
void loop()
{
  lcd.print("Your choice?");
  while(analogRead(sw)>=950)
  {}
  swValue1=analogRead(sw);
  delay(50);
  while(swValue1<900)
  { 
    if(swValue1>575 && swValue1<=625)
    {
      plchoice1=1;
      break;
    }  
    else if(swValue1>475 && swValue1<=525)
    {
      plchoice1=2;
      break;
    }
     else if(swValue1>300 && swValue1<=400)
    {
      plchoice1=3;
      break;
    }
  }
  
  win[0]=plchoice1;
  Serial.print(swValue1);
  lcd.clear();
  while(!Serial.available())
{
  if(plchoice1==1)
    {
      lcd.setCursor(0,0);
      lcd.print("ROCK Choice");
      lcd.setCursor(0,1);
      lcd.print("Accepted,Wait...");
    }
  if(plchoice1==2)
    {
      lcd.setCursor(0,0);
      lcd.print("PAPER Choice");
      lcd.setCursor(0,1);
      lcd.print("Accepted,Wait...");
    }
  if(plchoice1==3)
    {
      lcd.setCursor(0,0);
      lcd.print("SCISSOR Choice");
      lcd.setCursor(0,1);
      lcd.print("Accepted,Wait...");
    }  
}
  swValue2=Serial.parseInt();
delay(200);
  while(swValue2<900)
  {
      if(swValue2>825 && swValue2<=875)
      {
        plchoice2=1;
        break;
      }  
      else if(swValue2>750 && swValue2<=800)
      {
        plchoice2=2;
        break;
      }
     else if(swValue2>475 && swValue2<=525)
     {
        plchoice2=3;
        break;
     }
  }
  win[1]=plchoice2;
  lcd.clear();
  if((win[0]==1||win[0]==2||win[0]==3)&&(win[1]==1||win[1]==2||win[1]==3))
  {
    if(win[0]==win[1])
    {
      lcd.setCursor(0,0);
      if(win[0]==1)
      {
        lcd.print("Yours-ROCK");
        lcd.setCursor(0,1);
        lcd.print("PL 1-ROCK");
        delay(2000);
      }   
      else if(win[0]==2)
      {
        lcd.print("Yours-PAPER");
        lcd.setCursor(0,1);
        lcd.print("PL 1-PAPER");
        delay(3000);
      }
      else if(win[0]==3)
      {
        lcd.print("Yours-SCISSOR");
        lcd.setCursor(0,1);
        lcd.print("PL 1-SCISSOR");
        delay(3000);
      }
      lcd.clear();
      lcd.print("Same Choice");
      lcd.setCursor(0,1);
      lcd.print("Match Draw");
    }
  else if(win[0]==1 && win[1]==3)
  {
    lcd.setCursor(0,0);
    lcd.print("Yours-ROCK");
    lcd.setCursor(0,1);
    lcd.print("PL 1-SCISSOR");
    delay(2000);
    lcd.clear();
    lcd.print("YOU WIN!!");
  }
  else if(win[0]==1 && win[1]==2)
  {
    lcd.setCursor(0,0);
    lcd.print("Yours-ROCK");
    lcd.setCursor(0,1);
    lcd.print("PL 1-PAPER");
    delay(2000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("YOU LOSE!!");
  }
  
  else if(win[0]==2 && win[1]==1)
  {
    lcd.setCursor(0,0);
    lcd.print("Yours-PAPER");
    lcd.setCursor(0,1);
    lcd.print("PL 1-ROCK");
    delay(2000);
    lcd.clear();
    lcd.print("YOU WIN!!");
  }
  else if(win[0]==2 && win[1]==3)
  {
    lcd.setCursor(0,0);
    lcd.print("Yours-PAPER");
    lcd.setCursor(0,1);
    lcd.print("PL 1-SCISSOR");
    delay(2000);
    lcd.clear();
    lcd.print("YOU LOSE!!");
  }  
  
  else if(win[0]==3 && win[1]==1)
  {
    lcd.setCursor(0,0);
    lcd.print("Yours-SCISSOR");
    lcd.setCursor(0,1);
    lcd.print("PL 1-ROCK");
    delay(2000);
    lcd.clear();
    lcd.print("YOU LOSE!!");
  }
  else if(win[0]==3 && win[1]==2)
  {
    lcd.setCursor(0,0);
    lcd.print("Yours-SCISSOR");
    lcd.setCursor(0,1);
    lcd.print("PL 1-PAPER");
    delay(2000);
    lcd.clear();
    lcd.print("YOU WIN!!");
  }
 delay(2000);
 lcd.clear();

  }
}
