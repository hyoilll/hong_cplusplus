/*
	비쥬얼 스튜디오로 프로파일링 하기
*/

#include <iostream>

void func1()
{
	long long sum = 0;

	for (unsigned int i = 0; i < 1000'000; ++i)
		sum += i;

	std::cout << sum << std::endl;
}

void func2()
{
	long long sum = 0;

	for (unsigned int i = 0; i < 1000'000'000; ++i)
		sum += i;

	std::cout << sum << std::endl;
}

void run()
{
	func1();
	func2();
}

int main()
{
//	run();

	int* d = new int[10000];

	float* f = new float[100];

	delete[] d;

	delete[] f;

	return 0;
}