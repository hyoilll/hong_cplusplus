/*
	autoŰ����� �ڷ��� �߷�
*/

#include <iostream>

auto add(int x, int y) //�Ű������� auto�� �ȵǴ� ������ template�� ����
{ //���� + ���� �̱⿡ ��ȯ���� int��� �����Ϸ��� �ڵ����� ��Ī����
	return x + y;
}

int main()
{
	using namespace std;

	int a = 123; // == ���� ���� = ���� , ���� �ڷ����� ���� ����� �ʿ䰡 ������? �ؼ� ���°� autoŸ��

	auto b = 123; // ���ͷ�Ÿ������ �ڷ����� ���ϱ⿡ ����� �ʱ�ȭ ���� �ؾ���.
	auto c = 1 + 2;
	auto d = 1.5 + 3;

	cout << sizeof(b) << endl; //int
	cout << sizeof(c) << endl; //int
	cout << sizeof(d) << endl; //double

	auto result = add(60, 5);

	cout << result << endl;

	return 0;
}