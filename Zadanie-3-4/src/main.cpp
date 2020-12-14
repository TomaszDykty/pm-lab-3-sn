//341
//Uwagi nie skompilował się u mnie nie wiem czemu ale na tinkercad dział
#include <Arduino.h>
#define PIN_G 5
#define PIN_B 6
#define PIN_R 9

int r,g,b;

void setup() {
  pinMode(PIN_G, OUTPUT);
  pinMode(PIN_B, OUTPUT);
  pinMode(PIN_R, OUTPUT);
}

void loop() {
  analogWrite(PIN_R, rand());
  analogWrite(PIN_G, rand());
  analogWrite(PIN_B, rand());
  delay(1000);
}

