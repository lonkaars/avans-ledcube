#pragma once

#define PINOUT_SCK 4
#define PINOUT_SER 2
#define PINOUT_LCK 3

#define CONFIG_FRAMERATE 60
#define CONFIG_PWM_FREQ 1000
// shift register serial delay (rekening houden met propagation delay) (in nanoseconden)
#define CONFIG_SRSER_DELAY 20

#define CONFIG_SERIAL_BAUD 115200
// #define DEBUG
