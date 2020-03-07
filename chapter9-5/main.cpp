/*
	증감 연산자 오버로딩
*/

#include <iostream>

using namespace std;

class Digit
{
private:
	int m_digit;

public:
	Digit(const int digit = 0) :m_digit(digit) {}

	//prefix ++a
	//반환값이 Digit&인 이유는 ++연산 후 다시 <<연산자로 오버로딩 되있기에 연쇄호출 위한 것.
	Digit& operator++()
	{
		m_digit += 1;

		return *this; //자기 자신을 반환
	}

	/*void operator++()
	{
		m_digit += 1;
	}*/

	//postfix a++
	Digit operator ++(int)
	{
		Digit temp(m_digit);

		++(*this);

		return temp;
	}
	
	//prefix --a
	Digit& operator--()
	{
		m_digit -= 1;

		return *this;
	}

	//postfix a--
	Digit operator--(int)
	{
		Digit temp(m_digit);

		--(*this);

		return temp;
	}

	friend ostream& operator<<(std::ostream& out, const Digit& d)
	{
		out << d.m_digit << endl;

		return out;
	}

	int getDigit()const { return m_digit; }
};

int main()
{
	int a = 10;

	cout << ++a << endl;	//11
	cout << a << endl;		//11
	cout << a++ << endl;	//11
	cout << a << endl;		//12
	cout << endl;

	//--------------------------------------------------------

	Digit d(10);

	cout << ++d;
	cout << d;
	cout << d++;
	cout << d;
	cout << endl;

	//--------------------------------------------------------

	cout << --d;
	cout << d;
	cout << d--;
	cout << d;
	return 0;
}