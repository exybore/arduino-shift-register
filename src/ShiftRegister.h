/*
  ShiftRegister.h - Library to interact with a shift register such as the 74HC595.
  Created by Exybore, June 19, 2019.

  MIT License

  Copyright (c) 2019 Exybore

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.
*/

#ifndef SHIFTREGISTER_H_
#define SHIFTREGISTER_H_

#include "Arduino.h"

class ShiftRegister
{
public:
  /*!
   * Create a new shift register object
   * For the pins reference (for exemple 74HC595), see http://www.ti.com/lit/ds/symlink/sn74hc595.pdf at page 4
   * 
   * @param clock_pin The clock pin (SRCLK)
   * @param latch_pin The latch pin (RCLK)
   * @param data_pin The data pin (SER)
   * @param pins_number Number of available pins
   */
  ShiftRegister(int clock_pin, int latch_pin, int data_pin, int pins_number);

  /*!
   * Setup the three pins in output mode
   */
  void setup();

  /*!
   * Change a pin's mode
   * 
   * @param pin Pins to change
   * @param state States of the pin (HIGH or LOW)
   */
  void setPin(int pin, int state);

  /*!
   * Save data to the shift register
   */
  void save();

private:
  int _clock_pin;   /*!< Register's clock (SRCLK) pin */
  int _latch_pin;   /*!< Register's latch (RCLK) pin */
  int _data_pin;    /*!< Register's data pin */
  int _pins_number; /*!< Number of pins available on the shift register */
  int _pins[256];   /*!< Pins list */
  int _states[256]; /*!< States of the pins */
};

#endif
