#include <iostream>
#include <thread>

using std::thread;

void func1()
{
	for (unsigned int i = 0; i < 10; ++i)
		std::cout << "thread 1 �۵���" << std::endl;
}
void func2()
{
	for (unsigned int i = 0; i < 10; ++i)
		std::cout << "thread 2 �۵���" << std::endl;
}
void func3()
{
	for (unsigned int i = 0; i < 10; ++i)
		std::cout << "thread 3 �۵���" << std::endl;
}

int main()
{
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	//C++ ǥ�ؿ� ������, join �ǰų� detach ���� �ʴ� ��������� �Ҹ��ڰ� ȣ��ȴٸ� ���ܸ� �߻�
	t1.detach();
	t2.detach();
	t3.detach();

	std::cout << "���� �Լ� ���� \n";
	return 0;
}