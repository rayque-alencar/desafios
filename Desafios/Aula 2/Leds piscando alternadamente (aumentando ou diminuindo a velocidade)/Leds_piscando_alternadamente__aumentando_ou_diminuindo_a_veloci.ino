// definicao das constantes das portas
#define ledYellow 11
#define ledBlue 8
#define buttom 13

int speed = 1000;                  // variavel do tempo do delay
int buttomStatus = 0;              // bool da ativacao do botao

// funcao de analise do botao e realizacao de acao
void analise()                     
{
  buttomStatus = digitalRead(buttom);         // variavel recebe se o botao foi pressionado
  if(buttomStatus && speed > 100){            // caso tenha sido pressionado e a velocidade seja maior que 100
    speed -= 100;                             // tempo diminui em 0.1 seg
  }
}

void setup()
{
  // inicia os leds
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);
}

void loop()
{
  digitalWrite(ledYellow, HIGH);              // led amarelo acende
  digitalWrite(ledBlue, LOW);                 // led azul apaga
  analise();                                  // chamada da funcao analise
  
  delay(speed);                               // delay com o valor de speed
  
  digitalWrite(ledYellow, LOW);               // led amarelo apaga
  digitalWrite(ledBlue, HIGH);                // led azul acende
  analise();                                  // chamada da funcao analise
   
  delay(speed);                               // delay com o valor de speed
}
