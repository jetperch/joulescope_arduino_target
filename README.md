
# Arduino Target for Joulescope

This repository contains Arduino code that demonstrates 
[Joulescope](https://www.joulescope.com)'s measurement
capabilities.  The Arduino code is intended for an Arduino Pro Mini running
at 3.3V.  The code performs the following steps after reset:

1.  Blink the LED 10 times.
2.  Pulse the LED for 10 times with decreasing pulse width but constant spacing.
3.  Pulse the LED for 10 times, decreasing both pulse width and pulse spacing.
4.  Pulse with minimum width.
5.  Go to sleep.

When the Arduino is in sleep mode and pin D2 connects to ground, the Arduino
wakes up and repeats.  The code also transmits its actions out the serial port 
at 115200,N,8,1.


## Why an Arduino Pro Mini?

An Arduino Pro Mini can be configured to only have the ATmega chip and an LED
so that it gets to the lowest possible ATMega power level.  The Pro Mini is
also inexpensive and easy to program.  

Joulescope works with a wide range of targets, not just this Arduino target.
Joulescope supports targets that draw from 0 to 3 Amps at 0 to 15 Volts.


## Supplies

To repeat this experiment using off-the-shelf parts, you need:

*   [Joulescope](https://www.joulescope.com) and 
    included USB cable.
*   Host PC: Windows 10 (Linux and Mac support coming soon)
*   Joulescope host software - [download](https://www.joulescope.com/download/)
*   A 3.3V Arduino Pro Mini - 
    [Sparkfun](https://www.sparkfun.com/products/11114),
    [Adafruit](https://www.adafruit.com/product/2377)
*   A USB to 3.3V power supply with banana jacks

You can use Sparkfun [Banana to IC Hook Cables](https://www.sparkfun.com/products/506)
to connect the Arduino Pro Mini to Joulescope.  For a more permanent and
reliable connection, you can solder wires with banana jacks.

If you need to prepare a new Arduino Pro Mini you need:

*   FTDI Basic - [SparkFun](https://www.sparkfun.com/products/9873)
*   [Arduino IDE](https://www.arduino.cc/en/Main/Software)
*   6 pin right angle header - [SparkFun](https://www.sparkfun.com/products/553)
*   Soldering iron, solder, and solder wick


## Procedure

### Prepare the Arduino Pro Mini

If you have an Arduino Pro Mini Target from Jetperch, then skip to the next
section.

*   Program the Arduino Pro Mini.
*   Desolder the Arduino Pro Mini "Power isolation jumper" 
    (see [schematic](https://cdn.sparkfun.com/datasheets/Dev/Arduino/Boards/Arduino-Pro-Mini-v14.pdf))
    located near GND adjacent to digital pin 2.
*   Solder the 6-pin right-angle header to the end of the Arduino Pro Mini.
    However, you may be able to program the Arduino by just holding the 
    connector in place.  You can apply gentle pressure to ensure
    that all pins make electrical connection with the holes.
*   Connect the Arduino Pro Mini to the FTDI Basic and then connect the USB mini
    cable to your PC.  
*   Program the Arduino.  For details, follow this 
    [SparkFun Guide](https://learn.sparkfun.com/tutorials/using-the-arduino-pro-mini-33v).
*   Press the reset button and verify that the LED flashes.


### Connect the Power Supply

If you have the Joulescope demonstration power supply, connect the micro USB
cable to your PC using the provided USB cable.  Connect the banana jacks to 
the Joulescope IN port.  Make sure you connect "-" to "-" and "+" to "+".
Skip to the next section.

Otherwise, you can use any 3.3V supply for this demo.
A bench supply set to 3.3V works great if you have one. 
The FTDI Basic's 3.3V output also works sufficiently. 
You can construct the USB to 3.3V power supply using off-the-shelf parts:

*   Sparkfun [Breadboard Power Supply Stick @ 3.3V](https://www.sparkfun.com/products/13157)
*   Sparkfun [Hydra Power Cable](https://www.sparkfun.com/products/11579)
*   Sparkfun [Banana to IC Hook Cables](https://www.sparkfun.com/products/506)


### Connect the Arduino Pro Mini Target
    
Connect the Arduino Pro Mini GND to Joulescope OUT -.
Connect the Arduino Pro Mini VCC to Joulescope OUT +.


### Prepare Joulescope

*   [Download](https://www.joulescope.com/download/) and install the
    Joulescope User Interface (UI).
*   Connect Joulescope to your host computer using the provided USB cable.
*   Start the Joulescope User Interface.


### Perform the test

*   Press the reset button on the Arduino Pro Mini.
*   Notice that the Joulescope UI readings change.
*   Switch the Joulescope UI to "Oscilloscope" view.
    Click "View".  Click "Oscilloscope Default".
*   Press the reset button on the Arduino Pro Mini.
*   Zoom on the current y-axis to see the changing signal.  Explore!

You can repeat the test by pressing the Arduino reset button or by 
connecting the Arduino digital "2" signal to ground.
