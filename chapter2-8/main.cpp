/*
	리터럴 상수
*/
#include <iostream>

int main()
{
	using namespace std;
	
	unsigned int n = 5u;
	long n2 = 5L;
	double d = 6.0e1;

	int b = 0b0000'0001'0001; // 2진수
	int o = 012; // 8진수
	int h = 0xF; // 16진수
	cout << b << " " << o << " " << h << endl;

	return 0;
}