# Desafio da aula 6

## Índice
+ [Circuito](#circuito)
+ [Objetivo](#objetivo)
+ [Materiais](#materiais)
+ [Simulação e Código](#simulacao-codigo)


---

<h2 id="objetivo">Objetivo</h2>

Desenvolva um circuito que mostra a temperatura em tempo real no dislpay LCD, ultilizando 3 leds, crie um sistema para medir a temperatura: azul como baixa(temp <= 20), amarelo como média(20 > temp <= 50) e vermelho como alta(temp > 50), adicione um ventilador(motor) para ser ligado/desligado de acordo com a temperatura ambiente.


---

<h2 id="Circuito">Circuito</h2>


<div align='center'>
    <img src="https://github.com/rayque-alencar/desafios/blob/main/Desafios/Aula%206/Display%20de%20Temperatura%20com%20leds%20e%20ventilador/Circuito.png"></igm>
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
    <td>Resistor de 1k&Omega;</td>
    </tr>
    <tr>
    <td>3</td>
    <td>Resistores de 330&Omega;</td>
    </tr>
    <tr>
    <td>44&nbsp;</td>
    <td>
    <p>Jumper Macho-Macho</p>
    </td>
    </tr>
    <td>1&nbsp;</td>
    <td>Motor DC</td>
    </tr>
    <td>1&nbsp;</td>
    <td>Potenciometro</td>
    </tr>
    </tr>
    <td>1&nbsp;</td>
    <td>ponte H</td>
    </tr>
    </tr>
    <td>1&nbsp;</td>
    <td>Led vermelho</td>
    </tr>
    </tr>
    <td>1&nbsp;</td>
    <td>Led amarelo</td>
    </tr>
    </tr>
    <td>1&nbsp;</td>
    <td>Led azul</td>
    </tr>
    </tr>
    <td>1&nbsp;</td>
    <td>Sensor de temperatura [TMP36]</td>
    </tr>
    <td>1&nbsp;</td>
    <td>LCD 16 X 2</td>
     </tr>
    <td>2&nbsp;</td>
    <td>Protoboard</td>
    </tbody>
    </table>

<p>Tabela 1. Lista de materiais utilizados no desafio</p>

</div>

---

<h2 id="simulacao-codigo">Simulação e Código</h2>

<div align='center'>
    <img src="https://media.giphy.com/media/kjXuNlrh5U7NFT9TlO/giphy.gif"></img>
    <p>Figura 2. Projeto em funcionamento</p>
</div>

O código a seguir realiza as funções designadas para o projeto:

```cpp
#include <LiquidCrystal.h> // inclui a biblioteca do LCD

LiquidCrystal LCD (2,3,4,5,6,7); //cria um objeto da biblioteca liquidcrystal e inicializa com as portas

#define SENSOR A0      // define o sensor de temperatura como A0
#define INPUT1 12      // define o input1 da ponte H como 12
#define INPUT2 11      // define o input2 da ponte H como 11
#define ledRed 10      // define o led vermelho como 10
#define ledYellow 9    // define o led amarelo como 9
#define ledBlue 8      // define led azul como 8

void setup()
{
  LCD.begin(16, 2);             // inicia o LCD 16 colunas por 2 linhas
  pinMode(SENSOR, INPUT);       //inicia o sensor
  pinMode(INPUT1, OUTPUT);      // inicia o input1
  pinMode(INPUT2, OUTPUT);      // inicia o input2
  pinMode(ledRed, OUTPUT);      // inicia o led vermelho
  pinMode(ledYellow, OUTPUT);   // inicia o led amarelo
  pinMode(ledBlue, OUTPUT);     // inicia o led azul
}

void loop()
{ 
  int valor = analogRead(SENSOR);    // valor recebe o valor analogico do sensor
  
  valor = map(((valor - 20) * 3.04), 0, 1023, -40, 125); // valor é colocado na escla de Celsius
  
  if(valor <= 18){                    // se menor ou igual que 18 graus
    digitalWrite(ledBlue, HIGH);      // liga led azul
    digitalWrite(ledRed, LOW);        // desliga o led vermelho
    digitalWrite(ledYellow, LOW);     // desliga o led amarelo
  }
  if(valor > 18 && valor < 35){       // se entre 18 e 35
    digitalWrite(ledBlue, LOW);       //desliga led azul
    digitalWrite(ledRed, LOW);        // desliga o led vermelho
    digitalWrite(ledYellow, HIGH);    // liga o led amarelo
  }
  
  if(valor >= 35){                    // se maior ou igual a 35 graus
    digitalWrite(ledBlue, LOW);       // desliga led azul
    digitalWrite(ledRed, HIGH);       // liga led vermelho
    digitalWrite(ledYellow, LOW);     // desliga led amarelo
  }
  
  if(valor >= 30){                    // se maior que 30 graus
    digitalWrite(INPUT1, HIGH);       // liga o ventilador
    digitalWrite(INPUT2, LOW);
  }
  else{ // caso não
    digitalWrite(INPUT1, LOW);        // desliga ventilador
    digitalWrite(INPUT2, LOW);
  }
  
  LCD.setCursor(3,0);        // coloca o cursor na coluna 3, linha 0
  LCD.print("Temp: ");       // printa 'temp'
  LCD.print(valor);          // printa a temperatura
  LCD.print(" C");           // printa 'C'
  delay(2000);               // espera 2 segundos
  LCD.clear();               // apaga tela
  
}
```
