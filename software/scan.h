#pragma once

#define SCAN_HOR 0
#define SCAN_VER 1
extern unsigned char scan_direction;
extern unsigned char scan_index;
extern unsigned char scan_order[8];

unsigned char get_state_row(unsigned char row, unsigned char direction);

void scan();
void optimize_scan();

