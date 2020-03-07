/*
	증감 연산자
*/
#include <iostream>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

int main()
{
	int x = 6, y = 6;

	cout << x << " " << y << endl;
	cout << ++x << " " << --y << endl; //이 문장이 시작 전 ++ -- 실행
	
	x = 6, y = 6;
	
	cout << x++ << " " << y-- << endl; //이 문장이 끝난 후 ++ -- 실행
	cout << x << " " << y << endl;

	cout << endl;

	//---------------------------------------

	x = 6, y = 6;

	cout << x << " " << y << endl;		//6, 6
	cout << ++x << " " << --y << endl;	//7, 5
	cout << x << " " << y << endl;		//7, 5
	cout << x++ << " " << y-- << endl;	//7, 5
	cout << x << " " << y << endl;		//8, 4

	cout << endl;
	//-----------------------------------------

	int num = 1;
	int result = add(num, ++num); //잘못된 사용법

	cout << result << endl; //3이 아니라 4가 나옴

	return 0;
}