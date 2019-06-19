/*
  Shift Register - Basic usage example
  ------------------------------------
  In this program, we'll set the pins of
  a shift register using the ShiftRegister
  library. We're going to use a
  74HC595 (for more informations, go to
  http://www.ti.com/lit/ds/symlink/sn74hc595.pdf)
*/

// Include the ShiftRegister library
#include "ShiftRegister.h"

// Declare our shift register :
// - The first parameter is the clock pin (SRCLK)
// - The second one is the latch pin (RCLK)
// - The third is the data pin (SER)
// - Finally, we set the number of available pins on the register
// If you want help with the cabling, check the schema on the examples/BasicUsage/schema.png image, located in the library.
ShiftRegister reg(12, 8, 11, 8);

void setup()
{
  // Setup register's pins
  reg.setup();
}
void loop()
{
  // Here is how the class works :
  // In a first time, we set pins' state (HIGH or LOW)
  // In a second time, we save our changes to the register

  // Turn on the 2nd pin
  reg.setPin(2, HIGH);
  // Save our changes
  reg.save();

  // Add a little delay
  delay(500);

  // Repeating again and again...
  reg.setPin(2, LOW);
  reg.setPin(3, HIGH);
  reg.save();

  delay(100);

  reg.setPin(3, LOW);
  reg.setPin(4, HIGH);
  reg.setPin(5, HIGH);
  reg.save();

  delay(1000);

  reg.setPin(4, LOW);
  reg.setPin(5, LOW);
}