#pragma once

extern unsigned char shift_state[2];

/** @brief update physical state of shift registers with shift_state */
void update_shift_state();

/** @brief directly push data to the serial in of the shift registers */
void shift(unsigned char data);
