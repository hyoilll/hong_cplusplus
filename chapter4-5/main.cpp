/*
	����ȯ Type conversion
	����� vs ������
*/

#include <iostream>
#include <typeinfo>
#include <iomanip>
using namespace std;

int main()
{
	auto a = 123.0;
	cout << typeid(a).name() << endl; // �ڷ��� ���

	//numeric promotion
	float f = 1.0f;
	double d = f; 
	// double�� float���� ũ�Ⱑ ũ�� ������ ��������

	//numeric conversion ��ȯ
	int i = 30000;
	char c = i;
	cout << static_cast<int>(c) << endl; //����� ����ȯ
	// char(-128 ~ 127)�� int���� ũ�Ⱑ �۱� ������ int�� ���� �״�� ���� ���� ����. ���� �սǵ�

	d = 0.123456789123456789;
	f = d;

	cout << std::setprecision(20);
	cout << f << endl; //0.12345679104328155518
	cout << d << endl; //0.1234567891234567838
	// ���е��� float�� �� ���� ������ �սǵ�(��ȿ����)

	//unsigned
	cout << 5u - 10u << endl; //underflow

	//int < unsigned int < long < unsigned long < long long < unsigned long long < float < double < long double

	i = 4.0; //������ ��ȯ
	i = (int)4.0; //c style
	i = int(4.0); //c++
	i = static_cast<int>(4.0); //�ֱ�
	// => ��ɻ��� ���̴� ���� ����

	return 0;
}