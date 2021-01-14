# Desafio 1 da aula 4

## Índice
+ [Circuito](#circuito)
+ [Objetivo](#objetivo)
+ [Materiais](#materiais)
+ [Simulação e Código](#simulacao-codigo)


---

<h2 id="objetivo">Objetivo</h2>

Ligar/Desligar o led de acordo com a luminosidade ultilizando o LDR.

---

<h2 id="Circuito">Circuito</h2>


<div align='center'>
    <img src="https://github.com/rayque-alencar/desafios/blob/main/Desafios/Aula%204/Ligar%20ou%20Desligar%20o%20led%20de%20acordo%20com%20a%20luminosidade%20e%20utilizando%20LDR/Circuito.png"></igm>
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
    <td>1</td>
    <td>Resistor 330&Omega;</td>
    </tr>
    <tr>
    <tr>
    <td>1</td>
    <td>Resistor 1k&Omega;</td>
    </tr>
    <tr>
    <td>9&nbsp;</td>
    <td>
    <p>Jumper Macho-Macho</p>
    </td>
    </tr>
    <tr>
    <td>1&nbsp;</td>
    <td>Led azul</td>
    </tr>
    <td>1&nbsp;</td>
    <td>Fotorresistor</td>
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
    <img src="https://media.giphy.com/media/zFpQ3R73me4QDL8UNe/giphy.gif"></img>
    <p>Figura 2. Projeto em funcionamento</p>
</div>



O código a seguir realiza as funções designadas para o projeto:

```cpp
#define ledBlue 13    // define o led azul como 13
#define ldr A5        // define o fotorresistor como A5

int valor;            // variavel que recebe o valor de luminosidade

void setup()
{
  Serial.begin(9600);         // inicia porta serial
  pinMode(ledBlue, OUTPUT);   // Inicia led azul
}

void loop()
{ 
 valor = analogRead(ldr);           // valor recebe o valor analogico do LDR
  
  if(valor >= 685){                 //se o valor for maior ou igual a 685
   digitalWrite(ledBlue, HIGH);     // liga o led
  }
  else{                             // caso não
    digitalWrite(ledBlue, LOW);     // desliga o led
  }
  
  Serial.println(valor);            // printa o valor no monitor serial
  delay(100);
  
}
```
