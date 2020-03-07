#include <iostream>
#include <thread>

using std::thread;

void func1()
{
	for (unsigned int i = 0; i < 10; ++i)
		std::cout << "thread 1 작동중" << std::endl;
}
void func2()
{
	for (unsigned int i = 0; i < 10; ++i)
		std::cout << "thread 2 작동중" << std::endl;
}
void func3()
{
	for (unsigned int i = 0; i < 10; ++i)
		std::cout << "thread 3 작동중" << std::endl;
}

int main()
{
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	//C++ 표준에 따르면, join 되거나 detach 되지 않는 쓰레드들의 소멸자가 호출된다면 예외를 발생
	t1.detach();
	t2.detach();
	t3.detach();

	std::cout << "메인 함수 종료 \n";
	return 0;
}