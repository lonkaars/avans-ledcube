#pragma once
#ifdef DEBUG

/** @brief [DEBUG] print binary number padding with 0 */
void print_binary_number(unsigned char data);
/** @brief [DEBUG] print led_state in 8x8 grid */
void print_led_state();
/** @brief [DEBUG] pad and print number */
void print_padded_number(unsigned int number, char* pad_with, unsigned int pad_count);
/** @brief [DEBUG] print time and animation info */
void print_ani_debug(unsigned int effect_index, unsigned long relative_time);

#endif
