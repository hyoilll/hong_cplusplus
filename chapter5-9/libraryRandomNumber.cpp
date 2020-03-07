/*
	난수 만들기
*/

#include <iostream>
#include <cstdlib> // std::rand(), std::srand()
#include <ctime> // std::time()
#include <random>

using namespace std;

int main()
{
	std::random_device rd;
	//random number만드는 장치

	std::mt19937 mersenne(rd()); //32bit
	//random number 생성 알고리듬
	//create a mesenne twister,

	std::uniform_int_distribution<> dice(1, 6); // 1 ~ 6, 동일한 확률로 나옴

	for (int i = 1; i <= 20; ++i)
		cout << dice(mersenne) << endl;

	return 0;
}