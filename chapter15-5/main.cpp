/*
	std::unique_ptr
*/


#include "Resource.h"
#include <memory> //std::unique_ptr
using namespace std;

auto makePtr()
{
	return std::make_unique<Resource>(5);
}

void doSomething1(std::unique_ptr<Resource>& res)
{
	res->setAll(10);
}
auto doSomething2(std::unique_ptr<Resource> res)
{
	res->setAll(10);
	return res;
}
void doSomething3(Resource* res)
{
	res->setAll(10);
}

int main()
{
	/*{
		//초기화 방법

		//1.
		std::unique_ptr<Resource> res1(new Resource(5));

		//2. 가장 많이 씀
		//auto res2 = std::make_unique<Resource>(5);

		//3.
		//auto res3 = makePtr();

		res1->setAll(5);
		res1->print();

		std::unique_ptr<Resource> res2;

		std::cout << std::boolalpha;

		std::cout << static_cast<bool>(res1) << endl;
		std::cout << static_cast<bool>(res2) << endl;

		//res2 = res1; error unique_ptr은 여러 변수가 같은 메모리를 참조할 수 없음.
		res2 = std::move(res1);

		std::cout << std::boolalpha;

		std::cout << static_cast<bool>(res1) << endl;
		std::cout << static_cast<bool>(res2) << endl;

		if (res1 != nullptr)
			res1->print();

		if (res2 != nullptr)
			//res2->print();
			(*res2).print();


	}*/

	{
		auto res1 = std::make_unique<Resource>(5);

		res1->setAll(1);
		res1->print();

		//doSomething1(res1);
		/*
			void doSomething1(std::unique_ptr<Resource>& res)
			매개변수가 &형이 아니면 error가 발생함 call-by-value로 l-value복사가 일어나는데 unique_ptr은 복사를 허용하지 않기 때문에.

			굳이 &형이 아닌 값으로 받고자 한다면 
			void doSomething(std::unique_ptr<Resource> res) = std::movd(res);
		*/

		//res1 = doSomething2(std::move(res1)); 함수 반환값은 r-value이기에 바로 가능

		doSomething3(res1.get());

		res1->print();
	}

	/*{
		//하면 안되는 것들
		
		Resource* res = new Resource;

		//1. 두개의 unique_ptr에 같은 메모리를 참조하게 하는 것.
		std::unique_ptr<Resource> res1(res);
		std::unique_ptr<Resource> res2(res);

		//2. unique_ptr이 알아서 delete해줄텐데 또 다시 delete하는 것
		delete res;
	}*/

	return 0;
}