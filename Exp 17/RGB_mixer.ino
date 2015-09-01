int pot=A3,sensorValue,outputValue;
int led_r=3;
int led_g=5;
int led_b=6;
int mode=0;
int sw=A2;

void setup()
{
      Serial.begin(9600);
      pinMode(led_r, OUTPUT);
      pinMode(led_g, OUTPUT);
      pinMode(led_b, OUTPUT);
      mode=1;
}

void loop()
{ 
  switch (mode)
  {
     case 1:
           Serial.println("use knob to change the intensity of RED color and press button to change green color");
           while(analogRead(sw)>10)
           {
             sensorValue = analogRead(pot);
             outputValue = map(sensorValue, 0, 1023, 0, 255);
             analogWrite(led_r, outputValue);
           }
           delay(1000);
           mode=2;
     case 2:
           Serial.println("use knob to change the intensity of GREEN color and press button to change blue color ");
           while(analogRead(sw)>10)
           {
             sensorValue = analogRead(pot);
             outputValue = map(sensorValue, 0, 1023, 0, 255);
             analogWrite(led_g, outputValue);
           }
           delay(1000);
           mode=3;
     case 3:
           Serial.println("use knob to change the intensity of BLUE color and press button to change red color ");
           while(analogRead(sw)>10)
           {
             sensorValue = analogRead(pot);
             outputValue = map(sensorValue, 0, 1023, 0, 255);
             analogWrite(led_b, outputValue);
           }
           delay(1000);
           mode=1;
  }
}
      
           
           
         
      
