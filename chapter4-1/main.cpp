/*
	지역 변수의 범위와 지속시간(블록, 명칭공간, 이름충돌, 이름숨기기)
*/

#include <iostream>

namespace A
{
	int a = 1;
	void doSomething()
	{
		a += 3;
		return;
	}
}

namespace B
{
	int a = 1;
	void doSomething()
	{
		a += 5;
		return;
	}
}
int main()
{
	using namespace std;

	int apple = 5;

	cout << apple << endl;
	
	{
		//더 작은 영역에서 동일 이름의 변수가 선언 될 경우 이름이 숨겨짐
		//메모리를 적게 사용하기 위해 해당 변수가 사용될 부분에서만 사용하고 반납하게끔 하기 위해 사용함
		int apple = 1;
		cout << apple << endl;
	}

	cout << apple << endl;

	cout << A::a << endl;
	A::doSomething();
	cout << A::a << endl;

	cout << B::a << endl;
	B::doSomething();
	cout << B::a << endl;

	return 0;
}