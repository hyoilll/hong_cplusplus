#include "Calc.h"

using namespace std;
//cpp���Ͽ����� ���漱���ص� �ٸ� ����� ������ ���ֱ⿡ ������

Calc::Calc(int init_value) : m_value(init_value) {}

Calc& Calc::add(const int& value) { m_value += value; return *this; }

Calc& Calc::sub(const int& value) { m_value -= value; return *this; }

Calc& Calc::mul(const int& value) { m_value *= value; return *this; }

void Calc::print()
{
//	using namespace std; //������Ͽ� ���漱���ع����� include�ϴ� ��� ����� ������ ��ġ�⿡ ���ϴ°� ����
	cout << m_value << endl;
}
