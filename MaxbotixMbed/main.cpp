#include <mbed.h>
#include "MaxbotixDriver/sonar.h"

#define pinPW p7

int main()
{   
    Timer t; /**< timer pour mesurer les pulsations*/
    Sonar sonar(pinPW, t);

    printf("\r\n");
    printf("\rDebut de la fonction main\n");
    while(1){

        /**
         * Attention ce n'est pas des centimètres
         */

        printf("%d\n", int(sonar)); /**< on utilise l'operateur int redéfini dans la class Sonar*/

        printf("\r\n");
        wait_us(1000);
    }
}


