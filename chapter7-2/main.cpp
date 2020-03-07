/*
	값에 의한 전달 call-by-value
*/

#include <iostream>
using namespace std;

void print(int y)
{
	cout << "In func " << y << " " << &y << endl;
}

int main()
{
	print(5);

	int x = 6;

	cout << "In main " << x << " " << &x << endl;

	print(x);
	print(x + 1);

	return 0;
}