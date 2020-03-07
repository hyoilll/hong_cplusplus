/*
	��� �Լ��� �� �� �� ���ø�ȭ �ϱ�
*/

#include <iostream>

using namespace std;

template<class T>
class A
{
private:
	T m_value;

public:
	A(const T& input) :m_value(input) {}

	template<class TT>
	void doSomething(const TT& input)
	{
		cout << typeid(T).name() << " " << typeid(TT).name() << endl;
		cout << (TT)m_value << endl;
		cout << (int)input << endl;
	}

	void print() const
	{
		cout << m_value << endl;
	}
};

int main()
{
	A<int> a_int(123);
	
	a_int.print();

	a_int.doSomething(char());

	return 0;
}