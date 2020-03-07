/*
	형변환 오버로딩
*/

#include <iostream>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(const int& cents = 0) : m_cents(cents) {}

	int getCents()const { return m_cents; }
	void setCents(const int& cents) { m_cents = cents; }

	//int형으로 변환
	operator int()
	{
		return m_cents;
	}
};

void printInt(const int& value)
{
	cout << value << endl;
}

class Dollar
{
private:
	int m_dollars = 0;

public:
	Dollar(const int& input) : m_dollars(input) {}

	operator Cents()
	{
		return Cents(m_dollars * 100);
	}
};

int main()
{
	Cents c(7);
	int value = (int)c;
	value = int(c);
	value = static_cast<int>(c);

	printInt(c);

	//------------------------------------------------

	Dollar d(2);

	Cents cents = d;

	printInt(cents);
	return 0;
}