/*
	포인터와 정적배열
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
	cout << sizeof((*ms).arr) << endl; //*ms.arr이 error가 나는 이유는 연산순위가 .가 더 높음
}

void printArr(int arr[]) // == int* arr
{
	cout << sizeof(arr) << endl;
	//배열이 복사되는게 아니고 포인터변수를 하나 생성해서 기존의 배열메모리를 가르키는 것 뿐

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
	//함수에서 수정해도 본체의 메모리에 접근한 포인터변수로 바꾸기에 본체도 바꿈
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