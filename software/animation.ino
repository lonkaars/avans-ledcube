#include "animation.h"

unsigned long clamp_time(unsigned long unclamped_time, double framerate) {
	int frame_time_millis = (double) 1000 / framerate;
	return unclamped_time / frame_time_millis * frame_time_millis;
}

unsigned long get_frame(unsigned long unclamped_time, double framerate) {
	int frame_time_millis = (double) 1000 / framerate;
	return unclamped_time / frame_time_millis;
}

unsigned int zigzag(unsigned int size, int index) {
	unsigned int zigzag_size = 2 * size - 2;
	unsigned int mod = index % zigzag_size;
	return mod < size - 1 ? mod : zigzag_size - mod;
}

const unsigned int weights[3] = {16, 4, 1};
void fill_plane(unsigned int direction, unsigned int axis3_offset) {
	for(int i = 0; i < 16; i++) {
		unsigned char axis1_offset = i / 4;
		unsigned char axis2_offset = i % 4;

		unsigned int axis1_weight = weights[(direction + 1) % 3];
		unsigned int axis2_weight = weights[(direction - 1) % 3];
		unsigned int axis3_weight = weights[direction];

		led_state[led_map[
			(axis1_offset * axis1_weight +
			axis2_offset * axis2_weight +
			axis3_offset * axis3_weight) % 64
		]] = 1;
	}
}

