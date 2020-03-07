/*
	상속과 접근 지정자

	접근지정자와 상속접근지정자를 비교해서 좀 더 범위가 좁은 쪽으로 설정됨
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