#include "Minitel.h"

Minitel::Minitel(PinName TxPin, PinName RxPin, PinName ResetPin, PinName ErrorPin)
{
    /*
     * Instanciation de la qik
     */
    qik = new PololuQik2(TxPin, RxPin, ResetPin, ErrorPin, NULL, true);
    
    /*
     * Initialisation de la qik
     */
    do
    {
        qik.begin();
    } while(qik.hasFrameError() || qik.hasDataOverrunError() || qik.hasTimeoutError());
}

Minitel::avancer(double rate,int capteurDroit,int capteurGauche)
{
    printf("\r%f : Avance\n", timeEnd.read());

    qik.setMotor0Speed((int)AMOTEURD*rate);
    qik.setMotor1Speed((int)AMOTEURG*rate);

    if(!capteurDroit && !capteurGauche)
    {
        qik.setMotor0Speed((int)RMOTEURD*rate);
        qik.setMotor1Speed((int)RMOTEURG*rate);
    }

    /*
     * Tourne à gauche
     */
    if(!capteurDroit)
    {
        printf("\r%f : Gauche !\n", timeEnd.read());
	if(angleGo) {
	    cptPosition ++;
	    seuilStack(1);
	}
        qik.setMotor1Speed((int)RMOTEURG*rate);
    }

    /*
     * Troune à droite
     */
    if(!capteurGauche)
    {
        printf("\r%f : Droite !\n", timeEnd.read());
        if(angleGo) {
	    cptPosition --;
	    seuilStack(0);
	}
        qik.setMotor0Speed((int)RMOTEURD*rate);
    }    
}

Minitel::reculer(double rate)
{
    printf("\r%f : Reculer\n", timeEnd.read());

    qik.setMotor0Speed((int)RMOTEURD*rate);
    qik.setMotor1Speed((int)RMOTEURG*rate);

    if(!capteurDroit && !capteurGauche)
    {
        qik.setMotor0Speed((int)RMOTEURD*rate);
        qik.setMotor1Speed((int)RMOTEURG*rate);
    }

    /*
     * Tourne à gauche
     */
    if(!capteurDroit)
    {
        printf("\r%f : Gauche !\n", timeEnd.read());
        if(angleGo) {
	    cptPosition ++;
	    seuilStack(1);
	}
        qik.setMotor1Speed((int)RMOTEURG*rate);
    }

    /*
     * Troune à droite
     */
    if(!capteurGauche)
    {
        printf("\r%f : Droite !\n", timeEnd.read());
        if(angleGo) {
	    cptPosition --;
	    seuilStack(0);
	}
        qik.setMotor0Speed((int)RMOTEURD*rate);
    }
}

Minitel::seuilStack(int isLeft)
{
    if(cptStack >= 0 && isLeft)
    {
	++cptStack;
    }
    else if(cptStack <= 0 && isLeft)
    {
	cptStack = 1;
    }
    else if(cptStack >= 0 && !isLeft)
    {
	cptStack = -1;
    }
    else if(cptStack <=0 && !isLeft)
    {
	--cptStack;
    }
}

