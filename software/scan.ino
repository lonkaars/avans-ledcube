#include "scan.h"
#include "shift.h"
#include "software.h"

#ifdef DEBUG
#include "util.h"
#endif

// 0 = horizontal (top-bottom), 1 = vertical (left-right)
unsigned char scan_direction = 0;
unsigned char scan_index = 0;
unsigned char scan_order[8] = {1, 1, 1, 1, 1, 1, 1, 1};

unsigned char get_state_row(unsigned char row, unsigned char direction) {
	unsigned char return_value = 0;

	for (int i = 0; i < 8; i++)
		return_value = return_value | ( led_state[
			direction == SCAN_HOR ? (i + row * 8) : (row + i * 8) ] << (7 - i));

	return return_value;
}

void scan() {
	// optimize_scan();

	shift_state[0] = 0x00 ^ (1 << scan_index);
	shift_state[1] = 0xff ^ get_state_row(scan_index, scan_direction);

	update_shift_state();

	// go to next row/column
	for(int i = scan_index + 1; i < (scan_index + 7); i++) {
		if (scan_order[i % 8] == 0) continue;
		scan_index = i % 8;
		break;
	}
}

void optimize_scan() {
	unsigned char optimal_direction,
								hv_emptyc[2] = {0, 0},
								hv_empty[2][8];

	// calculate empty rows/columns
	for(unsigned char direction = 0; direction < 2; direction++) {
		for(unsigned char row; row < 8; row++) {
			hv_empty[direction][row] = get_state_row(row, direction) == 0;
			hv_emptyc[direction] += hv_empty[direction][row];
		}
	}

	// print_led_state();
	// delay(20);

	Serial.print("[ ");
	for(int i = 0; i < 8; i++) {
		Serial.print((unsigned int) hv_empty[0][i], DEC);
		if(i != 7) Serial.print(", ");
	}
	Serial.print(" ] ");


	optimal_direction = hv_emptyc[0] > hv_emptyc[1] ? 0 : 1;
	scan_direction = optimal_direction;
	memcpy(&scan_order, &hv_emptyc[optimal_direction], sizeof(scan_order));

	return;
}

