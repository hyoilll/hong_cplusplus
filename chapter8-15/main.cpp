/*
	실행시간 측정하기

	debug

	release 모드로 시간 측정해야함. 베포를 release모드로 하기 때문에
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

class Timer
{
	using clock_t = std::chrono::high_resolution_clock;
	using secont_t = std::chrono::duration<double, std::ratio<1>>;

	std::chrono::time_point<clock_t> start_time = clock_t::now();

public:

	void elapsed()
	{
		std::chrono::time_point<clock_t> end_time = clock_t::now();

		cout << std::chrono::duration_cast<secont_t>(end_time - start_time).count() << endl;
	}
};

int main()
{
	random_device rnd_device;
	mt19937 mersenne_engine{ rnd_device() };

	vector<int> vec(10);

	for (unsigned int i = 0; i < vec.size(); ++i)
		vec[i] = i;

	std::shuffle(begin(vec), end(vec), mersenne_engine); //벡터 요소를 섞어줌

	for (const auto& e : vec)
		cout << e << " ";
	cout << endl;

	Timer timer;

	std::sort(begin(vec), end(vec));

	timer.elapsed();

	for (const auto& e : vec)
		cout << e << " ";
	cout << endl;


	return 0;
}