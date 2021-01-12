#define ledRed 13 // Define led vermelho no pino 13
#define ledBlue 8 // Define led azul no pino 8

void setup()
{
pinMode(ledRed, OUTPUT);           // Saída de sinal digital
pinMode(ledBlue, OUTPUT);          // Saída de sinal digital
}

// Função loop() executa inifitamente
void loop()
{
digitalWrite(ledRed, HIGH);        // Acende o Led vermelho
delay(500);                        // Paraliza o código 500 milissegundos
digitalWrite(ledRed, LOW);         // Desliga o Led vermelho
digitalWrite(ledBlue, HIGH);       // Acende o Led azul
delay(500);                        // Paraliza o código 500 milissegundos
digitalWrite(ledBlue, LOW);        // Desliga o Led azul 
}
