/*
	���� ��� ����
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

	//=> ���� Ŭ������ �ٸ� �ν��Ͻ����� �ϳ��� static������ ������

	Something::s_value = 1024;

	cout << &Something::s_value << " " << Something::s_value << endl;

	return 0;
}