/*
	자료형이 아닌 템플릿 매개변수
*/

#include "MyArray.h"

int main()
{
	//std::vector<char> vec;
	//vec.resize(100);

	//MyArray<char> arr(100);

	//위 두개의 선언은 동적할당이기에 런타임중 매개변수가 정해져도 됨.

	MyArray<char, 100> arr;
	//컴파일타임에 100이라는 숫자가 정해져야 함.

	for (unsigned int i = 0; i < arr.getLength(); ++i)
		arr[i] = 65 + i;
	std::cout << &(arr[0]);
	arr.print();

	return 0;
}