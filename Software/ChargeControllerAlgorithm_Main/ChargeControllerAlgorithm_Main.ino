/*
See https://github.com/Brady-Beecham/Capstone-Team-PowerHouse for more information
*/

#include "ChargeControllerAlgorithm_Main.h"

#define CURRENT_SENSOR_PIN A0
#define MPPC_VOUT_PIN A1
#define PWM_CONTROL_PIN 
#define MINIMUM_INCREMENT  0x02 //TODO: Find a good increment amount
#define MINIMUM_DECREMENT  2 * MINIMUM_INCREMENT

static bool SolarPanelIsGeneratingPower(void);
static void UpdateChargingDutyCycle(void);
static void DisableBatteryCharging(void);
static void PutMCUIntoLowPowerMode(void);
static void DelayBeforeRestartingAlgorithm(void);

static void StoreCurrentAmpsOut(void);
static void IncrementDutyCycle(void);
static void DoubleDecrementDutyCycle(void);
static void ZeroTheDutyCycle(void);
static bool OutputCurrentHasBeenHarmed(void);

static uint16_t ReadCurrentSensor(void);
static uint16_t ReadSolarVout(void);
static void WritePWM(void);

static uint16_t CurrentAmpsOut;
static uint16_t PWM_DutyCycle;

void setup() 
{

}

void loop() 
{
  if(SolarPanelIsGeneratingPower())
  {
    UpdateChargingDutyCycle();
  }
  else
  {
    DisableBatteryCharging();
    PutMCUIntoLowPowerMode();
  }

  DelayBeforeRestartingAlgorithm();
}


void UpdateChargingDutyCycle()
{
  StoreCurrentAmpsOut();

  IncrementDutyCycle();

  if(OutputCurrentHasBeenHarmed())
  {
    DoubleDecrementDutyCycle();
  }
}

bool SolarPanelIsGeneratingPower()
{
  const uint16_t MIN_VOLTAGE_ALLOWED = 0xF0; //TODO: Find an accurate minimum voltage

  return (MIN_VOLTAGE_ALLOWED <= ReadSolarVout());
}

void DisableBatteryCharging()
{
  ZeroTheDutyCycle();
}

void PutMCUIntoLowPowerMode()
{

}

void DelayBeforeRestartingAlgorithm()
{

}

void StoreCurrentAmpsOut()
{
  CurrentAmpsOut = ReadCurrentSensor();
}

void IncrementDutyCycle()
{
  const uint16_t MAXIMUM_DUTY_CYCLE = 0xFF; //TODO: Verify Maximal Rate

  if(PWM_DutyCycle < MAXIMUM_DUTY_CYCLE)
  {
    PWM_DutyCycle += MINIMUM_INCREMENT;
  }

  WritePWM();
}

void DoubleDecrementDutyCycle()
{
  const uint16_t MINIMUM_DUTY_CYCLE = 0x00; //TODO: Verify minimum

  if(PWM_DutyCycle > MINIMUM_DUTY_CYCLE)
  {
    PWM_DutyCycle -= MINIMUM_DECREMENT;
  }

  WritePWM();
}

void ZeroTheDutyCycle()
{
  PWM_DutyCycle = 0;
  WritePWM();
}

bool OutputCurrentHasBeenHarmed()
{
  const uint16_t ACCEPTABLE_RANGE = 0x01; //TODO: Find an acceptable range

  return ReadCurrentSensor() < (CurrentAmpsOut - ACCEPTABLE_RANGE);
}

uint16_t ReadCurrentSensor()
{
  return analogRead(CURRENT_SENSOR_PIN);
}

uint16_t ReadSolarVout()
{
  return analogRead(MPPC_VOUT_PIN);
}

void WritePWM()
{

}
