## Keypad library for Arduino

**Authors:**  *Mark Stanley*, *Alexander Brevig*

The Keypad library is designed for driving matrix style keypads (matrix decoder) when using the Arduino platform. It uses the standard method of selecting a column and scanning all the rows to see which key may be pressed. Support is provided for various size keypads (or matrix style keyboards) up to 160 keys with a maximum of 16 columns and 10 rows. You can expand beyond that if you are willing to make minor changes to the library.

Features of this library are:
	Allows multiple, simultaneous, keypresses. (Current max of 10 keys at one time.)
	Backwards compatible with previous single-key methods.
	Has a built-in state-machine to debounce the keys without slowing down your code.

Online Wokwi Arduino Simulation link here: https://wokwi.com/arduino/projects/284084336653763080
Use this link to play with the keypad source code

Version 3.2 	2015-08-17 - Tim Trzepacz:
        Added "stated" event listener that also receives key state as a parameter.


You can get more information about matrix keypads and how to connect them to your Arduino on the playground:

http://arduino.cc/playground/Code/Keypad

The source and file structure has been modified to conform to the newer `1.5r2` library specification and is not compatible with legacy IDE's.
For these IDE's, visit the link above to grab the pre `1.0` compatible version, or download it directly here:  [[pre `1.0` version]](http://playground.arduino.cc/uploads/Code/keypad.zip).


