int sw=A2;
int i,n=0,swState,x,lastState;
int r_led=3,g_led=5;
void setup()
{
  pinMode(r_led,OUTPUT);
  pinMode(g_led,OUTPUT);
  pinMode(sw,INPUT);
  Serial.begin(9600);
}
void loop()
{
  x=millis();
  for(i=x;i<=x+2000;i++)
  {
    digitalWrite(g_led,HIGH);
    swState=digitalRead(sw);
    delay(5);
    if(swState==LOW && lastState==HIGH)
    {
      n++;
    }
    
    Serial.println(i);
    lastState=swState;
  }
  digitalWrite(g_led,LOW);
  for(int t=0;t<=n;t++)
  {
    digitalWrite(r_led,HIGH);
      delay(1000);
      digitalWrite(r_led,LOW);
      delay(1000);
  }
}
