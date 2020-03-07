/*
	string stream
	문자열 흐름의 버퍼역할
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
			stream에 넣어주는 개념 (append개념)

			os.str("hello");
			buffer를 hello로 바꿔줌
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

	cout << str << endl; //빈칸 잘림

	str = os.str();

	cout << str << endl;


	{
		stringstream s;

		s << "12345 67.89";

		string str1;
		string str2;

		s >> str1 >> str2; //빈칸으로 구분해서 넣어줌

		cout << str1 << "|" << str2 << endl;
	}

	{
		stringstream s;

		int i = 12345;
		double d = 67.89;

		s << i << " " << d;

		string str1;
		string str2;

		s >> str1 >> str2; //빈칸으로 구분해서 넣어줌

		cout << str1 << "|" << str2 << endl;
	}

	{
		//int값을 stringstream에 넣어주고 다시 넣은 값을 int변수로 받아옴
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
		//stringstream을 비우기

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