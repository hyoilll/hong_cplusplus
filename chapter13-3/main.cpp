/*
	�ڷ����� �ƴ� ���ø� �Ű�����
*/

#include "MyArray.h"

int main()
{
	//std::vector<char> vec;
	//vec.resize(100);

	//MyArray<char> arr(100);

	//�� �ΰ��� ������ �����Ҵ��̱⿡ ��Ÿ���� �Ű������� �������� ��.

	MyArray<char, 100> arr;
	//������Ÿ�ӿ� 100�̶�� ���ڰ� �������� ��.

	for (unsigned int i = 0; i < arr.getLength(); ++i)
		arr[i] = 65 + i;
	std::cout << &(arr[0]);
	arr.print();

	return 0;
}