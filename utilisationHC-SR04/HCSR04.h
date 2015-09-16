#ifndef H_HCSR04_H
#define H_HCSR04_H

#include "Arduino.h"

Public class HCSR04{
    Private :

    const byte m_nPinTrigger = 0;
    const byte m_nPinEcho = 0;

    /**
     *  \brief send a trigger for receive a distance
     */
    void sendTrigger();

    Public :

    /**
     * \brief Constructor
     *
     * \param p_nPinTrigger number of the pin for send the trigger
     * \param p_nPinEcho number of the pin for receive the distance
     */
    HCSR04(byte p_nPinTrigger, byte p_nPinEcho);
    
    /**
     * \brief calcul the distance with an obstacle
     * 
     * \return it's the distance with an obstacle
     */
     float calculDistance();
};

#endif


