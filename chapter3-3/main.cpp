/*
	���� ������
*/
#include <iostream>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

int main()
{
	int x = 6, y = 6;

	cout << x << " " << y << endl;
	cout << ++x << " " << --y << endl; //�� ������ ���� �� ++ -- ����
	
	x = 6, y = 6;
	
	cout << x++ << " " << y-- << endl; //�� ������ ���� �� ++ -- ����
	cout << x << " " << y << endl;

	cout << endl;

	//---------------------------------------

	x = 6, y = 6;

	cout << x << " " << y << endl;		//6, 6
	cout << ++x << " " << --y << endl;	//7, 5
	cout << x << " " << y << endl;		//7, 5
	cout << x++ << " " << y-- << endl;	//7, 5
	cout << x << " " << y << endl;		//8, 4

	cout << endl;
	//-----------------------------------------

	int num = 1;
	int result = add(num, ++num); //�߸��� ����

	cout << result << endl; //3�� �ƴ϶� 4�� ����

	return 0;
}