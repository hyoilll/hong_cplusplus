/*
	������

	��ü�� ������� �� ���� ���� ȣ��Ǵ� �Լ�
*/

#include <iostream>

using namespace std;

class Fraction
{
private:
	int m_numeraotr;
	int m_denominator;

public:
	//Fraction(){} default ������, ����ڰ� ���� �����ڷ� �����ϸ� default���������� �ڵ����� ����� ���� ����.

	Fraction(const int& numeraotr_input, const int& denominator_input)
	{
		m_numeraotr = numeraotr_input;
		m_denominator = denominator_input;
	}
	
	Fraction()
	{
		m_numeraotr = 0;
		m_denominator = 0;
	}

	void print()
	{
		cout << m_numeraotr << " / " << m_denominator << endl;
	}
};

class Second
{
public:
	Second() { cout << "class Second consturctor()" << endl; }
};

class Frist
{
public:
	Second sec;

public:
	Frist()
	{
		cout << "class Firtst constructor()" << endl;
	}
};

int main()
{
	Fraction frac(3.0, 5);

	/*
		Fraction frac(3.0, 5) vs Fraction frac2{ 3.0,5 }; 
		������
		()�� ������ ����ȯ�� ��� ����ִ� �ݸ�, {}�� error���� ����� �� ������.
	*/

	frac.print();
	cout << endl;

	//--------------------------------------------------------

	Frist f;
	/*
		class�� �ٸ� class�� ����� ��� �ִ� ���� 
	*/
	return 0;
}