/*
	sizeof ������ (�Լ��� �ƴ�), (comma operator)��ǥ ������, (conditional operator == ���׿�����)���Ǻ� ������
*/

#include <iostream>
using namespace std;

int main()
{
	//szieof (bytes����)

	float a = 0.0f; 

	sizeof(float);
	sizeof(a); // = sizeof a;

	//��ǥ ������

	int x = 3;
	int y = 10;
	int z = (++x, ++y);
	/* ==
		++x;
		++y;
		int z = y;

		=> ������ ���� ���ԵǴ� ��
	*/

	cout << x << " " << y << " " << z << endl;

	int n1 = 1, n2 = 10;
	int n3 = 0;

	n3 = n1, n2; // 1
	n3 = (n1, n2); // 10
	//��ȣ�� ������ ���� ���� �޶�����?
	//,�������� �켱������ ���Կ�����= ���� ���� �׷��� n1�� ���� ���� ������ (n3 = n1), n2;

	cout << n3 << endl;
	
	//���Ǻ� ������

	bool onSale = true;

	int price = 0; // const int price (x) 
	
	if (onSale == true)
		price = 10;
	else
		price = 100;

	cout << price << endl;
	/* ==
		const int price = (onSale == true) ? 10 : 100; 
		if�������� price�� const������ �� ���µ� ���׿����ڴ� const ������ �ʱ�ȭ�� �� ���� / ������ ��츸 ����� ��
		but ���� if�� Ȱ���ϰ� �ʹٸ� �Լ��� �ϳ� ���� const int price = getPrice(); �̷��� �� ���� ����
	*/

	cout << ((10 % 2 == 0) ? "¦��" : "Ȧ��") << endl; 
	// �켱���� ������ �������� ?:�����ڴ� �켱������ ������ ���Ƽ� << �����ڰ� ���� �����̵�

	return 0;
}