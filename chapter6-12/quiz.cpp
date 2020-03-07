/*
	동적할당 resizing
*/

#include <iostream>
using namespace std;

int main()
{
	int* i_arr = new int[5]{ 1,2,3,4,5 };

	int* newArr = new int[10]{};

	for (int i = 0; i < 5; ++i)
	{
		newArr[i] = i_arr[i];
	}

	delete[] i_arr;
	i_arr = newArr;
	newArr = nullptr;

	
	for (int i = 0; i < 10; ++i)
	{
		cout << i << " " << *(i_arr + i) << endl;
	}

	delete[] i_arr;
	i_arr = nullptr;

	return 0;
}