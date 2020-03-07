#include <iostream>
using namespace std;

int main()
{
	bool result = false;
	cout << boolalpha;
	// (true && true) || false
	//	=> true

	result = (true && true) || false;
	cout << result << endl;

	// (false && true) || true
	//	=> true

	result = (false && true) || true;
	cout << result << endl;

	// (false && true) || false || true
	//	=> true

	result = (false && true) || false || true;
	cout << result << endl;

	// (14 > 13 || 2 > 1) && (9 > 1)
	//	=> true

	result = (14 > 13 || 2 > 1) && (9 > 1);
	cout << result << endl;

	// !(2314123 > 2 || 123123 > 2387) == (2314123 < 2 && 123123 < 2387)
	// => false

	result = !(2314123 > 2 || 123123 > 2387);
	cout << result << endl;

	return 0;
}

