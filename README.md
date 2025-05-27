This is a very simple program for Kramer Protocol 3000 Devices.
This has been designed for simple switching of only video sources.
It is built on the assumption that an arduino is being connected to a 4x4 keyboard matrix and each key is programmed to a specific command.
If you connect a 4x4 matrix to the rows as pins 5-2 and the colums as 6-9 (inclusive) it will set each command to the commands stored in char commands further down in the file.
It then uses software serial on pin 11 for tx and 12 for rx (not that this program is configured for any data receiving but the handshake protocol uses it).
If somehow anyone finds this repo and thinks its junk, yes I know but I simply do not care, it works for my application. Anyone is more than welcome to make a pull request to fix its many many problems but the code does work and I don't care enough.
