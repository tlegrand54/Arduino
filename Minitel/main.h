#ifndefine MAIN_H
#define MAIN_H

/* #####################  AUTRES DEFINE  ############################ */
#define HAND_TROLL_TIMEOUT 3.5
#define TAILLE_MAX 5
#define DISTANCE_CAPTEUR 40
#define DISTANCE_FRESQUE 8
#define SEUIL 4
#define SEUIL_STACK 6
#define ANGLE_MAX_TIMER 5

// Dance !
#define DANCE_ROTATION_TIME 5
#define DANCE_OPENING_TIME 3
#define DANCE_CLOSING_TIME 3
#define DANCE_MOVING_TIME 5

// POM POM !
#define POM_POM_ROTATION_TIME 5
#define POM_POM_OPENING_TIME 2
#define POM_POM_CLOSING_TIME 2
#define POM_POM_MOVING_TIME 3

/* ################################################################## */

/* ##################  ENTREES SUR L'MBED  ########################## */
#define SDA p9
#define SCL p10

/* ======== define pour la qik de contrôle des moteurs  ============= */
#define TX_QIK p13
#define RX_QIK p14
#define RESET_QIK p15
#define ERROR_QIK p16

/* ======= define pour la qik de contrôle du moteur clavier  ======== */
#define TX_QIK_P p28
#define RX_QIK_P p27
#define RESET_QIK_P p25
#define ERROR_QIK_P p26

/* ======= define des autres entrées sur la Mbed  =================== */
#define COULEUR_PIN p7
#define TIRETTE_PIN p18
#define CAPTEUR_DROIT p22
#define CAPTEUR_GAUCHE p21

/* ################################################################## */

/* ###################  SORTIES SUR L'MBED  ######################### */
#define LED_DROITE p19
#define LED_GAUCHE p20

/* ################################################################## */

/* ###################  DECLARATION DES FONCTIONS ################### */

/**
 * Permet de faire descendre ou de remonter le clavier
 */
void actionClavier(int vitesse, int tempsAttente);

/**
 * Fait avancer le robot en suivant la ligne
 */
void avancer(double rate);

/**
 * Initialise les QIK au démarrage du robot pour qu'elles ne soient pas
 * en défaut
 */
void init();

/**
 * Fait reculer le robot en suivant la ligne
 */
void reculer(double rate);

/**
 * Fonction qui gére le match
 */
void match();

/**
 * Calcule et renvoie la moyenne d'un tableau
 */
 int moyenne(int tab[]);
 
 void seuilStack(int isLeft);
 
 // Yeah ! =)
 void iLikeToMoveItMoveIt();
 void pomPomGirl();
 
 /**
  * Rempli un tableau en décalant et supprimant le premier élément
  */
 /// tab est le tableau dans lequel il faut mettre le nouvelle elet
 /// nvlElt le nouvelle elet à mettre dans le tableau
 void remplirTab(int tab[], int nvlElt);
/* ################################################################## */
#endif
