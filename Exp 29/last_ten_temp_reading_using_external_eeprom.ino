#include <EEPROM.h>
// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain
#include "DHT.h"
#define DHTPIN 8     // what pin we're connected to
// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11 
#define DHTTYPE DHT11  
#include<Wire.h>
#include<Rtc_Pcf8563.h>
#include <I2C_eeprom.h>
I2C_eeprom ee(0x50,8192);

uint32_t totals = 0;
// DHT 22  (AM2302
// Connect pin 1 (on the left) of the sensor to +5V
// NOTE: If using a board with 3.3V logic like an Arduino Due connect pin 1
// to 3.3V instead of 5V!
// Connect pin 2 of the sensor to whatever your DHTPIN is
// Connect pin 4 (on the right) of the sensor to GROUND
// Connect a 10K resistor from pin 2 (data) to pin 1 (power) of the sensor
// Initialize DHT sensor for normal 16mhz Arduino
DHT dht(8, 11);
Rtc_Pcf8563 rtc;

// NOTE: For working with a faster chip, like an Arduino Due or Teensy, you
// might need to increase the threshold for cycle counts considered a 1 or 0.
// You can do this by passing a 3rd parameter for this threshold.  It's a bit
// of fiddling to find the right value, but in general the faster the CPU the
// higher the value.  The default for a 16mhz AVR is a value of 6.  For an
// Arduino Due that runs at 84mhz a value of 30 works.
// Example to initialize DHT sensor for Arduino Due:
//DHT dht(DHTPIN, DHTTYPE, 30);
int h,s,m,x,y,t,m1,ma,sv1,sv2,n,rx,l,k,sw=A2,i=0,u=0;
const int analogInPin = A0; 
const int analogInPin1 = A3;  // Analog input pin that the potentiometer is attached to
int sensorValue1 = 0;        // value read from the pot
int outputValue1 = 0;
int sensorValue = 0;        // value read from the pot
int outputValue = 0;
float hu;
int a[11][7],b[11][7];
void setup()
{
  Serial.begin(9600); 
  dht.begin();
  ee.begin();
  //clear out the registers
  for(x=0;x<=10;x++)
  {
    for(y=0;y<=3;y++)
    {
       a[x][y]=u;
       u++;
    }
  }
}
void loop() 
{
   if(analogRead(sw) > 10)
   {
    delay(2000);
     // Reading temperature or humidity takes about 250 milliseconds!
    // Sensor readings may also be up to 2 seconds 'old' (its a very slow sen  
    // Read temperature as Celsius
    float t = dht.readTemperature();
    // Read temperature as Fahrenheit
    // Check if any reads failed and exit early (to try again)
    // read the analog in value:

    rtc.getTime();
    int h =rtc.getHour();
    int m =rtc.getMinute();
    int s =rtc.getSecond();
   
      ee.writeByte(a[i][0],t);
    delay(5);
      ee.writeByte(a[i][1],h);
    delay(5);
      ee.writeByte(a[i][2],m);
    delay(5);
     ee.writeByte(a[i][3],s);
    delay(1000);

    i++;
    if(i>10)
     {
         l=1;
         for(k=0;k<=10;k++)
         {
             b[k][0]=ee.readByte(a[l][0]);
             delay(5);
             ee.writeByte(a[l-1][0],b[k][0]);
             delay(5);
             b[k][1]=ee.readByte(a[l][1]);
             delay(5);
             ee.writeByte(a[l-1][1],b[k][1]);
             delay(5);
             b[k][2]=ee.readByte(a[l][2]);
             delay(5);
             ee.writeByte(a[l-1][2],b[k][2]);
             delay(5);
             b[k][3]=ee.readByte(a[l][3]);
             delay(5);
             ee.writeByte(a[l-1][3],b[k][3]);
             delay(5);
             l++; 
         }   
        i=10;
      }
   }
   if (analogRead(sw)< 10)
   {  
         for(x=0;x<=9;x++)
         { 
           Serial.println("\t");
           Serial.print(ee.readByte(a[x][0]));
           delay(5);
           Serial.print("%\t @  ");
           delay(5);
           Serial.print(ee.readByte(a[x][1]));
           delay(5);
           Serial.print(":");
           delay(5);
           Serial.print(ee.readByte(a[x][2]));
           delay(5);
           Serial.print(":");
           Serial.print(ee.readByte(a[x][3]));
           
         }
         delay(1000);
   } 
  
}
