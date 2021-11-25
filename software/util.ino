#ifdef DEBUG
#include "software.h"

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

#endif
