#include "software.h"
#include "effects.h"

void fx_roundabout (unsigned long relative_time, bool (*leds)[64]) {
	unsigned long segment_time = SLIDESHOW_DURATION / 64;
	memset(led_state, 0, sizeof(led_state));
	led_state[(relative_time / segment_time) % 64] = 1;

	return;
}

void fx_wipexyz (unsigned long relative_time, bool (*leds)[64]) {
	bool flip_state = (relative_time % 1000) > 500;
	for(int i = 0; i < 64; i++) led_state[i] = i % 2 == flip_state;

	return;
}

void ( * slideshow_effects [SLIDESHOW_SIZE] )( unsigned long relative_time, bool (*leds)[64] ) = {
 	fx_roundabout,
 	fx_wipexyz,
// 	fx_rainfall
};
