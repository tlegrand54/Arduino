/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, INPUT);
}

void activate(int i) {
  int j;
  for(j = 10; j < 14; j++){
    if(i == j)
      digitalWrite(j, HIGH);      
    else
      digitalWrite(j, LOW);
  }
}

// the loop function runs over and over again forever
void loop() {
  int x = digitalRead(9);
  int i;
  if(x == HIGH) {
    for(i = 10; i< 14; i++) { 
      activate(i);
      delay(100);
    }
    activate(0);
  }
}
