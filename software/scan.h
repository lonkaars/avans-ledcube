#pragma once

// utility
#define SCAN_HOR 0
#define SCAN_VER 1
extern unsigned char scan_direction;
extern unsigned char scan_index;
extern unsigned char scan_order[8];

/** @brief fetch horizontal or vertical row from led_state */
unsigned char get_state_row(unsigned char row, unsigned char direction);

/** @brief scan through the 8x8 wiring matrix and display led_state */
void scan();
/** @brief optimize brightness by pruning empty lines */
void optimize_scan();

