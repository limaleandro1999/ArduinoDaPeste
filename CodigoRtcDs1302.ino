// Programa : Data e hora com modulo RTC DS1302
// Alteracoes e adaptacoes : Arduino e Cia e Arduino da Peste
// Baseado no programa original de Krodal e na biblioteca virtuabotixRTC

// Abaixo link para baixar a biblioteca necessaria
//https://drive.google.com/folderview?id=0B7LWVhDM1smbMFZfZ1NCUHRuS3c&usp=sharing

// Carrega a biblioteca virtuabotixRTC
#include <virtuabotixRTC.h>           

// Determina os pinos ligados ao modulo
// myRTC(clock, data, rst)
virtuabotixRTC myRTC(7, 6, 5);

//Conectar no pino digital 8 do Arduino Uno (Pode mudar o pino de entrada, mas mude tambem o numero do pino no codigo)
int rele = 8;
int ledL = 13;

void setup()  
{      
  Serial.begin(9600);

  pinMode(rele, OUTPUT);
  pinMode(ledL, OUTPUT);
  
  //Informacoes iniciais de data e hora
  //Se seu RTC ja esta ajustado a hora e data, deixe comentado a linha(29) de configuracao do RTC
  //Apos ajustar as informacoes de hora e data, comente a linha abaixo
  //myRTC.setDS1302Time(00, 58, 23, 2, 17, 11, 2014);
  // (segundos, minutos, hora, dia da semana, dia do mes, mes, ano)
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
  //Codigo abaixo, entre comentarios( /* */) para teste.
  //Modifique os horarios
  //Ele nao ira tocar, apenas mostrara no serial monitor "Tocando"
  /* 
    if(myRTC.hours == 07 && myRTC.minutes == 10 && myRTC.seconds == 0) //Primeiro toque.
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
  
  if(myRTC.hours == 07 && myRTC.minutes == 10 && myRTC.seconds == 0) //Primeiro toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    piscaLed();
  }
  else if(myRTC.hours == 07 && myRTC.minutes == 20 && myRTC.seconds == 0) //Segundo toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    piscaLed();
  }
  else if(myRTC.hours == 09 && myRTC.minutes == 00 && myRTC.seconds == 0) //Terceiro toque.
  {
    dSerial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    piscaLed();
  }
  else if(myRTC.hours == 09 && myRTC.minutes == 20 && myRTC.seconds == 0) //Quaerto toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    piscaLed();
  }
  else if(myRTC.hours == 11 && myRTC.minutes == 50 && myRTC.seconds == 0) //Quinto toque.
  {
    dSerial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    piscaLed();
  }
  else if(myRTC.hours == 13 && myRTC.minutes == 10 && myRTC.seconds == 0) //Sexto toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    piscaLed();
  }
  else if(myRTC.hours == 13 && myRTC.minutes == 20 && myRTC.seconds == 0) //Setimo toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    piscaLed();
  }
  else if(myRTC.hours == 15 && myRTC.minutes == 00 && myRTC.seconds == 0) //Oitavo toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    piscaLed();
  }
  else if(myRTC.hours == 15 && myRTC.minutes == 20 && myRTC.seconds == 0) //Nono toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    piscaLed();
  }
  else if(myRTC.hours == 16 && myRTC.minutes == 59 && myRTC.seconds >= 30 && myRTC.seconds == 0) //Decimo toque.
  {
    Serial.print("Esta tocando\n");
    digitalWrite(ledL, HIGH);
    digitalWrite(rele, HIGH);
    //Toca 15 segundos (15 * 1000)
    delay(15000);    
    digitalWrite(rele, LOW);
    piscaLed();
  }
  else
  {
    digitalWrite(rele, LOW);  //Rele desligado.
    piscaLed();
  }
}

void piscaLed()
{
  digitalWrite(ledL, HIGH);
  delay(500);
  digitalWrite(ledL, LOW);
  delay(500);
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
