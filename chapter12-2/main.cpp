/*
	가상함수와 다형성
*/

#include <iostream>

using namespace std;

class A
{
public:
	void print()const { cout << "A" << endl; }
};

class B : public A
{
public:
	void print()const { cout << "B" << endl; }
};

class C : public B
{
public:
	void print()const { cout << "C" << endl; }
};

class D : public C
{
public:
	void print(int a)const { cout << "D" << endl; }
};

int main()
{
	A a;
	a.print();

	B b;
	b.print();

	C c;
	c.print();

	D d;
	//d.print();

	cout << endl;

	A& ref = d;
	ref.print();

	cout << endl;

	A* ptr = &c;
	ptr->print();
	

	return 0;
}