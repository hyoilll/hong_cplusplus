/*
	std::string ���� �����ϱ�� �迭���� ��ȯ
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	{
		string str("abcdefg");

		cout << str << endl;

		str[0] = 'z';

		cout << str << endl;
	}

	{
		string str("abcdef");

		try
		{
			//str[100] = 'z'; ����ó�� �߻� �ȵ�	//�ӵ� �켱
			str.at(100) = 'z'; //����ó�� �߻� ��	//���� �켱
		}
		catch (std::exception & e)
		{
			cout << e.what() << endl;
		}
	}

	{
		string str("abcd");

		cout << str.c_str() << endl;

		const char* ctr = str.c_str(); // null���ڸ� �ٿ��� ��  = abcd\
		// == const char* ctr = str.data(); c_ctr()�� ����

		cout << ctr[0] << endl;
	}

	{
		string str("abcdefg");

		char buf[20];

		str.copy(buf, 5, 0); //�ڵ����� null�� �ٿ� ���� ����.
		
		buf[5] = '\0'; //���� null���� �ؾ���

		cout << buf << endl;
	}

	return 0;
}