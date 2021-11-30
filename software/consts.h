#pragma once

// pinouts
#define PINOUT_SCK 4
#define PINOUT_SER 2
#define PINOUT_LCK 3
#define PINOUT_NOISE A0

// debug options
// #define CONFIG_SERIAL_BAUD 115200
// #define DEBUG

/**
 * @brief map 3D cube coordinates to `led_state` indices
 *
 * usage: `led_state[led_map[x + 4*y + 16*z]]`
 */
const unsigned int led_map[64] = {
	0x31, 0x21, 0x11, 0x01,
	0x33, 0x23, 0x13, 0x03,
	0x35, 0x25, 0x15, 0x05,
	0x37, 0x27, 0x17, 0x07,
                  
	0x30, 0x20, 0x10, 0x00,
	0x32, 0x22, 0x12, 0x02,
	0x34, 0x24, 0x14, 0x04,
	0x36, 0x26, 0x16, 0x06,
                  
	0x38, 0x28, 0x18, 0x08,
	0x3a, 0x2a, 0x1a, 0x0a,
	0x3c, 0x2c, 0x1c, 0x0c,
	0x3e, 0x2e, 0x1e, 0x0e,
                  
	0x39, 0x29, 0x19, 0x09,
	0x3b, 0x2b, 0x1b, 0x0b,
	0x3d, 0x2d, 0x1d, 0x0d,
	0x3f, 0x2f, 0x1f, 0x0f,
};

