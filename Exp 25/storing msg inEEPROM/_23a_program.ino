#include <EEPROM.h>
char msg1[50]="My name is Abhishek Pandey.";
char msg2[50]="Stay Hungry.";
char msg3[50]="stay foolish.";
char msg4[50]="Get lost.";
char msg5[50]="Chasing the Dream.";
char msg6[50]="Beyond this world.";
char msg7[50]="Man at Work.";
char msg8[50]="Serving the nation.";
char msg9[50]="Good morning.";
char msg10[50]="Never say no.";
int i,add=0;
char c;
void setup()
{
Serial.begin(9600);
  for(i=0;msg1[i]!='\0';i++)
  {
    c=msg1[i];
    EEPROM.write(add,c);
    add++;
  }
  add=50;
  for(i=0;msg2[i]!='\0';i++)
  {
    c=msg2[i];
    EEPROM.write(add,c);
    add++;
  }
  add=100;
  for(i=0;msg3[i]!='\0';i++)
  {
    c=msg3[i];
    EEPROM.write(add,c);
    add++;
  }
  add=150;
  for(i=0;msg4[i]!='\0';i++)
  {
    c=msg4[i];
    EEPROM.write(add,c);
    add++;
  }
  add=200;
  for(i=0;msg5[i]!='\0';i++)
  {
    c=msg5[i];
    EEPROM.write(add,c);
    add++;
  }
  add=250;
  for(i=0;msg6[i]!='\0';i++)
  {
    c=msg6[i];
    EEPROM.write(add,c);
    add++;
  }
  add=300;
  for(i=0;msg7[i]!='\0';i++)
  {
    c=msg7[i];
    EEPROM.write(add,c);
    add++;
  }
  add=350;
  for(i=0;msg8[i]!='\0';i++)
  {
    c=msg8[i];
    EEPROM.write(add,c);
    add++;
  }
  add=400;
  for(i=0;msg9[i]!='\0';i++)
  {
    c=msg9[i];
    EEPROM.write(add,c);
    add++;
  }
  add=450;
  for(i=0;msg10[i]!='\0';i++)
  {
    c=msg10[i];
    EEPROM.write(add,c);
    add++;
  } 
    for(add=0;add<50;add++)
    {
      Serial.print((char)EEPROM.read(add));
      if((char)EEPROM.read(add) == '.')
          break;
    }
    for(add=50;add<100;add++)
    {
      Serial.print((char)EEPROM.read(add));
      if((char)EEPROM.read(add) == '.')
          break;
    }
    for(add=100;add<150;add++)
    {
      Serial.print((char)EEPROM.read(add));
      if((char)EEPROM.read(add) == '.')
          break;
    }
    for(add=150;add<200;add++)
    {
      Serial.print((char)EEPROM.read(add));
      if((char)EEPROM.read(add) == '.')
          break;
    }
    for(add=200;add<250;add++)
    {
      Serial.print((char)EEPROM.read(add));
      if((char)EEPROM.read(add) == '.')
          break;
    }
    for(add=250;add<300;add++)
    {
      Serial.print((char)EEPROM.read(add));
      if((char)EEPROM.read(add) == '.')
          break;
    }
    for(add=300;add<350;add++)
    {
      Serial.print((char)EEPROM.read(add));
      if((char)EEPROM.read(add) == '.')
          break;
    }
    for(add=350;add<400;add++)
    {
      Serial.print((char)EEPROM.read(add));
      if((char)EEPROM.read(add) == '.')
          break;
    }
    for(add=400;add<450;add++)
    {
      Serial.print((char)EEPROM.read(add));
      if((char)EEPROM.read(add) == '.')
          break;
    }
    for(add=450;add<500;add++)
    {
      Serial.print((char)EEPROM.read(add));
      if((char)EEPROM.read(add) == '.')
          break;
    }
}
void loop()
{
}
