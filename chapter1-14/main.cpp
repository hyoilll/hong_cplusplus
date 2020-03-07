/*
	전처리기와의 첫 만남
	전처리기 - 빌드하기 전에 결정이 됨
	전처리기(preprocessor)는 프로그램을 컴파일할 때 컴파일 직전에 실행되는 별도의 프로그램
	출처: https://boycoding.tistory.com/145 [소년코딩]

*/

#include <iostream>
#include <algorithm>

using namespace std;

//define의 범위는 해당 파일 안으로 국한됨
#define MY_NUMBER "Hello World"
#define MAX(a,b) ((a > b) ? a : b)
//#define LIKE_APPLE

int main()
{
	cout << MY_NUMBER << endl;
	cout << MAX(1, 2) << endl;
	cout << std::max(1, 2) << endl;

	
#ifdef LIKE_APPLE //LIKE_APPLE 이 정의되어 있으면 수행
	cout << "apple" << endl;
#endif

#ifndef LIKE_APPLE //LIKE_APPLE 이 정의되어 있지 않으면 수행
	cout << "orange" << endl;
#endif



	return 0;
}