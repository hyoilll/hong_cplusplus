/*
	���� ����ȯ (Dynamic Casting)

	�θ�Ŭ������ �ε����ϰ� �ڽ�Ŭ������ ����Ǿ�� �ϴ� ���

	ex) 
	
	Base* b = new Derived();

	auto* temp = dynamic_cast<Derived*>(b);
*/

#include <iostream>
using namespace std;

class Base
{
public:
	int m_i = 0;

	virtual void print() const
	{
		cout << "I'm Base" << endl;
	}
};

class Derived1 : public Base
{
public:
	int m_j = 1024;

	virtual void print() const override
	{
		cout << "I'm derived1" << endl;
	}
};

class Derived2 : public Base
{
public:
	string m_str = "hi";

	virtual void print() const override
	{
		cout << "I'm derived2" << endl;
	}
};

int main()
{
	Derived1 d1;

	d1.m_j = 2048;
	
	Base* b = &d1;

	auto* base_to_d1 = dynamic_cast<Derived1*>(b);

	//casting ���м� nullptr��ȯ <-> static_cast �� �����Ǻ�ȯ���� nullptrüũ ����
	if (base_to_d1 != nullptr)
		cout << base_to_d1->m_j;
	else
		cout << "Failed" << endl;



	return 0;
}