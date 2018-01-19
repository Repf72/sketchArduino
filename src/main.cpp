#include <Arduino.h>

String nivelesHor[3]= {"Izquierda", "Centro", "Derecha"};
String nivelesVer[3]= {"Abajo", "A nivel", "Arriba"};
String etiqHor, etiqVer;
int nivel[2] = {2, 3};
int poteHor = A0;
int poteVer = A1;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int lectHor = analogRead(poteHor);
  int lectVer = analogRead(poteVer);
  float voltHor = lectHor*5.0/1023.0;
  float voltVer = lectVer*5.0/1023.0;

  //Niveles horizontales
  if (voltHor <= nivel[0]) {
    etiqHor = nivelesHor[0];
  }
  else if (voltHor > nivel[0] && voltHor <= nivel[1]){
    etiqHor = nivelesHor[1];
  }
  else{
    etiqHor = nivelesHor[2];
  }

  //Niveles verticales
  if (voltVer <= nivel[0]) {
    etiqVer = nivelesVer[0];
  }
  else if (voltVer > nivel[0] && voltVer <= nivel[1]){
    etiqVer = nivelesVer[1];
  }
  else{
    etiqVer = nivelesVer[2];
  }

  delay(100);
  Serial.println("Vertical (" + String(voltVer) + "): " + etiqVer
        + " - Horizontal (" + String(voltHor) + "): " + etiqHor);
}
