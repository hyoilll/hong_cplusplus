/*
	c언어 스타일의 배열 문자열
	#include <istream>
	istream& istream::getline( char* buffer, streamsize num );
	istream& istream::getline( char* buffer, streamsize num, char delim );
	
	std::cin.getline(char*, size);

	#include <string>
	istream& std::getline( istream& is, string& s, char delimiter = '\n' );

	std::getline(cin, string)
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
	char myString[] = "string"; //string\ (\ - 0)

	for (int i = 0; i < 7; ++i)
		cout << (int)myString[i] << endl;

	cout << sizeof(myString) << endl; //\까지 포함해서 7bytes

	//---------------------------------------------------------------------

	char str[255];

	cin >> str;
	//cin.getline(str, 255);

	str[0] = 'A';
	str[4] = '\0'; //null이 나오기 전까지 출력;

	cout << str << endl;
	
	char temp = ' '; //32
	char temp1 = '\0'; //0

	cout << (int)temp << " " << (int)temp1 << endl;

	cout << endl;

	//-----------------------------------------------------------------------

	const char source[] = "Copy this!";
	char dest[50];

	strcpy_s(dest, 50, source);

	cout << source << endl;	//Copy this!
	cout << dest << endl;	//Copy this!

	/*
		strcat_s() 문자열 붙이기
		strcmp() 문자열이 동일한지 비교 (같으면 0 다르면 -1)
	*/

	strcat_s(dest, source);	

	cout << dest << endl;	//Copy this!Copy this!

	if (strcmp(dest, source) == 0)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;
	
	return 0;
}