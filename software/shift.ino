#include "shift.h"
#include "consts.h"
#ifdef DEBUG
#include "util.h"
#endif

unsigned char shift_state[2];

void update_shift_state() {
	for(int i = 0; i < 2; i++)
		shift(shift_state[i]);

	digitalWrite(PINOUT_LCK, HIGH);
	digitalWrite(PINOUT_LCK, LOW);
}

void shift(unsigned char data) {
	for(int i = 0; i < 8; i++) {
		bool bit = (data & 1 << (7 - i)) > 0;

		digitalWrite(PINOUT_SER, bit);

		digitalWrite(PINOUT_SCK, HIGH);
		digitalWrite(PINOUT_SCK, LOW);
	}
}
