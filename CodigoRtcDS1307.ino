// Abaixo link para baixar a biblioteca necessaria
//https://drive.google.com/folderview?id=0B7LWVhDM1smbMFZfZ1NCUHRuS3c&usp=sharing

#include <Wire.h>

#include "RTClib.h"

// Objeto rtc (relogio de tempo real)
RTC_DS1307 rtc;

//Conectar no pino digital 8 do Arduino Uno (Pode mudar o pino de entrada, mas mude tambem o numero do pino no codigo)
int rele = 8;
int ledL = 13;

void setup ()
{
  Serial.begin(9600);
  
  // A porta do rele esta configurada para liberar energia 
  pinMode(rele, OUTPUT);
  pinMode(ledL, OUTPUT);
  
  rtc.begin(); //inicia o objeto rtc
  
  //Comente a linha abaixo depois da primeira compilacao.
  //Se seu RTC ja esta com as horas configuradas, deixe esta linha comentada !
  //rtc.adjust(DateTime(__DATE__, __TIME__));

}
void loop()
{
  showInformations();
  horasDeTocar();
}
void showInformations()
{
  DateTime now = rtc.now();
  
  //Date
  Serial.print(now.day(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.year(), DEC);
  
  //Time
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
  
  delay(1000);
}
void horasDeTocar()
{
  DateTime now = rtc.now();
  
  //Codigo para teste.
  //Ele nao ira tocar apenas mostrara no serial monitor "Tocando"
  /*
  if(now.hour() == 9 && now.minute() == 50 && now.second() == 0) //Primeiro toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    //digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    //digitalWrite(rele, LOW);
    piscaLed();
  }
  */
  if(now.hour() == 7 && now.minute() == 10 && now.second() == 0) //Primeiro toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    //piscaLed();
  }
  else if(now.hour() == 7 && now.minute() == 20 && now.second() == 0) //Segundo toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    //piscaLed();
  }
  else if(now.hour() == 9 && now.minute() == 0 && now.second() == 0) //Terceiro toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
   // piscaLed();
  }
  else if(now.hour() == 9 && now.minute() == 20 && now.second() == 0) //Quarto toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
  //  piscaLed();
  }
  else if(now.hour() == 11 && now.minute() == 50 && now.second() == 0) //Quinto toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
   // piscaLed();
  }
  else if(now.hour() == 13 && now.minute() == 10 && now.second() == 0) //Sexto toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    //piscaLed();
  }
  else if(now.hour() == 13 && now.minute() == 20 && now.second() == 0) //Setimo toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
   // piscaLed();
  }
  else if(now.hour() == 15 && now.minute() == 0 && now.second() == 0) //Oitavo toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
 //   piscaLed();
  }
  else if(now.hour() == 15 && now.minute() == 20 && now.second() == 0) //Nono toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
   // piscaLed();
  }
  else if(now.hour() == 16 && now.minute() == 59 && now.second() == 0) //Decimo toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
   // piscaLed();
  }
  else
  {
    digitalWrite(rele, LOW); //Sirene desligada.
    //piscaLed();
  }
}
/*
void piscaLed()
{
  digitalWrite(ledL, HIGH);
  delay(500);
  digitalWrite(ledL, LOW);
  delay(500);
}
*/
