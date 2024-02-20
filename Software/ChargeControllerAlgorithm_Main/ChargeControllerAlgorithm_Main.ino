/*
See https://github.com/Brady-Beecham/Capstone-Team-PowerHouse for more information
*/

#include "ChargeControllerAlgorithm_Main.h"

static bool SolarPanelIsGeneratingPower(void);
static void PutMCUIntoSleepMode(void);
static void DelayBeforeRestartingAlgorithm(void);

void setup() 
{

}

void loop() 
{
  if(SolarPanelIsGeneratingPower())
  {

  }
  else
  {
    PutMCUIntoSleepMode();
  }

  DelayBeforeRestartingAlgorithm();
}

bool SolarPanelIsGeneratingPower()
{

}

void PutMCUIntoSleepMode()
{

}

void DelayBeforeRestartingAlgorithm()
{

}
