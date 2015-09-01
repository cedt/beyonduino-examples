
const int analogInPin = A0;  // Analog input pin that the ldr is attached to // 

int sensorValue = 0;        
int outputValue = 0;        

void setup() {

  Serial.begin(9600);
}

void loop() 
{
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 255);
  Serial.print("sensor = " );
  Serial.print(sensorValue);
  Serial.print("\t output = ");
  Serial.println(outputValue);

  delay(1000);
}
