//Below is the code for the random song MP3 Player, happy breadboarding! 
//THIS CODE CONTAINS "STAR WARS THEME" FROM ROBERT COUTO, 2019

#include <LiquidCrystal.h> 
#include <IRremote.h> 

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST 0

int tempo1 = 220; 
int harry[] = {
  
  REST, 2, NOTE_D4, 4,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_C5, -2, 
  NOTE_A4, -2,
  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,
  NOTE_F4, 2, NOTE_GS4, 4,
  NOTE_D4, -1, 
  NOTE_D4, 4,

  NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, //10
  NOTE_G4, 2, NOTE_D5, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_B4, 4,
  NOTE_G4, -1,
  NOTE_AS4, 4,
     
  NOTE_D5, 2, NOTE_AS4, 4,//18
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_DS5, 2, NOTE_D5, 4,
  NOTE_CS5, 2, NOTE_A4, 4,
  NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_D4, 4,
  NOTE_D5, -1, 
  REST,4, NOTE_AS4,4,  

  NOTE_D5, 2, NOTE_AS4, 4,//26
  NOTE_D5, 2, NOTE_AS4, 4,
  NOTE_F5, 2, NOTE_E5, 4,
  NOTE_DS5, 2, NOTE_B4, 4,
  NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4,
  NOTE_CS4, 2, NOTE_AS4, 4,
  NOTE_G4, -1, 
  
};

int notes1 = sizeof(harry) / sizeof(harry[0]) / 2;

int wholenote1 = (60000 * 4) / tempo1;

int divider1 = 0, noteDuration1 = 0;

int tempo2 = 130;
int star[] = { 
  NOTE_AS4,8, NOTE_AS4,8, NOTE_AS4,8,//1
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,8, NOTE_C5,8, NOTE_C5,8,
  NOTE_F5,2, NOTE_C6,2,
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4,  
  
  NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F6,2, NOTE_C6,4, //8  
  NOTE_AS5,8, NOTE_A5,8, NOTE_AS5,8, NOTE_G5,2, NOTE_C5,-8, NOTE_C5,16, 
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C5,-8, NOTE_C5,16,
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  
  NOTE_C6,-8, NOTE_G5,16, NOTE_G5,2, REST,8, NOTE_C5,8,//13
  NOTE_D5,-4, NOTE_D5,8, NOTE_AS5,8, NOTE_A5,8, NOTE_G5,8, NOTE_F5,8,
  NOTE_F5,8, NOTE_G5,8, NOTE_A5,8, NOTE_G5,4, NOTE_D5,8, NOTE_E5,4,NOTE_C6,-8, NOTE_C6,16,
  NOTE_F6,4, NOTE_DS6,8, NOTE_CS6,4, NOTE_C6,8, NOTE_AS5,4, NOTE_GS5,8, NOTE_G5,4, NOTE_F5,8,
  NOTE_C6,1
  
};

int notes2 = sizeof(star) / sizeof(star[0]) / 2;
int wholenote2 = (60000 * 4) / tempo2;
int divider2 = 0, noteDuration2 = 0;

IRrecv IR(52); 
const int whiteLED1 = 50, yellowLED1 = 48, blueLED1 = 46, whiteLED2 = 49, yellowLED2 = 51, blueLED2 = 53, redLED = 47, buzzer = 44; 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); 

void setup() {
  int LEDs[] = {whiteLED1, yellowLED1, blueLED1, whiteLED2, yellowLED2, blueLED2, redLED}; 
  int numOUT = sizeof(LEDs) / sizeof(LEDs[0]); 
  for(int counter = 0; counter < numOUT; counter++){
    pinMode(LEDs[counter], OUTPUT);
  }
  pinMode(buzzer, OUTPUT);
  IR.enableIRIn(); 
  lcd.begin(16, 2); 
  Serial.begin(9600); 
}

void loop() {
  if(IR.decode()){
    Serial.println(IR.decodedIRData.decodedRawData, HEX); //if IR.decodedIRData.decodedRawData == 0xhex code, this means if that button is pressed, continue 
      if(IR.decodedIRData.decodedRawData == 0xBA45FF00){
      digitalWrite(redLED, HIGH);
      delay(500); 
      lcd.print("Welcome!");
      delay(2000); 
      lcd.clear(); 
      lcd.print("Press 1 for");
      lcd.setCursor(0,1); 
      lcd.print("Hedwig's Theme"); 
      delay(3000);
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Press 2 for");
      lcd.setCursor(0,1); 
      lcd.print("Star Wars");
      delay(3000);
      }
      else if(IR.decodedIRData.decodedRawData == 0xF30CFF00){
          lcd.clear();
          lcd.setCursor(0,0);
          lcd.print("Now playing:");
          delay(1000);
          lcd.setCursor(0,1); 
          lcd.print("Hedwig's Theme"); 
          delay(1000);
              for (int thisNote = 0; thisNote < notes1 * 2; thisNote = thisNote + 2) {
                divider1 = harry[thisNote + 1];
                if (divider2 > 0) {
                noteDuration1 = (wholenote1) / divider1;
              } else if (divider1 < 0) {
                  noteDuration1 = (wholenote1) / abs(divider1);
                  noteDuration1 *= 1.5; // increases the duration in half for dotted notes
                }
            tone(buzzer, harry[thisNote], noteDuration1*0.9);
switch (ledCounter) {
          case 0:
            digitalWrite(whiteLED1, HIGH);
            break;
          case 1:
            digitalWrite(yellowLED1, HIGH);
            break;
          case 2:
            digitalWrite(blueLED1, HIGH);
            break;
          case 3:
            digitalWrite(whiteLED2, HIGH);
            break;
          case 4:
            digitalWrite(yellowLED2, HIGH);
            break;
          case 5:
            digitalWrite(blueLED2, HIGH);
            break;
        }
        delay(noteDuration1);
        switch (ledCounter) {
          case 0:
            digitalWrite(whiteLED1, LOW);
            break;
          case 1:
            digitalWrite(yellowLED1, LOW);
            break;
          case 2:
            digitalWrite(blueLED1, LOW);
            break;
          case 3:
            digitalWrite(whiteLED2, LOW);
            break;
          case 4:
            digitalWrite(yellowLED2, LOW);
            break;
          case 5:
            digitalWrite(blueLED2, LOW);
            break;
        }
        ledCounter = (ledCounter + 1) % 6;
        delay(noteDuration1 / 4);
        noTone(buzzer);
      }
      lcd.clear();
      digitalWrite(redLED, LOW);
        }
      } 
      else if (IR.decodedIRData.decodedRawData == 0xE718FF00){
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Now playing:");
        delay(1000); 
        lcd.setCursor(0,1); 
        lcd.print("Star Wars"); 
        delay(1000);
        int ledCounter = 0; 
        for (int thisNote = 0; thisNote < notes2 * 2; thisNote = thisNote + 2) {
            divider2 = star[thisNote + 1];
            if (divider2 > 0) {
              noteDuration2 = (wholenote2) / divider2;
            } else if (divider2 < 0) {
              noteDuration2 = (wholenote2) / abs(divider2);
              noteDuration2 *= 1.5; 
              }
        tone(buzzer, star[thisNote], noteDuration2*0.9);
        digitalWrite(whiteLED1, LOW);
        digitalWrite(yellowLED1, LOW);
        digitalWrite(blueLED1, LOW);
        digitalWrite(whiteLED2, LOW);
        digitalWrite(yellowLED2, LOW);
        digitalWrite(blueLED2, LOW);
        switch (ledCounter) {
          case 0:
            digitalWrite(whiteLED1, HIGH);
            break;
          case 1:
            digitalWrite(yellowLED1, HIGH);
            break;
          case 2:
            digitalWrite(blueLED1, HIGH);
            break;
          case 3:
            digitalWrite(whiteLED2, HIGH);
            break;
          case 4:
            digitalWrite(yellowLED2, HIGH);
            break;
          case 5:
            digitalWrite(blueLED2, HIGH);
            break;
        }
        delay(noteDuration2);
        switch (ledCounter) {
          case 0:
            digitalWrite(whiteLED1, LOW);
            break;
          case 1:
            digitalWrite(yellowLED1, LOW);
            break;
          case 2:
            digitalWrite(blueLED1, LOW);
            break;
          case 3:
            digitalWrite(whiteLED2, LOW);
            break;
          case 4:
            digitalWrite(yellowLED2, LOW);
            break;
          case 5:
            digitalWrite(blueLED2, LOW);
            break;
        }
        ledCounter = (ledCounter + 1) % 6;
        delay(noteDuration2 / 4);
        noTone(buzzer);
      }
    lcd.clear();
    digitalWrite(redLED, LOW);
    }
    lcd.clear();
    delay(1000); 
    IR.resume(); 
  }
}