/*
	Selection Sort
	
	index = array�� ���� ����Ǿ� �ִ� ��ġ
	value = ���� �� ��ġ�� ����Ǿ� �ִ� ��

				value		index
	3 5 2 1 4	3 -> 2 -> 1	0 -> 2 -> 3			=> 1�� 3�� ��ü
	1 5 2 3 4	5 -> 2		1 -> 2				=> 2�� 5�� ��ü
	1 2 5 3 4	5 -> 3		2 -> 3				=> 3�� 5�� ��ü
	1 2 3 5 4	5 -> 4		3 -> 4				=> 4�� 5�� ��ü
	1 2 3 4 5	5 ->		4 ->				=> ��
	
*/

#include <iostream>
using namespace std;

void printArray(int i_arr[], const int length)
{
	for (int i = 0; i < length; ++i)
	{
		cout << i_arr[i] << " ";
	}
	cout << endl;

	return;
}

int main()
{
	const int numbers = 5;
	int i_arr[numbers] = { 3,5,2,1,4 };

	int idx = 0;

	for (int i = 0; i < numbers - 1; ++i)
	{
		idx = i;

		for (int j = i + 1; j < numbers; ++j)
		{
			if (i_arr[idx] > i_arr[j])
			{
				idx = j;
			}
		}

		//std::swap(i_arr[i], i_arr[idx]);
		int temp = i_arr[i];
		i_arr[i] = i_arr[idx];
		i_arr[idx] = temp;
	}

	printArray(i_arr, numbers);

	return 0;
}