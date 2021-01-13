# Desafio 2 da aula 2

## Índice
+ [Circuito](#circuito)
+ [Objetivo](#objetivo)
+ [Materiais](#materiais)
+ [Simulação e Código](#simulacao-codigo)


---

<h2 id="objetivo">Objetivo</h2>

Ultilizando leds faça com que eles fiquem piscando alternadamente, aumentando a velocidade de piscada ou diminuindo para cada click no botão.


---

<h2 id="Circuito">Circuito</h2>



<div align='center'>
    <img src="https://github.com/rayque-alencar/desafios/blob/main/Desafios/Aula%202/Leds%20piscando%20alternadamente%20(aumentando%20ou%20diminuindo%20a%20velocidade)/Circuito.jpg"></igm>
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
    <td>1&nbsp;</td>
    <td>Resistor de 1K&Omega;</td>
    </tr>
    <tr>
    <td>1&nbsp;</td>
    <td>Led azul</td>
    </tr>
    <tr>
    <td>1&nbsp;</td>
    <td>
    <p>Led amarelo</p>
    </td>
    <tr>
    <td>1&nbsp;</td>
    <td>Botao</td>
    </tr>
    <td>7&nbsp;</td>
    <td>
    <p>Jumpers Macho-Macho</p>
    </td>
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
// definicao das constantes das portas
#define ledYellow 11
#define ledBlue 8
#define buttom 13

int speed = 1000;                  // variavel do tempo do delay
int buttomStatus = 0;              // bool da ativacao do botao

// funcao de analise do botao e realizacao de acao
void analise()                     
{
  buttomStatus = digitalRead(buttom);         // variavel recebe se o botao foi pressionado
  if(buttomStatus && speed > 100){            // caso tenha sido pressionado e a velocidade seja maior que 100
    speed -= 100;                             // tempo diminui em 0.1 seg
  }
}

void setup()
{
  // inicia os leds
  pinMode(ledBlue, OUTPUT);
  pinMode(ledYellow, OUTPUT);
}

void loop()
{
  digitalWrite(ledYellow, HIGH);              // led amarelo acende
  digitalWrite(ledBlue, LOW);                 // led azul apaga
  analise();                                  // chamada da funcao analise
  
  delay(speed);                               // delay com o valor de speed
  
  digitalWrite(ledYellow, LOW);               // led amarelo apaga
  digitalWrite(ledBlue, HIGH);                // led azul acende
  analise();                                  // chamada da funcao analise
   
  delay(speed);                               // delay com o valor de speed
}
```




