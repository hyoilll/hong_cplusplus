/*
	��Ӱ� ���� ������

	���������ڿ� ������������ڸ� ���ؼ� �� �� ������ ���� ������ ������
*/

#include <iostream>

using namespace std;

class A
{
public:
	int m_public;
protected:
	int m_protected;
private:
	int m_private;
};

class B : public A
{
public:
	B()
	{
		A::m_protected;
		A::m_public;
	}
};

class C : public B
{
public:
	C()
	{
		B::m_protected;
		B::m_public;
	}
};

int main()
{
	B b;

	return 0;
}