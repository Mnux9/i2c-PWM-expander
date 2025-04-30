/*
 *  Morse.h - Library for flashing Morse code.
 *  Created by David A. Mellis, November 2, 2007.
 *  Updated by Jason A. Cox, February 18, 2023.
 *  Released into the public domain.
 */

#ifndef I2CPWM_h
#define I2CPWM_h

#include "Arduino.h"

class I2CPWM
{
public:
  I2CPWM(int addr);
  void setPWM(int channel, int PWMValue);
private:
  int _addr;
};

#endif

