// Morse Code Project
  
 // This code will loop through a string of characters and convert these to morse code.  
 // It will blink two LED lights and play audio on a speaker.  
 //*/
 
 
//**************************************************//
//   Type the String to Convert to Morse Code Here  //
//**************************************************//
#include<EEPROM.h>
char stringToMorseCode[50];
// Create variable to define the output pins
int led6 = 6;        // blink an led on output 6
int audio8 = 11;      // output audio on pin 8
int note = 1200;      // music note/pitch
/*
	Set the speed of your morse code
	Adjust the 'dotlen' length to speed up or slow down your morse code
		(all of the other lengths are based on the dotlen)
	Here are the ratios code elements:
	  Dash length = Dot length x 3
	  Pause between elements = Dot length
		  (pause between dots and dashes within the character)
	  Pause between characters = Dot length x 3
	  Pause between words = Dot length x 7  
*/
int dotLen = 100;     // length of the morse code 'dot'
int dashLen = dotLen * 3;    // length of the morse code 'dash'
int elemPause = dotLen;  // length of the pause between elements of a character
int Spaces = dotLen * 4;     // length of the spaces between characters
int wordPause = dotLen * 7;  // length of the pause between words
int r,add;
// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output for LED lights.
 Serial.begin(9600);
Serial.println("There are 10 messages.\nSend the no. of message you want to play.\n");
while(!Serial.available())
{}
while(Serial.available())
{
  r=Serial.parseInt();
  Serial.print("\nMessage ");
  Serial.println(r);
  break;
}
Serial.println("Press reset switch if you want to choose another message.");
  pinMode(led6, OUTPUT);
  pinMode(audio8, OUTPUT);
}

// Create a loop of the letters/words you want to output in morse code (defined in string at top of code)
void loop()
{ 
   switch(r)
   {
     case 1:  add=0;
             for(int i=0;i<50;i++)
             {
               stringToMorseCode[i]=(char)EEPROM.read(add);
               if((char)EEPROM.read(add)=='.')
               {
                 stringToMorseCode[i]='\0';
                 break;
               }  
               add++;
             }
             break;
      case 2:  add=50;
             for(int i=0;i<50;i++)
             {
               stringToMorseCode[i]=(char)EEPROM.read(add);
               if((char)EEPROM.read(add)=='.')
               {
                 stringToMorseCode[i]='\0';
                 break;
               }  
               add++;
             }
             break;
        case 3:  add=100;
             for(int i=0;i<50;i++)
             {
               stringToMorseCode[i]=(char)EEPROM.read(add);
               if((char)EEPROM.read(add)=='.')
               {
                 stringToMorseCode[i]='\0';
                 break;
               }  
               add++;
             }
             break;
        case 4:  add=150;
             for(int i=0;i<50;i++)
             {
               stringToMorseCode[i]=(char)EEPROM.read(add);
               if((char)EEPROM.read(add)=='.')
               {
                 stringToMorseCode[i]='\0';
                 break;
               }  
               add++;
             }
             break;
        case 5:  add=200;
             for(int i=0;i<50;i++)
             {
               stringToMorseCode[i]=(char)EEPROM.read(add);
               if((char)EEPROM.read(add)=='.')
               {
                 stringToMorseCode[i]='\0';
                 break;
               }  
               add++;
             }
             break;
        case 6:  add=250;
             for(int i=0;i<50;i++)
             {
               stringToMorseCode[i]=(char)EEPROM.read(add);
               if((char)EEPROM.read(add)=='.')
               {
                 stringToMorseCode[i]='\0';
                 break;
               }  
               add++;
             }
             break;
        case 7:  add=300;
             for(int i=0;i<50;i++)
             {
               stringToMorseCode[i]=(char)EEPROM.read(add);
               if((char)EEPROM.read(add)=='.')
               {
                 stringToMorseCode[i]='\0';
                 break;
               }  
               add++;
             }
             break;
        case 8:  add=350;
             for(int i=0;i<50;i++)
             {
               stringToMorseCode[i]=(char)EEPROM.read(add);
               if((char)EEPROM.read(add)=='.')
               {
                 stringToMorseCode[i]='\0';
                 break;
               }  
               add++;
             }
             break;
        case 9:  add=400;
             for(int i=0;i<50;i++)
             {
               stringToMorseCode[i]=(char)EEPROM.read(add);
               if((char)EEPROM.read(add)=='.')
               {
                 stringToMorseCode[i]='\0';
                 break;
               }  
               add++;
             }
             break;
        case 10:  add=450;
             for(int i=0;i<50;i++)
             {
               stringToMorseCode[i]=(char)EEPROM.read(add);
               if((char)EEPROM.read(add)=='.')
               {
                 stringToMorseCode[i]='\0';
                 break;
               }  
               add++;
             }
             break;     
             
   }
   for(int i=0;stringToMorseCode[i]!='\0';i++)
   {
    char c=stringToMorseCode[i];
   Serial.print(c);
   Serial.println("\n\n");
   }
  // Loop through the string and get each character one at a time until the end is reached
    for (int i = 0; i < sizeof(stringToMorseCode) - 1; i++)
  {
    // Get the character in the current position
	char tmpChar = stringToMorseCode[i];
	// Set the case to lower case
	tmpChar = toLowerCase(tmpChar);
	// Call the subroutine to get the morse code equivalent for this character
        GetChar(tmpChar);
  }  
  // At the end of the string long pause before looping and starting again
  LightsOff(8000);			
}

// DOT
void MorseDot()
{ 
  digitalWrite(led6, HIGH); 
  digitalWrite(audio8, LOW); 
  delay(dotLen);             	// hold in this position
}

// DASH
void MorseDash()
{
   digitalWrite(led6, HIGH);
  digitalWrite(audio8, LOW); 
  delay(dashLen);               // hold in this position
}

// Turn Off
void LightsOff(int delayTime)
{
  digitalWrite(led6, LOW);
  digitalWrite(audio8, HIGH); 
  delay(delayTime);            	// hold in this position
}

// *** Characters to Morse Code Conversion *** //
void GetChar(char tmpChar)
{
	// Take the passed character and use a switch case to find the morse code for that character
	switch (tmpChar) {
	  case 'a':	
		MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		break;
	  case 'b':
		MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
	  case 'c':
	    MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
	  case 'd':
		MorseDash();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
	  case 'e':
		MorseDot();
		LightsOff(elemPause);
		break;
	  case 'f':
	    MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
	  case 'g':
		MorseDash();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
	  case 'h':
	    MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
	  case 'i':
	    MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
	  case 'j':
	    MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		break;
      case 'k':
	    MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		break;
	  case 'l':
	    MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
      case 'm':
	    MorseDash();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		break;
	  case 'n':
	    MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
	  case 'o':
	    MorseDash();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		break;
	  case 'p':
	    MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
	  case 'q':
	    MorseDash();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		break;
	  case 'r':
	    MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
	  case 's':
	    MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
	  case 't':
	    MorseDash();
		LightsOff(elemPause);
		break;
	  case 'u':
	    MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		break;
	  case 'v':
	    MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		break;
	  case 'w':
	    MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		break;
	  case 'x':
	    MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		break;
	  case 'y':
	    MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		break;
	  case 'z':
	    MorseDash();
		LightsOff(elemPause);
		MorseDash();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		MorseDot();
		LightsOff(elemPause);
		break;
	  default: 
		// If a matching character was not found it will default to a blank space
		LightsOff(Spaces);			
	}
}

