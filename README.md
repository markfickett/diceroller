# Automatically Roll and Photograph Dice

[![video](http://img.youtube.com/vi/UdA5ydENTHY/0.jpg)](https://www.youtube.com/watch?v=UdA5ydENTHY)

[Project details, results, and construction photos](TODO).

## Circuit Diagram

TODO

## Parts

The core circuitry:

* ATtiny85, programmed with SparkFun's USB programmer, running the 8MHz internal-clock bootloader
* 5 LilyPad white LEDs
* [2-channel opto-isolator](TODO) for camera trigger
* MOSFET for LED power control
* 3 330-ohm 1/4W resistors, current-limiting for the MOSFET and opto-isolator controls
* hookup wire for LEDs
* metal-geared micro servo
* servo connectors and wire for multi-pin connections (except camera power)
* servo wire as a flexible connection to LEDs on the movable container

Supporting hardware:

* ATX PSU for both 5v supply (microcontroller and servo) and 12v (via a 9v regulator for the camera)
* cardboard, masking tape, translucent plastic (nametag), plastic wrap, rubber band
* Nikon D90 on tripod with 55-200mm lens
