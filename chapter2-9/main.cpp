/*
	심볼릭 상수
*/

#include <iostream>
#include "MY_CONSTANTS.h"
using namespace std;

void printNumber(const int my_number) // == const int my_number(123)
{
	cout << my_number << endl;
	return;
}

int main()
{
	printNumber(123);

	const double gravity{ 9.8 };
	constexpr double num1{ 123 };
	//상수는 값을 바꿀 수 없기에 선언시 초기화해야함
	//선언시 초기화를 리터럴 상수로 해줬기 때문에 컴파일에 상수가 확정이 됨.
	// => 컴파일 상수를 구별하는 문법은 'constexpr'

	int number = 0;
	cin >> number;

	const int special_number(number);
	//초기화를 사용자 입력값으로 하기때문에 런타임 중 상수가 확정이 됨.

	//------------------------------------------------------------
	cout << endl;

	int num_item = 123;
	const int price_per_item = 30;
	
	//int price = num_item * 30; x
	int price = num_item * price_per_item;

	//---------------------------------------------------------------
	cout << endl;

	double radius;
	cin >> radius;

	double circumference = 2.0 * radius * constants::pi;

	return 0;
}