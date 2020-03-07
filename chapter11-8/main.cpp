/*
	상속받은 함수 감추기

	1. private:
		  using Base::print;

	2. private:
		  void print() = delete;

	자식클래스가 부모로부터 상속받았다고 해서 외부에서 접근이 불가함
*/

#include <iostream>

using namespace std;

class Base
{
protected:
	int m_i;

public:
	Base(int value) : m_i(value) {}

	void print()
	{
		cout << "i am base" << endl;
	}

};

class Derived : public Base
{
public:
	Derived(int value) :Base(value) {}

	using Base::m_i; //protected 변수를 public으로 강제 변환

private:
	using Base::print; //do not add () 

private:
	void print() = delete;
};

int main()
{
	Base b(5);
	b.print();
	Derived d(5);

	d.m_i = 10;
	cout << d.m_i << endl;

	//d.print();
	return 0;
}