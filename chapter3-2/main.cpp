/*
	��� ������ arithmetic operators
*/

#include <iostream>
using namespace std;

int main()
{
	int x = 7;
	int y = 4;

	cout << x / y << endl;
	cout << float(x) / y << endl;
	cout << x / float(y) << endl;
	cout << float(x) / float(y) << endl;

	// => ������ ���� �Ǽ����� ������ ũ�⶧���� �Ǽ����� ���Ե� ���ÿ��� �Ǽ������� ��ȯ�� ����� ��ȯ

	cout << 5 % 2 << endl; // -1
	cout << -5 % 2 << endl; // 1
	
	// =>  % ����� ������ ���� �����̸� ����� ������, ����̸� ����� �����
	return 0;
}