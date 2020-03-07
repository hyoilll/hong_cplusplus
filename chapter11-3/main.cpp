/*
	������ Ŭ�������� ���� ����

	�θ�Ŭ������ ���� �ʱ�ȭ �� �ڽ�Ŭ������ �ʱ�ȭ��
*/

#include <iostream>

using namespace std;

class Mother
{
public:
	int m_i;

	Mother() :m_i(1)
	{
		cout << "Mother construction" << endl;
	}
	~Mother()
	{
		cout << "Mother distruction" << endl;
	}
};

class Child : public Mother
{
public:
	double m_d;

	Child() : m_d(1.0)
	{
		cout << "Child construction" << endl;
	}
	~Child()
	{
		cout << "Child distruction" << endl;
	}
};

class A
{
public:
	A()
	{
		cout << "A constructor" << endl;
	}
};

class B : public A
{
public:
	B()
	{
		cout << "B constructor" << endl;
	}
};

class C : public B
{
public:
	C()
	{
		cout << "C constructor" << endl;
	}
};

int main()
{
	Child c;

	cout << endl;

	C cc;
	return 0;
}