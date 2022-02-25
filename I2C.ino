#include "lib_I2CLCD.h"

/*
Designed to be used with RW1063-0B-002
Sample code
*/

void setup() {

  Wire.begin();                                   // Start the IIC.

  initLCD();                                      // Initialize the LCD.

  clearDisplayLCD();                              // Set all DDRAM to 0x20 and return to home position (0, 0).

  cursorOFF();                                    // Disable the cursor.

  returnHomeLCD();                                // Return to home position (0, 0).

  printDisplayLCD("     HELLO WORLD    ");        // Print HELLO WORLD.

  locateCursorLCD(3, 2);                          // Go to position (3, 2). Fourth character (3) and third line (2).

  printDisplayLCD("I2CLCD");
}

void loop() {

  static int cpt = 0;

  delay(500);
  cpt++;
  locateCursorLCD(12, 2);
  printIntLCD(cpt, 3);                            // Print an int on 3 characters.
}