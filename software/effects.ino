#include "const.h"
#include "effects.h"
#include "animation.h"

#define FX_LEN_ROUNDABOUT 5e3
void fx_roundabout (unsigned long relative_time, bool (*leds)[64]) {
	memset(leds, 0, sizeof(leds));
	unsigned long tick = relative_time / 300;
	unsigned int roundabout_coordinates[12] = {
		0x0, 0x1, 0x2, 0x3, 0x7, 0xb,
		0xf, 0xe, 0xd, 0xc, 0x8, 0x4
	};
	
	for(int trail = 0; trail < 4; trail++) {
		unsigned int xy_coords = roundabout_coordinates[(tick + trail) % 12];
		for(int z = 0; z < 4; z++) *leds[led_map[xy_coords + z * 0xf0]] = 1;
	}

	return;
}

#define FX_LEN_WIPEXYZ 6e3
void fx_wipexyz (unsigned long relative_time, bool (*leds)[64]) {
	memset(leds, 0, sizeof(leds));
	unsigned long tick = relative_time / 200;
	unsigned int  direction = (tick / 6) % 3;

	fill_plane(direction, zigzag(4, tick));

	return;
}

#define FX_LEN_RAINFALL 7e3
void fx_rainfall (unsigned long relative_time, bool (*leds)[64]) {

	return;
}

void ( * slideshow_effects [SLIDESHOW_SIZE] )( unsigned long relative_time, bool (*leds)[64] ) = {
 	fx_roundabout,
 	fx_wipexyz,
 	fx_rainfall
};

#ifndef SLIDESHOW_DURATION
unsigned long slideshow_lengths[SLIDESHOW_SIZE] = {
	FX_LEN_ROUNDABOUT,
	FX_LEN_WIPEXYZ,
	FX_LEN_RAINFALL
};
#endif

/* void test_leds_inorder (unsigned long relative_time, bool (*leds)[64]) {
	unsigned long segment_time = SLIDESHOW_DURATION / 64;
	memset(leds, 0, sizeof(leds));
	*leds[(relative_time / segment_time) % 64] = 1;

	return;
} */

