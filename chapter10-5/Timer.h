#pragma once

#include <iostream>
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