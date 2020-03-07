/*
	string stream
	���ڿ� �帧�� ���ۿ���
*/

#include <iostream>
#include <sstream> //string stream
using namespace std;



int main()
{
	stringstream os;

	os << "Hello, World!"; // << : insertion operator, >> : extraction operator

	os.str("Hello, World!");

	{
		/*
			os << "hello";
			stream�� �־��ִ� ���� (append����)

			os.str("hello");
			buffer�� hello�� �ٲ���
		*/

		stringstream s;

		s << "hello";

		cout << s.str() << endl;

		s << " world";

		cout << s.str() << endl;

		s.str("bye");

		cout << s.str() << endl;

		cout << endl;
	}

	string str;

	os >> str;

	cout << str << endl; //��ĭ �߸�

	str = os.str();

	cout << str << endl;


	{
		stringstream s;

		s << "12345 67.89";

		string str1;
		string str2;

		s >> str1 >> str2; //��ĭ���� �����ؼ� �־���

		cout << str1 << "|" << str2 << endl;
	}

	{
		stringstream s;

		int i = 12345;
		double d = 67.89;

		s << i << " " << d;

		string str1;
		string str2;

		s >> str1 >> str2; //��ĭ���� �����ؼ� �־���

		cout << str1 << "|" << str2 << endl;
	}

	{
		//int���� stringstream�� �־��ְ� �ٽ� ���� ���� int������ �޾ƿ�
		stringstream s;

		int i = 12345;

		s << i;

		cout << s.str() << endl;

		int temp;

		s >> temp;

		int result = temp + 1;

		cout << result << endl;
	}

	{
		//stringstream�� ����

		stringstream s;

		s.str("zzzzzz");

		cout << s.str() << endl;

		s.str(""); // == s.str(string());

		cout << s.str() << endl;

		s << "Hello";

		cout << s.str() << endl;
	}

	return 0;
}