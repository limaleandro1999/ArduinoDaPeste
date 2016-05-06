#include <Wire.h>

#include "RTClib.h"


// Objeto rtc (relogio de tempo real)
RTC_DS1307 rtc;

//Conectar no pino digital 8 do Arduino Uno (Pode mudar o pino de entrada, mas mude tambem o numero do pino no codigo)
int rele = 8;

void setup () 
{
     Serial.begin(9600);
     
     pinMode(rele, OUTPUT);
     
     rtc.begin();  //inicia o objeto rtc

     // Verifica se o RTC esta funcionando
     if (!rtc.isrunning()) 
     {
           Serial.print("RTC is NOT running!");
     }
     else
     { 
         rtc.adjust(DateTime(__DATE__, __TIME__)); // Ajusta o rtc para a data e hora em que o sketch foi compilado
         Serial.print("RTC is running!");
     }
}


void loop() 
{
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
  if(now.hour == 07 && now.minute >= 10) //Primeiro toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(now.hour == 07 && now.minute >= 20) //Segundo toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(now.hour == 09 && now.minute >= 00) //Terceiro toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(now.hour == 09 && now.minute >= 20) //Quaerto toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(now.hour == 11 && now.minute >= 50) //Quinto toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(now.hour == 13 && now.minute >= 10) //Sexto toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(now.hour == 13 && now.minute >= 20) //Setimo toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(now.hour == 15 && now.minute >= 00) //Oitavo toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(now.hour == 15 && now.minute >= 20) //Nono toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(now.hour == 16 && now.minute >= 59 && now,second >= 30 ) //Decimo toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else
  {
    digitalWrite(rele, LOW);  //Rele desligado.
  }
}
