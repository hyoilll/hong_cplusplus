/*
	지역 범위
*/
#include <iostream>
using namespace std;

void doSomething(int x)
{
	x = 123;
	cout << x << endl; // 123
}


int main()
{
	int x = 0;

	cout << x << endl; // 0
	doSomething(x);
	cout << x << endl; // 0

	{
		int x = 5;
		cout << x << endl;
	}

	return 0;
}