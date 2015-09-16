#include "HCSR04.h"

HCSR04::HCSR04(byte p_byPinEcho, byte p_byPinTrigger)  : m_byPinEcho(p_byPinEcho), m_byPinTrigger(p_byPinTrigger)
{
	pinMode(m_byPinEcho, INPUT);
	pinMode(m_byPinTrigger, OUTPUT);
}

void HCSR04::sendTrigger()
{
  digitalWrite(m_byPinTrigger,LOW);
  delayMicroseconds(3);
  digitalWrite(m_byPinTrigger,HIGH);
  delayMicroseconds(5);
}

float HCSR04::calculDistance()
{
  sendTrigger();
  
  float m_fDistanceMS = 331.5 + 0.6 * 20;
  float fEcho = pulseIn(m_byPinEcho,HIGH);
  float fTime = fEcho / 1000.0 / 1000.0 / 2;
  
  return m_fDistanceMS * fTime * 100;
}

bool HCSR04::isObstacle(short p_sNCapture, short p_sLimite, short p_sInterval)
{
  float fMoyenne = 0.0;

  for(int i = 0; i < p_sNCapture; i++)
  {
      fMoyenne += calculDistance();
      delayMicroseconds(p_sInterval);
  }

  return (fMoyenne / p_sNCapture) < p_sLimite;
}

