/*
	�ɺ��� ���
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
	//����� ���� �ٲ� �� ���⿡ ����� �ʱ�ȭ�ؾ���
	//����� �ʱ�ȭ�� ���ͷ� ����� ����� ������ �����Ͽ� ����� Ȯ���� ��.
	// => ������ ����� �����ϴ� ������ 'constexpr'

	int number = 0;
	cin >> number;

	const int special_number(number);
	//�ʱ�ȭ�� ����� �Է°����� �ϱ⶧���� ��Ÿ�� �� ����� Ȯ���� ��.

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