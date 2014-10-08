/*
  Maxbotix simple test

  Instructions:
  - At least one of: (comment the appropriate code below)
    * PW is digital pin 8
    * TX is digital pin 6
    * AN is analog pin A0
  - Change code below according to your model (LV, XL and
  HRLV supported)

  Note:
  For convenience, the getRange method will always return centimeters.
  You can use convert fuctions to convert to another unit (toInches and
  toCentimeters are available)

*/
#include <PololuQik.h>
#include <SoftwareSerial.h>
#include <Maxbotix.h>

Maxbotix rangeSensorD(8, Maxbotix::TX, Maxbotix::LV);
Maxbotix rangeSensorG(13, Maxbotix::TX, Maxbotix::LV);
PololuQik qik(3, 4, 10);

void setup()
{
  Serial.begin(9600);
  qik.init();
}

void loop()
{
  unsigned long start;
  
  Serial.println("Reading...");

  start = millis();
  Serial.print("TX droit: ");
  Serial.print(rangeSensorD.getRange());
  Serial.print("cm - ");
  Serial.print(millis() - start);
  Serial.println("ms");

  Serial.println();

  start = millis();
  Serial.print("TX gauche: ");
  Serial.print(rangeSensorG.getRange());
  Serial.print("cm - ");
  Serial.print(millis() - start);
  Serial.println("ms");
  
  Serial.println();
  delay(500);
  
  qik.setM0Speed(127);
  qik.setM1Speed(127);
  delay(500);
  qik.setM0Speed(0);
  qik.setM1Speed(0);
}

