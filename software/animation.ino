#include "software.h"

unsigned long clamp_time(unsigned long unclamped_time) {
	return unclamped_time / frame_time_millis * frame_time_millis;
}

unsigned int zigzag(unsigned int size, int index) {
	unsigned int zigzag_size = 2 * size - 2;
	unsigned int mod = index % zigzag_size;
	return mod < size - 1 ? mod : zigzag_size - mod;
}

void fill_plane(unsigned int direction, unsigned int offset) {
	for(int i = 0; i < 16; i++) {
		unsigned char axis1_offset = i / 4;
		unsigned char axis2_offset = i % 4;

		unsigned int axis1_weight = pow((direction + 1) % 3, 4);
		unsigned int axis2_weight = pow((direction - 1) % 3, 4);
		unsigned int axis3_weight = pow((direction    ) % 3, 4);

		led_state[
			axis1_offset * axis1_weight +
			axis2_offset * axis2_weight +
			offset * axis3_weight
		] = 1;
	}
}

