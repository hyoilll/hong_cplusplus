/*
	thread_promise

	1~99 гу = 4950
*/

#include <vector>
#include <future>
#include <functional>
#include <iostream>

auto sum(std::vector<int>::iterator from, std::vector<int>::iterator to, std::promise<int>&& p)
{
	int temp = 0;
	for (auto i = from; i < to; ++i)
	{
		temp += *i;
	}

	return temp;
}

int main()
{
	std::vector<std::future<int>> futures;

	futures.reserve(4);

	std::vector<int> data;
	data.reserve(100);

	for (unsigned int i = 0; i < 100; ++i)
		data.push_back(i);

	std::vector<std::promise<int>> p;

	for (unsigned int i = 0; i < 4; ++i)
		futures[i] = p[i].get_future();

	for (unsigned int i = 0; i < 4; ++i)
	{
		futures.push_back(std::thread(sum, data.begin() + (i * 25), data.begin() + ((i + 1) * 25), std::move(p)));
	}

	std::vector<int> result(4);

	for (unsigned int i = 0; i < 4; ++i)
		result[i] = futures[i].get();

	std::cout << result[0] << " " << result[1] << " " << result[2] << " " << result[3] << std::endl;

	std::cout << "result : " << result[1] + result[0] + result[2] + result[3] << std::endl;

	return 0;
}