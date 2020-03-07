/*
	Ŭ������ const
*/

#include <iostream>
#include <string>
using namespace std;

class Something
{
public:
	int m_value = 0;

	Something(const Something& st_in)
	{
		m_value = st_in.m_value;
		cout << "copy Constructor " << endl;
	}

	Something() { cout << "Constructor " << endl; }

	void setValue(const int& value) { m_value = value; }
	int getValue()const { return m_value; } //const : ����Լ� �ȿ��� ���� ������ ����.
};

void print(Something st) // ���� ������ ȣ�� => Something st = something;  �̷��� ��
{
	cout << &st << endl;
	cout << st.m_value << endl;
}

/*
	ȣ���ϴ� ������ reference�� �����ϱ⿡ ���簡 �Ͼ�� ����.
	void print(const Something& st)
	{
		cout << &st << endl;
		cout << st.m_value << endl;
	}
*/

class Dosomething
{
public:
	string m_value = "default";

	const string& getValue() const 
	{
		cout << "const version" << endl; 
		return m_value; 
	}
	string& getValue() //������ const�� overroding�� ��� 
	{
		cout << "non-const version" << endl; 
		return m_value; 
	}
};

int main()
{
	const Something something;

	//const�� ������� �ν��Ͻ� something�� ���� �ٲ� ���� ����. ��� ���� ������ �Ͼ�� setValue�� error
	//something.setValue(3); error

	cout << something.getValue() << endl;
	//const�� ���� ����Լ��� �����
	cout << endl;

	//---------------------------------------------------------------------

	//instance send to reference
	cout << &something << endl;

	print(something);
	cout << endl;

	//--------------------------------------------------------------------

	//const overroding
	Dosomething ds;
	ds.getValue();

	const Dosomething ds2;
	ds2.getValue();

	return 0;
}