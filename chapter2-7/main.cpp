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

	// => ����������

	cout << static_cast<char>(65) << endl;
	cout << static_cast<int>('A') << endl;

	// => �⺻�� ��ȯ�� �����Ϸ����� ��ȯ�� �� �ִ���? �����ϸ� ��ȯ����� ��� ����
	
	char ch(97);
	cout << ch << endl;
	cout << static_cast<int>(ch) << endl;
	cout << ch << endl;

	// => casting�ص� ������ ���� ������ �ʴ´�.

	//-----------------------------------------------------------
	cout << endl;

	char c(65);

	cin >> c; //abc
	cout << c << " " << static_cast<int>(c) << endl;

	cin >> c;
	cout << c << " " << static_cast<int>(c) << endl;

	cin >> c;
	cout << c << " " << static_cast<int>(c) << endl;

	// => ������ �Է°��� ��� �޾Ƶ����� ���ϸ� buffer�� ���� ���� �����ϰ� �������� �޾ƿ�
	// ex) ab�� �Է½� 3���� �Է��� �ޱ� ������ ������ �ѹ��� �Է��� ��ٸ�

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

	//=> endl �� \n�� ����
	//endl : buffer�� �ִ� ���ڿ��� �� ��� �� �ٹٲ�
	//flush : buffer�� �ִ� ���ڿ��� �� ��� (�ٹٲ� x)
	//\n : �ܼ� �ٹٲ�

	return 0;
}