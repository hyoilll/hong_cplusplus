/*
	익명 객체
*/

#include <iostream>
using namespace std;

class A
{
public:
	int m_value;

public:
	A()
	{
		cout << "Constructor" << endl;
		cout << this << endl;
	}
	~A()
	{
		cout << "Destructor" << endl;
	}
	void print()
	{
		cout << "Hello" << endl;
	}
};

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	int getCents()const { return m_cents; }
};

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
	/*A a;

	a.print();

	//인스턴스를 만들지 않고 호출 = 재사용 불가
	A().print();
	A().print();
	//생성과 소멸이 이 한줄에서 다 일어남
	cout << endl;*/

	//------------------------------------------------------------

	cout << add(Cents(4), Cents(2)).getCents() << endl;
	cout << int(4) + int(2) << endl;

	return 0;
}