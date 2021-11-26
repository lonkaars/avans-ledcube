#pragma once

#include "consts.h"

/** @brief round time to nearest frame */
unsigned long clamp_time(unsigned long unclamped_time);

/** @brief 'zigzag' value between 0 and `size - 1`, like modulo (`%`) operator */
unsigned int zigzag(unsigned int size, int index);
