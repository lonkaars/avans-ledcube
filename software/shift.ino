#include "shift.h"
#include "consts.h"
#ifdef DEBUG
#include "util.h"
#endif

unsigned char shift_state[2];

void update_shift_state() {
	for(int i = 0; i < 2; i++)
		shift(shift_state[i]);
}

void shift(unsigned char data) {
	// pull down latch
	digitalWrite(PINOUT_LCK, LOW);

	for(int i = 0; i < 8; i++) {
		bool bit = (data & 1 << i) > 0;

		// write bit and pulse serial clock
		digitalWrite(PINOUT_SER, bit);
		digitalWrite(PINOUT_SCK, HIGH);
		delayMicroseconds(CONFIG_SRSER_DELAY);
		digitalWrite(PINOUT_SCK, LOW);
	}
	
	// pull up latch
	digitalWrite(PINOUT_LCK, HIGH);
}
