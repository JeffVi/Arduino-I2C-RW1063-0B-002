# Arduino-I2C-RW1063-0B-002
A little library to easily set up I2C communication with the `RW1063-0B-002` LCD

## Content
Provides functions to init, configure, and print strings/numbers on the LCD using the [Wire](https://www.arduino.cc/en/Reference/Wire) library.

A sample project is also provided.

The default slave address used is `0x3C`, this can be changed by editing `addr` in [lib_I2CLCD.h](lib_I2CLCD.h).

Possible slave addresses for `RW1063-0B-002` are `0x3C`, `0x3D`, `0x3E`, and `0x3F`.

The LCD is initialized with this configuration:
+ Increment cursor moving direction
+ Cursor ON
+ Blink OFF
+ 8-bit bus
+ 2-line display
+ 5x8 dots format