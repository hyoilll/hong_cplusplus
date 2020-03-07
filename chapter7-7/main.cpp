/*
	함수 오버로딩 (조건 : 매개변수타입, 매개변수 개수)

	어느 함수를 사용할지 컴파일할 때 결정이 되야함.
	
*/

#include <iostream>
#include <string>
using namespace std;

int add(int x, int y)
{
	return x + y;
}

double add(double x, double y)
{
	return x + y;
}

/*
	typedef int my_int;

	void print(int x){}

	void print(my_int x){}
	
	똑같은 함수임
*/

void print(char* value) {}
void print(int value) {}
void print(unsigned int value) {}
void print(float value) {}

int main()
{
	cout << add(3, 4) << endl;
	cout << add(3.14, 4.1) << endl;

	print(0);
	print('a'); //print(int value)
	
	print('a');
	print(0);
	print(3.14159f);

	return 0;
}