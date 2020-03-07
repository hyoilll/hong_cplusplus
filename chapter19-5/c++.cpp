#include <future>
#include <iostream>
#include <string>
#include <thread>

void worker(std::promise<std::string>* p)
{
	//약속을 이행하는 모습, 해당 결과는 future에 들어간다.
	p->set_value("some data");
}

int main()
{
	//연산을 수행 후에 돌려줄 객체의 타입을 템플릿 인자로 받습니다.
	std::promise<std::string> p;

	//미래에 string 데이터를 돌려주겠다는 약속
	std::future<std::string> str = p.get_future();

	std::thread t(worker, &p);

	//미래에 약속된 데이터를 받을 때까지 기다린다
	str.wait();

	//wait이 리턴했다는 뜻이 future에 데이터가 준비됐다는 의미.
	//참고로 wait없이 그냥 get 해도 wait한 것과 같다.

	std::cout << "get data : " << str.get() << std::endl;

	/*
		참고로 굳이 wait 함수를 따로 호출할 필요는 없는데
		, get 함수를 바로 호출하더라도 알아서 promise 가 
		future 에 객체를 전달할 때 까지 기다린다음에 리턴합니다. 
		참고로 get 을 호출하면 future 내에 있던 데이터가 이동 됩니다.
		따라서 get 을 다시 호출하면 안됩니다.
	*/
	t.join();

	return 0;
}