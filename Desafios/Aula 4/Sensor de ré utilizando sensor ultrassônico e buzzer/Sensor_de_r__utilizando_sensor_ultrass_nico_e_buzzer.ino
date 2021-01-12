#define ultra_echo 11     // define o echo do ultrassonico como 11
#define ultra_trig 12     // define o trig do ultrassonico como 12
#define buzzer 10         // define o buzzer como 10
float distanciaCm = 0;    // variavel que armazena a distancia

// função para calcular a distância
void calc_dist() 
{
  digitalWrite(ultra_trig, LOW);      // desliga o trig (por segurança)
  delay(10);
  
  digitalWrite(ultra_trig, HIGH);     // liga o trig, emitindo o sinal
  delayMicroseconds(10);              // delay de 10 microssegundos
  digitalWrite(ultra_trig, LOW);      // desliga o trig, parando de emitir sinal
  
  float duracaoMili = pulseIn(ultra_echo, HIGH);    // Calcula o tempo desde a saida até o retorno do sinal do trig
  
  distanciaCm = duracaoMili/58;                     // transforma tempo em distancia em cm
}

void setup()
{
  Serial.begin(9600);            // inicia a porta serial
  
  pinMode(buzzer, OUTPUT);       // inicia o buzzer 
  pinMode(ultra_trig, OUTPUT);   // inicia o trig do ultrassonico
  pinMode(ultra_echo, INPUT);    // inicia o echo do ultrassonico
}

void loop()
{
  calc_dist(); // chama a função calc_dist
  
  if(distanciaCm <= 100 && distanciaCm >= 50){     // se a distancia estiver entre 100 cm e 50 cm
    tone(buzzer, 245);                             // buzzer toca uma nota de frequencia 245
    delay(1000);                                   // espera de 1 segundo
    noTone(buzzer);                                // buzzer para de tocar
    delay(1000);                                   // espera de 1 segundo
  }
  if(distanciaCm <= 50 && distanciaCm >= 25){      // se a distancia estiver entre 50 cm e 25 cm
    tone(buzzer, 245);                             // buzzer toca uma nota de frequencia 245
    delay(1000);                                   // espera de 1 segundo
    noTone(buzzer);                                // buzzer para de tocar
    delay(500);                                    // espera de meio segundo
  }
  if(distanciaCm <= 25){                           // se a distancia for menor que 25
    tone(buzzer, 245);                             // toca sem parar na frequencia de 245
  }
  if(distanciaCm >= 100){                          // se a distancia for maior que 100cm
    noTone(buzzer);                                //desliga o buzzer
  }
  delay(10);
}
