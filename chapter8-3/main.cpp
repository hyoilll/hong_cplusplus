/*
	생성자

	객체가 만들어질 때 가장 먼저 호출되는 함수
*/

#include <iostream>

using namespace std;

class Fraction
{
private:
	int m_numeraotr;
	int m_denominator;

public:
	//Fraction(){} default 생성자, 사용자가 직접 생성자룰 구현하면 default생성자조차 자동으로 만들어 주지 않음.

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
		차이점
		()는 묵시적 형변환시 경고만 띄워주는 반면, {}는 error까지 띄워줌 더 강력함.
	*/

	frac.print();
	cout << endl;

	//--------------------------------------------------------

	Frist f;
	/*
		class가 다른 class를 멤버로 들고 있는 경우는 
	*/
	return 0;
}