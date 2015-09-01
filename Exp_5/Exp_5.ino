int* addr = (int*)0x01FF;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(5, OUTPUT);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  Serial.println((unsigned long int)addr);
  Serial.println(*addr);
  if(*addr == 100)
  {
    digitalWrite(3, HIGH);
  }
  else
  {
    *addr = 100;
    digitalWrite(5, HIGH);
  }
  Serial.println(*addr);
}

void loop() 
{
  // put your main code here, to run repeatedly:

}
