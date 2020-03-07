/*
	std::string
	http://blog.naver.com/PostView.nhn?blogId=lyw94k&logNo=220859905348&categoryNo=11&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=search
	std::cin.ignore()함수 관련
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
	//c style 문자열 처리
	const char my_strs [] = "Hello world"; //Hello world\
	
	//c++ style 문자열 처리 (사용자정의 자료형)
	const string my_hello = "Hello world"; //초기화 3가지 타입 모두 가능

	cout << my_hello << endl;

	//--------------------------------------------------------------------------------------------------------

	cout << "Your name ?" << endl;

	string name = "";
	//cin >> name; 

	//띄어쓰기가 존재하면 끊김
	std::getline(cin, name);
	//getline => 라인단위로 읽어 들이는데 enter를 만나면 끝

	cout << "Your age ?" << endl;

	string age = "";
	//cin >> age;

	std::getline(cin, age);

	cout << name << " " << age << endl;

	//------------------------------------------------------------------------------------------------------------
	//문제발생 사례

	/*
		cout << "Your age ? " << endl;
		int i_age = 0;
		cin >> i_age;
	
		cout << "Your name ?" << endl;
		name;
		std::getline(cin, name);

		cout << name << " " << i_age << endl;
	*/
	
	//=> buffer에 1enter가 들어가있음. -> buffer를 비워줘야 함

	cout << "Your age ? " << endl;
	int i_age = 0;
	cin >> i_age;

	//std::cin.ignore(32767, '\n'); //\n을 만날 때 까지 최대 32767개의 글자를 무시해라(비워라)
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //32767상수를 보기 싫을 경우 (버퍼사이즈 최대)

	cout << "Your name ?" << endl;
	name;
	std::getline(cin, name);

	cout << name << " " << i_age << endl;
	
	/*
		buffer의 값이 있는지 없는지 확인
		#include <conio.h>

		bool isBufferFlag = _kbhit();
	*/
	
	//--------------------------------------------------------------------------------------------

	string a("Hello, ");
	string b("World ");
	
	//append(string add)
	string hw = a + b; //Hello, World 

	hw = hw + "I'm good";

	cout << a + b << endl; //Hello, World I'm good

	//=> string class에 연산자 오버로딩 되어있음.

	//lengtth
	cout << a.length() << endl; //length : 7


	return 0;
}