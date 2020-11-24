#include <Arduino.h>

uint8_t ledPin[] ={2,3,4,5,6,7,8,9,10,11,12,13};
String receiveData = "";
int LED_PIN;

void setup() {
  Serial.begin(115200);//Uruchomienie komunikacji
  while (!Serial);//Czekaj na połączenie
  for (int i = 0; i < 14; i++) {
    digitalWrite (ledPin[i], HIGH);  //wprowadzamy wysoki stan na pinach aby zmieniac je
    digitalRead (ledPin[i]);
  }
}

void loop() {
  // wyłączanie diód
  if (Serial.available() > 0){
    Serial.println("wprowadz numer pinu");
    receiveData = Serial.readStringUntil('\n');
    LED_PIN = receiveData.toInt();
    for (int i = 0; i < 14; i++) {
      if (LED_PIN > 0 || digitalRead(ledPin[LED_PIN]) == HIGH)
      {
        digitalWrite(ledPin[LED_PIN - 2],LOW);
      } else {
      break;}
   
  }}
  // włączanie diód
  if (Serial.available() > 0){
    Serial.println("wprowadz numer pinu");
    receiveData = Serial.readStringUntil('\n');
    LED_PIN = receiveData.toInt();
    for (int i = 0; i < 14; i++) {
      if (LED_PIN > 0 || digitalRead(ledPin[LED_PIN]) == LOW)
      {
        digitalWrite(ledPin[LED_PIN - 2],HIGH);
      } else {
      break;} 
     
  }} 
}