#include <Servo.h> 

Servo servoDroit;  
Servo servoGauche;

int i = 0;

/**
 *
 */
void setup()
{ 
  servoDroit.attach(9);   
  servoGauche.attach(11);
  i = 0;
} 


void loop() 
{ 
  for(i = 0; i <= 70; i += 1)
  {
    servoDroit.write(i);
    delay(10);
    servoGauche.write(i);
    delay(10);
  }
  
  for(i = 70; i >= 0; i -=1)
  {
    servoDroit.write(i);
    delay(10);
    servoGauche.write(i);
    delay(10);
  }
} 

