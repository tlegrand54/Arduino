#ifndef MINITEL_H_
#define MINITEL_H_

#include "PololuQik2/PololuQik2.h"
#include "mbed.h"

#define AMOTEURD 27
#define AMOTEURG 32
#define RMOTEURD -27
#define RMOTEURG -27

class Minitel
{
private:
    PololuQik2 qik;

    void seuilStack(int isLeft);

public:
    /**
     * \brief Initialisation de la qik pour faire bouger le robot
     *
     * \param txPin
     * \param rxPin
     * \param resetPin
     * \param errorPin
     */
    Minitel(PinName txPin, PinName rxPin, PinName resetPin, PinName errorPin);

    /**
     * \brief Fait avancer le minitel en suivant la ligne
     *
     * \param rate
     * \param sensorRight
     * \param sensorLeft
     */
    void trackLine(double rate,int sensorRight,int sensorLeft);

    /**
     * \brief fait avancer le robot
     *
     * \param rate
     */
    void go(int rate);

    /**
     * \brief Fait reculer le minitel en suivant la ligne
     *
     * \param rate
     * \param sensorRight
     * \param sensorLeft
     */
    void reculer(double rate,int sensorRight,int sensorLeft);

    /**
     * \brief Stop the left motor
     */
    void stopMotorLeft();

    /**
     * \brief Stop the right motor
     */
    void stopMotorRight();

    /**
     * \brief Stop the both motors
     */
    void stopMotors();
};
#endif
