/*
	using문과 모호성(이름이 같은 함수가 있을 때 어느 것을 호출해야 할지 애매한 것)
*/

#include <iostream>
using namespace std;

namespace a
{
	int my_var(10);
	int count = 5;
}

namespace b
{
	int my_var(10);
}

int main()
{
	
	
	{
		using namespace a;
		cout << my_var << endl;
		//cout << count << endl; std안에도 count가 있기 때문에 이름충돌남
		cout << a::count << endl;
	}

	{
		using namespace b;
		cout << my_var << endl;
	}

	return 0;
}