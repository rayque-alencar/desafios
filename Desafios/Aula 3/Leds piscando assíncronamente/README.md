# Desafio 2 da aula 3

## Índice
+ [Circuito](#circuito)
+ [Objetivo](#objetivo)
+ [Materiais](#materiais)
+ [Simulação e Código](#simulacao-codigo)


---

<h2 id="objetivo">Objetivo</h2>

Monte um programa que faça com que 2 ou mais leds(adicione um Buzzer se preferir) pisquem de maneira assícrona, com tempos de duração diferentes, ultilizando a função Milis().

---

<h2 id="Circuito">Circuito</h2>



<div align='center'>
    <img src="https://github.com/rayque-alencar/desafios/blob/main/Desafios/Aula%203/Leds%20piscando%20assíncronamente/Circuito.jpg"></igm>
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
    <td>Resistores de 330&Omega;</td>
    </tr>
    <tr>
    </tr>
    <tr>
    <td>2</td>
    <td>Resistor de 1k&Omega;</td>
    </tr>
    <tr>
    <td>9&nbsp;</td>
    <td>
    <p>Jumper Macho-Macho</p>
    </td>
    </tr>
    <tr>
    <td>1&nbsp;</td>
    <td>Led vermelho</td>
    </tr>
    <td>1&nbsp;</td>
    <td>Led azul</td>
    <tr>
    <td>1&nbsp;</td>
    <td>Buzzer</td>
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
    <img src="https://media.giphy.com/media/woJjyvVIXwr6v6Ws8m/giphy.gif"></img>
    <p>Figura 2. Projeto em funcionamento</p>
</div>

O código a seguir realiza as funções designadas para o projeto:

```cpp
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
```




