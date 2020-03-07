/*
	���� ������ �����ε�
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
	//��ȯ���� Digit&�� ������ ++���� �� �ٽ� <<�����ڷ� �����ε� ���ֱ⿡ ����ȣ�� ���� ��.
	Digit& operator++()
	{
		m_digit += 1;

		return *this; //�ڱ� �ڽ��� ��ȯ
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