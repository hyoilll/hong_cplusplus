/*
	객체 잘림과 reference_wrapper
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
		base클래스는 derived보다 사이즈가 작기에 복사할 수 없음. base의 정보를 제외한 나머지 정보는 잘려나감
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

		==> 마찬가지로 객체 잘림 현상 발생함. 다형성이아니라 단순 복사이기 때문에.
	*/

	std::vector<Base*> vec; //vector는 &넣을 수 없음. 무조건 *
	vec.push_back(&bb);
	vec.push_back(&dd);

	/*
		but 굳이 reference로 vector를 구현하고 싶다면, #include <functional>
		
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