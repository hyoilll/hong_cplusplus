/*
	bit_mask를 활용한 r, g, d 추출
*/

#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	const unsigned int red_mask = 0xFF0000;
	const unsigned int green_mask = 0x00FF00;
	const unsigned int blue_mask = 0x0000FF;

	cout << std::bitset<32>(red_mask) << endl;
	cout << std::bitset<32>(green_mask) << endl;
	cout << std::bitset<32>(blue_mask) << endl;

	unsigned int pixel_color = 0xDAA520; // red, green, blue

	cout << std::bitset<32>(pixel_color) << endl;

	unsigned int red = pixel_color & red_mask; // 11011010 00000000 00000000
	red = red >> 16; // 00000000 00000000 11011010
	
	cout << "red " << std::bitset<8>(red) << " " << int(red) << endl; // 11011010

	unsigned int green = pixel_color & green_mask; //10100101 00000000
	green = green >> 8; //00000000 10100101

	cout << "green " << std::bitset<8>(green) << " " << int(green) << endl; //10100101

	unsigned char blue = pixel_color & blue_mask;

	cout << "blue " << std::bitset<8>(blue) << " " << int(blue) << endl;


	return 0;
}