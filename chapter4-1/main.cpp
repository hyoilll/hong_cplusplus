/*
	���� ������ ������ ���ӽð�(���, ��Ī����, �̸��浹, �̸������)
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
		//�� ���� �������� ���� �̸��� ������ ���� �� ��� �̸��� ������
		//�޸𸮸� ���� ����ϱ� ���� �ش� ������ ���� �κп����� ����ϰ� �ݳ��ϰԲ� �ϱ� ���� �����
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