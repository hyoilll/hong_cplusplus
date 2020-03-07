/*
	thread

	1~99 гу = 4950
*/

#include <vector>
#include <thread>
#include <functional>
#include <iostream>

void sum(std::vector<int>::iterator from, std::vector<int>::iterator to, int& sum)
{
	int temp = 0;
	for (auto i = from; i < to; ++i)
	{
		temp += *i;
	}

	sum = temp;
}

int main()
{
	std::vector<std::thread> threads;

	threads.reserve(4);

	std::vector<int> sums(4);

//	sums.reserve(4);

	std::vector<int> data;
	data.reserve(100);

	for (unsigned int i = 0; i < 100; ++i)
		data.push_back(i);

	for (unsigned int i = 0; i < 4; ++i)
	{
 		threads.push_back(std::thread(sum, data.begin() + (i * 25), data.begin() + ((i + 1) * 25), std::ref(sums[i])));
	}

	for (auto& e : threads)
		e.join();

	int result = sums[0] + sums[1] + sums[2] + sums[3];

	std::cout << sums[0] << " " << sums[1] << " " << sums[2] << " " << sums[3] << std::endl;

	std::cout << "result : " << result << std::endl;

	return 0;
}