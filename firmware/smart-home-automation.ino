#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11); 
// Arduino D10 = RX
// Arduino D11 = TX

const int LIGHT1 = 4;
const int FAN1   = 5;
const int LIGHT2 = 6;
const int FAN2   = 7;

void setup() {

  pinMode(LIGHT1, OUTPUT);
  pinMode(FAN1, OUTPUT);
  pinMode(LIGHT2, OUTPUT);
  pinMode(FAN2, OUTPUT);

  // For an active-LOW relay:
  digitalWrite(LIGHT1, HIGH);
  digitalWrite(FAN1, HIGH);
  digitalWrite(LIGHT2, HIGH);
  digitalWrite(FAN2, HIGH);

  Serial.begin(9600);
  BT.begin(9600);

  Serial.println("Bluetooth Home Automation Ready");
}

void loop() {

  if (BT.available()) {

    char command = BT.read();

    Serial.print("Received: ");
    Serial.println(command);

    switch(command) {

      case 'A':
        digitalWrite(LIGHT1, LOW);
        break;

      case 'a':
        digitalWrite(LIGHT1, HIGH);
        break;

      case 'B':
        digitalWrite(FAN1, LOW);
        break;

      case 'b':
        digitalWrite(FAN1, HIGH);
        break;

      case 'C':
        digitalWrite(LIGHT2, LOW);
        break;

      case 'c':
        digitalWrite(LIGHT2, HIGH);
        break;

      case 'D':
        digitalWrite(FAN2, LOW);
        break;

      case 'd':
        digitalWrite(FAN2, HIGH);
        break;
    }
  }
}