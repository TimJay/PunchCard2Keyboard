//Copyright Tim Jagenberg <tim@jagenberg.info>
//Licensed under the Apache License, Version 2.0
//http://www.apache.org/licenses/LICENSE-2.0.html
//
//Program Version 1.0

#ifndef _PunchCard2Keyboard_H_
#define _PunchCard2Keyboard_H_
#include "Arduino.h"

#ifdef __cplusplus
extern "C" {
#endif
void loop();
void setup();
#ifdef __cplusplus
}
#endif

#define ROWY 15
#define ROWX 14
#define ROW0 12
#define ROW1 11
#define ROW2 10
#define ROW3 9
#define ROW4 8
#define ROW5 7
#define ROW6 6
#define ROW7 5
#define ROW8 4
#define ROW9 3

uint8_t row_map[] = { 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 14, 15 };

uint16_t index_map[] = {
		1,
		2,
		4,
		8,
		16,
		32,
		64,
		128,
		256,
		512,
		1024,
		2048,
		9,
		17,
		33,
		65,
		129,
		257,
		513,
		1025,
		2049,
		10,
		18,
		34,
		66,
		130,
		258,
		514,
		1026,
		2050,
		12,
		20,
		36,
		68,
		132,
		260,
		516,
		1028,
		2052,
		1040,
		1056,
		1088,
		1152,
		1280,
		1536,
		1041,
		1057,
		1089,
		1153,
		1281,
		1537,
		1042,
		1058,
		1090,
		1154,
		1282,
		1538,
		1044,
		1060,
		1092,
		1156,
		1284,
		1540,
		3
};

char char_map[] = {
		'&',
		'-',
		'0',
		'1',
		'2',
		'3',
		'4',
		'5',
		'6',
		'7',
		'8',
		'9',
		'A',
		'B',
		'C',
		'D',
		'E',
		'F',
		'G',
		'H',
		'I',
		'J',
		'K',
		'L',
		'M',
		'N',
		'O',
		'P',
		'Q',
		'R',
		'/',
		'S',
		'T',
		'U',
		'V',
		'W',
		'X',
		'Y',
		'Z',
		':',
		'#',
		'@',
		'\'',
		'=',
		'"',
		'c',
		'.',
		'<',
		'(',
		'+',
		'|',
		'!',
		'$',
		'*',
		')',
		';',
		'~',
		' ',
		',',
		'%',
		'_',
		'>',
		'?',
		' '
};

#endif /* _PunchCard2Keyboard_H_ */
