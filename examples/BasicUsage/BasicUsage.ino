/*
  Shift Register - Basic usage example
  ------------------------------------
  In this program, we'll set the pins of
  a shift register using the ShiftRegister
  library. We're going to use a
  74HC595 (for more informations, go to
  http://www.ti.com/lit/ds/symlink/sn74hc595.pdf)

  Created 19 June 2019 by Exybore
  https://github.com/exybore/arduino-shift-register
*/

// Include the ShiftRegister library
#include "ShiftRegister.h"

// Declare our shift register :
// - The first parameter is the clock pin (SRCLK)
// - The second one is the latch pin (RCLK)
// - The third is the data pin (SER)
// - Finally, we set the number of available pins on the register
// If you want help with the cabling, check the schema on the schema.png image, located in the library.
ShiftRegister shiftRegister(12, 8, 11, 8);

void setup()
{
  // Setup register's pins
  shiftRegister.setup();
}
void loop()
{
  // Here is how the class works :
  // In a first time, we set pins' state (HIGH or LOW)
  // In a second time, we save our changes to the register

  // Turn on the 2nd pin
  shiftRegister.setPin(2, HIGH);
  // Save our changes
  shiftRegister.save();

  // Add a little delay
  delay(500);

  // Repeating again and again...
  shiftRegister.setPin(2, LOW);
  shiftRegister.setPin(3, HIGH);
  shiftRegister.save();

  delay(100);

  shiftRegister.setPin(3, LOW);
  shiftRegister.setPin(4, HIGH);
  shiftRegister.setPin(5, HIGH);
  shiftRegister.save();

  delay(1000);

  shiftRegister.setPin(4, LOW);
  shiftRegister.setPin(5, LOW);
}