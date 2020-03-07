/*
	상속받은 함수 오버라이딩
*/
#include <iostream>

using namespace std;

class Base
{
private:
	int m_private;

public:
	Base(int value) : m_private(value) {}

	void print() const
	{
		cout << "i am base" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Base& b)
	{
		out << "operator << Base;" << std::endl;
		return out;
	}

};

class Derived : public Base
{
private:
	int a;
public:
	Derived(int value) :Base(value) {}

	void print() const
	{
		Base::print();
		cout << "i am derived" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Derived& b)
	{
		//out << static_cast<Base> (b) << endl;
		out << "operator << Derived;" << std::endl;
		return out;
	}
};

int main()
{
	Base b(5);
	b.print();

	Derived d(7);
	d.print();

	cout << endl;

	cout << b;
	cout << d;
	return 0;
}