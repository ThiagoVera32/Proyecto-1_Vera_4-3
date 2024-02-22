#include<Servo.h>

#define led 4
#define PIR1 2
#define PIR2 3
#define luz A0

Servo izq;
Servo der;

void setup()
{
  Serial.begin(9600);
  pinMode(led, OUTPUT);
  pinMode(PIR1, INPUT);
  pinMode(PIR2, INPUT);
  pinMode(luz, INPUT);
  izq.attach(9);
  der.attach(10);
  
  izq.write(180);
  der.write(0);
  
}

void loop()
{
  lectura();
  ambiente();
}

void lectura()
{
  int count = 0;
  int afuera = digitalRead(PIR1);
  int adentro = digitalRead(PIR2);
  
  Serial.print("Afuera: ");
  Serial.println(afuera);
  Serial.print("Adentro: ");
  Serial.println(adentro);
  delay(2);
  
  if(afuera == 1 || adentro == 1)
  {
    izq.write(90);
  	der.write(90);
    delay(3000);
  }
  
  else
  {
   izq.write(180);
   der.write(0); 
  }
  
  /*
  if(afuera == 1)
  {
    do
    {
      izq.write(90);
  	  der.write(90);
     }
    while(afuera != 1 and adentro == 1);
  }
  else
  {
   izq.write(180);
   der.write(0); 
  }
  
  if(adentro == 1)
  {
    do
    {
      izq.write(90);
  	  der.write(90);
     }
    while(adentro != 1 and afuera == 1);
  }
  else
  {
   izq.write(180);
   der.write(0); 
  }*/
}


void ambiente()
{
  int estado;
  int ldr = analogRead(luz); 
  
  if(ldr < 100)
  {
   estado = 0;
  }
  else
  {
   estado = 1; 
  }
 	
  if (estado == 0)
  {
   digitalWrite(led, HIGH); 
  }
  else
  {
   digitalWrite(led, LOW); 
  }
}
