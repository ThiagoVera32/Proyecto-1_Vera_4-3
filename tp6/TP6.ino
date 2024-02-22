#define LedR 2
#define LedG 7
#define LedB 4

void setup()
{
  pinMode(LedR, OUTPUT);
  pinMode(LedG, OUTPUT);
  pinMode(LedB, OUTPUT);
  
  Serial.begin(9600);
}

void loop()
{
  for (int x = 0; x <= 255; x++)
  {
  	analogWrite(LedR, x);
    Serial.print("R Up: ");
    Serial.println(x);
    delay(20);
  }
  
  for (int x = 0; x <= 255; x++)
  {
  	analogWrite(LedG, x);
    Serial.print("G Up: ");
    Serial.println(x);
    delay(20);
  }
  
  for (int x = 0; x <= 255; x++)
  {
  	analogWrite(LedB, x);
    Serial.print("B Up: ");
    Serial.println(x);
    delay(20);
  }
  
 
  
  for (int x = 255; x >= 0; x--)
  {
  	analogWrite(LedR, x);
    Serial.print("R Down: ");
    Serial.println(x);
    delay(20);
  }
  
  for (int x = 255; x >= 0; x--)
  {
  	analogWrite(LedG, x);
    Serial.print("G Down: ");
    Serial.println(x);
    delay(20);
  }
  
  for (int x = 255; x >= 0; x--)
  {
  	analogWrite(LedB, x);
    Serial.print("B Down: ");
    Serial.println(x);
    delay(20);
  }
  