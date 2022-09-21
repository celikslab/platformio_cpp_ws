#include <Arduino.h>
#include "proj_uart.hpp"


void setup() 
{
  project.initialize();
}



void loop() 
{
  project.scheduler();
  delay(10);
}