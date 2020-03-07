/*
	Ŭ���� ���ø� Ư��ȭ
*/

#include <iostream>
#include <array>

using namespace std;

template<class T>
class A
{
public:
	void doSomething()
	{
		cout << typeid(T).name() << endl;
	}

	void test() {}

};

//char class Specialization
template<>
class A<char>
{
public:
	void doSomething()
	{
		cout << "Char type specialization" << endl;
	}
};

int main()
{
	A<int> a_int;
	A<double> a_double;
	A<char> a_char;

	a_int.doSomething();
	a_double.doSomething();
	a_char.doSomething();

	/*
		a_int.test();
		a_double.test();
		//not error

		a_char.test();
		//error 

		//==> �ƿ� �ٸ� Ŭ������� �����ϸ� ����
	*/

	return 0;
}