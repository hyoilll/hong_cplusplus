/*
	�۾� ��� �񵿱� ���α׷���
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

		t.join(); //thread�� ���� ������ ��ٸ�

		cout << result << endl;
	}

	// task-based parallelism (thread���� ������)
	{
		auto fut = std::async([] {return 1 + 2; });

		cout << fut.get() << endl; // async���� �۾��� ��ġ�� ���� �Ѱ��� ������ ��ٸ�
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

	//thread�� �ٸ��� join�� ��� async�� �˾Ƽ� ��ٸ�
	{
		//std::async�� future�� �޾����� ������ ���������� �ǹ���(����)
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