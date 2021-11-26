#define SERIAL_DELAY 3

#define SERIAL_CLK 4
#define SERIAL_INP 2
#define LATCH_CLK 3

void shift(unsigned char gert, unsigned char gert2) {
	digitalWrite(LATCH_CLK, LOW);
	shiftOut(SERIAL_INP, SERIAL_CLK, LSBFIRST, gert);
	shiftOut(SERIAL_INP, SERIAL_CLK, LSBFIRST, gert2);
	digitalWrite(LATCH_CLK, HIGH);
}

void setup() {
	pinMode(SERIAL_CLK, OUTPUT);
	pinMode(SERIAL_INP, OUTPUT);
	pinMode(LATCH_CLK, OUTPUT);

	shift(0, 0);
}

unsigned int i = 0;

void loop() {
	i = ( i + 1 ) % 64;
	unsigned char sr1 = 0x00 ^ (1 << (i / 8));
	unsigned char sr2 = 0xff ^ (1 << (i % 8));

	shift(sr1, sr2);

	delay(10);
}
