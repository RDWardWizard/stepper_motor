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

Opto-coupler-1 | ESP32 board:
V | VIN
S | GPIO13
GND | GND

Opto-coupler-2 | ESP32 board:
V | VIN
S | GPIO12
GND | GND

start/stop push button |ESP32:
1 | GPIO14 (pulled-up in code)
2 | GND

All the switches except the M2 switch in the 10-switch side switchbar have been put in on position. This enables the driver to drive the motor with 16 micro-step configuration.

travel distance: ~190mm
travelled distance per revolution of the motor: 2mm
micro steps settings: 16 Turn switch-7 low and keep switch-8 high to set this micro setting.
Motor: NEMA 17 4.2KGCM
pulses per revolution when micro steps = 1: 200
Hence, pulses per revolution required with microsteps = 16: 16*200=3200

What this particular code does: Rotates the motor in one direction for 95 revolutions when the push button is pressed. The motor will stop rotation if the 95 revolutions are over or the optocoupler at the other end detects obstacle.
When the button is pressed again, the motor will rotate in the opposite direction for 95 revolution or upto the 1st optocoupler detects obstacle. Then when the switch is pressed again, the motor will again start to rotate in the intial direction. This cycle will keep on repeating.
