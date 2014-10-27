
int ledPin[8] = {6,7,8,9,10,11,12,13}; // Numéro de pin des 8 LEDs
int bouton = 2;
int cpt = 0;

void setup()
{
  for(cpt=0;cpt<8;cpt++)
  {
    pinMode(13, OUTPUT);
  }
  attachInterrupt(0,affichage,CHANGE);
}

void loop()
{
  for(cpt=0;cpt<8;cpt++)
  {
    digitalWrite(13,HIGH);
    delay(100);
  }
  
  delay(100);
  
  for(cpt=0;cpt<8;cpt++)
  {
    digitalWrite(13,LOW);
    delay(100);
  }
}

void affichage()
{
  cpt = 0;
  for(cpt=0;cpt<8;cpt++)
  {
    digitalWrite(ledPin[cpt],HIGH);
    delay(100);
  }
  
  delay(100);
  
  for(cpt=0;cpt<8;cpt++)
  {
    digitalWrite(ledPin[cpt],LOW);
    delay(100);
  }
}
