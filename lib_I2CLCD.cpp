#include "lib_I2CLCD.h"

void initLCD()  {

  Wire.beginTransmission(addr);

  Wire.write(0x80);               // 1000 0000 -> control byte
  Wire.write(0x3C);               // 0011 1100 -> function set
  delayMicroseconds(150);         // 150 us

  Wire.write(0x80);               // 1000 0000 -> control byte
  Wire.write(0x0E);               // 0000 1110 -> display on
  delayMicroseconds(150);         // 150 us

  Wire.write(0x80);               // 1000 0000 -> control byte
  Wire.write(0x01);               // 0000 0001 -> clear display
  delay(15);                      // 15 ms

  Wire.write(0x00);               // 0000 0000 -> control byte
  Wire.write(0x06);               // 0000 0110 -> entry mode set
  delayMicroseconds(150);         // 150 us

  Wire.endTransmission();
}

void clearDisplayLCD() {

  Wire.beginTransmission(addr);

  Wire.write(0x00);               // 0000 0000 -> control byte
  Wire.write(0x01);               // 0000 0001 -> clear display
  delayMicroseconds(850);         // 850 us

  Wire.endTransmission();
}

void returnHomeLCD() {

  Wire.beginTransmission(addr);

  Wire.write(0x00);               // 0000 0000 -> control byte
  Wire.write(0x02);               // 0000 0010 -> return home
  delayMicroseconds(850);         // 850 us

  Wire.endTransmission();
}

void locateCursorLCD(byte x, byte y) {

  byte address;

  if (y == 0){address = 0x00;}
  else if (y == 1){address = 0x40;}
  else if (y == 2){address = 0x14;}
  else if (y == 3){address = 0x54;}

  address = (address + x) | 0x80; // 1000 0000 -> set DDRAM address byte

  Wire.beginTransmission(addr);

  Wire.write(0x00);               // 0000 0000 -> control byte
  Wire.write(address);
  delayMicroseconds(20);          // 20 us

  Wire.endTransmission();
}

void cursorOFF() {

  Wire.beginTransmission(addr);

  Wire.write(0x00);               // 0000 0000 -> control byte
  Wire.write(0x0C);               // 0000 1100 -> display on, cursor off, blink off
  delayMicroseconds(20);          // 20 us

  Wire.endTransmission();
}

void cursorON() {

  Wire.beginTransmission(addr);

  Wire.write(0x00);               // 0000 0000 -> control byte
  Wire.write(0x0E);               // 0000 1110 -> display on, cursor on, blink off
  delayMicroseconds(20);          // 20 us

  Wire.endTransmission();
}

void blinkON() {

  Wire.beginTransmission(addr);

  Wire.write(0x00);               // 0000 0000 -> control byte
  Wire.write(0x0F);               // 0000 1111 -> display on, cursor on, blink on
  delayMicroseconds(20);          // 20 us

  Wire.endTransmission();
}

void displayShiftRight()
{
  Wire.beginTransmission(addr);

  Wire.write(0x00);               // 0000 0000 -> control byte
  Wire.write(0x1C);               // 0001 1100 -> display shift, right shift
  delayMicroseconds(20);          // 20 us

  Wire.endTransmission();
}

void displayShiftLeft()
{
  Wire.beginTransmission(addr);

  Wire.write(0x00);               // 0000 0000 -> control byte
  Wire.write(0x18);               // 0001 1000 -> display shift, left shift
  delayMicroseconds(20);          // 20 us

  Wire.endTransmission();
}

void cursorShiftRight()
{
  Wire.beginTransmission(addr);

  Wire.write(0x00);               // 0000 0000 -> control byte
  Wire.write(0x14);               // 0001 0100 -> cursor shift, right shift
  delayMicroseconds(20);          // 20 us

  Wire.endTransmission();
}

void cursorShiftLeft()
{
  Wire.beginTransmission(addr);

  Wire.write(0x00);               // 0000 0000 -> control byte
  Wire.write(0x10);               // 0001 0000 -> cursor shift, left shift
  delayMicroseconds(20);          // 20 us

  Wire.endTransmission();
}

void printDisplayLCD(String msg) {

  char char_array[21];
  msg.toCharArray(char_array, msg.length()+1);

  Wire.beginTransmission(addr);

  Wire.write(0x40);               // 0100 0000 -> write display data
  Wire.write(char_array);
  delayMicroseconds(20*(msg.length()+1));          // 20 us * char

  Wire.endTransmission();
}

void printIntLCD(int num, byte chars) {
  
  byte size_str = 0x00;
  String num_array = "";

  size_str = String(num).length();
  
  if (size_str >= chars){return;}            // Can't be displayed with the given number of chars

  for (int k = size_str; k < chars; k++)
  {
    num_array += " ";
  }

  num_array += String(num);

  printDisplayLCD(num_array);
}

void printFloatLCD(float num, byte chars, byte dec) {

  byte size_str = 0x00;
  String num_array = "";

  size_str = String(num, dec).length();

  if (size_str >= chars){return;}            // Can't be displayed with the given number of chars
  
  for (int k = size_str; k < chars; k++)
  {
    num_array += " ";
  }

  num_array += String(num, dec);

  printDisplayLCD(num_array);
}

void printDoubleLCD(double num, byte chars, byte dec) {

  byte size_str = 0x00;
  String num_array = "";

  size_str = String(num, dec).length();

  if (size_str >= chars){return;}            // Can't be displayed with the given number of chars
  
  for (int k = size_str; k < chars; k++)
  {
    num_array += " ";
  }

  num_array += String(num, dec);

  printDisplayLCD(num_array);
}