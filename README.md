
# MICROCONTROLLER - MICROPROCESSOR, LABORATORY 2

This is the second lab to get familiar with Buttons & Switches through a big exercises focused on simulate a 2-WAYs-TRAFFIC-LIGHT.


## 1. Schematic for this lab

I simulated the source code on an STM32F103C6 using Proteus 8. The schematic looks like this:

![Proteus Schematic](./images/Proteus_Schematic_LAB3.png)

The pin assignments are listed in the table below:

| PIN      | PIN LABEL      |
|:---------|:---------------|
| PA0      | SEG_0          |
| PA1      | SEG_1          |
| PA2      | SEG_2          |
| PA3      | SEG_3          |
| PA4      | SEG_4          |
| PA5      | SEG_5          |
| PA6      | SEG_6          |
| PA7      | SEG_7          |
| PA8      | EN_0           |
| PA9      | EN_1           |
| PA10     | EN_2           |
| PA11     | EN_3           |
| PA12     | LED_RED        |
| PA13     | not in use     |
| PA14     | not in use     |
| PA15     | not in use     |
| PB0      | not in use     |
| PB1      | not in use     |
| PB2      | not in use     |
| PB3      | not in use     |
| PB4      | LED_RED_0      |
| PB5      | LED_YEL_0      |
| PB6      | LED_GRN_0      |
| PB7      | LED_RED_1      |
| PB8      | LED_YEL_1      |
| PB9      | LED_GRN_1      |
| PB10     | not in use     |
| PB11     | not in use     |
| PB12     | BTN_0          |
| PB13     | BTN_1          |
| PB14     | BTN_2          |
| PB15     | not in use     |

## 2. How to run the exercises source code?

1. Ensure that all hardware connections are correct as described above. The timer is configured with prescaler = 799, counter = 9 so the TICK is 1 ms.

2. Clone this Project and Run.