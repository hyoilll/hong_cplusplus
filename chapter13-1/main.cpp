/*
	함수 템플릿
*/

#include <iostream>
#include "Cents.h"
using namespace std;

template <class T>
T getMax(T x, T y)
{
	return (x > y) ? x : y;
}

int main()
{
	cout << getMax(3, 5) << endl;
	cout << getMax(1.3, 1.4) << endl;

	std::cout << getMax(Cents(14), Cents(9)) << endl;

	return 0;
}