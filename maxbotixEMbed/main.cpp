#include <mbed.h>
#include "MaxSonar.h"

#define pinTX p9
#define pinRx p10

int main()
{   
  printf("\r\n");
  printf("\rDebut de la fonction main\n");
  printf("\r\n");
  MaxSonar *range;
  float r;
  
  // Create and configure object for 3.3V powered LV-series device, 
  // accessed with analog reads (in cm) on p16, triggered by p7.
  range = new MaxSonar(MS_LV, MS_ANALOG, p7, p16);
  range->setVoltage(3.3);
  range->setUnits(MS_CM);
  
  while(1) {
    // Trigger read, wait 49ms until ranger finder has
    // finished, then read. 
    range->triggerRead();
    wait_ms(49);
    r = range->read();
           
    // Print and delay 0.5s.
    printf("Range: %.3f cm\n", r);
    wait(0.5);
  }
 

  printf("\r\n");
  printf("\rFin du match et du code\n");
  return EXIT_SUCCESS;
}




