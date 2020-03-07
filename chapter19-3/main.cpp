/*
	std::thread�� ��Ƽ �������� ����
*/

#include <iostream>
#include <thread>
#include <vector>
#include <string>
#include <mutex>
using namespace std;

mutex mtx; //mutual exclusion ��ȣ����

int main()
{
	/*
		process
		os�� ����ڰ� �ۼ��� ���α׷��� �����ų �� �����ϴ� ����

		1���� process�� �������� thread�� ���� �� �� ����
	*/

	const int num_pro = std::thread::hardware_concurrency(); //core ����

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

		t1.join(); //t1�� ���� ������ ��ٷ���
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

				mtx.lock(); //���� ���� ���ڴ�

				cout << name << std::this_thread::get_id() << "is working " << i << endl;

				mtx.unlock(); //���� �� ������ �ƹ��� �ٽ� ���
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