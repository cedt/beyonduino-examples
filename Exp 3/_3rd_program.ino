int r_led = 3;
void setup()
{
  pinMode(r_led,OUTPUT);
}
void loop()
{
  digitalWrite(r_led,HIGH);
  delay(100);
  digitalWrite(r_led,LOW);
  delay(100);
}

