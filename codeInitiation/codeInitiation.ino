/*
  Code Initiation
  
  switch les leds de on à off
 */
 
volatile boolean sens = false; /**< Détermine le sens du chenillard */
 
/**
 * \brief SETUP
 *         Boucle d'initialisation des I/O et autres fonctions du programme
 */ 
void setup()
{ 
  for(int i = 6; i<14;i++) /**< Initialisation des pins en sortie */
  {
    pinMode(i,OUTPUT);
  }
  
  attachInterrupt(0,changeSens,RISING); /**< Création de l'intérruption */
}

/**
 * \brief LOOP
 *         Boucle principale du programme, boucle infinie
 */
void loop() 
{
  if(sens)
  {
     for(int i = 6; i< 14; i++) 
     { 
        activate(i);
        delay(100);
     }
  }
  else
  {
    for(int i = 13; i > 5; i--) 
     { 
        activate(i);
        delay(100);
     }
  }
}


/**
 * \brief ACTIVATE
 *         Boucle permettant d'allumer les leds dans n'importe quel sens
 */
void activate(int i) {
  int j;
  for(j = 6; j < 14; j++)
  {
    if(i == j)
      digitalWrite(j, HIGH);      
    else
      digitalWrite(j, LOW);
  }
}

/**
 * \brief CHANGESENS
 *         Boucle exécuté quand l'Arduino détecte une interruption matériel
 */
void changeSens()
{
  sens = !sens;
}
