# PunchCard2Keyboard

This [Arduino](http://arduino.cc/)/[Teensy 3.1](http://www.pjrc.com/teensy/teensy31.html) program interprets 12 inputs as rows of classical punch cards and decodes the characters according to [IBM model 029 keypunch](http://homepage.cs.uiowa.edu/~jones/cards/codes.html). The Teensy 3.1 is recognised as a USB HID keyboard and sends the decoded characters as key presses. Each card is finalised with an 'enter' key press.

## Compiling

This program was developed in Eclipse IDE and not the original Arduino IDE. For compiling you should import this project in an Eclipse Mars CPP with the [GNU ARM Eclipse plugins](http://gnuarmeclipse.livius.net/blog/) and [Teensyduino](https://www.pjrc.com/teensy/teensyduino.html) installed. You need to set up the environment variable `TEENSYDUINO_ROOT` pointing to the installation directory of Teensyduino and link the directory `${TEENSYDUINO_ROOT}/hardware/teensy/cores/teensy3` as a linked folder in the project root.

## Usage

1. Build your own punch card reader: http://tim.jagenberg.info/2014/11/20/punchcard2keyboard/
2. Program your Teensy 3.1 with Release/PunchCard2Keyboard.hex
3. Wire the punch card reader contacts as shown in the table below.
4. Plugin in the Teensy 3.1 via USB and use it as a keyboard, feeding it punch cards.

CardReader | Teensy 3.1
---- | ----------
ROW_Y | 15
ROW_X | 14
ROW_0 | 12
ROW_1 | 11
ROW_2 | 10
ROW_3 | 9
ROW_4 | 8
ROW_5 | 7
ROW_6 | 6
ROW_7 | 5
ROW_8 | 4
ROW_9 | 3
BLK | GND
RED | 3.3V


## Contributing

1. Fork it!
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request :D

## History

* Version 1.0 - first release

## License

Copyright Tim Jagenberg <tim@jagenberg.info>  
Licensed under the Apache License, Version 2.0  
http://www.apache.org/licenses/LICENSE-2.0.html
