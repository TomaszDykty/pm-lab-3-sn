//225
/*
#include <Arduino.h>
#include <SPI.h>

#define SPI_CS_PIN 10

typedef int32_t BMP280_S32_t;
typedef uint32_t BMP280_U32_t;

uint8_t configReg = 0, ctrlReg = 0;

uint8_t device_id = 0;
uint8_t rawdata[32];
uint32_t rawVal = 0;
uint32_t degC = 0, press = 0;
double ddegC = 0, dpress = 0;


uint16_t dig_T1 = 0;
int16_t dig_T2 = 0, dig_T3 = 0;
uint16_t dig_P1 = 0;
int16_t dig_P2 = 0, dig_P3 = 0, dig_P4 = 0, dig_P5 = 0;
int16_t dig_P6 = 0, dig_P7 = 0, dig_P8 = 0, dig_P9 = 0;

BMP280_S32_t t_fine;

BMP280_S32_t bmp280_compensate_T_int32(BMP280_S32_t adc_T);
BMP280_S32_t bmp280_compensate_P_int32(BMP280_S32_t adc_p);

void setup()
{
  Serial.begin(9600);
  Serial.setTimeout(4000);

  SPI.begin();
  pinMode(SPI_CS_PIN, OUTPUT);
  digitalWrite(SPI_CS_PIN, HIGH);

  digitalWrite(SPI_CS_PIN, LOW);
  SPI.transfer(0xD0);
  device_id = SPI.transfer(0x00);
  digitalWrite(SPI_CS_PIN, HIGH);
  Serial.print("Device ID: "); Serial.println(device_id, HEX);

  digitalWrite(SPI_CS_PIN, LOW);
  SPI.transfer(0x88);
  for(int i = 0;i<24;i++)
  {
    rawdata[i] = SPI.transfer(0x00);}
    digitalWrite(SPI_CS_PIN, HIGH);

    dig_T1 = (((uint16_t)rawdata[1]) << 8) | ((uint16_t)rawdata[0]);
    dig_T2 = (((int16_t)rawdata[3]) << 8) | ((int16_t)rawdata[2]);
    dig_T3 = (((int16_t)rawdata[5]) << 8) | ((int16_t)rawdata[4]);
    dig_P1 = (((uint16_t)rawdata[7]) << 8) | ((uint16_t)rawdata[6]);
    dig_P2 = (((int16_t)rawdata[9]) << 8) | ((int16_t)rawdata[8]);
    dig_P3 = (((int16_t)rawdata[11]) << 8) | ((int16_t)rawdata[10]);
    dig_P4 = (((int16_t)rawdata[13]) << 8) | ((int16_t)rawdata[12]);
    dig_P5 = (((int16_t)rawdata[15]) << 8) | ((int16_t)rawdata[14]);
    dig_P6 = (((int16_t)rawdata[17]) << 8) | ((int16_t)rawdata[16]);
    dig_P7 = (((int16_t)rawdata[19]) << 8) | ((int16_t)rawdata[18]);
    dig_P8 = (((int16_t)rawdata[21]) << 8) | ((int16_t)rawdata[20]);
    dig_P9 = (((int16_t)rawdata[23]) << 8) | ((int16_t)rawdata[22]);


  configReg = (0x04 << 5) | (0x04 << 2) | 0x00;
  ctrlReg = (0x02 << 5) | (0x05 << 2) | 0x03;
  digitalWrite(SPI_CS_PIN, LOW);
  SPI.transfer(0x75);
  SPI.transfer(configReg);
  SPI.transfer(0x74);
  SPI.transfer(ctrlReg);
  digitalWrite(SPI_CS_PIN, HIGH);
}

void loop() {
  digitalWrite(SPI_CS_PIN, LOW);
  SPI.transfer(0xF7);
  for(int i = 0; i < 6; i++)
  {
    rawdata[i] = SPI.transfer(0x00);
  }
  digitalWrite(SPI_CS_PIN, HIGH);

  rawVal = (((uint32_t)rawdata[3]) << 12) | (((uint32_t)rawdata[4]) << 4) | (((uint32_t)rawdata[5]) >> 4);
  degC = bmp280_compensate_T_int32(rawVal);
  ddegC = degC /100.0;
  Serial.print("Temperatura: "); Serial.print(ddegC); Serial.println("stC");

  rawVal = (((uint32_t)rawdata[0]) << 12) | (((uint32_t)rawdata[1]) << 4) | (((uint32_t)rawdata[2]) >> 4);
  press = bmp280_compensate_P_int32(rawVal);
  dpress = press / 100.0;
  Serial.print("Cisnienei: "); Serial.print(dpress); Serial.println("hPa");

  delay(3000);
}
BMP280_S32_t bmp280_compensate_T_int32(BMP280_S32_t adc_T){
}
BMP280_U32_t bmp280_compensate_P_int32(BMP280_S32_t adc_P){

}

*/



/* nie zrobiont tinker
//324
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



//323 ukończono
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
        Serial.println("LED swieci"); 
      } else {
        digitalWrite(LED_BUILTIN, LOW);
        Serial.println("nie swieci LED ");  
      }
      Serial.println("OK!");
    }else if(!strcmp(paramStr, "blink")) {
      for(int i = 0; i <paramVal; i++) {

        digitalWrite(LED_BUILTIN, HIGH); Serial.println(" swieci LED ");   delay(500);
        digitalWrite(LED_BUILTIN, LOW); Serial.println("nie swieci LED ");   delay(500);
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











