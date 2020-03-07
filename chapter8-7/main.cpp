/*
	this 포인터와 연쇄 호출
*/

#include <iostream>

using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(const int& id)
	{
		setId(id);

		cout << this << endl;
	}

	void setId(const int& id) { m_id = id; }
	int getId()const { return m_id; }

	const Simple* getSimple() const
	{
		return this;
	}
};

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value) : m_value(init_value) {}

	Calc& add(const int& value) { m_value += value; return *this; }
	Calc& sub(const int& value) { m_value -= value; return *this; }
	Calc& mul(const int& value) { m_value *= value; return *this; }

	void print() { cout << m_value << endl; }
};

int main()
{
	Simple s1(1), s2(2);

	cout << &s1 << " " << &s2 << endl << endl;

	/*
		클래스의 멤버함수의 작동 원리
		
		Simple::setId(&s1, number) -> 인스턴스가 공유하는 setId라는 함수에 자기 자신의 주소를 넣어서 사용

		== s1.setId(number)
	*/

	const Simple* sp = s1.getSimple();

	cout << &s1 << endl;
	cout << sp << endl;

	//-------------------------------------------------------------------

	Calc cal(10);
	cal.add(10).sub(1).mul(2).print();
	/*
		==
		Calc& temp1 = cal.add(10);
		Calc& temp2 = temp1.sub(1);
		Calc& temp3 = temp2. mul(2);
		temp3.print();
	*/
	/*
		==
		cal.add(10);
		cal.sub(1);
		cal.mul(2);
		cal.print();
	*/
	

	return 0;
}