#include <LiquidCrystal.h>
#include"DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11
DHT dht(8,11);
int v_min = 20, v_max=40;
volatile int values[16] = {0, 0 , 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
byte lcd_char[8];

LiquidCrystal lcd(9, 10, 13, 12, 4, 7);

void addValue(int value)
{
  for(int k = 0; k <15 ; k++)
    values[k] = values[k+1];
Serial.println(value);
  int scaled_value = map(value, v_min, v_max, 1, 16);
  Serial.println(scaled_value);
  values[15] = scaled_value;
}

void loadCustomChars()
{
  for(int i = 0; i < 8; i++)
  {
    for(int j = 0; j < 8; j++)
    {
      if(i == (7-j))
        lcd_char[j] = B11111;
      else
        lcd_char[j] = B00000;
    }
    lcd.createChar(i, lcd_char);
  }  
}

void updateStripChart()
{
  for(int i = 0; i < 16; i++)
  {
    
    if(values[i] > 8)
    {
      lcd.setCursor(i, 0);
      lcd.write(values[i] );
      lcd.setCursor(i, 1);
      lcd.write(16);
    }
    else
    {
      lcd.setCursor(i, 0);
      lcd.write(16);
      lcd.setCursor(i, 1);
      if(values[i] > 0)
      {
        lcd.write(values[i]);
      }
      else
      {
        lcd.write(16);
      }
    }
  }
}

void setup()
{
  dht.begin();
  lcd.begin(16, 2);
  loadCustomChars();
  Serial.begin(9600);
}

void loop()
{
  delay(2000);
  int t = dht.readTemperature();
  addValue(t);
  updateStripChart();
  delay(100);   
}
