# stepper_motor
Connections:
TB6560AHQ driver module | ESP32 board:
EN+ | GPIO18
EN- | GND
PUL+ | GPIO15
PUL- | GND
DIR+ | GPIO2
DIR- | GND (control-side)
TB6560AHQ | 12V converter:
V+ | 12V
V- | GND (power-side)
TB6560AH! | NEMA17 4.2kgcm stepper motor:
A+ A- | coil-1
B+ B- | coil-2
