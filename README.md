lighthouse-attiny-softpwm
=========================

software PWM based lighthouse blinker for AVR ATtiny

Building
--------

 - Edit the first five variables in `Makefile` (or use command line arguments
   or environment variables) to match your microcontroller and programmer
   setup. The default is an ATtiny22 using its internal clock and an STK500
   connected to the first USB-serial converter on Linux.
 - To build the firmware file `main.hex` enter `make`
 - To burn the firmware to the microcontroller (and build if needed), enter
   `make upload`

Dependencies
------------

 - for building: GCC AVR cross-compiler (Debian/Ubuntu package: `gcc-avr`)
 - for burning: avrdude (Debian/Ubuntu package: `avrdude`)

License
-------

The whole project is licensed under MIT license, see [LICENSE](LICENSE).
