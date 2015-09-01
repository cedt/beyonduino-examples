const float a = -2E-07, b=0.0003, c=-0.2529, d = 101.63;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long x = analogRead(A1);
  unsigned long x2 = x * x;
  unsigned long x3 = x * x * x;
  
  float tmp = a*x3 + b*x2 + c*x + d;

  Serial.println(tmp);  
  
}
