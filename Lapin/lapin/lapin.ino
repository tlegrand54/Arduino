#include <Servo.h> 

Servo myservo;  // create servo object to control a servo 
// a maximum of eight servo objects can be created 
Servo myservo2;

int pos = 0;    // variable to store the servo position 
int i = 0;

void setup()
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
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

