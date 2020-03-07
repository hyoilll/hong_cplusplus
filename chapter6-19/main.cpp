/*
	이중 포인터와 동적 다차원 배열
	https://twinparadox.tistory.com/439
*/

#include <iostream>
using namespace std;

int main()
{
	int* ptr = nullptr;
	int** ptrptr = nullptr;

	int value = 5;

	ptr = &value;

	ptrptr = &ptr;

	cout << ptr << " " << *ptr << " " << &ptr << endl;
	cout << ptrptr << " " << *ptrptr << " " << &ptrptr << endl;
	cout << **ptrptr << endl << endl;

	//----------------------------------------------------------------

	const int row = 3;
	const int col = 5;

	const int s2da[3][5] =
	{
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15}
	};
	/*
	1. 
		int* r1 = new int[col] { 1,2,3,4,5 };
		int* r2 = new int[col] {6, 7, 8, 9, 10};
		int* r3 = new int[col] {11, 12, 13, 14, 15};
	
		int** rows = new int* [row] {r1, r2, r3};
	
		cout << r1 << endl;
		cout << &(r1[0]) << endl;
		cout << rows[0] << endl;

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				cout << rows[i][j] << " ";
			}
			cout << endl;
		}
	*/
	
	/*
	2.
		1차원 배열을 2차원 배열처럼 사용하기

		int* arr = int [row * col];
		for (int i = 0 ; i < row ; i++)
		{
			for (int j = 0 ; j < col ; j++)
			{
				arr[j + (col * i)] = s2da[i][j];
			}
		}

	*/

	int** rows = new int* [row];
	for (int i = 0; i < row; i++)
	{
		rows[i] = new int [col];
	}
	cout << rows[0] << endl;
	cout << &(rows[0][0]) << endl;
	cout << rows[1] << endl;
	cout << &(rows[1][0]) << endl;
	cout << rows[2] << endl;
	cout << &(rows[2][0]) << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			rows[i][j] = s2da[i][j];
		}
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << rows[i][j] << " ";
		}
		cout << endl;
	}
	/*
		delete[] r1;
		delete[] r2;
		delete[] r3;
	*/

	for (int i = 0; i < row; i++)
	{
		delete[] rows[i];
	}
	
	delete[] rows;

	return 0;
}