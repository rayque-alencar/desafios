// variaveis das portas dos leds
const int ledBlue = 12;
const int ledYellow = 10;
const int buzzer = 3;

// variaveis para a funcao millis
unsigned long int tempAtual = 0;
unsigned long int tempBlue = 0;
unsigned long int tempYellow = 0;
unsigned long int tempBuzzer = 0;

void setup()
{ 
  pinMode(ledBlue, OUTPUT);    // inicia os leds e buzzer
  pinMode(ledYellow, OUTPUT);
  pinMode(buzzer, OUTPUT);
}

void loop()
{
  tempAtual = millis();                                // tempo atual recebe o valor da funcao millis(tempo desde que o programa se iniciou)
  
  if(tempAtual - tempBlue > 500){                      // se passar 0.5 segundos
    digitalWrite(ledBlue, !digitalRead(ledBlue));      // apaga/desliga led azul
    tempBlue = tempAtual;                              // tempBlue recebe o tempo passado, resetando a diferenca
  }
  
  if(tempAtual - tempYellow > 1000){                   // se passar 1 segundo
    digitalWrite(ledYellow, !digitalRead(ledYellow));  // apaga/desliga led amarelo
    tempYellow = tempAtual;                            // tempYellow recebe o tempo passado, resetando a diferenca
  }
  
  if(tempAtual - tempBuzzer > 2000){                   // se passar 2 segundos
    tone(buzzer, 265);                                 // toca buzzer com frequencia 265
    tempBuzzer = tempAtual;                            // tempBuzzer recebe o tempo passado, resetando a diferenca
  }
  else{
    noTone(buzzer);                                    // buzzer para de tocar
  }
  
  delay(20);
  
}
