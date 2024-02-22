#include <LiquidCrystal.h>

//LiquidCrystal(rs, enable, d4, d5, d6, d7)

LiquidCrystal lcd(5, 6, 8, 9, 10, 11);

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
#define SILENCIO   0

int melody[][2] = {
    {NOTE_E5,4},  
    {NOTE_B4,8},  
    {NOTE_C5,8},  
    {NOTE_D5,4},  
    {NOTE_C5,8},  
    {NOTE_B4,8},
    {NOTE_A4,4},  
    {NOTE_A4,8},  
    {NOTE_C5,8},  
    {NOTE_E5,4},  
    {NOTE_D5,8},  
    {NOTE_C5,8},
    {NOTE_B4,4},  
    {NOTE_C5,8},  
    {NOTE_D5,4},  
    {NOTE_E5,4},
    {NOTE_C5,4},  
    {NOTE_A4,4},  
    {NOTE_A4,8},  
    {NOTE_A4,4},  
    {NOTE_B4,8},  
    {NOTE_C5,8},
    {NOTE_D5,4},
    {NOTE_F5,8},
    {NOTE_A5,4},
    {NOTE_G5,8},
    {NOTE_F5,8},
    {NOTE_E5,4},
    {NOTE_C5,8},
    {NOTE_E5,4},
    {NOTE_D5,8},
    {NOTE_C5,8},
    {NOTE_B4,4},
    {NOTE_B4,8},
    {NOTE_C5,8},
    {NOTE_D5,4},
    {NOTE_E5,4},
    {NOTE_C5,4},
    {NOTE_A4,4},
    {NOTE_A4,4}, 
    {SILENCIO,4},
    {NOTE_E5,4},
    {NOTE_B4,8},
    {NOTE_C5,8},
    {NOTE_D5,4},
    {NOTE_C5,8},
    {NOTE_B4,8},
    {NOTE_A4,4},
    {NOTE_A4,8},
    {NOTE_C5,8},
    {NOTE_E5,4},
    {NOTE_D5,8},
    {NOTE_C5,8},
    {NOTE_B4,4},
    {NOTE_C5,8},
    {NOTE_D5,4},
    {NOTE_E5,4},
    {NOTE_C5,4},
    {NOTE_A4,4},
    {NOTE_A4,8},
    {NOTE_A4,4},
    {NOTE_B4,8},
    {NOTE_C5,8},
    {NOTE_D5,4},
    {NOTE_F5,8},
    {NOTE_A5,4},
    {NOTE_G5,8},
    {NOTE_F5,8},
    {NOTE_E5,4},
    {NOTE_C5,8},
    {NOTE_E5,4},
    {NOTE_D5,8},
    {NOTE_C5,8},
    {NOTE_B4,4},
    {NOTE_B4,8},
    {NOTE_C5,8},
    {NOTE_D5,4},
    {NOTE_E5,4},
    {NOTE_C5,4},
    {NOTE_A4,4},
    {NOTE_A4,4}, 
    {SILENCIO,4},
    {NOTE_E5,2},
    {NOTE_C5,2},
    {NOTE_D5,2},
    {NOTE_B4,2},
    {NOTE_C5,2},
    {NOTE_A4,2},
    {NOTE_GS4,2},
    {NOTE_B4,4},
    {SILENCIO,8},
    {NOTE_E5,2},
    {NOTE_C5,2},
    {NOTE_D5,2},
    {NOTE_B4,2},
    {NOTE_C5,4},
    {NOTE_E5,4},
    {NOTE_A5,2},
    {NOTE_GS5,2}
};



float tempo = 1.5;

#define buzz 3

void setup()
{
  lcd.begin(16, 2);
  
  pinMode(buzz, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  /*lcd.setCursor( 2  , 0);
 	lcd.print("hola");
  
  	lcd.setCursor( 6  , 1);
 	lcd.print("mundo");
  
  	lcd.setCursor( 7 , 0);
  	lcd.write( byte( 5 ) );
  
  	delay(200);
  	lcd.clear();*/
  
  for (int i = 0; i < 99; i++)
  {
    lcd.setCursor( 2  , 0);
    lcd.print(i);
    lcd.setCursor( 8  , 0);
    lcd.print(melody[i][0]);
   	tone(buzz, melody[i][0], (1000/melody[i][1]) * tempo);
    delay((1000/melody[i][1]) * tempo);
    lcd.clear();
  }
  
  noTone( buzz );
  delay(2000);
}