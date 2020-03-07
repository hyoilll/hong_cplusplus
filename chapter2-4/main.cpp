/*
	void, void*
*/
#include <iostream>

int main()
{
	using namespace std;

	int i = 123;
	float f = 123.456f;

	void* my_void = nullptr;

	my_void = (void*)&i;
	
	cout << &i << endl;
	cout << my_void << endl;
	cout << &my_void << endl;
	

	return 0;
}