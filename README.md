# Frequency-Counter-Using-8051-Microcontroller

## Overview

This project implements a frequency counter using an AVR microcontroller, a 16-bit timer, and external interrupts. It allows measuring the frequency of an input square wave signal accurately.

## Hardware Setup

1. Connect the frequency generator's TTL output to the external interrupt pin (e.g., INT0) of the microcontroller.
2. Connect the ground (GND) of the frequency generator to the microcontroller's ground (GND).
3. Ensure the voltage levels of the frequency generator are compatible with the microcontroller (e.g., 5V TTL).

## Software Implementation

1. Configure the microcontroller to enable external interrupts on the chosen pin (e.g., INT0).
2. Implement an Interrupt Service Routine (ISR) for the external interrupt:
   - Start a timer (e.g., Timer1) on the rising edge of the input signal.
   - Stop the timer on the next rising edge, calculate the elapsed time, and determine the frequency.
   - Handle timer overflows to avoid errors in frequency calculation.
3. Display the measured frequency on a seven-segment display or via serial communication to a computer.

## Frequency Range

1. Experimentally determine the practical frequency range that the system can accurately measure.
2. Theoretical limits include:
   - Lower Limit: Limited by the microcontroller's timer resolution and processing speed.
   - Upper Limit: Limited by the maximum frequency the timer and interrupt system can handle effectively.

## Additional Notes

- The project code can be customized for different microcontrollers and timer configurations.
- Ensure proper decoupling and noise immunity measures in hardware to improve accuracy.
- Contributions, bug reports, and suggestions are welcome via GitHub issues and pull requests.

