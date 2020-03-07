/*
	유도(자식) 클래스에서 출력연산자 사용하기
*/

#include <iostream>
using namespace std;

class Base
{
public:
	Base() {}

	friend std::ostream& operator<<(std::ostream& out, const Base& b)
	{
		return b.print(out);
	}

	virtual std::ostream& print(std::ostream& out)const
	{
		out << "Base";
		return out;
	}
};

class Derived : public Base
{
public:
	Derived() {}

	virtual std::ostream& print(std::ostream& out)const override
	{
		out << "Derivced";
		return out;
	}
};

class C : public Derived
{
public:
	virtual std::ostream& print(std::ostream& out)const override
	{
		out << "C";
		return out;
	}
};

int main()
{
	Base b;
	std::cout << b << endl;

	Derived d;
	std::cout << d << endl;

	C c;
	std::cout << c << endl;

	Base* ptr_b = &d;
	std::cout << *ptr_b << endl;
	return 0;
}