#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
using std::thread;
using std::vector;

std::mutex m;

void worker(vector<int>::iterator start, vector<int>::iterator end, int & result)
{
	int sum = 0;
	for (auto itr = start; itr <= end; ++itr)
		sum += *itr;
	result = sum;

	m.lock();
	std::cout << *start << " ~ " << *end << " : " << result << std::endl;
	m.unlock();
}

int main() 
{
	vector<int> result_vec(4);

	vector<int> range;
	range.reserve(10000);

	for (unsigned int i = 0; i < 10000; ++i)
		range.push_back(i);
	
	vector<thread> thread_vec;
	thread_vec.reserve(4);

	for (unsigned int i = 0; i < 4; ++i)
		thread_vec.push_back(thread(worker, range.begin() + (i * 2500), range.begin() + ((i + 1) * 2500 - 1), std::ref(result_vec[i])));
	
	for (auto& e : thread_vec)
		e.join();

	std::cout << result_vec[0] + result_vec[1] + result_vec[2] + result_vec[3];

	return 0;
}