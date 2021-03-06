/*
	이진수(Binary Numbers)
*/

#include <iostream>
using namespace std;

int main()
{
	/*
		0	= 2^0 * 0						= 0
		1	= 2^0 * 1						= 1
		10	= 2^1 * 1 + 2^0 * 0				= 2
		11	= 2^1 * 1 + 2^0 * 1				= 3
		100	= 2^2 * 1 + 2^1 * 0 + 2^0 * 0	= 4
		101
		110
		111
		1000
		...
	*/

	/*
		2진수 -> 10진수

		7	6	5	4	3	2	1	0
		128	64	32	16	8	4	2	1
		0	1	0	1	1	1	1	0

		= 2^7 * 0 + 2^6 * 1 + 2^5 * 0 + 2^4 * 1 + 2^3 * 1 + 2^2 *1 + 2^1 * 1 + 2^0 * 0 = 94
	*/
	
	/*
		10진수 -> 2진수

		1. 148

		148 / 2 = 74 ... 0
		74	/ 2 = 37 ... 0
		37	/ 2 = 18 ... 1
		18	/ 2 = 9	 ... 0
		9	/ 2 = 4  ... 1
		4	/ 2 = 2  ... 0
		2	/ 2 = 1  ... 0
		1	/ 2 = 0  ... 1

		=> 1001 0100

		2. 148

		128	64	32	16	8	4	2	1
		 1	0	0	1	0	1	0	0

		148 >= 128 -> 148 - 128 = 20

		20 >= 16 -> 20 - 16 = 4

		4 >= 4 -> 4 - 4 = 0

		=> 1001 0100
	*/

	/*
		2진수 덧셈

			0110	= 6
		+	0111	= 7
		=	1101	= 13
	*/

	/*
		2의 보수

		-5
		
		0000 0101 = 5
		1111 1010 = 1의 보수
		1111 1011 = 2의 보수 => -5
		
		0000 0100 = 1의 보수
		0000 0101 = 2의 보수 => 5

		ex)
		1001 1110의 10진수 값은?

		0110 0001 -> 0110 0010 = 64 + 32 + 2 = 98 = -98 

		-98의 2진수 값은?

		0110 0010 -> 1001 1101 -> 1001 1110
	*/

	/*
		signed vs unsigned

		unsigned 0 ~ 255
		1001 1110 -> 128 + 16 + 8 + 4 + 2 = 158

		signed -128 ~ 127
		1001 1110 -> 0110 0001 -> 0110 0010 = 64 + 32 + 2 = 98 = -98
	*/


	return 0;
}