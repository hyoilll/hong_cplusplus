/*
	형변환 오버로딩을 사용한 cm, m, k 단위 변환
*/

#include <iostream>
using namespace std;

class Miter;

class Kilo
{
private:
	double m_kilo;

public:
	Kilo(const double& input) :m_kilo(input) {}

	operator Miter();

	operator double()
	{
		return m_kilo;
	}
};

class Cen;

class Miter
{
private:
	int m_miter;

public:
	Miter(const int& input) :m_miter(input) {}

	//miter -> kilo
	operator Kilo()
	{
		return Kilo((double)m_miter / 1000);
	}

	//miter -> cen
	operator Cen();

	operator int()
	{
		return m_miter;
	}
};

Kilo::operator Miter()
{
	return Miter(m_kilo * 1000);
}

class Cen
{
private:
	int m_cen;

public:
	Cen(const int& input) :m_cen(input) {}

	//cen -> miter
	operator Miter()
	{
		return Miter(m_cen / 100);
	}

	operator int()
	{
		return m_cen;
	}
};

Miter::operator Cen()
{
	return Cen(m_miter * 100);
}

void printDistance(const int& d)
{
	cout << d << endl;
}

void printDistance(const double& d)
{
	cout << d << endl;
}

int main()
{
	Miter m(10);

	Cen c = m;

	printDistance(c);

	Kilo k = m;

	printDistance(k);

	return 0;
}