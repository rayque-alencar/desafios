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
