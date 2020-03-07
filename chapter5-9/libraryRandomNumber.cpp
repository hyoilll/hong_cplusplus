/*
	���� �����
*/

#include <iostream>
#include <cstdlib> // std::rand(), std::srand()
#include <ctime> // std::time()
#include <random>

using namespace std;

int main()
{
	std::random_device rd;
	//random number����� ��ġ

	std::mt19937 mersenne(rd()); //32bit
	//random number ���� �˰���
	//create a mesenne twister,

	std::uniform_int_distribution<> dice(1, 6); // 1 ~ 6, ������ Ȯ���� ����

	for (int i = 1; i <= 20; ++i)
		cout << dice(mersenne) << endl;

	return 0;
}