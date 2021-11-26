#include "software.h"

unsigned long clamp_time(unsigned long unclamped_time) {
	return unclamped_time / frame_time_millis * frame_time_millis;
}

unsigned int zigzag(unsigned int size, int index) {
	unsigned int zigzag_size = 2 * size - 2;
	unsigned int mod = index % zigzag_size;
	return mod < size - 1 ? mod : zigzag_size - mod;
}
