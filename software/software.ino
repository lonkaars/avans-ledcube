#include "software.h"
#include "consts.h"
#include "effects.h"
#include "scan.h"

unsigned long frame_time_millis;
bool led_state[64];
bool scan_enable = true;
#ifndef SLIDESHOW_DURATION
unsigned long slideshow_length_total;
#endif

void setup() {
	pinMode(PINOUT_SER, OUTPUT);
	pinMode(PINOUT_SCK, OUTPUT);
	pinMode(PINOUT_LCK, OUTPUT);

	#ifdef DEBUG
	Serial.begin(CONFIG_SERIAL_BAUD);
	#endif

	#ifndef SLIDESHOW_DURATION
	for(int i = 0; i < SLIDESHOW_SIZE; i++)
		slideshow_length_total += slideshow_lengths[i];
	#endif

	frame_time_millis = 1000 / CONFIG_FRAMERATE * CONFIG_FRAMERATE;
}

void loop() {
	unsigned long current_time = millis();

	#ifdef SLIDESHOW_DURATION
	unsigned long slide_time = current_time % SLIDESHOW_DURATION;
	unsigned int  slide_index = (current_time / SLIDESHOW_DURATION) % SLIDESHOW_SIZE;
	#else
	unsigned long slide_time = current_time % slideshow_length_total;
	unsigned int  slide_index = 0;
	unsigned long slide_sum = 0;
	for(int i = 0; i < SLIDESHOW_SIZE; i++) {
		slide_sum += slideshow_lengths[i];
		if (slide_time >= slide_sum) continue;
		slide_index = i;
		break;
	}
	#endif
	slideshow_effects[slide_index](slide_time, &led_state);

	if (scan_enable) scan();
}
