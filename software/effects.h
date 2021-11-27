#pragma once

// slideshow config
#define SLIDESHOW_SIZE     (int) 3
// uncomment for fixed slide length
// #define SLIDESHOW_DURATION (int) 5e3

// definition of done sprint 3
void fx_roundabout (unsigned long relative_time);
void fx_wipexyz    (unsigned long relative_time);
void fx_rainfall   (unsigned long relative_time);

// evil function pointer array
extern void ( * slideshow_effects [SLIDESHOW_SIZE] )( unsigned long relative_time );
#ifndef SLIDESHOW_DURATION
extern unsigned long slideshow_lengths[SLIDESHOW_SIZE];
#endif
