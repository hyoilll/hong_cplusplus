/*
	char
*/

#include <iostream>
#include <limits>

int main()
{
	using namespace std;

	char c1(65);
	char c2('A');

	cout << c1 << " " << c2 << " " << int(c1) << " " << int(c2) << endl;
	
	// c style casting
	cout << (char)65 << endl; 
	cout << (int)'A' << endl;

	// c++ style casting
	cout << char(65) << endl;
	cout << int('A') << endl;

	// => 강제형변형

	cout << static_cast<char>(65) << endl;
	cout << static_cast<int>('A') << endl;

	// => 기본형 변환시 컴파일러에게 변환할 수 있는지? 가능하면 변환해줘라 라는 문법
	
	char ch(97);
	cout << ch << endl;
	cout << static_cast<int>(ch) << endl;
	cout << ch << endl;

	// => casting해도 원래의 값은 변하지 않는다.

	//-----------------------------------------------------------
	cout << endl;

	char c(65);

	cin >> c; //abc
	cout << c << " " << static_cast<int>(c) << endl;

	cin >> c;
	cout << c << " " << static_cast<int>(c) << endl;

	cin >> c;
	cout << c << " " << static_cast<int>(c) << endl;

	// => 변수가 입력값을 모두 받아들이지 못하면 buffer에 남은 것을 보관하고 차례차례 받아옴
	// ex) ab를 입력시 3번의 입력을 받기 때문에 마지막 한번의 입력을 기다림

	//-----------------------------------------------------------
	cout << endl;

	cout << sizeof(char) << endl; //-128 ~ 127
	cout << (int)numeric_limits<char>::max() << endl;
	cout << (int)numeric_limits<char>::lowest() << endl;

	cout << sizeof(unsigned char) << endl; //0 ~ 255
	cout << (int)numeric_limits<unsigned char>::max() << endl;
	cout << (int)numeric_limits<unsigned char>::lowest() << endl;

	//-------------------------------------------------------------
	cout << endl;

	cout << int('\n') << endl;
	cout << "This is first line \nsecond line\n";
	cout << "This is first line " << endl;
	cout << "second line" << endl;

	//=> endl 과 \n의 차이
	//endl : buffer에 있는 문자열을 다 출력 후 줄바꿈
	//flush : buffer에 있는 문자열을 다 출력 (줄바꿈 x)
	//\n : 단순 줄바꿈

	return 0;
}