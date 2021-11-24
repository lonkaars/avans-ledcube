#pragma once

// configuratie opties voor de 'diavoorstelling' van de effecten
#define SLIDESHOW_SIZE     (int) 1
#define SLIDESHOW_DURATION (int) 5e3

// definition of done voor sprint 3
void fx_roundabout (unsigned long relative_time, bool (*leds)[64]);
void fx_wipexyz    (unsigned long relative_time, bool (*leds)[64]);
void fx_rainfall   (unsigned long relative_time, bool (*leds)[64]);

// evil function pointer array
extern void ( * slideshow_effects [SLIDESHOW_SIZE] )( unsigned long relative_time, bool (*leds)[64] );
