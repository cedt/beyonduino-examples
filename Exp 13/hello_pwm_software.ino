

// Pin 5 has an red LED connected on beyondueno
// give it a name:
int led = 5,i;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() 
{
  for(i=5;i<=990;i++)
  {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delayMicroseconds(i);               
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delayMicroseconds(1000-i);              
  }
  for(i=990;i>=5;i--)
  {
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delayMicroseconds(i);              
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delayMicroseconds(1000-i); 
  }
}
