#ifndef LIB_I2CLCD_H
#define LIB_I2CLCD_H

#include <Wire.h>
#include <Arduino.h>

// Designed to be used with RW1063-0B-002

#define addr 0x3C   // Default slave is 0x3C

// Initialize the LCD. To be used once
void initLCD();

// Set all DDRAM to 0x20 and return to home position (0, 0)
void clearDisplayLCD();

// Return to home position (0, 0)
void returnHomeLCD();

// Go to position (x, y)
void locateCursorLCD(byte x, byte y);

// Disable the cursor, disable the blink
void cursorOFF();

// Enable the cursor, disable the blink
void cursorON();

// Enable the cursor, enable the blink
void blinkON();

// Select what is shifted and in which direction
void displayShiftRight();
void displayShiftLeft();
void cursorShiftRight();
void cursorShiftLeft();

// Print a string at the current position
void printDisplayLCD(String msg);

// Print a nember at the current position
// (num, chars, dec)
// num -> The number to display
// chars -> The size of the string to display
// dec -> The number of decimals to display
// printFloatLCD(22.55f, 6, 1) will display the string "  22.5"
void printIntLCD(int num, byte chars);
void printFloatLCD(float num, byte chars, byte dec);
void printDoubleLCD(double num, byte chars, byte dec);

#endif