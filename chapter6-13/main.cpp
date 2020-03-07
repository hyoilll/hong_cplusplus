/*
	포인터와 const
									참조하는 메모리 주소의 값 변경 여부			참조하려는 주소 변경 여부
	int* ptr				->						o										o
	const int* ptr			->						x										o
	int* const ptr			->						o										x
	const int* const ptr	->						x										x
*/

#include <iostream>
using namespace std;

int main()
{
	int value1 = 5;
	int* ptr1 = &value1;
	*ptr1 = 6;

	//-----------------------------------------------------------
	
	/*
		const int value2 = 5;
		int* ptr2 = &value2;
		*ptr2 = 6;

		=> ptr로 value의 값을 바꾸려고 할 수도 있기에 error
	*/
	
	//------------------------------------------------------------
	
	const int value2 = 5;
	const int* ptr2 = &value2;
	//*ptr2 = 6; const!!

	//------------------------------------------------------------

	int value3 = 5;
	int temp = 61;
	const int* ptr3 = &value3;
	//*ptr3 = 6;	x
	value3 = 6;

	cout << *ptr3 << endl; // 6

	ptr3 = &temp;

	cout << *ptr3 << endl; // 61 
	
	// => 가르키는 메모리 주소의 값을 변경하지 않겠다.

	//------------------------------------------------------------

	int value4 = 5;
	int* const ptr4 = &value4;

	cout << *ptr4 << endl;

	*ptr4 = 1;

	cout << *ptr4 << endl;

	int v = 10;

	//*ptr4 = &v;	x

	// => 참조하는 메모리를 변경하지 않겠다.

	//-----------------------------------------------------------

	int value5 = 5;

	const int* const ptr5 = &value5;

	//*ptr5 = 1;	x

	int v2 = 10;

	//ptr5 = &v2;	x

	// => 참조하는 메모리, 그 메모리의 값 모두 변경하지 않겠다.

	return 0;
}