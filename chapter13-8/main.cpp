/*
	멤버 함수를 한 번 더 템플릿화 하기
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