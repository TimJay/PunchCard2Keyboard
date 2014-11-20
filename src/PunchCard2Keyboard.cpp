//Copyright Tim Jagenberg <tim@jagenberg.info>
//Licensed under the Apache License, Version 2.0
//http://www.apache.org/licenses/LICENSE-2.0.html
//
//Program Version 1.0

#include "PunchCard2Keyboard.h"

boolean buffer[12];
boolean wasAllHigh = true;
boolean wasAllLow = false;
boolean cardActive = false;

void resetBuffer() {
	for (uint8_t i = 0; i < 12; i++) {
		buffer[i] = false;
	}
	wasAllHigh = false;
	wasAllLow = false;
}

void setup() {
	Serial.begin(115200);
	pinMode(ROWY, INPUT_PULLUP);
	pinMode(ROWX, INPUT_PULLUP);
	pinMode(ROW0, INPUT_PULLUP);
	pinMode(ROW1, INPUT_PULLUP);
	pinMode(ROW2, INPUT_PULLUP);
	pinMode(ROW3, INPUT_PULLUP);
	pinMode(ROW4, INPUT_PULLUP);
	pinMode(ROW5, INPUT_PULLUP);
	pinMode(ROW6, INPUT_PULLUP);
	pinMode(ROW7, INPUT_PULLUP);
	pinMode(ROW8, INPUT_PULLUP);
	pinMode(ROW9, INPUT_PULLUP);
	resetBuffer();
}

char getCharacter() {
	uint16_t bufVal = 0;
	for (uint8_t i = 0; i < 12; i++) {
		bufVal |= buffer[i] << (11 - i);
	}
	for (uint8_t i = 0; i < 64; i++) {
		if (bufVal == index_map[i]) {
			return (char_map[i]);
		}
	}
	return (0);
}

void updateBuffer() {
	for (uint8_t i = 0; i < 12; i++) {
		buffer[i] |= !digitalRead(row_map[i]);
	}
}

boolean allRowsHigh() {
	boolean all = true;
	for (uint8_t i = 0; i < 12; i++) {
		all &= !digitalRead(row_map[i]);
	}
	return (all);
}

boolean allRowsLow() {
	boolean all = false;
	for (uint8_t i = 0; i < 12; i++) {
		all |= !digitalRead(row_map[i]);
	}
	return (!all);
}

void cardStarted() {
	Serial.println("Card started!");
	cardActive = true;
	resetBuffer();
}

void cardFinished() {
	Serial.println();
	Serial.println("Card finished!");
	Keyboard.println();
	cardActive = false;
}

void parseCharacter() {
	char character = getCharacter();
	Serial.print(character);
	Keyboard.print(character);
	resetBuffer();
}

void parseBuffer() {
	if (allRowsHigh()) {
		if (!wasAllHigh) {
			cardFinished();
		}
		wasAllHigh = true;
	} else if (allRowsLow()) {
		if (!cardActive) {
			cardStarted();
		} else if (!wasAllLow) {
			parseCharacter();
		}
		wasAllLow = true;
	} else {
		wasAllHigh = false;
		wasAllLow = false;
	}
}

void loop() {
	updateBuffer();
	parseBuffer();
}
