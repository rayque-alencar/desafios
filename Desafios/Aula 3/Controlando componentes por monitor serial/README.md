# Desafio 1 da aula 3

## Índice
+ [Circuito](#circuito)
+ [Objetivo](#objetivo)
+ [Materiais](#materiais)
+ [Simulação e Código](#simulacao-codigo)


---

<h2 id="objetivo">Objetivo</h2>

Monte um programa que faça com que 2 ou mais leds pisquem apenas quando o usuario mandar, através do Monitor Serial.

---

<h2 id="Circuito">Circuito</h2>


<div align='center'>
    <img src="https://github.com/rayque-alencar/desafios/blob/main/Desafios/Aula%203/Controlando%20componentes%20por%20monitor%20serial/Circuito.jpg"></igm>
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
    <td>3</td>
    <td>Resistor 330&Omega;</td>
    </tr>
    <tr>
    <td>10&nbsp;</td>
    <td>
    <p>Jumper Macho-Macho</p>
    </td>
    </tr>
    <tr>
    <td>1&nbsp;</td>
    <td>Led azul</td>
    </tr>
    <td>1&nbsp;</td>
    <td>Led amarelo</td>
    </tr>
    <td>1&nbsp;</td>
    <td>Led verde</td>
    </tr>
    <td>1&nbsp;</td>
    <td>Protoboard</td>
    </tbody>
    </table>

<p>Tabela 1. Lista de materiais utilizados no desafio</p>

</div>

---


<h2 id="simulacao-codigo">Simulação e Código</h2>

Descreva como utilizar seu app, circuito ou sistema. Explicar o que for necessário para o uso dos elementos do projeto, artimanhas utilizadas no código e afins.

<div align='center'>
    <img src="https://media.giphy.com/media/NQZJkfNYha09PF7HMt/giphy.gif"></img>
    <p>Figura 2. Projeto em funcionamento</p>
</div>

<div align='center'>
    <img src="https://media.giphy.com/media/YihnfT6XPknxTWvtxC/giphy.gif"></img>
    <p>Figura 3. Projeto em funcionamento</p>
</div>

<div align='center'>
    <img src="https://media.giphy.com/media/GgeF8x2Eg8ftSzpV1X/giphy.gif"></img>
    <p>Figura 4. Projeto em funcionamento</p>
</div>

O código a seguir realiza as funções designadas para o projeto:

```cpp
#define ledYellow 12     // define ledYellow como 12
#define ledBlue 9        // define ledGreen como 9
#define ledGreen 5       // define ledGreen como 5

String serialData;       // variavel string que recebe o valor do monitor serial

void setup()
{
  Serial.begin(9600);    // inicia a porta serial
  
  pinMode(ledYellow, OUTPUT);      // inicia o led amarelo
  pinMode(ledBlue, OUTPUT);        // inicia o led azul
  pinMode(ledGreen, OUTPUT);       // inicia o led verde
}

void loop()
{
  if(Serial.available() > 0){                             // se receber informacoes
    serialData = Serial.readString();                     // SerialData recebe informacao digitada no monitor
    if(serialData == "Amarelo"){                          // se for digitado Amarelo
      digitalWrite(ledYellow, !digitalRead(ledYellow));   // acende/apaga led amarelo
    }
    if(serialData == "Azul"){                             // se for digitado Azul
      digitalWrite(ledBlue, !digitalRead(ledBlue));       // acende/apaga led azul
    }
    if(serialData == "Verde"){                            // se for digitado Verde
      digitalWrite(ledGreen, !digitalRead(ledGreen));     // acende/apaga led verde
    }
  }
}
```




