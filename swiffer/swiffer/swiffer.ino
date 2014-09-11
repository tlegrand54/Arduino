/*
    Auteur : Thomas LEGRAND
    
                Code de fonctionnement du robot swiffer
                
    Remarque : Pour éteindre les moteurs, il faut les mettre à l'état haut et pour les rallumer il faut les mettre à l'état bas.
                
*/

#include <Servo.h> 

//  Définition des pins de controles des moteurs et des capteurs
const int moteurD = 6;   //  pin de controle du moteur droite
const int moteurG = 7;   //  pin de controle du moteur gauche
const int capteurD = 13;  //  pin de retour du capteur droit
const int capteurG = 12;  //  pin de retour du capteur gauche


//  variable d'état du capteur
int EtatCapteurG = 0;   
int EtatCapteurD = 0;

//  Creation de l'objet myservo de la bibliotheque servo.h et de la position initiale
Servo myservo;
int pos = 90;

void setup()
{
  //  initialisation des pins en sortie
  pinMode(moteurG, OUTPUT);
  pinMode(moteurD, OUTPUT);
  
  //  initialisation des pins en entrée
  pinMode(capteurG, INPUT);
  pinMode(capteurD, INPUT);  
  
  //  affectation de la pin pour communiquer avec le servo
  myservo.attach(9);
  myservo.write(pos);  //  mise en position initiale du servo au démarrage de l'Arduino
  
  digitalWrite(moteurG, LOW);  //  J'allume deux les moteurs
  digitalWrite(moteurD, LOW);
}

void loop()
{
    
    EtatCapteurG = digitalRead(capteurG);  //  réception de l'état du capteur gauche à chaque bloucle
    EtatCapteurD = digitalRead(capteurD);  //  réception de l'état du capteur droit à chaque bloucle
    
    
    if (EtatCapteurG == HIGH)
    {
      digitalWrite(moteurD, HIGH);  //  J'éteins le moteur droit
    }
    else if (EtatCapteurD == HIGH)
    {
      digitalWrite(moteurG, HIGH);  //  J'éteins le moteur gauche
    }
    else if((EtatCapteurG == HIGH) && (EtatCapteurD == HIGH))
    {
      digitalWrite(moteurG, HIGH);  //  J'éteins les deux moteurs
      digitalWrite(moteurD, HIGH);
    }
    else
    {
      digitalWrite(moteurG, LOW);  //  J'allume deux les moteurs
      digitalWrite(moteurD, LOW);
    }
}
