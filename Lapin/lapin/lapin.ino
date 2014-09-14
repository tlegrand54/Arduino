#include <Servo.h> 

Servo myservo;  
Servo myservo2;

int pos = 0; 
int i = 0;

/**
 *
 */
void setup()
{ 
  myservo.attach(9);   
  myservo2.attach(10);

  myservo.write(10);
  myservo2.write(0);
} 


void loop() 
{ 
  for(i=0;i<100;i++)
  {
    myservo.write(i);
    delay(10);
    myservo2.write(100-i);
    delay(10);
  }
  
  delay(10);
  
  for(i=100;i>0;i--)
  {
    myservo.write(i);
    delay(10);
    myservo2.write(100-i);
    delay(10);
  }
  
  delay(10);
  
} 

