/*
	헤더파일 만들기
	헤더파일 다른 파일로 이동
*/
#include <iostream>
#include "add.h"
#include "MyHeader/subtract.h"
#include "MyHeader/multiply.h"
using namespace std;

int main()
{
	cout << add(1, 2) << endl;
	cout << subtract(1, 2) << endl;
	cout << multiply(3, 4) << endl;
	return 0;
}