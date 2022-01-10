# stepper_motor:
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
TB6560AHQ | NEMA17 4.2kgcm stepper motor:
A+ A- | coil-1
B+ B- | coil-2
All the switches except the M2 switch in the 10-switch side switchbar have been put in on position. This enables the driver to drive the motor with 16 micro-step configuration.

travel distance: ~190mm
travelled distance per revolution of the motor: 2mm
micro steps settings: 16 Turn switch-7 low and keep switch-8 high to set this micro setting.
Motor: NEMA 17 4.2KGCM
pulses per revolution when micro steps = 1: 200
Hence, pulses per revolution required with microsteps = 16: 16*200=3200

What this particular code does: Rotates the motor in one direction for 95 revolution. Then stops the motor for a second. Then rotates the motor in another direction for 95 revolutions. Then repeat.
