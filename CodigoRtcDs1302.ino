// Programa : Data e hora com modulo RTC DS1302
// Alteracoes e adaptacoes : Arduino e Cia e Arduino da Peste
// Baseado no programa original de Krodal e na biblioteca virtuabotixRTC

// Carrega a biblioteca virtuabotixRTC
#include <virtuabotixRTC.h>           

// Determina os pinos ligados ao modulo
// myRTC(clock, data, rst)
virtuabotixRTC myRTC(7, 6, 5);

//Conectar no pino digital 8 do Arduino Uno (Pode mudar o pino de entrada, mas mude tambem o numero do pino no codigo)
int rele = 8;

void setup()  
{      
  Serial.begin(9600);

  pinMode(rele, OUTPUT);
  
  // Informacoes iniciais de data e hora
  // Apos setar as informacoes, comente a linha abaixo
  // (segundos, minutos, hora, dia da semana, dia do mes, mes, ano)
  myRTC.setDS1302Time(00, 58, 23, 2, 17, 11, 2014);
}

void loop()  
{
  // Le as informacoes do CI
  myRTC.updateTime(); 
  
  showInformations();
  
  horasDeTocar();
}

void horasDeTocar()
{
  if(myRTC.hours == 07 && myRTC.minutes >= 10) //Primeiro toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(myRTC.hours == 07 && myRTC.minutes >= 20) //Segundo toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(myRTC.hours == 09 && myRTC.minutes >= 00) //Terceiro toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(myRTC.hours == 09 && myRTC.minutes >= 20) //Quaerto toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(myRTC.hours == 11 && myRTC.minutes >= 50) //Quinto toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(myRTC.hours == 13 && myRTC.minutes >= 10) //Sexto toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(myRTC.hours == 13 && myRTC.minutes >= 20) //Setimo toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(myRTC.hours == 15 && myRTC.minutes >= 00) //Oitavo toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(myRTC.hours == 15 && myRTC.minutes >= 20) //Nono toque.
  {
    digitalWrite(rele, HIGH);
    Serial.print("Esta tocando\n");
    delay(5000);  
    digitalWrite(rele, LOW);
    
  }
  else if(myRTC.hours == 16 && myRTC.minutes >= 59 && myRTC.seconds >= 30 ) //Decimo toque.
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

void showInformations()
{
  // Imprime as informacoes no serial monitor
  Serial.print("Data : ");
  
  // Chama a rotina que imprime o dia da semana
  imprime_dia_da_semana(myRTC.dayofweek);
  Serial.print(", ");
  Serial.print(myRTC.dayofmonth);
  Serial.print("/");
  Serial.print(myRTC.month);
  Serial.print("/");
  Serial.print(myRTC.year);
  Serial.print("  ");
  Serial.print("Hora : ");
  
  // Adiciona um 0 caso o valor da hora seja <10
  if (myRTC.hours < 10)
  {
    Serial.print("0");
  }
  
  Serial.print(myRTC.hours);
  Serial.print(":");
  // Adiciona um 0 caso o valor dos minutos seja <10
  if (myRTC.minutes < 10)
  {
    Serial.print("0");
  }
  Serial.print(myRTC.minutes);
  Serial.print(":");
  // Adiciona um 0 caso o valor dos segundos seja <10
  if (myRTC.seconds < 10)
  {
    Serial.print("0");
  }
  Serial.println(myRTC.seconds);

  delay( 1000);  
}

void imprime_dia_da_semana(int dia)
{
  switch (dia)
  {
    case 1:
    Serial.print("Domingo");
    break;
    case 2:
    Serial.print("Segunda");
    break;
    case 3:
    Serial.print("Terca");
    break;
    case 4:
    Serial.print("Quarta");
    break;
    case 5:
    Serial.print("Quinta");
    break;
    case 6:
    Serial.print("Sexta");
    break;
    case 7:
    Serial.print("Sabado");
    break;
  }
}
