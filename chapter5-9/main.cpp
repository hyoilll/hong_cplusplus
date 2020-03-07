/*
	난수 만들기
*/

#include <iostream>
#include <cstdlib> // std::rand(), std::srand()
#include <ctime> // std::time()


using namespace std;

unsigned int PRNG()
{
	static unsigned int seed = 5523;

	seed = 8253729 * seed + 2396403;

	return seed % 32768;
}

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (RAND_MAX + 1.0); 
	//RAND_MAX = random number를 생성할 때 나올 수 있는 가장 큰 숫자

	return min + static_cast<int>((max - min + 1) * (std::rand()) * fraction);
}

int main()
{
	//seed number setting
	//std::srand(5323); 
	//seed number가 고정되어 있어 계속 같은 난수가 나옴
	//debuging할 때 사용하면 좋음

	std::srand(static_cast<unsigned int>(std::time(0)));
	//컴퓨터 시간을 불러와 seed 변경

	for (int i = 1; i <= 100; i++)
	{
		cout << getRandomNumber(0, 10) << "\t";

		if (i % 5 == 0) cout << endl;
	}


	return 0;
}