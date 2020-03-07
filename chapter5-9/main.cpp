/*
	���� �����
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
	//RAND_MAX = random number�� ������ �� ���� �� �ִ� ���� ū ����

	return min + static_cast<int>((max - min + 1) * (std::rand()) * fraction);
}

int main()
{
	//seed number setting
	//std::srand(5323); 
	//seed number�� �����Ǿ� �־� ��� ���� ������ ����
	//debuging�� �� ����ϸ� ����

	std::srand(static_cast<unsigned int>(std::time(0)));
	//��ǻ�� �ð��� �ҷ��� seed ����

	for (int i = 1; i <= 100; i++)
	{
		cout << getRandomNumber(0, 10) << "\t";

		if (i % 5 == 0) cout << endl;
	}


	return 0;
}