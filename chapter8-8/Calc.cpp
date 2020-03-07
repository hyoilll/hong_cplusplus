#include "Calc.h"

using namespace std;
//cpp파일에서는 전방선언해도 다른 헤더에 영향을 안주기에 무관함

Calc::Calc(int init_value) : m_value(init_value) {}

Calc& Calc::add(const int& value) { m_value += value; return *this; }

Calc& Calc::sub(const int& value) { m_value -= value; return *this; }

Calc& Calc::mul(const int& value) { m_value *= value; return *this; }

void Calc::print()
{
//	using namespace std; //헤더파일에 전방선언해버리면 include하는 모든 헤더에 영향을 미치기에 안하는게 좋음
	cout << m_value << endl;
}
