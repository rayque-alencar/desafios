// declaracao das variaveis das portas
// (preferencialmente se usa define, mas para mostrar que e possivel)
const int ledRed = 12;
const int ledYellow = 11;
const int ledGreen = 10;
const int button = 6;

int buttonStatus = 0; // variavel do estado do botao

// funcao que analisa se botao foi pressionado e age caso tenha sido
void analise() 
{
  buttonStatus = digitalRead(button);     // variavel recebe estado do botao
    if(buttonStatus){                     // se pressionado
      digitalWrite(ledRed, HIGH);         // led vermelho acende
      digitalWrite(ledYellow, LOW);       // led amarelo apaga
      digitalWrite(ledGreen, LOW);        // led verde apaga
      delay(4000);                        // espera de 4 segundos

      digitalWrite(ledRed,LOW);           // led vermelho apaga
    }
}

void setup()
{
  
  pinMode(ledRed, OUTPUT);                // inicia os leds e botao
  pinMode(ledYellow, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(button, INPUT_PULLUP);
}

void loop()
{
    digitalWrite(ledGreen, HIGH);         // led verde acende
    analise();                            // chamada da funcao analise

    delay(4000);                          // espera de 4 segundos
  
    analise();                            // chamada da funcao analise

    digitalWrite(ledRed, LOW);            // led vermelho apaga
    digitalWrite(ledGreen, LOW);          // led verde apaga

    digitalWrite(ledYellow, HIGH);        // led amarelo apaga

    analise();                            // chamada da funcao analise

    delay(2000);                          // espera de 2 segundos

    analise();                            // chamada da funcao analise

    digitalWrite(ledYellow, LOW);         // led amarelo apaga
    digitalWrite(ledGreen, LOW);          // led verde apaga
    digitalWrite(ledRed, HIGH);           // led vermelho acende

    analise();                            // chamada da funcao analise

    delay(4000);                          // espera de 4 segundos

    analise();                            // chamada da funcao analise

    digitalWrite(ledRed, LOW);            // led vermelho apaga
    digitalWrite(ledYellow, LOW);         // led amarelo apaga
}
