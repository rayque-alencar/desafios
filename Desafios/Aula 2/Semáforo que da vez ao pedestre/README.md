# Desafio 3 da aula 2

## Índice
+ [Circuito](#circuito)
+ [Objetivo](#objetivo)
+ [Materiais](#materiais)
+ [Simulação e Código](#simulacao-codigo)


---

<h2 id="objetivo">Objetivo</h2>

Fazaer um semáforo que dá a vez para o pedestre quando clicar no botão.

---

<h2 id="Circuito">Circuito</h2>



<div align='center'>
    <img src="https://github.com/rayque-alencar/desafios/blob/main/Desafios/Aula%202/Semáforo%20que%20da%20vez%20ao%20pedestre/Circuito.jpg"></igm>
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
    <td>Resistores de 220&Omega;</td>
    </tr>
    <tr>
    <td>1</td>
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
    <tr>
    <td>1&nbsp;</td>
    <td>Led amarelo</td>
    </tr>
    <tr>
    <td>1&nbsp;</td>
    <td>Led verde</td>
    </tr>
    <td>1&nbsp;</td>
    <td>Botão</td>  
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
    <img src="https://media.giphy.com/media/eyr3VOM0TnnEvqAfIG/giphy.gif"></img>
    <p>Figura 2. Projeto em funcionamento</p>
</div>

O código a seguir realiza as funções designadas para o projeto:

```cpp
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
```




