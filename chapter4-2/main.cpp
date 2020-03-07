/*
	���� ����, ���� ����, ���� ����, �ܺ� ����

	int g_x; external linkage	�ٸ� cpp���Ͽ��� ���� ����
	static int g_x; internal linkage	�ٸ� cpp���Ͽ��� ���� �Ұ�
	const int g_x; x

	extern int g_z;
	extern const int g_z; o
	
	int g_y(1);
	static int g_y(1);
	const int g_y(1);

	extern int g_w(1); 
	extern const int g_w(1);
*/

#include <iostream>
#include "MyConstant.h"

using namespace std;

int value = 123; //�������� �ش� ���Ͽ����� ���� ��������

static int g_a = 1; // �ٸ� cpp���Ͽ��� ����� �� ���� ������������

extern int z = 9; // �ٸ� cpp���Ͽ����� ����� �� �ִ� ��������

extern void print(); //forward declaration ��򰡿� print�Լ��� ��ü�� �����ϴ� �����Ͻ� �����ض�


void doSomething()
{
	static int a = 1;

	++a;

	cout << a << endl;
}

int main()
{
	

	//���� ����
	cout << value << endl; // 123
	
	int value = 1;

	cout << value << endl; // 1
	cout << ::value << endl; // 123

	cout << endl;
	//-----------------------------------

	//���� ���� static
	doSomething();
	doSomething();

	/*
		static �� ó�� �ʱ�ȭ�� �ѹ��� ��. �޸� ����
		static vs global
		1. static�� ��������ó�� �ش� ������ �������� ������ ����
		2. ��������ó�� ���α׷��� ���� �ɶ����� ���� �Ҹ���� ����.
	*/

	print();
	cout << z << endl;

	cout << "main.cpp " << Constants::pi << " " << &Constants::pi << endl;

	return 0;
}