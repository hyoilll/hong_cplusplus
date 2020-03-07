/*
	복사 생성자, 복사 초기화, RVO(Retrun Value Optimization)

	복사생성자 호출 시점
	[참고] https://huiyu.tistory.com/entry/C-%EB%B3%B5%EC%82%AC-%EC%83%9D%EC%84%B1%EC%9E%90%EC%9D%98-%ED%98%B8%EC%B6%9C%EC%8B%9C%EC%A0%90
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

Fraction doSomething()
{
	Fraction temp(1, 2);

	return temp;
}

int main()
{
	Fraction f1(3, 1);

	cout << f1 << endl;

	Fraction f2(f1);	//복사생성자 호출

	cout << f2 << endl;

	Fraction f3 = f2;	//복사생성자 호출
	
	cout << f3 << endl;

	Fraction f4{ f3 };	//복사생성자 호출

	cout << f4 << endl;

	Fraction f5(Fraction(3, 10)); // == Fraction f4(3,10);

	cout << f5 << endl;

	//------------------------------------------------------------------

	/*
		release 모드에서는 복사생성자 호출이 안됨, 반환객체 주소와, result객체의 주소가 같게되어 복사할 필요 없음.
		debug모드에서는 주소가 다른 인스턴스로 인식되어 복사하게 됨.
	*/
	Fraction result = doSomething();

	cout << result << endl;
	


	return 0;
}