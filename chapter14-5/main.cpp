/*
	�Լ� try

	������ �̴ϼȶ����� ����Ʈ���� �߻��ϴ� ���ܸ� ó���ϴ� �Լ�try

	[����] https://www.learncpp.com/cpp-tutorial/14-7-function-try-blocks/
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

	//�������� ���ܸ� ȣ���� main���� ó������ �ʰ�, ���� �ش� Ŭ�������� ó���ϰ� ���� ���
	B(const int& a_i, const int& b_i)try :A(a_i), b(b_i)
	{
		throw - 1;
	}
	catch (...)
	{
		cout << "Catch int B constructor" << endl;
		//throw;
		//rwthrow�� ���̸� ��ġ �ִ� �� ó�� main�� catch���� �ѹ� �� �����
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