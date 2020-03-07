/*
	유도된 클래스에 새로운 기능 추가하기
*/

#include <iostream>

using namespace std;

class Base
{
protected:
	int m_protected;
	
private:
	int m_private;

public:
	Base(int value) : m_protected(value) {}

	void setValue(const int& value)
	{
		m_private = value;
	}
};

class Derived : public Base
{
public:
	Derived(int value) :Base(value)
	{

	}

	void setValue(int value)
	{
		Base::m_protected = value;	//첫 번째 방법  protected 변수
		Base::setValue(value);		//두 번째 방법	public 함수
	}
};

int main()
{


	return 0;
}