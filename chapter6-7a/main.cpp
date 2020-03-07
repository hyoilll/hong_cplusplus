/*
	nullptr
*/

#include <iostream>
#include <cstddef>
using namespace std;

void doSomething(double* ptr)
{
	cout << "address of pointer varaible in doSomething() " << &ptr << endl;
	
	if (ptr != nullptr)
	{
		//do something useful
		cout << *ptr << endl;
		cout << &(*ptr) << endl;
	}
	else
	{
		//no nothing with ptr
		cout << "nullptr" << endl;
	}
}

int main()
{
	double* ptr = 0; // c-style
	ptr = NULL;

	ptr = nullptr; //modern c++

	doSomething(ptr);
	doSomething(nullptr);

	double d = 123.4;

	doSomething(&d);

	ptr = &d;

	doSomething(ptr);

	std::nullptr_t nptr; //nullptr�� �����ϴ� �ڷ��� / #include <cstddef>

	cout << "address of pointer varaible in main() " << &ptr << endl;
	cout << "address of pointer varaible in main() " << *ptr << endl;
	cout << &d << endl;

	/*
		main�� ������ ������ ����Ű�� d�� �޸𸮸� �Լ��� ���ο� �����ͺ����� �Ȱ��� d�� ����Ŵ
	*/

	return 0;
}