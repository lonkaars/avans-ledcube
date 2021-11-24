#include "shift.h"
#include "consts.h"

unsigned char shift_state[2] = {0};

void update_shift_state() {
	for(int i = 0; i < 2; i++)
		shift(shift_state[i]);
}

void shift(unsigned char data) {
	#ifdef DEBUG
	Serial.print("Sending data to shift register: ");
	Serial.println(data, BIN);
	#endif

	// pull down latch
	digitalWrite(PINOUT_LCK, LOW);

	for(int i = 0; i < 8; i++) {
		bool bit = (data & 1 << i) > 0;

		// schrijf bit en pulse serial clock
		digitalWrite(PINOUT_SER, bit);
		digitalWrite(PINOUT_SCK, HIGH);
		delayMicroseconds(CONFIG_SRSER_DELAY);
		digitalWrite(PINOUT_SCK, LOW);
	}
	
	// pull up latch
	digitalWrite(PINOUT_LCK, HIGH);
}
