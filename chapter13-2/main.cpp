/*
	클래스 템플릿
*/

#include "MyArray.h"

int main()
{
	MyArray<char> arr(10);
	
	for (unsigned int i = 0; i < arr.getLength(); ++i)
		arr[i] = 65 + i;
	std::cout << &(arr[0]);
	arr.print();
}