# Bit-Encryptor
MICROCONTROLLER COMPARISON VIA ENCRYPTION TABLE IMPLEMENTATION:
The objective of this project was to create a 4 -bit encryption system that masks that the output using
Boolean Expression. The encryption algorithm was derived from a Truth Table of inputs and its
subsequent output. The 4-bit input would be fed into a microcontroller which would then encrypt the
output according to the Truth Table using Boolean logic expression and display it via 4 LEDs to signify 4-
bits. A total of 16 possible encryption combinations are possible using this 4-bit circuit: from a value of 0
to 15.
This encryption system was programmed in the Arduino IDE using both default C-programming using
Arduino Libraries and Register Level Programming. The aim was to monitor the difference between
running a program coded in high-level default program using headers and libraries and low-level Register
Level Programming and compare their differences of program size, memory occupied, and time taken to
execute the program.
The HEX file of the programmed Arduino IDE code was then imported to a circuit schematic designed in
Proteus for simulation of the complete system. A virtual terminal was also used monitor the execution.
The encryption system was implemented using two different boards in Proteus: i) Arduino UNO which
uses the ATmega328p microcontroller and ii) Arduino Mega 2560 which uses the ATmega2650
microcontroller. Both boards implemented the encryption program in each type of programming to
compare the differences of performance and memory to ensure the results are consistent and reliable.
