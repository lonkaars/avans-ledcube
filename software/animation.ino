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

const unsigned int weights[3] = {1, 4, 16};
void fill_plane(unsigned int direction, unsigned int offset) {
	for(int i = 0; i < 16; i++) {
		unsigned int index = offset * weights[direction];
		index += (i / 4) * weights[(direction + 1) % 3];
		index += (i % 4) * weights[(direction + 2) % 3];

		Serial.print("xyz"[direction]);

		led_state[led_map[index]] = 1;
	}
}

