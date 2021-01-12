# Desafio 2 da aula 1

## Índice
+ [Circuito](#circuito)
+ [Objetivo](#objetivo)
+ [Materiais](#materiais)
+ [Simulação e Código](#simulacao-codigo)


---

<h2 id="objetivo">Objetivo</h2>

Ultilizando tres led um vermelho, um amarelo e um verde, faça um semáforo.

---

<h2 id="Circuito">Circuito</h2>



<div align='center'>
    <img src="https://github.com/rayque-alencar/desafios/blob/main/Desafios/Aula%201/Semáforo/Circuito.png"></igm>
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
    <td>Led amarelo</td>
    </tr>
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

<div align='center'>
    <img src="https://thumbs.gfycat.com/CandidSophisticatedImperatorangel-max-1mb.gif"></img>
    <p>Figura 3. Projeto em funcionamento</p>
</div>

O código a seguir realiza as funções designadas para o projeto:

```cpp
#define ledRed 11      // define o led vermelho na porta 11
#define ledYellow 10   // define o led amarelo na porta 10
#define ledGreen 9     // define o led verde na porta 9

void setup()
{
  pinMode(ledRed, OUTPUT);          // inicia led vermelho
  pinMode(ledYellow, OUTPUT);       // inicia led amarelo
  pinMode(ledGreen, OUTPUT);        // inicia led verde
}

void loop()
{
  digitalWrite(ledRed, HIGH);             // acende led 
  delay(2000);                            // espera de 2 segundos
  
  digitalWrite(ledRed, LOW);              // apaga o led vermelho
  digitalWrite(ledYellow, HIGH);          // acende o led amarelo
  delay(2000);                            // espera 2 segundos
  
  digitalWrite(ledYellow, LOW);           // apaga o led amarelo
  digitalWrite(ledGreen, HIGH);           // acende o led verde
  delay(2000);                            // espera 2 segundos
  
  digitalWrite(ledGreen, LOW);            // apaga o led verde
  
}
```




