/*
	friend 함수와 클래스
*/

#include <iostream>
using namespace std;

class B; // class A에서 friend함수의 매개변수에 const B& b를 모르기에 전방선언 해줌

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

	friend void doSomething(const A& a, const B& b); //함수   friend
	friend class C;									 //클래스 friend
	friend void C::printFriendValue(const A& a);	 //특정 클래스의 특정 함수만 friend해줌, 
													 //but C클래스에 printFriendValue가 있는지 알 수 없어서 error
													 //C클래스를 위로 올려줌
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