/*
	Ȧ/¦ �Ǵ� ���α׷�
*/

#include <iostream>

int main()
{
	using namespace std;

	int num = 0;
	
	cout << "Your input : ";
	cin >> num;

	if ((num & 1) != 0)
		cout << "Ȧ��" << endl;
	else
		cout << "¦��" << endl;

	return 0;
}