#pragma once

#define SR_ROW 0
#define SR_COL 1
extern unsigned char shift_state[2];

/** @brief shift shift_state naar de shift registers */
void update_shift_state();

/** @brief direct data naar de shift registers sturen */
void shift(unsigned char data);
