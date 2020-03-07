/*
	주소에 의한 전달 call-by-address
*/

#include <iostream>
using namespace std;

void foo(int* ptr)
{
	cout << *ptr << " " << ptr << " " << &ptr << endl;

	*ptr = 10;

	return;
}

int main()
{
	int value = 5;

	cout << value << " " << &value << endl;

	int* ptr = &value;

	foo(ptr);
	foo(&value);
	//foo(5); : error, const활용한 기호적상수도 error



	return 0;
}