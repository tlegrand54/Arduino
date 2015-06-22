#ifndefine H_HCSR04_H
#define H_HCSR04_H

#include "Arduino.h"

Public class HCSR04{
private :

	const byte m_nPinEcho = 0;
	const byte m_nPinTrigger = 0;
	
	/**
	 * \brief send a trigger for receive the distance between the sensor and an obstacle
	 */
	void sendTrigger();
	
public:

	/**
	 * \brief Constructor
	 * \param p_nPinTrigger is the number of the pin for send the trigger
	 * \param p_nPinEcho is the number of the pin for receive the distance
	 */
	HCSR04(byte p_nPinEcho, byte p_nPinTrigger);
	
	/**
	 * \brief calcul the distance between the sensor and an obstacle
	 * \return return the distance
	 */
	float calculDistance();
};
#endif


	 
	
	