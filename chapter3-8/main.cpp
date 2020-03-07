/*
	비트단위 연산자 (Bitwise Operators)
	비트연산할때는 unsigned를 사용하는게 일반적임, 부호비트때문에
	좀 더 빠른 연산
*/
#include <iostream>
#include <bitset> //2진수로 바꿔서 출력해 주는 라이브러리

int main()
{
	using namespace std;
	
	// << left shift
	unsigned int a = 3;

	cout << std::bitset<8>(a) << endl; //0011

	unsigned int b = a << 3;

	cout << std::bitset<8>(b) << " " << b << endl; //0110

	cout << std::bitset<8>(a << 1) << " " << (a << 1) << endl;
	cout << std::bitset<8>(a << 2) << " " << (a << 2) << endl;
	cout << std::bitset<8>(a << 3) << " " << (a << 3) << endl;
	cout << std::bitset<8>(a << 4) << " " << (a << 4) << endl;
	
	cout << endl;
	
	// >> right shift
	a = 1024;

	cout << std::bitset<16>(a) << endl; //0011

	b = a << 3;

	cout << std::bitset<16>(b) << " " << b << endl; //0110

	cout << std::bitset<16>(a >> 1) << " " << (a >> 1) << endl;
	cout << std::bitset<16>(a >> 2) << " " << (a >> 2) << endl;
	cout << std::bitset<16>(a >> 3) << " " << (a >> 3) << endl;
	cout << std::bitset<16>(a >> 4) << " " << (a >> 4) << endl;

	cout << endl;
	
	//!
	a = 1024;

	cout << std::bitset<16>(~a) << " " << (~a) << endl;

	cout << endl;

	//&, |, ^
	a = 0b1100;
	b = 0b0110;

	cout << std::bitset<4>(a & b) << endl; //0100
	cout << std::bitset<4>(a | b) << endl; //1110
	cout << std::bitset<4>(a ^ b) << endl; //1010

	return 0;
}