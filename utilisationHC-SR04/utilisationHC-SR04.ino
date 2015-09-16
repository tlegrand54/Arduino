
#include "HCSR04.h"

const byte m_byPinTrigger = 8;
const byte m_byPinEcho = 7;

const byte m_byPinTrigger2 = 4;
const byte m_byPinEcho2 = 6;

HCSR04 sensorLeft(m_byPinEcho,m_byPinTrigger);
HCSR04 sensorRight(m_byPinEcho2,m_byPinTrigger2);

void setup() {
  Serial.begin(115200);
  Serial.println("================================");
  Serial.println("| Détection d'un obstacle avec |");
  Serial.println("|       un capteur HCSR04      |");
  Serial.println("================================");
}

void loop() { 
  Serial.print("Distance de l'obstacle sensorLeft : ");
  Serial.println( sensorLeft.calculDistance(),DEC);
  Serial.print("Distance de l'obstacle sensorRight : ");
  Serial.println( sensorRight.calculDistance(),DEC);
  delay(10);
}

