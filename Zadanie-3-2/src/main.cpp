
//323
#include <Arduino.h>
#include <stdio.h>

char rxBuff[32];
int bytesNo = 0;
char paramStr[16];
int paramVal = 0;

void setup() {
  Serial.begin(9600);
  Serial.setTimeout(4000);
  
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  bytesNo = Serial.readBytesUntil('\r',rxBuff, sizeof(rxBuff) - 1);
  
  sscanf(rxBuff, "%s %d", paramStr, &paramVal);
  
  if (bytesNo) {
    Serial.print("Wykonuje ...");
    if(!strcmp(paramStr, "led")){
      if(paramVal) {
        digitalWrite(LED_BUILTIN, HIGH); 
      } else {
        digitalWrite(LED_BUILTIN, LOW); 
      }
      Serial.println("OK!");
    }else if(!strcmp(paramStr, "blink")) {
      for(int i = 0; i <paramVal; i++) {
        digitalWrite(LED_BUILTIN, HIGH); delay(500);
        digitalWrite(LED_BUILTIN, LOW); delay(500);
      }
      Serial.println("OK!");
    } else {
      Serial.println("Blad!");
    }
  }
  for (int i = 0; i < Serial.available(); i++) {
    Serial.read();
  }
  
  for(int i = 0; i < sizeof(rxBuff); i++) {
    rxBuff[i] = 0;
  }
}








/*
//322 ukończono
#include <Arduino.h>
#define BUTTON 2

int stanPrzycisku;
int poprzedniStanPrzycisku = LOW;
unsigned long poprzedniCzas = 0;
unsigned int liczba_nacisniec = 0;

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT);
}

void loop() {
  int odczyt = digitalRead(BUTTON);

  if (odczyt != poprzedniStanPrzycisku) {
    poprzedniCzas = millis();
  }

  if ((millis() - poprzedniCzas) > 50) {
    if (odczyt != stanPrzycisku) {
      stanPrzycisku = odczyt;
      if (stanPrzycisku == HIGH) {
        liczba_nacisniec++;

        Serial.print("Liczba nacisniec przycisku: ");
        Serial.println(liczba_nacisniec);
      }
    }
  }

  poprzedniStanPrzycisku = odczyt;
}

*/



//321 ukończono
/*
#include <Arduino.h>
uint8_t i = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("Witaj programisto!");
}

void loop() {
 Serial.println(i);
delay(2000);
}
*/



/*
//324działa jeszcze nie aktywowany
#include <Arduino.h>
#include <stdint.h>

#define FOSC 16000000
#define BAUD 9600
#define MY_UBRR (FOSC / 16 / BAUD - 1)
#define USE_UART_RX_IRQ 1
char ReceivedChar;
char Message[] = "Hello";
char * pMessage = Message;
void setup(){
  UBRR0H = (MY_UBRR >> 8);
  UBRR0L = MY_UBRR;
  UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
  UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);

  while(*pMessage){
    while ( !( UCSR0A & (1<<UDRE0)) );
    UDR0 = *pMessage;
    pMessage++;
  }

#if (USE_UART_RX_IRQ == 1)
  UCSR0B |= (1 << RXCIE0);
#endif
}
void loop(){
#if (USE_UART_RX_IRQ == 0)
  while (!(UCSR0A & (1 << RXC0)))
  ;
  ReceivedChar = UDR0;
  while (!(UCSR0A & (1 << UDRE0)))
  ;
  UDR0 = ReceivedChar;
#endif
}
#if (USE_UART_RX_IRQ == 1)
ISR (USART_RX_vect){
  ReceivedChar = UDR0;
  UDR0 = ReceivedChar;
}
#endif

*/








