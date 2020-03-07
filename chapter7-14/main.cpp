/*
	�ܾ��ϱ� assert VS static assert

	��Ÿ���߿� ������ Ȯ���ϴ� ��
	compiler�� ������ �޾� errorȮ��
	assert���� �������ڷ� ���� �� ���� ���ε��� �ϴ°� ����.
	�׷��� ��𿡼� ������ ������ Ȯ���� �� �� ����.

	assert(bool) => ������ ���̸� ���, �����̸� �����߻�

	[����] https://blog.naver.com/ejsvk3284/221332477269
*/

#include <cassert> // assert.h
#include <array>
#include <iostream>

void printValue(const std::array<int, 5>& arr, const int& idx)
{
	assert(idx >= 0);
	assert(idx <= arr.size() - 1);

	std::cout << arr[idx] << std::endl;
}

int main()
{
	int number = 5;

	//number should be 5
	assert(number == 5); //release ��忡���� �۵��ȵ�.

	//-----------------------------------------------------

	std::array<int, 5> arr{ 1,2,3,4,5 };

	printValue(arr, 10);

	//-----------------------------------------------------

	//static assert ������Ÿ�ӿ� ���� �߻�
	const int x = 5;

	assert(x == 5);

	static_assert(x == 5, "x should be 5");


	return 0;
}