/*
	동적 할당 배열
*/

#include <iostream>
using namespace std;

int main()
{
	int length = 0;

	cin >> length;

	int* i_arr = new int[length] {0, };

	
	for (int i = 0; i < length; ++i)
	{
		cout << (uintptr_t)&i_arr[i] << endl;
		cout << i_arr[i] << endl;
	}

	delete[] i_arr;
	i_arr = nullptr;
	cout << endl;

	//-----------------------------------------------------------

	int fixedArray[] = { 1,2,3,4,5 };

	i_arr = new int[5] {1, 2, 3, 4, 5};

	delete[]i_arr;
	i_arr = nullptr;

	return 0;
}