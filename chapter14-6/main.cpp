/*
	예외처리 위험성과 단점

	try-catch는 속도가 느려지기에 for문 안에 넣는 것은 삼가해라

	모든 예외를 다 try-catch로 잡는건 좋지 않다.
	
	분산처리, 병렬처리, 하드웨어작업, 파일입출력 등에 try-catch 사용 (논리적으로 해결할 수 없는 경우)

	사용자 입력같은 예외는 if문으로 걸러내는 것이 좋음.

	unique_ptr[참조] https://blog.naver.com/sssang97/221805546474
*/

#include <iostream>
#include <memory>
using namespace std;

class A
{
public:
	~A()
	{
		//throw "error";
		//메모리를 모두 지우고 사라지기에 소멸자에서 예외를 던질 수 없다.
	}
};

int main()
{
	try
	{
		int* i = new int[10];

		//do something with 1

		throw "error";

		delete[] i;
		//메모리 할당받고 예외 발생하게 되면 delete를 하지 못해 메모리 누수 발생 => 스마트포인터 사용

		//------------------------------------------------------------------------------------------------------

		unique_ptr<int> up_i(new int[10]);
		//영역이 끝나면(catch로 이동도 포함) 유니크포인터가 알아서 메모리 해제함
		
		//------------------------------------------------------------------------------------------------------

		A a;
	}
	catch (...)
	{
		cout << "Catch" << endl;
	}

	return 0;
}