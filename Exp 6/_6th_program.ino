int sw = A2;
int r_led = 3;
int currentValue,lastValue;
boolean t = LOW;
void setup()
{
  pinMode(sw,INPUT);
  pinMode(r_led,OUTPUT);
}
void loop()
{
  currentValue = digitalRead(sw);
  delay(50);
  if(currentValue==LOW && lastValue == HIGH)
  {
    t =!t;
  }
  lastValue=currentValue;
  digitalWrite(r_led,t);
}
