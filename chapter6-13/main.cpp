/*
	�����Ϳ� const
									�����ϴ� �޸� �ּ��� �� ���� ����			�����Ϸ��� �ּ� ���� ����
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

		=> ptr�� value�� ���� �ٲٷ��� �� ���� �ֱ⿡ error
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
	
	// => ����Ű�� �޸� �ּ��� ���� �������� �ʰڴ�.

	//------------------------------------------------------------

	int value4 = 5;
	int* const ptr4 = &value4;

	cout << *ptr4 << endl;

	*ptr4 = 1;

	cout << *ptr4 << endl;

	int v = 10;

	//*ptr4 = &v;	x

	// => �����ϴ� �޸𸮸� �������� �ʰڴ�.

	//-----------------------------------------------------------

	int value5 = 5;

	const int* const ptr5 = &value5;

	//*ptr5 = 1;	x

	int v2 = 10;

	//ptr5 = &v2;	x

	// => �����ϴ� �޸�, �� �޸��� �� ��� �������� �ʰڴ�.

	return 0;
}