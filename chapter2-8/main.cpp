/*
	���ͷ� ���
*/
#include <iostream>

int main()
{
	using namespace std;
	
	unsigned int n = 5u;
	long n2 = 5L;
	double d = 6.0e1;

	int b = 0b0000'0001'0001; // 2����
	int o = 012; // 8����
	int h = 0xF; // 16����
	cout << b << " " << o << " " << h << endl;

	return 0;
}