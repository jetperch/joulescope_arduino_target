
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


## Procedure

### Setup

*   Connect Joulescope to your host computer over USB.
*   Start the Joulescope host software.
    [download](https://www.joulescope.com/download/)
*   Connect the Arduino Pro Mini Target to Joulescope.
    *   Connect the Arduino Pro Mini GND to Joulescope OUT -.
    *   Connect the Arduino Pro Mini VCC to Joulescope OUT +.
*   Connect a +3.3V power supply to Joulescope.  Be sure to observe the
    correct polarity.  If you have the Evaluation Kit, insert the banana 
    plugs into Joulescope and connect the USB micro connector to an available
    USB port on your host computer using the provided cable.
    
    
### Perform the test

*   Press the reset button on the Arduino Pro Mini.
*   Notice that the Joulescope UI readings change.
*   Switch the Joulescope UI to "Oscilloscope" view.
    Click "View" -> "Oscilloscope Default".
*   Press the reset button on the Arduino Pro Mini.
*   Zoom on the current y-axis to see the changing signal.  Explore!

You can repeat the test by pressing the Arduino reset button or by 
connecting the Arduino digital "2" signal to ground.


## Supplies

If you have the Joulescope Evaluation Kit 1, you have everything that you need.
The evaluation kit includes:

*   1 USB to +3.3V power supply
*   1 USB A to Micro B cable
*   1 target device: a modified Arduino Pro Mini

The next steps describe how to create your own setup if you do not have the
Joulescope Evaluation Kit.


### Prepare the Arduino Pro Mini

If you have an Arduino Pro Mini Target from the Joulescope Evaluation Kit 1,
skip this section.

You will need:

*   A 3.3V Arduino Pro Mini - 
    [Sparkfun](https://www.sparkfun.com/products/11114),
    [Adafruit](https://www.adafruit.com/product/2377).
*   FTDI Basic - [SparkFun](https://www.sparkfun.com/products/9873)
    (used to program the Arduino Pro Mini).
*   [Arduino IDE](https://www.arduino.cc/en/Main/Software).
*   6 pin through header - [SparkFun](https://www.sparkfun.com/products/553),
    but most common 0.1" header will work.
*   Soldering iron, solder, and solder wick.
*   Arduino to Joulescope Banana Jacks, such as Sparkfun 
    [Banana to IC Hook Cables](https://www.sparkfun.com/products/506).


And here is the procedure:

*   Program the Arduino Pro Mini.
    *   Clone this repo or download the sketch directly.
    *   Launch the Arduino IDE and open joulescope_arduino_target.ino.
    *   Connect the FTDI basic to your PC.
    *   Select Tools -> Board -> "Arduino Pro or Pro Mini".
    *   Select Tools -> Processor -> "ATmega 328P (3.3V, 8 MHz)".
    *   Select Tools -> Port -> (serial port for the FTDI basic).
    *   Insert the header into the FTDI basic.  Align correctly with the
        Arduino Pro Mini.  Insert into Arduino Pro Mini and hold in place.
        Apply slight sideways pressure to make connection.  Hold while pressing
        the "Upload" button in the Arduino IDE.  Continue to hold until the
        programming succeeds.
    *   If you run into any issues, see this excellent
        [SparkFun Guide](https://learn.sparkfun.com/tutorials/using-the-arduino-pro-mini-33v).
*   Press the reset button and verify that the LED flashes.
*   Desolder the Arduino Pro Mini "Power isolation jumper" 
    (see [schematic](https://cdn.sparkfun.com/datasheets/Dev/Arduino/Boards/Arduino-Pro-Mini-v14.pdf))
    located near GND adjacent to digital pin 2.



## Prepare a power supply

If you have an USB to +3.3V supply from the Joulescope Evaluation Kit 1,
skip this section.

The FTDI Basic's 3.3V output works sufficiently. Simply use 
Sparkfun [Banana to IC Hook Cables](https://www.sparkfun.com/products/506) to
connect it to Joulescope.

Most 3.3V supplies will work since the Arduino Pro Mini draws 10 mA max.
You can use a bench supply if you have one.  If you do not have a bench supply,
here is one reasonably cost-effective approach.

*   Sparkfun [Breadboard Power Supply Stick @ 3.3V](https://www.sparkfun.com/products/13157).
*   Sparkfun [Hydra Power Cable](https://www.sparkfun.com/products/11579).
*   Sparkfun [Banana to IC Hook Cables](https://www.sparkfun.com/products/506).

For a more permanent and reliable connection, you can solder wires with 
banana jacks.
