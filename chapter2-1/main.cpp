/*
	�⺻ �ڷ��� �Ұ�
	�ʱ�ȭ ���
*/
#include <iostream>

int main()
{
	using namespace std;

	bool bValue = false;
	char chValue = 65;
	float fValue = 3.141592f; // f�� ���̴� ������ �Ҽ��� ���ͷ��� doubleŸ������ 
							  // �������� ������ f�� ���� double > float �̷� ������ �Ǳ⿡ ���
	double dValue = 3.141592;

	cout << fValue << endl;
	cout << dValue << endl;

	auto aValue = "hiqweqwewqeqe";

	cout << sizeof(aValue) << endl;
	cout << sizeof(char*) << endl;

	int a = (int)3.1415;	// copy initialization
	int b((int)3.14);		// direct initialization
	int c{ 3 };				// uniform initialization

	cout << a << " " << b << " " << c << endl;


	return 0;

}