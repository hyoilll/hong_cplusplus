#include <future>
#include <iostream>
#include <string>
#include <thread>

void worker(std::promise<std::string>* p)
{
	//����� �����ϴ� ���, �ش� ����� future�� ����.
	p->set_value("some data");
}

int main()
{
	//������ ���� �Ŀ� ������ ��ü�� Ÿ���� ���ø� ���ڷ� �޽��ϴ�.
	std::promise<std::string> p;

	//�̷��� string �����͸� �����ְڴٴ� ���
	std::future<std::string> str = p.get_future();

	std::thread t(worker, &p);

	//�̷��� ��ӵ� �����͸� ���� ������ ��ٸ���
	str.wait();

	//wait�� �����ߴٴ� ���� future�� �����Ͱ� �غ�ƴٴ� �ǹ�.
	//����� wait���� �׳� get �ص� wait�� �Ͱ� ����.

	std::cout << "get data : " << str.get() << std::endl;

	/*
		����� ���� wait �Լ��� ���� ȣ���� �ʿ�� ���µ�
		, get �Լ��� �ٷ� ȣ���ϴ��� �˾Ƽ� promise �� 
		future �� ��ü�� ������ �� ���� ��ٸ������� �����մϴ�. 
		����� get �� ȣ���ϸ� future ���� �ִ� �����Ͱ� �̵� �˴ϴ�.
		���� get �� �ٽ� ȣ���ϸ� �ȵ˴ϴ�.
	*/
	t.join();

	return 0;
}