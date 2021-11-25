#include "software.h"
#include "consts.h"
#include "effects.h"
#include "scan.h"

unsigned long frame_time_millis;
bool led_state[64];
bool scan_enable = true;

void setup() {
	pinMode(PINOUT_SER, OUTPUT);
	pinMode(PINOUT_SCK, OUTPUT);
	pinMode(PINOUT_LCK, OUTPUT);

	#ifdef DEBUG
	Serial.begin(CONFIG_SERIAL_BAUD);
	#endif

	frame_time_millis = 1000 / CONFIG_FRAMERATE * CONFIG_FRAMERATE;
}

void loop() {
	unsigned long current_time = millis();

	unsigned long slide_time = current_time % SLIDESHOW_DURATION;
	unsigned int  slide_index = (current_time / SLIDESHOW_DURATION) % SLIDESHOW_SIZE;

	slideshow_effects[slide_index](slide_time, &led_state);

	if (scan_enable) scan();
}
