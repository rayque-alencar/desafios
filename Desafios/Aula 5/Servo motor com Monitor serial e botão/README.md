# Desafio 2 da aula 5

## Índice
+ [Circuito](#circuito)
+ [Objetivo](#objetivo)
+ [Materiais](#materiais)
+ [Simulação e Código](#simulacao-codigo)


---

<h2 id="objetivo">Objetivo</h2>

Utilizem o que já aprenderam de monitor Serial para enviar os valores de posição do servo motor pelo Monitor Serial e ele assume a posição enviada, Utilizem tambem botões para mudar a posição do Servo Motor para direita e esquerda enquanto são clicados.


---

<h2 id="Circuito">Circuito</h2>


<div align='center'>
    <img src="https://github.com/rayque-alencar/desafios/blob/main/Desafios/Aula%205/Servo%20motor%20com%20Monitor%20serial%20e%20botão/Circuito.png"></igm>
    <p align='center'>Figura 1</p>
</div>

---

<h2>Materiais</h2>

<div align='center'>
    <table>
    <tbody>
    <tr>
    <td>&nbsp;Qnt.</td>
    <td>Item</td>
    </tr>
    <tr>
    <td>1</td>
    <td>Arduino Uno</td>
    </tr>
    <tr>
    <td>2</td>
    <td>Resistores de 1k&Omega;</td>
    </tr>
    <tr>
    <td>12&nbsp;</td>
    <td>
    <p>Jumper Macho-Macho</p>
    </td>
    </tr>
    <td>2&nbsp;</td>
    <td>Botões</td>
    </tr>
    <td>1&nbsp;</td>
    <td>Micro-servo</td>
    </tr>
    <td>1&nbsp;</td>
    <td>Protoboard</td>
    </tbody>
    </table>

<p>Tabela 1. Lista de materiais utilizados no desafio</p>

</div>

---


<h2 id="simulacao-codigo">Simulação e Código</h2>

<div align='center'>
    <img src="https://media.giphy.com/media/8jERQvNC3t1qFDjGt9/giphy.gif"></img>
    <p>Figura 2. Projeto em funcionamento</p>
</div>

<div align='center'>
    <img src="https://media.giphy.com/media/63tpn4j87Z8kn2jpeh/giphy.gif"></img>
    <p>Figura 3. Projeto em funcionamento</p>
</div>

O código a seguir realiza as funções designadas para o projeto:

```cpp
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
```




