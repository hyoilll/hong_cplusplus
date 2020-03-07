/*
	���� ������, ���� �ʱ�ȭ, RVO(Retrun Value Optimization)

	��������� ȣ�� ����
	[����] https://huiyu.tistory.com/entry/C-%EB%B3%B5%EC%82%AC-%EC%83%9D%EC%84%B1%EC%9E%90%EC%9D%98-%ED%98%B8%EC%B6%9C%EC%8B%9C%EC%A0%90
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

	Fraction(int num = 0, int den = 1) :m_numerator(num), m_denominator(den)
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

Fraction doSomething()
{
	Fraction temp(1, 2);

	return temp;
}

int main()
{
	Fraction f1(3, 1);

	cout << f1 << endl;

	Fraction f2(f1);	//��������� ȣ��

	cout << f2 << endl;

	Fraction f3 = f2;	//��������� ȣ��
	
	cout << f3 << endl;

	Fraction f4{ f3 };	//��������� ȣ��

	cout << f4 << endl;

	Fraction f5(Fraction(3, 10)); // == Fraction f4(3,10);

	cout << f5 << endl;

	//------------------------------------------------------------------

	/*
		release ��忡���� ��������� ȣ���� �ȵ�, ��ȯ��ü �ּҿ�, result��ü�� �ּҰ� ���ԵǾ� ������ �ʿ� ����.
		debug��忡���� �ּҰ� �ٸ� �ν��Ͻ��� �νĵǾ� �����ϰ� ��.
	*/
	Fraction result = doSomething();

	cout << result << endl;
	


	return 0;
}