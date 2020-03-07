/*
	레이스 컨디션(race condition), std::atomic, std::scoped_lock
*/

#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>
#include <mutex>
using namespace std;

int main()
{
	//atomic<int> shared_memory = 0;
	int shared_memory = 0;
	mutex mt;

	auto count_func = [&]()
	{
		for (unsigned int i = 0; i < 1000; ++i)
		{
			this_thread::sleep_for(chrono::microseconds(1));
			
			//mt.lock();

			//std::lock_guard<mutex> lock(mt); //lock_guard를 더 권창함 mutex.lock보다

			std::scoped_lock lock(mt); //lock_guard보다 더 발전한 lock 권장함 c++ 17

			shared_memory++;

			//mt.unlock();
			/*
				1. cpu로 읽어옴
				2. 1 더해줌
				3. 다시 메모리에 덮어씀
			*/
		}
	};

	std::thread t1 = std::thread(count_func);
	std::thread t2 = std::thread(count_func);

	t1.join();
	t2.join();


	cout << "After memory : " << shared_memory << endl;

	return 0;
}