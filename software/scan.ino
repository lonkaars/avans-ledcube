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
			direction == SCAN_HOR ? (i + row * 8) : (63- row - i * 8) ] << (7 - i));

	return return_value;
}

void scan() {
	optimize_scan();

	if (scan_direction == SCAN_HOR) {
		shift_state[0] = 0x00 ^ (1 << scan_index);
		shift_state[1] = 0xff ^ get_state_row(scan_index, SCAN_HOR);
	} else {
		shift_state[0] = 0x00 ^ get_state_row(scan_index, SCAN_VER);
		shift_state[1] = 0xff ^ (1 << scan_index);
	}

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
		for(unsigned char row = 0; row < 8; row++) {
			hv_empty[direction][row] = get_state_row(direction == SCAN_HOR ? row : 7 - row, direction) > 0;
			hv_emptyc[direction] += hv_empty[direction][row];
		}
	}

	// garbage debug code (delete if worky)
	/* Serial.print("\r\n");
	Serial.print("\r\n");
	Serial.print("\r\n");
	for(int row = -1; row < 8; row++) {
		if (row == -1) {
			for(int i = 0; i < 8; i++) {
				Serial.print(hv_empty[1][i], DEC);
				Serial.print(" ");
			}
			Serial.print("\r\n");
			continue;
		}
		for(int col = 0; col < 9; col++) {
			if (col == 8) {
				Serial.print(hv_empty[0][row], DEC);
				Serial.print(" ");
				continue;
			}
			Serial.print(led_state[row * 8 + col], DEC);
			Serial.print(" ");
		}
		Serial.print("\n\r");
	}
	Serial.print("\r\n");
	Serial.print(hv_emptyc[0], DEC);
	Serial.print(" ");
	Serial.print(hv_emptyc[1], DEC);
	Serial.print("\r\n");
	delay(80); */


	optimal_direction = hv_emptyc[0] > hv_emptyc[1] ? 1 : 0;
	scan_direction = optimal_direction;
	memcpy(&scan_order, &hv_empty[optimal_direction], sizeof(scan_order));

	return;
}

