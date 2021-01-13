# Desafio 1 da aula 1

## Índice
+ [Circuito](#circuito)
+ [Objetivo](#objetivo)
+ [Materiais](#materiais)
+ [Simulação e Código](#simulacao-codigo)


---

<h2 id="objetivo">Objetivo</h2>

Ultilizando 2 leds faça um programa para que eles pisquem de maneira alternada. Com tempos de duração entre ligado e desligado diferentes.


---

<h2 id="Circuito">Circuito</h2>



<div align='center'>
    <img src="https://github.com/rayque-alencar/RAS1/blob/main/aula%201/Circuito.png"></igm>
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
    <td>Resistor 330&Omega;</td>
    </tr>
    <tr>
    <td>7&nbsp;</td>
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
    <td>
    <p>Protoboard</p>
    </tbody>
    </table>

<p>Tabela 1. Lista de materiais utilizados no desafio</p>

</div>

---


<h2 id="simulacao-codigo">Simulação e Código</h2>

Descreva como utilizar seu app, circuito ou sistema. Explicar o que for necessário para o uso dos elementos do projeto, artimanhas utilizadas no código e afins.

<div align='center'>
    <img src="https://media.giphy.com/media/TJUopNPhqukspIVJTe/giphy.gif"></img>
    <p>Figura 3. Projeto em funcionamento</p>
</div>

O código a seguir realiza as funções designadas para o projeto:

```cpp
#define ledRed 13 // Define led vermelho no pino 13
#define ledBlue 8 // Define led azul no pino 8

void setup()
{
pinMode(ledRed, OUTPUT);      // Saída de sinal digital
pinMode(ledBlue, OUTPUT);     // Saída de sinal digital
}

// Função loop() executa inifitamente
void loop()
{
digitalWrite(ledRed, HIGH);      // Acende o Led vermelho
delay(500);                      // Paraliza o código 500 milissegundos
digitalWrite(ledRed, LOW);       // Desliga o Led vermelho
digitalWrite(ledBlue, HIGH);     // Acende o Led azul
delay(500);                      // Paraliza o código 500 milissegundos
digitalWrite(ledBlue, LOW);      // Desliga o Led azul 
}
```




