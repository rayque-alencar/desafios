# Desafio 1 da aula 2

## Índice
+ [Circuito](#circuito)
+ [Objetivo](#objetivo)
+ [Materiais](#materiais)
+ [Simulação e Código](#simulacao-codigo)


---

<h2 id="objetivo">Objetivo</h2>

Acionamento de um alarme(Buzzer) ao apertar um botão.


---

<h2 id="Circuito">Circuito</h2>



<div align='center'>
    <img src="https://github.com/rayque-alencar/desafios/blob/main/Desafios/Aula%202/Alarme%20com%20botão/Circuito.jpg"></igm>
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
    <td>resistores de 1K&Omega;</td>
    </tr>
    <tr>
    <td>6&nbsp;</td>
    <td>
    <p>Jumper Macho-Macho</p>
    </td>
    </tr>
    <tr>
    <td>1&nbsp;</td>
    <td>Botão</td>
    </tr>
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
    <img src="https://media.giphy.com/media/c0MWabFTlXkE9SZaD0/giphy.gif"></img>
    <p>Figura 2. Projeto em funcionamento</p>
</div>

O código a seguir realiza as funções designadas para o projeto:

```cpp
#define buttonPin 2       // define o botão na porta 2
#define buzzer 13         // define o buzzer na porta 13
int buttonStatus = 0;     // variavel bool para saber se o botão foi pressionado

void setup()
{
  pinMode(buzzer, OUTPUT);        // Inicia buzzer
  pinMode(buttonPin, INPUT);      // Inicia botão
}

void loop()
{
  buttonStatus = digitalRead(buttonPin);       // buttomStatus recebe se o botão foi apertado
  if(buttonStatus == HIGH){                    // se tiver apertado
    tone(buzzer, 265);                         // liga o buzzer com frequencia 265
  }
  else{                                        // caso não tiver apertado
    noTone(buzzer);                            // desliga o buzzer
  }
}
```




