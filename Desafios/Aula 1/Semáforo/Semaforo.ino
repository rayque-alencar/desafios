#define ledRed 11      // define o led vermelho na porta 11
#define ledYellow 10   // define o led amarelo na porta 10
#define ledGreen 9     // define o led verde na porta 9

void setup()
{
  pinMode(ledRed, OUTPUT);          // inicia led vermelho
  pinMode(ledYellow, OUTPUT);       // inicia led amarelo
  pinMode(ledGreen, OUTPUT);        // inicia led verde
}

void loop()
{
  digitalWrite(ledRed, HIGH);             // acende led 
  delay(2000);                            // espera de 2 segundos
  
  digitalWrite(ledRed, LOW);              // apaga o led vermelho
  digitalWrite(ledYellow, HIGH);          // acende o led amarelo
  delay(2000);                            // espera 2 segundos
  
  digitalWrite(ledYellow, LOW);           // apaga o led amarelo
  digitalWrite(ledGreen, HIGH);           // acende o led verde
  delay(2000);                            // espera 2 segundos
  
  digitalWrite(ledGreen, LOW);            // apaga o led verde
  
}
