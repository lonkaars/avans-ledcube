#include "effects.h"

void fx_roundabout (unsigned long relative_time, bool (*leds)[64]) {
	return;
}

void ( * slideshow_effects [SLIDESHOW_SIZE] )( unsigned long relative_time, bool (*leds)[64] ) = {
 	fx_roundabout,
// 	fx_wipexyz,
// 	fx_rainfall
};
