/*
	std::string 문자 접근하기와 배열로의 변환
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
			//str[100] = 'z'; 예외처리 발생 안됨	//속도 우선
			str.at(100) = 'z'; //예외처리 발생 함	//안정 우선
		}
		catch (std::exception & e)
		{
			cout << e.what() << endl;
		}
	}

	{
		string str("abcd");

		cout << str.c_str() << endl;

		const char* ctr = str.c_str(); // null문자를 붙여서 줌  = abcd\
		// == const char* ctr = str.data(); c_ctr()과 같음

		cout << ctr[0] << endl;
	}

	{
		string str("abcdefg");

		char buf[20];

		str.copy(buf, 5, 0); //자동으로 null을 붙여 주지 않음.
		
		buf[5] = '\0'; //직접 null삽입 해야함

		cout << buf << endl;
	}

	return 0;
}