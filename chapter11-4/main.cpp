/*
	유도된 클래스의 생성과 초기화
*/

#include <iostream>

using namespace std;

class Mother
{
public:
	int m_i;

	Mother() :m_i(1)
	{
		cout << "Mother construction" << endl;
	}
	~Mother()
	{
		cout << "Mother distruction" << endl;
	}
};

class Child : public Mother
{
public:
	double m_d;

	Child() : m_d(1.0)
	{
		cout << "Child construction" << endl;
	}
	~Child()
	{
		cout << "Child distruction" << endl;
	}
};

int main()
{
	cout << sizeof(Mother) << endl; //Mother
	cout << sizeof(Child) << endl; //Mother + Child

	return 0;
}