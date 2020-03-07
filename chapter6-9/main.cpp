/*
	포인터 연산과 배열 인덱싱
*/

#include <iostream>
using namespace std;

int main()
{
	int value = 7;
	int* ptr = &value;

	cout << uintptr_t(ptr - 1) << endl;
	cout << uintptr_t(ptr) << endl;
	cout << uintptr_t(ptr + 1) << endl;
	//int형 자료형 만큼 4bytes 한칸씩 이동
	cout << endl;

	//--------------------------------------------

	int arr[] = { 1,2,3,4,5 };

	cout << arr[0] << " " << &arr[0] << endl;
	cout << arr[1] << " " << &arr[1] << endl;
	cout << arr[2] << " " << &arr[2] << endl;
	cout << arr[3] << " " << &arr[3] << endl;
	cout << arr[4] << " " << &arr[4] << endl;
	//4씩 증가 - 메모리를 이웃해서 가지고 있음. => 그래서 for문으로 가능한 것
	cout << endl;

	ptr = arr;
	for (int i = 0; i < 5; ++i)
	{
		//cout << arr[i] << " " << &arr[i] << endl;
		cout << *(arr + i) << " " << &(*(arr + i)) << endl;
	}
	cout << endl;

	//--------------------------------------------------------------------------

	char name[] = "java java";

	const int n_name = sizeof(name) / sizeof(char);

	for (int i = 0; i < n_name; ++i)
	{
		cout << *(name + i) << " "; //name[i]
	}

	return 0;
}