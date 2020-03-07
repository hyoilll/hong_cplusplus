/*
	�����Ϳ� �����迭
*/

#include <iostream>
using namespace std;

struct myStruct
{
	int arr[5] = { 1,2,3,4,5 };
};

void doSomething(myStruct *ms)
{
	cout << sizeof(ms) << endl;
	cout << sizeof((*ms).arr) << endl; //*ms.arr�� error�� ���� ������ ��������� .�� �� ����
}

void printArr(int arr[]) // == int* arr
{
	cout << sizeof(arr) << endl;
	//�迭�� ����Ǵ°� �ƴϰ� �����ͺ����� �ϳ� �����ؼ� ������ �迭�޸𸮸� ����Ű�� �� ��

	cout << *arr << endl;
	cout << *(arr + 1) << endl;

	*arr = 100;

	cout << *arr << endl;
}

int main()
{
	int arr[5] = { 1,2,3,4,5 };

	cout << arr << endl; //pointer
	cout << &arr[0] << endl;
	cout << &arr[1] << endl;

	cout << *arr << endl;
	cout << *(arr + 1) << endl; // [1]

	char name[] = "javajava";
	cout << *name << endl;

	int* ptr = arr;
	cout << ptr << endl;
	cout << *ptr << endl;
	cout << endl;

	//------------------------------------------------------
	
	cout << sizeof(arr) << endl;	//20
	cout << sizeof(ptr) << endl;	//4
	
	printArr(arr);

	cout << *arr << endl;
	//�Լ����� �����ص� ��ü�� �޸𸮿� ������ �����ͺ����� �ٲٱ⿡ ��ü�� �ٲ�
	cout << endl;

	//--------------------------------------------------------

	cout << *(arr + 1) + *(arr + 2) << endl; // 2 + 3 = 5;
	cout << endl;

	//--------------------------------------------------------

	myStruct ms;
	cout << ms.arr[0] << endl;
	
	cout << sizeof(ms.arr) << endl;

	doSomething(&ms);

	
	return 0;
}