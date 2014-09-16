#include <SoftwareSerial.h>
#include "PololuQik.h"

PololuQik2s9v1 qik(4, 5, 2);

int numError = 3;
int numReset = 2;

/**
 * \brief Boucle d'initialisation 
 */

void setup()
{
  Serial.begin(115200);
  
  pinMode(numError,INPUT);
  pinMode(numReset,OUTPUT);
 
  qik.init(9600);  
}


/**
 *\brief Boucle principale du programme
 */
void loop()
{
  Serial.println(qik.getErrors(),HEX);
  
  qik.setM0Speed(127);
  qik.setM1Speed(127);

  delay(100);
  
}
  
  
