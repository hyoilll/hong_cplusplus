/*
	�Ű�����(parameter)�� ����(argument)�� ����
*/

#include <iostream>
using namespace std;

int foo(int x, int y);

int foo(int x, int y) //x, y : parameter
{
	return x + y;
}

int main()
{
	int x = 1, y = 2;

	foo(6, 7);		//6, 7 : argument (= actual parameters)
	foo(x, y + 1);	//1, 3 : argument

	return 0;
}