#ifdef DEBUG
#include "software.h"
#include "animation.h"

void print_binary_number(unsigned char data) {
	for(int i = 7; i >= 0; i--) Serial.print((data & (1 << i)) > 0, DEC);
}

void print_led_state() {
	for(int row = 0; row < 8; row++) {
		for(int col = 0; col < 8; col++) {
			Serial.print(led_state[row * 8 + col], DEC);
			Serial.print(" ");
		}
		Serial.print("\n\r");
	}
}

void print_padded_number(unsigned int number, char* pad_with, unsigned int pad_count) {
	unsigned int pad_amount = pad_count - (int) log10(number);
	for(int i = 0; i < pad_amount; i++) Serial.print(pad_with);
	Serial.print(number, DEC);
}

void print_ani_debug(unsigned int effect_index, unsigned long relative_time) {
	Serial.print("[");
	print_padded_number(effect_index + 1, "0", 2);
	Serial.print("] time ");
	print_padded_number(relative_time / 1000, " ", 2);
	Serial.print(",");
	print_padded_number(relative_time % 1000, "0", 2);
	Serial.print(" frame ");
	print_padded_number(get_frame(relative_time), " ", 2);
	Serial.print("\r\n");
}

#endif

