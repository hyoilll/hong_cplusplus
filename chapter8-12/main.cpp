/*
	friend �Լ��� Ŭ����
*/

#include <iostream>
using namespace std;

class B; // class A���� friend�Լ��� �Ű������� const B& b�� �𸣱⿡ ���漱�� ����

class A;

class C
{
public:
	void printFriendValue(const A& a);
};

class A
{
private:
	int m_value = 1;

	friend void doSomething(const A& a, const B& b); //�Լ�   friend
	friend class C;									 //Ŭ���� friend
	friend void C::printFriendValue(const A& a);	 //Ư�� Ŭ������ Ư�� �Լ��� friend����, 
													 //but CŬ������ printFriendValue�� �ִ��� �� �� ��� error
													 //CŬ������ ���� �÷���
};

void C::printFriendValue(const A& a)
{
	cout << a.m_value << endl;
}

class B
{
private:
	int m_value = 2;

	friend void doSomething(const A& a, const B& b);
};


void doSomething(const A& a, const B& b)
{
	cout << a.m_value << " " << b.m_value << endl;
}

int main()
{
	A a;
	B b;
	doSomething(a, b);

	C c;
	c.printFriendValue(a);

	return 0;
}