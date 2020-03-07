/*
	��ӹ��� �Լ� ���߱�

	1. private:
		  using Base::print;

	2. private:
		  void print() = delete;

	�ڽ�Ŭ������ �θ�κ��� ��ӹ޾Ҵٰ� �ؼ� �ܺο��� ������ �Ұ���
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

	using Base::m_i; //protected ������ public���� ���� ��ȯ

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