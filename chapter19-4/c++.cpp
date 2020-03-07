#include <iostream>
#include <thread>
#include <vector>
#include <mutex>  // mutex �� ����ϱ� ���� �ʿ�, ��ȣ ���� (mutual exclusion) 

void counter(int & cnt, std::mutex& m)
{
	/*
		m.lock() �� m.unlock() ���̿� �� �����常�� �����ϰ�
		������ �� �ִ� �ڵ� �κ��� �Ӱ� ����(critical section) 

		���࿡ ��԰� m.unlock() �� ���� �ʴ´ٸ� ��� �ɱ��?
		���ؽ��� ����� �����尡 unlock �� ���� �����Ƿ�, �ٸ� ��� ��������� ��ٸ��� �˴ϴ�. 
		������ ���ε� ���������� m.lock() �� �ٽ� ȣ���ϰ� �ǰ�, unlock �� ���� �ʾұ⿡ ���� ���� ��ٸ��� ����.
		�ᱹ �ƹ� �����嵵 ������ �������� ���ϰ� �˴ϴ�. �̷��� ��Ȳ�� �����(deadlock)

		����� �ذ� ��� => lock_guard
	*/

//	m.lock();
	
	std::lock_guard<std::mutex> lock(m); // lock ���� �ÿ� m.lock() �� �����Ѵٰ� ���� �ȴ�.

	int& count = cnt;
	for (unsigned int i = 0; i < 10000; ++i)
		count++;

	// scope �� ���� ������ lock �� �Ҹ�Ǹ鼭
	// m �� �˾Ƽ� unlock �Ѵ�.

//	m.unlock();
}

int main()
{
	int count = 0;
	std::mutex m;

	std::vector<std::thread> thread_vec;

	for (unsigned int i = 0; i < 4; ++i)
		thread_vec.push_back(std::thread(counter, std::ref(count), std::ref(m)));

	for (auto& e : thread_vec)
		e.join();

	std::cout << "total count = " << count << std::endl;

	return 0;
}