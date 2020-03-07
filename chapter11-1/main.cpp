/*
	»ó¼Ó
*/

#include <iostream>

using namespace std;

class Mother //
{
private:
	int m_i;

protected:
	int m_p = 0;

public:
	Mother(const int& i_in) :m_i(i_in)
	{
		cout << "Mother constructor" << endl;
	}

	void setValue(const int& value)
	{
		m_i = value;
	}

	int getValue()const
	{
		return m_i;
	}
};

class Child : public Mother //derived class
{
private:
	double m_d;

public:
	Child(const int& i_in, const double& d_in) : Mother(i_in), m_d(d_in) {}

	void setValue(const int& i, const double& d)
	{
		Mother::setValue(i);
		m_d = d;

		m_p = 10; //protected
	}

	void setValue(const double& d)
	{
		m_d = d;
	}

	double getValue()const
	{
		return m_d;
	}
};

class Daughter : public Mother
{

};

class Son : public Mother
{

};

int main()
{
	Mother m(1024);

	cout << m.getValue() << endl;

	Child c(1000, 128);
	cout << c.getValue() << endl;

	cout << c.Mother::getValue() <<  endl;
	return 0;
}