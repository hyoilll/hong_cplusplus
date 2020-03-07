/*
	��ü �߸��� reference_wrapper
*/

#include <iostream>
#include <vector>
#include <functional>

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

class Derived : public Base
{
public:
	int m_j = 1;

	virtual void print() const override
	{
		cout << "I'm derived" << endl;
	}
};

void doSomething(const Base& b)
{
	b.print();
}

int main()
{
	Derived d;
	/*
		Base b = d;
		baseŬ������ derived���� ����� �۱⿡ ������ �� ����. base�� ������ ������ ������ ������ �߷�����
	*/
	Base &b = d;

	b.print();

	doSomething(d);

	//--------------------------------

	Base bb;
	Derived dd;

	/*
		std::vector<Base> vec;
		vec.push_back(bb);
		vec.push_back(dd);

		==> ���������� ��ü �߸� ���� �߻���. �������̾ƴ϶� �ܼ� �����̱� ������.
	*/

	std::vector<Base*> vec; //vector�� &���� �� ����. ������ *
	vec.push_back(&bb);
	vec.push_back(&dd);

	/*
		but ���� reference�� vector�� �����ϰ� �ʹٸ�, #include <functional>
		
		std::vector<std::reference_wrapper<Base>> vec;
		vec.push_back(bb);
		vec.push_back(dd);

		for (const auto& e : vec)
			e.get().print();
	*/

	for (const auto& e : vec)
		e->print();

	return 0;
}