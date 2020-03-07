/*
	for
*/

#include <iostream>
using namespace std;

int main()
{

	for (int i = 0; i < 10; ++i)
	{
		cout << i << endl;
	}

	for (int i = 0, j = 0; i < 10; ++i, --j)
		cout << i << " " << j << endl;

	/*
	for (unsigned int i = 9; i >= 0; --i)//무한루프
		cout << i << endl;
	*/

	return 0;
}