#include <Arduino.h>

#define LED_RED 10

void setup(){
  //put your setup code here, to run once:
  pin mode(LED_RED, OUTPUT);
}

void loop(){
  //put your main code here, to run repeatedly:
  digitalWrite(LED_RED, High);
  delay(500);
  digitalWrite(LED_RED, LOW);
  delay(500);
}

