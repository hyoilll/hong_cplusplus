/*
	방어적 프로그래밍의 개념	=> 예외처리
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{

	int x;
	cin >> x;

	if (x > 5)
		cout << "x is greater than 5" << endl;

	//violated assumption

	string hello = "hello, my name is Jack jack";

	return 0;
}