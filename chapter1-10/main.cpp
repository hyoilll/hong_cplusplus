/*
	선언과 정의의 분리
*/

#include <iostream>

using namespace std;

//forward declaration 전방선언
int add(int a, int b); 
int multiply(int a, int b);
int subtract(int a, int b);

int main()
{

	return 0;
}

//definition 정의
int add(int a, int b)
{
	return a + b;
}

int multiply(int a, int b)
{
	return a * b;
}

int subtract(int a, int b)
{
	return a - b;
}
