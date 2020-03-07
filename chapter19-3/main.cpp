/*
	std::thread와 멀티 쓰레딩의 기초
*/

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
using namespace std;

mutex mtx; //mutual exclusion 상호배제

int main()
{
	/*
		process
		os가 사용자가 작성한 프로그램을 실행시킬 때 관리하는 단위

		1개의 process가 여러개의 thread를 관리 할 수 있음
	*/

	const int num_pro = std::thread::hardware_concurrency(); //core 갯수

	cout << std::this_thread::get_id() << endl;

	/*{
		std::thread t1 = std::thread([]()
			{
				cout << std::this_thread::get_id() << endl;

				while (true)
				{

				}
			});

		std::thread t2 = std::thread([]()
			{
				cout << std::this_thread::get_id() << endl;

				while (true)
				{

				}
			});

		std::thread t3 = std::thread([]()
			{
				cout << std::this_thread::get_id() << endl;

				while (true)
				{

				}
			});

		std::thread t4 = std::thread([]()
			{
				cout << std::this_thread::get_id() << endl;

				while (true)
				{

				}
			});

		t1.join(); //t1이 끝날 때까지 기다려라
		t2.join();
		t3.join();
		t4.join();
	}*/

	{
		vector<std::thread> thread_vec;
		thread_vec.resize(num_pro);

		for (auto& e : thread_vec)
			e = std::thread([]()
				{
					cout << std::this_thread::get_id() << endl;
					/*while (true)
					{

					}*/
				});


		for (auto& e : thread_vec)
			e.join();
	}

	/*{
		auto work_func = [](const string& name)
		{
			for (unsigned int i = 0; i < 5; ++i)
			{
				std::this_thread::sleep_for(std::chrono::microseconds(100));

				mtx.lock(); //내가 먼저 쓰겠다

				cout << name << std::this_thread::get_id() << "is working " << i << endl;

				mtx.unlock(); //내가 다 썼으니 아무나 다시 써라
			}
		};

		//work_func("JackJack");
		//work_func("Dash");

		std::thread t1 = std::thread(work_func, "JackJack");
		std::thread t2 = std::thread(work_func, "Dash");

		t1.join();
		t2.join();
	}*/

	return 0;
}