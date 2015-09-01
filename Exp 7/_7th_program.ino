int sw = A2;
int r_led = 3;
int currentValue,lastValue;
int r=200;
void setup()
{
  pinMode(sw,INPUT);
  pinMode(r_led,OUTPUT);
  Serial.begin(9600);
  
}
void loop()
{
  currentValue = digitalRead(sw);
 delay(1);
  Serial.println(currentValue);
  if(currentValue==LOW && lastValue==HIGH)
  {
    r=r-10;
  }
 Serial.println(r);
    digitalWrite(r_led,HIGH);
    delay(r);
    digitalWrite(r_led,LOW);
    delay(r);
  lastValue=currentValue;
  
}
