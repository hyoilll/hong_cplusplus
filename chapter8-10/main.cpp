/*
	정적 멤버 변수
*/

#include <iostream>

using namespace std;

class Something
{
public:
	static int s_value;
	//static const int s_value = 1;
	//static constexpr int s_value = 1;

};

int Something::s_value = 1; // define in cpp / complie error in header

int main()
{
	cout << &Something::s_value << " " << Something::s_value << endl;

	Something s1;
	Something s2;

	s1.s_value = 2;

	cout << &s1.s_value << " " << s1.s_value << endl;
	cout << &s2.s_value << " " << s2.s_value << endl;

	//=> 같은 클래스의 다른 인스턴스들은 하나의 static변수를 공유함

	Something::s_value = 1024;

	cout << &Something::s_value << " " << Something::s_value << endl;

	return 0;
}