/*
	std::string
	http://blog.naver.com/PostView.nhn?blogId=lyw94k&logNo=220859905348&categoryNo=11&parentCategoryNo=0&viewDate=&currentPage=1&postListTopCurrentPage=1&from=search
	std::cin.ignore()�Լ� ����
*/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
	//c style ���ڿ� ó��
	const char my_strs [] = "Hello world"; //Hello world\
	
	//c++ style ���ڿ� ó�� (��������� �ڷ���)
	const string my_hello = "Hello world"; //�ʱ�ȭ 3���� Ÿ�� ��� ����

	cout << my_hello << endl;

	//--------------------------------------------------------------------------------------------------------

	cout << "Your name ?" << endl;

	string name = "";
	//cin >> name; 

	//���Ⱑ �����ϸ� ����
	std::getline(cin, name);
	//getline => ���δ����� �о� ���̴µ� enter�� ������ ��

	cout << "Your age ?" << endl;

	string age = "";
	//cin >> age;

	std::getline(cin, age);

	cout << name << " " << age << endl;

	//------------------------------------------------------------------------------------------------------------
	//�����߻� ���

	/*
		cout << "Your age ? " << endl;
		int i_age = 0;
		cin >> i_age;
	
		cout << "Your name ?" << endl;
		name;
		std::getline(cin, name);

		cout << name << " " << i_age << endl;
	*/
	
	//=> buffer�� 1enter�� ������. -> buffer�� ������ ��

	cout << "Your age ? " << endl;
	int i_age = 0;
	cin >> i_age;

	//std::cin.ignore(32767, '\n'); //\n�� ���� �� ���� �ִ� 32767���� ���ڸ� �����ض�(�����)
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //32767����� ���� ���� ��� (���ۻ����� �ִ�)

	cout << "Your name ?" << endl;
	name;
	std::getline(cin, name);

	cout << name << " " << i_age << endl;
	
	/*
		buffer�� ���� �ִ��� ������ Ȯ��
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

	//=> string class�� ������ �����ε� �Ǿ�����.

	//lengtth
	cout << a.length() << endl; //length : 7


	return 0;
}