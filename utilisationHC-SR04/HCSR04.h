#ifndef H_HCSR04_H
#define H_HCSR04_H

#include "Arduino.h"

class HCSR04{
private :

	 byte m_byPinEcho;
	 byte m_byPinTrigger;
	
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
	HCSR04(byte p_byPinEcho, byte p_byPinTrigger);
	
	/**
	 * \brief calcul the distance between the sensor and an obstacle
	 * \return return the distance
	 */
	float calculDistance();

 /**
  * \brief Enable to know if an obstacle is present
  * \param p_sNCapture define the numbre of capture 
  * \param p_sLimite define the limit for say if there is an obstacle
  * \param p_sInterval interval between two calculDistance
  * \return True if an obstacle is present otherwise False
  */
  bool isObstacle(short p_sNCapture, short p_sLimite, short p_sInterval);
};
#endif


	 
	
	
