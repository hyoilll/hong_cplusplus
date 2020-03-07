/*
	변환 생성자 - 생성자를 변환시켜주는 생성자,
	explicit - 변환생성자를 생성못하게 막아버림,
	delete - 특정한 생성자를 사용하지 못하게 지워버림
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
		assert(den != 0); //true - 통과, false - error
	}

	//복사생성자를 호출하기 원하지 않으면 private영역에 정의함.
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

	//변환생성자, Fraction형이 받을 수 있도록 매개변수를 변환 시켜줌
	
	//doSomething(7); 
	
	//explicit 키워드를 추가하면 error
	// => doSomething(Fraction(7));
	
	//Fraction('c'); //delete 키워드로 인해 char를 받는 객체를 생성 불가
	
	return 0;
}