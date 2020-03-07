/*
	산술 연산자 오버로딩

	연산자 오버로딩이 안되는 연산자 (?: :: sizeof . .*)

	오버로딩을 해도 연산자 우선순위는 그대로임

	^연산자는 우선순위가 낮아서 안하는게 낫다.

	=, [], (), ->은 멤버 함수로만 오버로딩이 가능
*/

#include <iostream>
#include <fstream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(const int& cents) : m_cents(cents) {}

	int getCents()const { return m_cents; }
	
	Cents operator+(const Cents& c2)
	{
		return Cents(m_cents + c2.m_cents);
	}

	Cents operator-(const Cents& c2)
	{
		return Cents(m_cents - c2.m_cents);
	}

	Cents operator*(const Cents& c2)
	{
		return Cents(m_cents * c2.m_cents);
	}

	Cents operator/(const Cents& c2)
	{
		return Cents(m_cents / c2.m_cents);
	}

	friend ostream& operator<<(std::ostream& out, const Cents& c)
	{
		out << c.m_cents;
		return out;
	}
};

/*Cents operator+(const Cents& c1, const Cents& c2)
{
	return Cents(c1.m_cents + c2.m_cents);
}*/

int main()
{
	
	Cents c1(6);
	Cents c2(8);

	cout << (c1 + c2 + Cents(6)).getCents() << endl;
	//== (c1.operator+(c2)).operator+(Cents(6));

	cout << (c1 - c2).getCents() << endl;

	cout << (c1 * c2).getCents() << endl;

	cout << (c1 / c2).getCents() << endl;

	ofstream of("test.txt");

	of << c1;

	of.close();
	return 0;
}