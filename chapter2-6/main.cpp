/*
	bool / if
*/

#include <iostream>

bool isEqual(int a, int b)
{
	bool result = (a == b) ? true : false;

	return result;
}

int main()
{
	using namespace std;

	bool b1 = true; // copy initialization
	bool b2(false); //direct initialization
	bool b3{ true };//uniform initialization
	b3 = false;

	cout << boolalpha; // bool ���� ��½� true / false �� ǥ���ϰ��� �� ��
	cout << b3 << endl;
	cout << b1 << endl;

	cout << isEqual(1, 1) << endl;
	cout << isEqual(0, 3) << endl;

	//----------------------------------------------
	cout << endl;

	bool b;
	cin >> b;

	// 0 - false
	// false �� �ƴ� �͵� - true
	cout << "Your input : " << b << endl;

	return 0;
}