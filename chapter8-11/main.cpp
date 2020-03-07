/*
	���� ��� �Լ�
*/

#include <iostream>
using namespace std;

class Something
{
public:
	class _init
	{
	public:
		_init()
		{
			s_value = 1234;
		}
	};

private:
	static int s_value;
	int m_value;

	static _init s_initializer;

public:
	static int getValue()
	{
		return s_value;
		//static �Լ������� this�� �ȵ�
		//�ν��Ͻ��� ���� ���� �ʱ� ������ ������ �ν��Ͻ��� ����Ű�� this�� ����� �� ����.
		// m_value���ٵ� error
	}
	int temp()
	{
		return this->s_value;
	}
};

int Something::s_value = 1024;
Something::_init Something::s_initializer;

int main()
{
	cout << Something::getValue() << endl;

	Something s1, s2;

	cout << s1.getValue() << endl;
	//cout << s1.s_value << endl;

	//---------------------------------------------------------

	int (Something:: * fptr1)() = &Something::temp;

	cout << (s2.*fptr1)() << endl;

	//--------------------------------------------------------

	int (* fptr2)() = &Something::getValue;

	cout << fptr2() << endl;

	//--------------------------------------------------------


	return 0;
}