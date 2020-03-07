/*
	È¦/Â¦ ÆÇ´Ü ÇÁ·Î±×·¥
*/

#include <iostream>

int main()
{
	using namespace std;

	int num = 0;
	
	cout << "Your input : ";
	cin >> num;

	if ((num & 1) != 0)
		cout << "È¦¼ö" << endl;
	else
		cout << "Â¦¼ö" << endl;

	return 0;
}