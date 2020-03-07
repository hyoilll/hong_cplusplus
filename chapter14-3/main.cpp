/*
	예외 클래스와 상속
*/

#include <iostream>

using namespace std;

class Exception
{
public:
	virtual void report() const
	{
		cerr << "Exception report" << endl;
	}
};

class ArrayException : public Exception
{
public:
	void report() const override
	{
		cerr << "Array exception" << endl;
	}
};

class MyArray
{
private:
	int m_arr[5];

public:
	int& operator[] (const int& index)
	{
		//if (index < 0 || index > 4) throw - 1;
		if (index < 0 || index > 4) throw ArrayException();

		return m_arr[index];
	}
};

void doSomething()
{
	MyArray my_arr;

	try
	{
		my_arr[100]; //멤버함수에서 throw를 던져도 받을 수 있음.
	}
	catch (const int& x)
	{
		cerr << "Exception" << x << endl;
	}
	catch (Exception & e)// Exception & e = ArrayException();
	{
		cout << "doSomething()" << endl;
		e.report();

		//rethorw
		throw e; //하면 다형성이 풀림?
		//throw;
	}
}

int main()
{
	try
	{
		doSomething();
	}
	catch (Exception & e)
	{
		cout << "main()" << endl;
		e.report();
	}

	return 0;
}