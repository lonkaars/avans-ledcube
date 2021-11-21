#define SERIAL_DELAY 3

// groen
#define SERIAL_CLK 4
// geel
#define SERIAL_INP 2
// blauw
#define LATCH_CLK 3

void setup() {
	pinMode(SERIAL_CLK, OUTPUT);
	pinMode(SERIAL_INP, OUTPUT);
	pinMode(LATCH_CLK, OUTPUT);
	Serial.begin(9600);
}

void shift(unsigned char gert) {
	digitalWrite(LATCH_CLK, LOW);
	delay(SERIAL_DELAY);
	shiftOut(SERIAL_INP, SERIAL_CLK, LSBFIRST, gert);
	digitalWrite(LATCH_CLK, HIGH);
	delay(SERIAL_DELAY);
	Serial.println(gert, BIN);
}

void ani1() {
  for(int i = 0; i < 8; i++) {
    delay(200);
		shift(0b01010101 << (i % 2 == 0));
  }
}

void ani2() {
  for(int j = 0; j < 2; j++) {
		for(int i = 0; i < 8; i++) {
			delay(100);
			shift(1 << i);
		}
		for(int i = 6; i > 0; i--) {
			delay(100);
			shift(1 << i);
		}
  }
}

void ani3() {
  for(int j = 0; j < 2; j++) {
		for(int i = 1; i < 8; i++) {
			delay(100);
			shift(1 << i | 1 << (i-1));
		}
		for(int i = 6; i > 1; i--) {
			delay(100);
			shift(1 << i | 1 << (i-1));
		}
  }
}

void ani4() {
  for(int j = 0; j < 2; j++) {
		for(int i = 0; i < 8; i++) {
			delay(100);
			unsigned char state = 1 << i | 1 << (7 - i);
			shift(state);
		}
		for(int i = 6; i > 0; i--) {
			delay(100);
			unsigned char state = 1 << i | 1 << (7 - i);
			shift(state);
		}
  }
}

void loop() {
	
	/*digitalWrite(LATCH_CLK, HIGH);
	shift(0b00000000);
	digitalWrite(LATCH_CLK, LOW);
	delay(SERIAL_DELAY);
	delay(1e3);

	digitalWrite(LATCH_CLK, HIGH);
	shift(0b11111111);
	digitalWrite(LATCH_CLK, LOW);
	delay(SERIAL_DELAY);
	delay(1e3);*/
  ani1();
  ani2();
  ani3();
  ani4();
}
