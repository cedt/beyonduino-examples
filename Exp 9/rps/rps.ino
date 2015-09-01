int r_led=3,g_led=5,b_led=6;
int plchoice,comchoice,sw=A2,swValue;
int i=0,j,loopEntered=0,win[2]={0,0};
unsigned int mod,k;
void setup()
{
  pinMode(r_led,OUTPUT);
  pinMode(g_led,OUTPUT);
  pinMode(b_led,OUTPUT);
  pinMode(sw,INPUT);
}
void loop()
{
  loopEntered=0;
  while(digitalRead(sw)==1)
  {}
  while(digitalRead(sw)==0)
  {
    if(loopEntered==0)
    delay(30);
    loopEntered=1;
    if(i==151)
    i=0;
    if(i>=0 && i<=50)
    {
      digitalWrite(r_led,HIGH);
      digitalWrite(g_led,LOW);
      digitalWrite(b_led,LOW);
      delay(10);
    }
    if(i>50 && i<=100)
    {
      digitalWrite(r_led,LOW);
      digitalWrite(g_led,HIGH);
      digitalWrite(b_led,LOW);
      delay(10);
    }
   if(i>100 && i<=150)
    {
      digitalWrite(r_led,LOW);
      digitalWrite(g_led,LOW);
      digitalWrite(b_led,HIGH);
      delay(10);
    } 
i++;  
}
while(digitalRead(sw)==1 && loopEntered==1)
{
  digitalWrite(r_led,LOW);
  digitalWrite(g_led,LOW);
  digitalWrite(b_led,LOW);
  if(i>=0 && i<=50)
  {
    plchoice =1;
    digitalWrite(r_led,HIGH);
    delay(2000);
    digitalWrite(r_led,LOW);
  }
  else if(i>50 && i<=100)
  {
    plchoice=2;
    digitalWrite(g_led,HIGH);
    delay(2000);
    digitalWrite(g_led,LOW);
  }
  else if(i>100 && i<=150)
  {
    plchoice=3;
    digitalWrite(b_led,HIGH);
    delay(2000);
    digitalWrite(b_led,LOW);
  }
  break;
} 
win[0]=plchoice;
delay(500);
for(j=0;j<5;j++)
{
  digitalWrite(r_led,HIGH);
  digitalWrite(g_led,LOW);
  digitalWrite(b_led,LOW);
  delay(100);
  digitalWrite(r_led,LOW);
  digitalWrite(g_led,HIGH);
  digitalWrite(b_led,LOW);
  delay(100);
  digitalWrite(r_led,LOW);
  digitalWrite(g_led,LOW);
  digitalWrite(b_led,HIGH);
  delay(100);
}
digitalWrite(r_led,LOW);
digitalWrite(g_led,LOW);
digitalWrite(b_led,LOW);
delay(1000);
k=millis();
mod=(k%3)+1;
switch(mod)
{
  case 1:
          comchoice=1;
          digitalWrite(r_led,HIGH);
          delay(2000);
          digitalWrite(r_led,LOW);
          break;
  case 2:
          comchoice=2;
          digitalWrite(g_led,HIGH);
          delay(2000);
          digitalWrite(g_led,LOW);
          break;
  case 3:
          comchoice=3;
          digitalWrite(b_led,HIGH);
          delay(2000);
          digitalWrite(b_led,LOW);
          break;
}
win[1]=comchoice;
delay(500);
for(j=0;j<5;j++)
{
  digitalWrite(r_led,HIGH);
  digitalWrite(g_led,LOW);
  digitalWrite(b_led,LOW);
  delay(100);
  digitalWrite(r_led,LOW);
  digitalWrite(g_led,HIGH);
  digitalWrite(b_led,LOW);
  delay(100);
  digitalWrite(r_led,LOW);
  digitalWrite(g_led,LOW);
  digitalWrite(b_led,HIGH);
  delay(100);
}
digitalWrite(r_led,LOW);
digitalWrite(g_led,LOW);
digitalWrite(b_led,LOW);
delay(1000);
  if(win[0]==win[1])
  {
    for(int n=1;n<=10;n++)
    {
      digitalWrite(r_led,HIGH);
      delay(100);
      digitalWrite(r_led,LOW);
      delay(100);
    }
  }
  digitalWrite(r_led,LOW);
  digitalWrite(g_led,LOW);
  digitalWrite(b_led,LOW);
  if(win[0]==1 && win[1]==3)
{
  for(int n=1;n<=10;n++)
    {
      digitalWrite(b_led,HIGH);
      delay(100);
      digitalWrite(b_led,LOW);
      delay(100);
    }
}
digitalWrite(r_led,LOW);
digitalWrite(g_led,LOW);
digitalWrite(b_led,LOW);
   if(win[0]==1 && win[1]==2)
{
  for(int n=1;n<=10;n++)
    {
      digitalWrite(g_led,HIGH);
      delay(100);
      digitalWrite(g_led,LOW);
      delay(100);
    }
}
  digitalWrite(r_led,LOW);
  digitalWrite(g_led,LOW);
  digitalWrite(b_led,LOW);
   if(win[0]==2 && win[1]==1)
  {
    for(int n=1;n<=10;n++)
    {
      digitalWrite(b_led,HIGH);
      delay(100);
      digitalWrite(b_led,LOW);
      delay(100);
    }
  }
  digitalWrite(r_led,LOW);
  digitalWrite(g_led,LOW);
  digitalWrite(b_led,LOW);
   if(win[0]==2 && win[1]==3)
 {
   for(int n=1;n<=10;n++)
    {
      digitalWrite(g_led,HIGH);
      delay(100);
      digitalWrite(g_led,LOW);
      delay(100);
    }
 }  
  digitalWrite(r_led,LOW);
  digitalWrite(g_led,LOW);
  digitalWrite(b_led,LOW);
   if(win[0]==3 && win[1]==1)
  {
    for(int n=1;n<=10;n++)
    {
      digitalWrite(g_led,HIGH);
      delay(100);
      digitalWrite(g_led,LOW);
      delay(100);
    }
  }
  digitalWrite(r_led,LOW);
  digitalWrite(g_led,LOW);
  digitalWrite(b_led,LOW);
   if(win[0]==3 && win[1]==2)
  {
    for(int n=1;n<=10;n++)
    {
      digitalWrite(b_led,HIGH);
      delay(100);
      digitalWrite(b_led,LOW);
      delay(100);
    }
  }
  digitalWrite(r_led,LOW);
  digitalWrite(g_led,LOW);
  digitalWrite(b_led,LOW);
 
}
