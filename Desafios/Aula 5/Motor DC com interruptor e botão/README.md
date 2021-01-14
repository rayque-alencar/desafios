# Desafio 1 da aula 5

## Índice
+ [Circuito](#circuito)
+ [Objetivo](#objetivo)
+ [Materiais](#materiais)
+ [Simulação e Código](#simulacao-codigo)


---

<h2 id="objetivo">Objetivo</h2>

Utilizando um botão para ligar e desligar, outro para alterar o sentido de um motor de corrente contínua.


---

<h2 id="Circuito">Circuito</h2>


<div align='center'>
    <img src="https://github.com/rayque-alencar/desafios/blob/main/Desafios/Aula%205/Motor%20DC%20com%20interruptor%20e%20botão/Circuito.png"></igm>
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
    <td>Resistores de 1k&Omega;</td>
    </tr>
    <tr>
    <tr>
    <td>1</td>
    <td>Resistor 220&Omega;</td>
    </tr>
    <tr>
    <td>21&nbsp;</td>
    <td>
    <p>Jumper Macho-Macho</p>
    </td>
    </tr>
    <tr>
    <td>1&nbsp;</td>
    <td>Led verde</td>
    </tr>
    <td>3&nbsp;</td>
    <td>Botões</td>
    </tr>
    <td>1&nbsp;</td>
    <td>Ponte h</td>
    </tr>
    <td>1&nbsp;</td>
    <td>Motor DC</td>
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
    <img src="https://media.giphy.com/media/brt8vlC0SKeHh9MGrQ/giphy.gif"></img>
    <p>Figura 2. Projeto em funcionamento</p>
</div>

O código a seguir realiza as funções designadas para o projeto:

```cpp
/*
Constantes simbólicas que definem os pinos conectados a:
*/
#define INPUT1 2        //Input da shield L293D
#define INPUT2 3        //Input da shield L293D
#define BUT_ON 4        //Pino do botão liga-desliga
#define BUT_LEFT 5      //Pino do botão de rotação negativa 
#define BUT_RIGHT 6     //Pino do botão de rotação positiva
#define led 7           //Pino do led

//Cria uma variável para controlar o processo
//de liga-desliga mandado para a shield L293D
int on_off = 0; 

//Função que ativa e desativa a shield
void interruptor(){
  if(digitalRead(BUT_ON)){     //Verifica se há corrente vindo do botão liga-desliga
    if(on_off == 0)            //Verifica se a variável on_off guarda o valor 0 e se sim muda para 1
      on_off = 1;
    else{
      on_off = 0; //on_off recebe 0
      digitalWrite(led, LOW);        //Para de enviar corrente para o led
      digitalWrite(INPUT1, HIGH);    //Manda corrente para o input1 da shield
      digitalWrite(INPUT2, HIGH);    //Manda corrente para o input2 da shield
    }
    delay(1000); //Espera 1000 milissegundos
  }
}
/*
Esta função é executada assim que o arduino é inicializado
*/
void setup()
{
  //Define os pinos especificados como entrada ou saída
  pinMode(INPUT1, OUTPUT);
  pinMode(INPUT2, OUTPUT);
  pinMode(BUT_ON, INPUT);
  pinMode(BUT_LEFT, INPUT);
  pinMode(BUT_RIGHT, INPUT);
  pinMode(led, OUTPUT);
}

/*
Esta função se repetirá enquanto a placa arduino estiver ligada
permitindo que o programa sofra alterações em cada iteração
e fazendo o hardware reagir a essas mudanças
*/
void loop()
{
  interruptor();  //Chama a função de liga-desliga
   
   if(on_off){    //Se a variável on_off for diferente de 0, faça
     
     digitalWrite(led, HIGH);   //Manda corrente para o led (liga)
    
     if(digitalRead(BUT_RIGHT)){     //Se o botão de rotação positiva for pressionado, faça
      digitalWrite(INPUT1, HIGH);    //Manda corrente para o input1 da shield
      digitalWrite(INPUT2, LOW);     //Tira a corrente que vai para o input2 da shield
    }
    
    if(digitalRead(BUT_LEFT)){       //Se o botão de rotação negativa for pressionado, faça
      digitalWrite(INPUT1, LOW);     //Tira a corrente que vai para o input1 da shield
      digitalWrite(INPUT2, HIGH);    //Manda corrente para o input2 da shield
    }
    
  }
}
```




