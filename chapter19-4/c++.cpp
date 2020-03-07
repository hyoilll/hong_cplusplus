#include <iostream>
#include <thread>
#include <vector>
#include <mutex>  // mutex 를 사용하기 위해 필요, 상호 배제 (mutual exclusion) 

void counter(int & cnt, std::mutex& m)
{
	/*
		m.lock() 과 m.unlock() 사이에 한 쓰레드만이 유일하게
		실행할 수 있는 코드 부분을 임계 영역(critical section) 

		만약에 까먹고 m.unlock() 을 하지 않는다면 어떻게 될까요?
		뮤텍스를 취득한 쓰레드가 unlock 을 하지 않으므로, 다른 모든 쓰레드들이 기다리게 됩니다. 
		심지어 본인도 마찬가지로 m.lock() 을 다시 호출하게 되고, unlock 을 하지 않았기에 본인 역시 기다리게 되죠.
		결국 아무 쓰레드도 연산을 진행하지 못하게 됩니다. 이러한 상황을 데드락(deadlock)

		데드락 해결 방안 => lock_guard
	*/

//	m.lock();
	
	std::lock_guard<std::mutex> lock(m); // lock 생성 시에 m.lock() 을 실행한다고 보면 된다.

	int& count = cnt;
	for (unsigned int i = 0; i < 10000; ++i)
		count++;

	// scope 를 빠져 나가면 lock 이 소멸되면서
	// m 을 알아서 unlock 한다.

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