/*
	산술 연산자 arithmetic operators
*/

#include <iostream>
using namespace std;

int main()
{
	int x = 7;
	int y = 4;

	cout << x / y << endl;
	cout << float(x) / y << endl;
	cout << x / float(y) << endl;
	cout << float(x) / float(y) << endl;

	// => 정수형 보다 실수형이 범위가 크기때문에 실수형이 포함된 계산시에는 실수형으로 변환시 계산후 반환

	cout << 5 % 2 << endl; // -1
	cout << -5 % 2 << endl; // 1
	
	// =>  % 연산시 좌항의 값이 음수이면 결과도 음수로, 양수이면 결과도 양수로
	return 0;
}