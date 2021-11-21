#include "consts.h"

extern unsigned long frame_time_millis;
bool led_state[64];

void shift(unsigned char data) {
	#ifdef DEBUG
	Serial.print("Sending data to shift register: ");
	Serial.println(data, BIN);
	#endif

	// pull down latch register
	digitalWrite(PINOUT_LCK, LOW);

	for(int i = 0; i < 8; i++) {
		bool bit = data & 1 << i > 0;

		// schrijf bit en pulse serial clock
		digitalWrite(PINOUT_SER, bit);
		digitalWrite(PINOUT_SCK, HIGH);
		delayMicroseconds(CONFIG_SRSER_DELAY);
		digitalWrite(PINOUT_SCK, LOW);
	}
	
	// pull up latch register
	digitalWrite(PINOUT_LCK, HIGH);
}

void setup() {
	pinMode(PINOUT_SER, OUTPUT);
	pinMode(PINOUT_SCK, OUTPUT);
	pinMode(PINOUT_LCK, OUTPUT);

	#ifdef DEBUG
	Serial.begin(CONFIG_SERIAL_BAUD);
	#endif

	frame_time_millis = 1000 / CONFIG_FRAMERATE * CONFIG_FRAMERATE;
}

void test_effect1(unsigned long relative_time, bool (*leds)[64]) {
	return;
}
void test_effect2(unsigned long relative_time, bool (*leds)[64]) {
	return;
}
void test_effect3(unsigned long relative_time, bool (*leds)[64]) {
	return;
}


#define SLIDESHOW_SIZE     ( (int) 3 )
#define SLIDESHOW_DURATION ( (int) 5e3 )
// evil function pointer array
void ( * slideshow_effects [SLIDESHOW_SIZE] )( unsigned long relative_time, bool (*leds)[64] ) = {
	test_effect1,
	test_effect2,
	test_effect3
};

void loop() {
	unsigned long current_time = millis();

	unsigned long slide_time = current_time % SLIDESHOW_DURATION;
	unsigned int  slide_index = (current_time / SLIDESHOW_DURATION) % SLIDESHOW_SIZE;

	slideshow_effects[slide_index](slide_time, &led_state);
}
