/*
	��� ������ �����ε�

	������ �����ε��� �ȵǴ� ������ (?: :: sizeof . .*)

	�����ε��� �ص� ������ �켱������ �״����

	^�����ڴ� �켱������ ���Ƽ� ���ϴ°� ����.

	=, [], (), ->�� ��� �Լ��θ� �����ε��� ����
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