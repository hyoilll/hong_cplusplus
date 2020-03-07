/*
	���� ������ �����ε�, ���� ����, ���� ����
*/

#include <iostream>
#include <cassert>
using namespace std;

class MyString
{
public:
	char* m_data = nullptr;
	int m_length = 0;

public:
	MyString(const char* source = "")
	{
		assert(source);

		m_length = std::strlen(source) + 1;
		m_data = new char[m_length];

		for (int i = 0; i < m_length; ++i)
			m_data[i] = source[i];

		m_data[m_length - 1] = '\0';
	}

	MyString(const MyString& str) :m_length(str.m_length)
	{
		cout << "copy constructor" << endl;

		if (str.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
			{
				m_data[i] = str.m_data[i];
			}
		}
	}

	MyString& operator=(const MyString& str)
	{
		cout << "Assignment operator" << endl;

		if (this == &str) //prevent self-assignment
			return *this;

		delete[] m_data;// �̹� ������ ��ü�� ���� ������ �����ִ� �ּҰ� ���� ���� �ֱ⿡ ������.

		m_length = str.m_length;

		if (str.m_data != nullptr)
		{
			m_data = new char[m_length];

			for (int i = 0; i < m_length; ++i)
			{
				m_data[i] = str.m_data[i];
			}
		}
	}

	~MyString()
	{
		delete[] m_data;
		cout << "destroy" << endl;
	}

	char* getString()const { return m_data; }
	int getLength()const { return m_length; }
};

int main()
{
	//���������
	MyString hello("Hello");

	cout << (int*)hello.m_data << endl;
	cout << hello.getString() << endl;

	{
		MyString copy = hello;
		cout << (int*)copy.m_data << endl;
		cout << copy.getString() << endl;
	}

	//-------------------------------------------------------------

	//���Կ�����
	MyString bye("bye");

	hello = hello; //self-assignment

	cout << hello.getString() << endl;

	hello = bye;

	cout << hello.getString() << endl;

	//-------------------------------------------------------------

	/*
		MyString hello("Hello");

		MyString str1 = hello; //���������

		MyString str2;
		str2 = hello; //���Կ�����
	*/
	return 0;
}