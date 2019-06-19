#include "Arduino.h"
#include "ShiftRegister.h"

ShiftRegister::ShiftRegister(int clock_pin, int latch_pin, int data_pin, int pins_number)
{
  _clock_pin = clock_pin;
  _latch_pin = latch_pin;
  _data_pin = data_pin;
  _pins_number = pins_number;
  for (int i = 0; i < pins_number; i++)
  {
    _pins[i] = i + 1;
    _states[i] = LOW;
  }
}

void ShiftRegister::setup()
{
  pinMode(_clock_pin, OUTPUT);
  pinMode(_latch_pin, OUTPUT);
  pinMode(_data_pin, OUTPUT);
}

void ShiftRegister::setPin(int pin, int state)
{
  _states[pin - 1] = state;
}

void ShiftRegister::save()
{
  byte bitsToSend = 0;

  // turn off the output so the pins don't light up
  // while you're shifting bits:
  digitalWrite(_latch_pin, LOW);

  for (int i = 0; i < _pins_number; i++)
  {
    bitWrite(bitsToSend, _pins[i], _states[i]);
  }

  // shift the bits out:
  shiftOut(_data_pin, _clock_pin, MSBFIRST, bitsToSend);

  // turn on the output so the LEDs can light up:
  digitalWrite(_latch_pin, HIGH);
}