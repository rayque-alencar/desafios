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
