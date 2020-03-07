/*
	단항 연산자 오버로딩
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

	Cents operator-()const
	{
		return Cents(-m_cents);
	}

	friend ostream& operator<<(std::ostream& out, const Cents& c)
	{
		out << c.m_cents;
		return out;
	}

	bool operator!()const
	{
		if (m_cents == 0)
			return true;
		else
			return false;
	}

};

int main()
{
	Cents c1(6);
	Cents c2(0);

	cout << c1 << endl;
	cout << -c1 << endl;
	cout << -Cents(-10) << endl;

	cout << !c1 << " " << !c2 << endl;

	return 0;
}