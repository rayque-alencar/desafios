#include <Servo.h>  // inclui a biblioteca do servo-motor

#define SERVO 3     // define o servo como 3
#define BUT1 11     // define o botão1 como 11
#define BUT2 8      // define o botão2 como 8

int valor;          // variavel que recebe o angulo do monitor serial

Servo servin;       // cria um objeto da biblioteca Servo

void setup()
{
  Serial.begin(9600);     // inicia a porta serial
  servin.attach(SERVO);   // Inicia o servo
  servin.write(0);        // deixa o servo em 0 graus
  delay(1000);            // espera 1 seg
}

void loop()
{
  if(Serial.available() > 0){    // se receber informações no monitor serial
    valor = Serial.parseInt();   // converte o valor informado em inteiro
    delay(10);
  }
  if(digitalRead(BUT1)){         // se o botão1 for pressionado
    valor += 10;                 // angulo aumenta em 10
    delay(250);
  }
  if(digitalRead(BUT2)){         // se o botão2 for pressionado
    valor -= 10;                 // angulo reduzido em 10
    delay(250);
  }
  servin.write(valor);           // servo vai para o angulo resultante
}
