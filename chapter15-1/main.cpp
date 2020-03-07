/*
	'이동'의 의미와 스마트 포인터 소개

	move VS deep copy

	// syntax vs semantics
	int x = 1, y = 1;
	x + y;

	string str1("Hello"), str2("World");
	str1 + str2; //append

	스마트 포인터 [참조] https://blog.naver.com/sssang97/221805546474
*/

#include "Resource.h"
#include "AutoPtr.h"

using namespace std;

void doSomething()
{
	//Resource* res = new Resource; //dull pointer

	//work with res

	//delete res;

	AutoPtr<Resource> a_res(new Resource);


	return;
}

int main()
{
	//doSomething();

	//------------------------------------------------

	{
		AutoPtr<Resource> res1(new Resource);
		AutoPtr<Resource> res2;
		AutoPtr<Resource> res3;
		/*
			int i;
			int* ptr1 = &i
			int* ptr2;
		*/


		res1->m_data;
		res1->print();

		(*res1).print();

		cout << std::boolalpha;

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;

		res3 = res2 = res1; //move semantics 소유권 이전
		//res2.operator=(res1);
		//res3.operator=(res2.operator=(res1));

		cout << res1.m_ptr << endl;
		cout << res2.m_ptr << endl;
	}



	return 0;
}