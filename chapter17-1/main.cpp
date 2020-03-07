/*
	std::string
	std::wstring
*/

#include <iostream>
#include <string>


using namespace std;



int main()
{
	//c-style string example
	{
		char* ctr = new char[7];
		strcpy_s(ctr, sizeof(char) * 7, "hello!");
		std::cout << ctr << std::endl;
	}

	//string, wstring
	{
		std::string str;
		std::wstring wstr;

		wchar_t wc; // wide-charater/unicode
	}


	return 0;
}