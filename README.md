# Automatically Roll and Photograph Dice

[![video](http://img.youtube.com/vi/UdA5ydENTHY/0.jpg)](https://www.youtube.com/watch?v=UdA5ydENTHY)

[Project details, results, and construction photos](http://www.markfickett.com/dice).

## Circuit Diagram

[![circuit diagram hosted on flickr](https://farm1.staticflickr.com/683/22142748074_fd9b4c79d8_o.png)](https://www.flickr.com/photos/markfickett/22142748074/in/dateposted-public/)

## Parts

The core circuitry:

* ATtiny85, programmed with [SparkFun's Tiny AVR Programmer](https://www.sparkfun.com/products/11801), running the [8MHz internal-clock bootloader](https://github.com/damellis/attiny/tree/ide-1.6.x-boards-manager)
* [5 LilyPad white LEDs](https://www.sparkfun.com/products/10081) with builtin resistors
* [2-channel opto-isolator](http://www.mouser.com/ProductDetail/Vishay-Semiconductors/ILD2/) for camera trigger
* MOSFET for LED power control
* 3 [330-ohm 1/4W resistors](http://www.mouser.com/ProductDetail/Xicon/291-330-RC), current-limiting for the MOSFET and opto-isolator controls
* [hookup wire](https://www.sparkfun.com/products/11375) for LEDs
* [metal-geared micro servo](https://www.adafruit.com/products/1143)
* [servo connectors](http://www.hobbyking.com/hobbyking/store/__61682__15cm_Male_to_Male_Servo_Lead_JR_26AWG_10pcs_set_.html) and [long headers](https://www.sparkfun.com/products/10158) for multi-pin connections (except camera power)
* [servo wire](http://www.hobbyking.com/hobbyking/store/__5492__Flat_26AWG_servo_wire_1mtr_R_B_W_.html) as a flexible connection to LEDs on the movable container

Supporting hardware:

* ATX PSU for both 5v supply (microcontroller and servo) and 12v (via a 9v regulator for the camera)
* cardboard, masking tape, translucent plastic (nametag), plastic wrap, rubber band
* Nikon D90 on tripod with 55-200mm lens
