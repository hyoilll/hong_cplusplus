/*
	참조와 const
*/

#include <iostream>
using namespace std;

void doSomething(const int& x)
{
	cout << x << endl;
}

int main()
{
	const int x = 5;
	const int& ref = x;

	const int& ref2 = ref;

	//---------------------------------------

	/*
		int &ref_x = 3 + 5;

		error
	*/

	const int& ref_x = 3 + 5;

	//int* const ptr = 3 + 5; pointer는 안됨

	cout << ref_x << endl;
	cout << &ref_x << endl;

	int a = 5;

	doSomething(a);		//5
	doSomething(4 + 2);	//6
	doSomething(a + 3);	//7

	return 0;
}