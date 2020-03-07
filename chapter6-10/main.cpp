/*
	c ��Ÿ���� ���ڿ� ��ȣ��(Symbolic) ���
*/

#include <iostream>
using namespace std;

const char* getName()
{
	return "java java";
}

int main()
{
	//char* name = "java java"; 
	//error : "java java"�� ���ͷ� �̶� �����ͺ����� �ٷ� ����Ű�� ����. "java java"�� ���� �޸𸮰� �ʿ���
	
	const char* name1 = getName(); //const�� �ٿ��ָ� ��ȣ���� ���ó�� ��밡����.

	const char* name2 = "java java";

	cout << (uintptr_t)name1 << endl;
	cout << (uintptr_t)name2 << endl;
	//"java java"�����ϱ� �׳� ���� �� �����Ѷ�~
	//���ڿ��� �޶����� �ּҵ� �޶���.
	cout << endl;

	//------------------------------------------------------------------------

	int i_arr[] = { 1,2,3,4,5 };
	char c_arr[] = "Hello, World!";
	const char* name = "java java";

	cout << i_arr << endl;	//address
	cout << c_arr << endl;	//Hello, World!
	cout << name << endl;	//java java
	//���ڿ� �������� ��� Ư���ϰ� ó����. �����ͺ��� �׳� ���ڿ��� �ƴұ�? ��� ������ ��.
	cout << endl;

	//------------------------------------------------------------------------

	char c = 'Q';

	cout << &c << endl; //���ڿ��̶�� ������ ��.
	

	return 0;
}