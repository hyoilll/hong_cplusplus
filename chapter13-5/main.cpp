/*
	클래스 템플릿 특수화
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

		//==> 아예 다른 클래스라고 생각하면 편함
	*/

	return 0;
}