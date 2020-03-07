/*
	연산자와의 첫 만남
*/
#include <iostream>
using namespace std;

int main()
{
	int x = 2; // x is a variable, 2 is a literal.

	cout << 1 + 2 << endl;

	int y = (x < 0) ? 1 : 2; // (x > 0)이 참이면 1이 대입됨, 거짓이면 2가 대입

	cout << y << endl;
	cout << "Hello World" << endl;

	return 0;
}