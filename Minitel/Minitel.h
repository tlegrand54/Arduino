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
    int cptStack=0, cptPosition=0, angleGo=0;

    void seuilStack(int isLeft);

public:
    /**
     * \brief Constructor 
     *
     * \param txPin
     * \param rxPin
     * \param resetPin
     * \param errorPin
     */
    Minitel(PinName txPin, PinName rxPin, PinName resetPin, PinName errorPin);

    /**
     * \brief go and track the line
     *                    
     * \param rate
     * \param sensorRight status of the right sensor
     * \param sensorLeft status of the left sensor
     */
    void trackLine(double rate,int rightSensor,int leftSensor);

    /**
     * \brief go without track the line
     *
     * \param rate
     */
    void go(int rate);

    /**
     * \brief Fait reculer le minitel en suivant la ligne
     *
     * \param rate
     * \param sensorRight status of the right sensor
     * \param sensorLeft status of the left sensor
     */
    void goBackward(double rate,int rightSensor,int leftSensor);

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

    /**
     * \brief Destructor
     */
    ~Minitel();
};
#endif
