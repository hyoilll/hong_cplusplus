/*
	정적 다차원 배열
*/

#include <iostream>
using namespace std;

int main()
{
	const int num_rows = 3;
	const int num_columns = 5;

	//int i_arr[num_rows][num_columns] = { 0, };
	
	int i_arr[num_rows][num_columns] =
	{
		{1,2,3,4,5},		// row 0
		{6,7,8,9,10},		// row 1
		{11,12,13,14,15}	// row 2
	};
	

	for (int i = 0; i < num_rows; ++i)
	{
		for (int j = 0; j < num_columns; ++j)
		{
			cout << &i_arr[i][j] << "\t";
			//메모리가 1열로 되어있는것을 보기 쉽게 층을 나눠 놓은것
		}
		cout << endl;
	}

	return 0;
}