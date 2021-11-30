#pragma once

#include "consts.h"

/** @brief round time to nearest frame */
unsigned long clamp_time(unsigned long unclamped_time, double framerate);

/** @brief get frame */
unsigned long get_frame(unsigned long unclamped_time, double framerate);

/** @brief 'zigzag' value between 0 and `size - 1`, like modulo (`%`) operator */
unsigned int zigzag(unsigned int size, int index);

/** @brief color leds on plane perpendicular to `direction` with `offset` */
void fill_plane(unsigned int direction, unsigned int offset);
