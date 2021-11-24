#include "software.h"

unsigned long clamp_time(unsigned long unclamped_time) {
	return unclamped_time / frame_time_millis * frame_time_millis;
}
