/*
	��ȯ ������ - �����ڸ� ��ȯ�����ִ� ������,
	explicit - ��ȯ�����ڸ� �������ϰ� ���ƹ���,
	delete - Ư���� �����ڸ� ������� ���ϰ� ��������
*/

#include <iostream>
#include <cassert>
using namespace std;

class Fraction
{
private:
	int m_numerator;
	int m_denominator;
public:
	Fraction(char) = delete;

	explicit Fraction(int num = 0, int den = 1) :m_numerator(num), m_denominator(den)
	{
		assert(den != 0); //true - ���, false - error
	}

	//��������ڸ� ȣ���ϱ� ������ ������ private������ ������.
	Fraction(const Fraction& fraction) :m_numerator(fraction.m_numerator), m_denominator(fraction.m_denominator)
	{
		cout << "Copy consturctor called" << endl;
	}

	friend std::ostream& operator << (std::ostream& out, const Fraction& f)
	{
		cout << f.m_numerator << " / " << f.m_denominator << endl;
		return out;
	}
};

void doSomething(Fraction f)
{
	cout << f << endl;
}

int main()
{
	doSomething(Fraction(7));

	//��ȯ������, Fraction���� ���� �� �ֵ��� �Ű������� ��ȯ ������
	
	//doSomething(7); 
	
	//explicit Ű���带 �߰��ϸ� error
	// => doSomething(Fraction(7));
	
	//Fraction('c'); //delete Ű����� ���� char�� �޴� ��ü�� ���� �Ұ�
	
	return 0;
}