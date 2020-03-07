/*
	c++ 17 함수에서 여러 개의 리턴값 반환하기
*/

#include <iostream>
#include <tuple>
using namespace std;

auto func()
{
	return tuple(123, 456, 789); //tuple<int, int, int>(123,456,789);
}

int main()
{
	{
		auto result = func();

		cout << std::get<0>(result) << " " << std::get<1>(result) << " " << std::get<2>(result) << endl;
	}

	{
		auto [a, b, c] = func();

		cout << a << " " << b << " " << c << endl;
	}
	return 0;
}