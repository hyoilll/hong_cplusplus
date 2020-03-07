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
		//�ʱ�ȭ ���

		//1.
		std::unique_ptr<Resource> res1(new Resource(5));

		//2. ���� ���� ��
		//auto res2 = std::make_unique<Resource>(5);

		//3.
		//auto res3 = makePtr();

		res1->setAll(5);
		res1->print();

		std::unique_ptr<Resource> res2;

		std::cout << std::boolalpha;

		std::cout << static_cast<bool>(res1) << endl;
		std::cout << static_cast<bool>(res2) << endl;

		//res2 = res1; error unique_ptr�� ���� ������ ���� �޸𸮸� ������ �� ����.
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
			�Ű������� &���� �ƴϸ� error�� �߻��� call-by-value�� l-value���簡 �Ͼ�µ� unique_ptr�� ���縦 ������� �ʱ� ������.

			���� &���� �ƴ� ������ �ް��� �Ѵٸ� 
			void doSomething(std::unique_ptr<Resource> res) = std::movd(res);
		*/

		//res1 = doSomething2(std::move(res1)); �Լ� ��ȯ���� r-value�̱⿡ �ٷ� ����

		doSomething3(res1.get());

		res1->print();
	}

	/*{
		//�ϸ� �ȵǴ� �͵�
		
		Resource* res = new Resource;

		//1. �ΰ��� unique_ptr�� ���� �޸𸮸� �����ϰ� �ϴ� ��.
		std::unique_ptr<Resource> res1(res);
		std::unique_ptr<Resource> res2(res);

		//2. unique_ptr�� �˾Ƽ� delete�����ٵ� �� �ٽ� delete�ϴ� ��
		delete res;
	}*/

	return 0;
}