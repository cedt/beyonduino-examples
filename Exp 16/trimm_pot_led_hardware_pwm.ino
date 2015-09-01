int led = 3,pot;

// the setup routine runs once when you press reset:
void setup() {
  // initialize the digital pin as an output.
  pinMode(led, OUTPUT);
}

// the loop routine runs over and over again forever:
void loop() {
  pot=analogRead(A3);
  digitalWrite(led, HIGH);   // turn the LED on (HIGH is the voltage level)
  delayMicroseconds(pot);               // wait 
  digitalWrite(led, LOW);    // turn the LED off by making the voltage LOW
  delayMicroseconds(1027-pot);          // wait 
}
