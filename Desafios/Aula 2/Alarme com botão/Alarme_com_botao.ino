#define buttonPin 2       // define o botão na porta 2
#define buzzer 13         // define o buzzer na porta 13
int buttonStatus = 0;     // variavel bool para saber se o botão foi pressionado

void setup()
{
  pinMode(buzzer, OUTPUT);        // Inicia buzzer
  pinMode(buttonPin, INPUT);      // Inicia botão
}

void loop()
{
  buttonStatus = digitalRead(buttonPin);       // buttomStatus recebe se o botão foi apertado
  if(buttonStatus == HIGH){                    // se tiver apertado
    tone(buzzer, 265);                         // liga o buzzer com frequencia 265
  }
  else{                                        // caso não tiver apertado
    noTone(buzzer);                            // desliga o buzzer
  }
}
