#define ledBlue 13    // define o led azul como 13
#define ldr A5        // define o fotorresistor como A5

int valor;            // variavel que recebe o valor de luminosidade

void setup()
{
  Serial.begin(9600);         // inicia porta serial
  pinMode(ledBlue, OUTPUT);   // Inicia led azul
}

void loop()
{ 
 valor = analogRead(ldr);           // valor recebe o valor analogico do LDR
  
  if(valor >= 685){                 //se o valor for maior ou igual a 685
   digitalWrite(ledBlue, HIGH);     // liga o led
  }
  else{                             // caso não
    digitalWrite(ledBlue, LOW);     // desliga o led
  }
  
  Serial.println(valor);            // printa o valor no monitor serial
  delay(100);
  
}
