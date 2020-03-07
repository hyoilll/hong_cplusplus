/*
	std::string

	����, ��ȯ, �����̱�(append), ����
*/

#include <iostream>
#include <string>
using namespace std;


int main()
{
	{
		string str1("one");

		string str2(str1);

		cout << str2 << endl;

		str2.assign("two").append(" ").append("Hello");

		cout << str2 << endl;
	}

	cout << endl;
	
	{
		string str1("one");

		string str2("two");

		cout << str1 << " " << str2 << endl;

		std::swap(str1, str2);

		cout << str1 << " " << str2 << endl;

		str1.swap(str2);

		cout << str1 << " " << str2 << endl;

		str1.push_back('a'); //���ڸ� ���� �� ����.

		cout << str1 << endl;
	}

	cout << endl;
	
	{
		string str("aaaa");

		str.insert(2, "bbb");

		cout << str << endl;
	}

	return 0;
}