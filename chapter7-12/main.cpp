/*
	���
*/

#include <iostream>
using namespace std;

//0~5���� ���(�������� / ��������)
void countDown(int count)
{
	/*
	5	4	3	2	1	0
	if (count == 0)
	{
		cout << count << endl;
		return;
	}
	cout << count << endl;
	countDown(--count);
	*/

	//0	1	2	3	4	5
	if (count > 0)
		countDown(count - 1);
	
	cout << count << endl;
	
}

//0~sumto���� ���ϱ�
int sumTo(int sumto)
{
	if (sumto == 0)
		return 0;
	else
		return sumTo(sumto - 1) + sumto;
}

int main()
{
	countDown(5);
	cout << endl;

	cout << sumTo(10) << endl;

	return 0;
}