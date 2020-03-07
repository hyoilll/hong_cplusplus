/*
	단언하기 assert VS static assert

	런타임중에 에러를 확인하는 것
	compiler의 도움을 받아 error확인
	assert문은 논리연산자로 묶는 것 보다 따로따로 하는게 좋음.
	그래야 어디에서 에러가 나는지 확실히 알 수 있음.

	assert(bool) => 조건이 참이면 통과, 거짓이면 에러발생

	[참고] https://blog.naver.com/ejsvk3284/221332477269
*/

#include <cassert> // assert.h
#include <array>
#include <iostream>

void printValue(const std::array<int, 5>& arr, const int& idx)
{
	assert(idx >= 0);
	assert(idx <= arr.size() - 1);

	std::cout << arr[idx] << std::endl;
}

int main()
{
	int number = 5;

	//number should be 5
	assert(number == 5); //release 모드에서는 작동안됨.

	//-----------------------------------------------------

	std::array<int, 5> arr{ 1,2,3,4,5 };

	printValue(arr, 10);

	//-----------------------------------------------------

	//static assert 컴파일타임에 오류 발생
	const int x = 5;

	assert(x == 5);

	static_assert(x == 5, "x should be 5");


	return 0;
}