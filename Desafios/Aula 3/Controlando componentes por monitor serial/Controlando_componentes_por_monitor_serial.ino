#define ledYellow 12     // define ledYellow como 12
#define ledBlue 9        // define ledGreen como 9
#define ledGreen 5       // define ledGreen como 5

String serialData;       // variavel string que recebe o valor do monitor serial

void setup()
{
  Serial.begin(9600);    // inicia a porta serial
  
  pinMode(ledYellow, OUTPUT);      // inicia o led amarelo
  pinMode(ledBlue, OUTPUT);        // inicia o led azul
  pinMode(ledGreen, OUTPUT);       // inicia o led verde
}

void loop()
{
  if(Serial.available() > 0){                             // se receber informacoes
    serialData = Serial.readString();                     // SerialData recebe informacao digitada no monitor
    if(serialData == "Amarelo"){                          // se for digitado Amarelo
      digitalWrite(ledYellow, !digitalRead(ledYellow));   // acende/apaga led amarelo
    }
    if(serialData == "Azul"){                             // se for digitado Azul
      digitalWrite(ledBlue, !digitalRead(ledBlue));       // acende/apaga led azul
    }
    if(serialData == "Verde"){                            // se for digitado Verde
      digitalWrite(ledGreen, !digitalRead(ledGreen));     // acende/apaga led verde
    }
  }
}
