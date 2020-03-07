/*
	작업 기반 비동기 프로그래밍
*/

#include <iostream>
#include <future> //
#include <thread>

using namespace std;

int main()
{
	// multi-threading
	{
		int result;
		std::thread t = std::thread([&]() {result = 1 + 2; });

		t.join(); //thread가 끝날 때까지 기다림

		cout << result << endl;
	}

	// task-based parallelism (thread보다 권장함)
	{
		auto fut = std::async([] {return 1 + 2; });

		cout << fut.get() << endl; // async에서 작업을 마치고 값을 넘겨줄 때까지 기다림
	}

	//future and promise
	{
		std::promise<int> p;

		auto fut = p.get_future();
		
		auto t = std::thread([](std::promise<int>&& _p)
			{
				_p.set_value(1 + 2);
			}, std::move(p));

		cout << fut.get() << endl;

		t.join();
	}

	//thread와 다르게 join이 없어도 async는 알아서 기다림
	{
		//std::async가 future로 받아주지 않으면 순차진행이 되버림(동기)
		auto f1 = std::async([]
			{
				cout << "async1 start" << endl;
				this_thread::sleep_for(chrono::seconds(2));

				cout << "async1 end" << endl;
			});

		auto f2 = std::async([]
			{
				cout << "async2 start" << endl;
				this_thread::sleep_for(chrono::seconds(1));

				cout << "async2 end" << endl;
			});

		cout << "Main function" << endl;
	}

	return 0;
}