int r_led = 3;
void setup()
{
  pinMode(r_led,OUTPUT);
}
void loop()
{
  digitalWrite(r_led,HIGH);
  delay(1000);
  digitalWrite(r_led,LOW);
  delay(1000);
  
}
