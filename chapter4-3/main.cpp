/*
	using���� ��ȣ��(�̸��� ���� �Լ��� ���� �� ��� ���� ȣ���ؾ� ���� �ָ��� ��)
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
		//cout << count << endl; std�ȿ��� count�� �ֱ� ������ �̸��浹��
		cout << a::count << endl;
	}

	{
		using namespace b;
		cout << my_var << endl;
	}

	return 0;
}