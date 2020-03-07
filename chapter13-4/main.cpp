/*
	함수 템플릿 특수화(Spectialization)
*/

#include <iostream>
#include "Storage.h"
using namespace std;

template <class T>
T getMax(const T& x, const T& y)
{
	return (x > y) ? x : y;
}

//function Spectialization
//char의 경우에만 밑의 getMax를 사용해라.
//if를 사용해서 분기할 수 없는 이유는 컴파일 타임에 정해야 하기 때문.
template<>
char getMax(const char& x, const char& y)
{
	cout << "Warning : comparing chars" << endl;

	return (x > y) ? x : y;
}

int main()
{
	cout << getMax('a', 'b') << endl; // == getMax<int>(1, 2)

	cout << endl;

	//-------------------------------------------------------------

	Storage<int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print();


	return 0;
}