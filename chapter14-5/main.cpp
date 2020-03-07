/*
	함수 try

	생성자 이니셜라이즈 리스트에서 발생하는 예외를 처리하는 함수try

	[참조] https://www.learncpp.com/cpp-tutorial/14-7-function-try-blocks/
*/

#include <iostream>
using namespace std;

class A
{
private:
	int a;
public:
	A(const int& a_i) :a(a_i) {}
};

class B : public A
{
private:
	int b;
public:
	/*
		
		B(const int& a_i, const int& b_i) :A(a_i), b(b_i) 
		{
			throw - 1;
		}
	*/

	//생성자의 예외를 호출한 main에서 처리하지 않고, 직접 해당 클래스에서 처리하고 싶은 경우
	B(const int& a_i, const int& b_i)try :A(a_i), b(b_i)
	{
		throw - 1;
	}
	catch (...)
	{
		cout << "Catch int B constructor" << endl;
		//throw;
		//rwthrow가 없이만 마치 있는 것 처럼 main의 catch문도 한번 더 실행됨
	}
};

void doSomething()
{
	try
	{
		throw - 1;
	}
	catch (...)
	{
		cout << "Catch in doSomething()" << endl;
	}
}

int main()
{
	try
	{
		//doSomething();
		B(1, 2);
	}
	catch (...)
	{
		cout << "Catch in main()" << endl;
	}


	return 0;
}