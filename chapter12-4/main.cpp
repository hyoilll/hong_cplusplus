/*
	가상 소멸자
*/

#include <iostream>

using namespace std;

class Base
{
public:
	virtual ~Base() 
	{
		cout << "~Base()" << endl;
	}
};

class Derived :public Base
{
private:
	int* m_arr;

public:
	Derived(int length)
	{
		m_arr = new int[length];
	}

	virtual ~Derived() override
	{
		cout << "~Derived()" << endl;
		delete[] m_arr;
	}
};

int main()
{
	Base* b = new Derived(5);

	cout << &b << endl;
	cout << &(*b) << endl;

	delete b;

	return 0;
}