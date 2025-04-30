/*
 *
 */

#include "Arduino.h"
#include "I2CPWM.h"
#include "Wire.h"

I2CPWM::I2CPWM(int addr)
{
  _addr = addr;
}

void I2CPWM::setPWM(int channel, int PWMvalue)
{
  Wire.beginTransmission(_addr); // transmit to device #4
  Wire.write(channel);
  Wire.write(PWMvalue);
  Wire.endTransmission();    // stop transmitting
}
