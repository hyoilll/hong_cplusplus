/*
	디폴트 매개변수
*/

#include <iostream>
#include <string>
using namespace std;

//디폴트 매개변수는 선언과 정의 한군데에서만 가능, 보통 선언부에 넣어둠
void print(int x, int y = 3, int z = 5);

void print(int x, int y, int z)
{
	cout << x << " " << y << " " << z << endl;
	return;
}

void print(std::string str) {}
void print(char ch = ' ') {}
void print(int x) {}
void print(int x, int y = 20) {}


int main()
{
	/*
		print(10);

		error.
		void print(int x, int y = 3, int z = 5);
		void print(int x) {}

		충돌, 오버로딩 모호함
	*/
	print(1,2,3);

	print(); //print(char)

	return 0;
}