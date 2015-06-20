const byte m_nPinTrigger = 8;
const byte m_nPinEcho = 7;

void setup() {
  Serial.begin(115200);
  Serial.println("================================");
  Serial.println("| Détection d'un obstacle avec |");
  Serial.println("|       un capteur HCSR04      |");
  Serial.println("================================");

  Serial.println("");
  Serial.println("Initialisation du capteur");
  init(m_nPinTrigger,m_nPinEcho);
}

void loop() { 
  Serial.print("Distance de l'obstacle : ");
  Serial.println( calculDistance(),DEC);
  delay(10);
}
/**
 * \brief Initialise les deux pins de communication en entrée et en sortie
 * \param p_nPinTrigger numéro de pin pour faire le trigger
 * \param p_nPinEcho numéro de pin pour écouter
 */
void init(const byte p_nPinTrigger, const byte p_nPinEcho){
  pinMode(p_nPinTrigger,OUTPUT);
  pinMode(p_nPinEcho,INPUT);
}

/**
 * \brief  Renvoie la distance d'un obstacle en cm
 * \return Renvoie la distance de l'obstacle en cm 
 */
float calculDistance(){
  sendTrigger();
  float m_fDistanceMS = 331.5 + 0.6 * 20;
  float fEcho = pulseIn(m_nPinEcho,HIGH);
  float fTime = fEcho / 1000.0 / 1000.0 / 2;
  return m_fDistanceMS * fTime * 100;
}

/**
 * \brief Envoie un trigger pour faire l'acquisition d'une distance
 */
void sendTrigger(){
  digitalWrite(m_nPinTrigger,LOW);
  delayMicroseconds(3);
  digitalWrite(m_nPinTrigger,HIGH);
  delayMicroseconds(5);
}

