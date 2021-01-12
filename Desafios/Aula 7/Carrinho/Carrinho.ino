/*
Constantes simólicas que definem os pinos para:
*/
#define input1 2 
#define input2 3 
#define input3 4 
#define input4 5 
#define ledf1 10
#define ledf2 11
#define ledt1 8
#define ledt2 9
#define ldr A0
#define buzzer 13

int valor;  // Declara uma variável inteira

/*
Esta função desliga os faróis traseiros
*/
void desled(){
  digitalWrite(ledt1, LOW);
  digitalWrite(ledt2, LOW);
}

void farol(){
  if(analogRead(ldr) >= 685){     // Verifica se a intensidade luminosa identificada pelo sensor ldr tem valor maior ou igual a 685 
    digitalWrite(ledf1, HIGH);    // Como a intensidade luminosa é baixa, acende os faróis da frontais 
    digitalWrite(ledf2, HIGH);
  }
  else{
    digitalWrite(ledf1, LOW);     // Como a intensidade luminosa é alta, apaga os faróis da frontais 
    digitalWrite(ledf2, LOW);
  }
}

void buzina(){          // toca bzina
  tone(buzzer, 250);    // toca buzzer na frequencia 250
  delay(500);           // espera 0.5 segundos
  noTone(buzzer);       // para de tocar buzzer
}

void parar(){           // para o carro
  desled();             // chama a função desled()
  
  digitalWrite(input1, LOW);   // para o motor
  digitalWrite(input2, LOW);
  
  digitalWrite(input3, LOW);   // para o motor
  digitalWrite(input4, LOW);
}

void frente(){                  // vai pra frente
  desled();                     // chama a função desled()
  
  digitalWrite(input1, HIGH);   // liga o motor
  digitalWrite(input2, LOW);
  
  digitalWrite(input3, HIGH);   // liga o motor no mesmo sentido
  digitalWrite(input4, LOW);
  
}

void tras(){                    // vai pra tras
  digitalWrite(ledt1, HIGH);    // acende farois para ré
  digitalWrite(ledt2, HIGH); 
  
  digitalWrite(input1, LOW);    // liga  motor para trás
  digitalWrite(input2, HIGH);
  
  digitalWrite(input3, LOW);    // liga o motor para trás
  digitalWrite(input4, HIGH);
  
}

void esquerda(){
  desled();                     // chama a função desled()
  
  digitalWrite(input1, HIGH);   // gira o motor em um sentido
  digitalWrite(input2, LOW);
  
  digitalWrite(input3, LOW);    // gira o motor 
  digitalWrite(input4, HIGH);
  
}

void direita(){                 // função que vai para direita
  desled();                     // chama a função desled()
  
  digitalWrite(input1, LOW);    // gira o motor em um sentido
  digitalWrite(input2, HIGH);
  
  digitalWrite(input3, HIGH);   // gira o motor no sentido oposto
  digitalWrite(input4, LOW);
  
}

void setup()
{
  Serial.begin(9600);          // inicia a porta serial
  
  pinMode(input1, OUTPUT);     // inicia o input1
  pinMode(input2, OUTPUT);     // inicia o input2
  pinMode(input3, OUTPUT);     // inicia o input3
  pinMode(input4, OUTPUT);     // inicia o input4
  pinMode(ledf1, OUTPUT);      // inicia o ledf 1
  pinMode(ledf2, OUTPUT);      // inicia o ledf2
  pinMode(ledt1, OUTPUT);      // inicia o ledt1
  pinMode(ledt2, OUTPUT);      // inicia o ledt2
}

void loop()
{ 
  farol(); // chama a funcao farol
  
  if(Serial.available() > 0){      // se receber dados do monitor serial
    char comando = Serial.read();  // le os dados
    
    if(comando == 'F'){            // se for F
      frente();                    // chama a funçao frente
    }
    if(comando == 'T'){            // se for T
     tras();                       //chama a função trás
    }
    if(comando == 'E'){            // se for E
      esquerda();                  // chama a função esquerda
    }
    if(comando == 'D'){            // se for D
      direita();                   //chama a função direita
    }
    if(comando == 'P'){            // se for P
      parar();                     // chama a função parar
    }
    if(comando == 'B'){            // se for B
     buzina();                     // chama a função buzina
    }
  }
}
