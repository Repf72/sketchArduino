#include <Arduino.h>

String bajo = "Buenos dias";
String medio = "Buenas tardes";
String alto = "Buenas noches";

int pote = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lectura = analogRead(pote);
  float voltaje = lectura*5.0/1023.0;
  //Serial.print(voltaje);
  //Serial.print("Volts \n");

  if (voltaje <= 1.5) {
    Serial.println(String(voltaje) + " " + bajo);
  }
  else if (voltaje > 1.6 && voltaje < 3.5){
    Serial.println(String(voltaje) + " " + medio);
  }
  else{
    Serial.println(String(voltaje) + " " + alto);
  }
  delay(100);
}
