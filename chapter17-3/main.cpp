/*
	std::string�� ���̿� �뷮
*/

#include <iostream>
#include <string>
using namespace std;



int main()
{
	{
		string str("012345678");
		string emptyStr("");
		cout << str.size() << endl;

		//charó�� �������� null�� ���� ���� ����, Ŭ�����̱� ������ length�� ���� ���� �־ ���� null�� �ʿ����.

		cout << std::boolalpha;

		cout << str.empty() << endl; //true - �������, false - ������� ����.
		cout << emptyStr.empty() << endl;
		//""���Խ� cosnt char*�δ� ������ 1�� ������ string�� ����ִ� �ɷ� ó���� ��
	}

	{
		string str("01234567");

		//str.reserve(1000);
		str.resize(1000);

		/*
		reserve - ���� ����� �������� �뷮�� Ȯ���س���.
		resize - ���� �ٷ� ����ϴϱ� length���� ���� ������ ��ħ
		*/

		cout << std::boolalpha;
		cout << str.length() << endl;
		cout << str.size() << endl;
		cout << str.capacity() << endl;
		cout << str.max_size() << endl;
	}

	{

	}

	return 0;
}