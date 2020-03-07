#include <queue>
#include <string>
#include <mutex>
#include <vector>
#include <thread>
#include <chrono> // std::chrono::miliseconds
#include <condition_variable>  // std::condition_variable
#include <iostream>

void producer(std::queue<std::string>* downloaded_pages, std::mutex* m, int index, std::condition_variable* cv)
{
	for (unsigned int i = 0; i < 5; ++i)
	{
		//웹사이트를 다운로드하는데 걸리는 시간
		//각 쓰레드마다 다운로드 하는 시간이 다름
		std::this_thread::sleep_for(std::chrono::microseconds(100 * index));
		
		std::string content = "웹사이트 : " + std::to_string(i) + " from thread(" + std::to_string(index) + ")\n";

		
		m->lock();
		
		downloaded_pages->push(content); //data는 쓰레드 사이에서 공유되므로 critical section에 넣어야 함
		
		m->unlock();

		//consumer에게 content가 준비됐음을 알림.
		cv->notify_one(); //1개의 thread를 깨움
	}
}

void consumer(std::queue<std::string>* download_pages, std::mutex* m, int* num_processed, std::condition_variable* cv)
{
	while (*num_processed < 25)
	{
		/*m->lock();

		if (download_pages->empty())
		{
			m->unlock();

			std::this_thread::sleep_for(std::chrono::microseconds(10));
			continue;
		}*/

		std::unique_lock<std::mutex> lk(*m);

		cv->wait(lk, [&] {return !download_pages->empty() || *num_processed == 25; });

		if (*num_processed == 25)
		{
		 	lk.unlock();
			return;
		}

		std::string content = download_pages->front();
		download_pages->pop();

		(*num_processed)++;
		lk.unlock();

		//content 처리
		std::cout << content;
		std::this_thread::sleep_for(std::chrono::microseconds(80));
	}
}

int main()
{
	std::queue<std::string> downloaded_pages;
	std::mutex m;
	std::condition_variable cv;

	std::vector<std::thread> producers;

	for (unsigned int i = 0; i < 5; ++i)
		producers.push_back(std::thread(producer, &downloaded_pages, &m, i + 1, &cv));

	int num_processed = 0;
	std::vector<std::thread> consumers;

	for (unsigned int i = 0; i < 3; ++i)
		consumers.push_back(std::thread(consumer, &downloaded_pages, &m, &num_processed, &cv));


	for (auto& e : producers)
		e.join();

	// 나머지 자고 있는 쓰레드들을 모두 깨운다.
	cv.notify_all();

	for (auto& e : consumers)
		e.join();


	return 0;
}