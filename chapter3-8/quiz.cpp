#include <iostream>
#include <bitset>
using namespace std;

int main()
{
	//1. 0110 >> 2 -> ?
	unsigned int a = 0b0110;

	cout << std::bitset<4>(a >> 2) << " " << (a >> 2) << endl; // 0001 1

	//2. 5 | 2 -> ?
	a = 5;					//0101
	unsigned int b = 12;	//1100

	cout << std::bitset<4>(a | b) << " " << (a | b) << endl; // 1101 13
	
	//3. 5 & 12 -> ?
	cout << std::bitset<4>(a & b) << " " << (a & b) << endl; // 0100 4

	//4. 5 ^ 12 -> ?
	cout << std::bitset<4>(a ^ b) << " " << (a ^ b) << endl; // 1001 9

	//5. !5 -> ?
	cout << std::bitset<4>(~a) << " " << (~a) << endl; //1010 

	return 0;
}
	
	
