#define PINOUT_SER 2
#define PINOUT_SCK 3
#define PINOUT_LCK 4

bool leds[16];

void animate() {
	unsigned long t_offset = millis() % (unsigned long)15e3;
	if(0e3 < t_offset && t_offset < 4e3) {
		bool flip_state = (t_offset % 1000) > 500;
		for(int i = 0; i < 16; i++) leds[i] = (i % 2 == flip_state) ^ (i / 4 % 2 == 0) > 0;
	}
	else if(4e3 < t_offset && t_offset < 7e3) {
		bool flip_state = (t_offset % 1000) < 500;
		for(int i = 0; i < 16; i++) leds[i] = flip_state;
	}
	else if(7e3 < t_offset && t_offset < 11e3) {
		int index = (t_offset - 7e3) / 250;
		int volgorde[16] = {0, 1, 2, 3, 7, 6, 5, 4, 8, 9, 10, 11, 15, 14, 13, 12};
		leds[volgorde[(index - 1) % 16]] = 0;
		leds[volgorde[index % 16]] = 1;
	}
	else if(11e3 < t_offset && t_offset < 15e3) {
		int index = (t_offset - 11e3) / 250;
		int volgorde[16] = {0, 1, 2, 3, 7, 6, 5, 4, 8, 9, 10, 11, 15, 14, 13, 12};
		memset(&leds, 0, sizeof(int) * 16);
		leds[volgorde[index % 16]] = 1;
		leds[volgorde[15 - index]] = 1;
	}
}

void setup() {
	pinMode(PINOUT_LCK, OUTPUT);
	pinMode(PINOUT_SCK, OUTPUT);
	pinMode(PINOUT_SER, OUTPUT);
	Serial.begin(115200);
}

void loop() {
	animate();
	for (int row = 0; row < 4; row++) {
		unsigned char serdata = 0xff ^ (1 << (row + 4));

		serdata = (serdata & 0b11110000) |
			leds[row * 4 + 0] << 3 |
			leds[row * 4 + 1] << 2 |
			leds[row * 4 + 2] << 1 |
			leds[row * 4 + 3] << 0;

		digitalWrite(PINOUT_LCK, LOW);
		shiftOut(PINOUT_SER, PINOUT_SCK, LSBFIRST, serdata);
		digitalWrite(PINOUT_LCK, HIGH);
	}
}
