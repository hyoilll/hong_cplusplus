/*
	1. 0100 1101 - > 10����
	64 + 8 + 4 + 1 = 77

	2. 93 -> unsigned 2����
	0101 1101
	93 - 64 = 29
	29 - 16 = 13
	13 - 8  = 5
	5  - 4  = 1
	1  - 1  = 0

	3. -93 -> signed 2����
	0101 1101 -> 1010 0010 -> 1010 0011

	4. 1010 0010 -> unsigned 10����
	128 + 32 + 2 = 162

	5. 1010 0010 -> signed 10����
	1010 0010 -> 0101 1101 -> 0101 1110 -> 64 + 16 + 8 + 4 + 2 = 94 = -94
*/