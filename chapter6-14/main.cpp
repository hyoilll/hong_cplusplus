/*
	���� ����
*/

#include <iostream>
using namespace std;

void douSomething(int &n) //const int& n 
{
	n = 10;

	cout << "In doSomething " << n << endl;
	cout << &n << endl;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

int main()
{
	int value = 5;

	int& ref = value; //value�� �� �ٸ� �̸�

	int* ptr = &value;

	ref = 10;

	cout << ref << " " << value << endl;

	cout << &value << endl;	//0xA
	cout << &ref << endl;	//0xA
	cout << ptr << endl;	//0xA
	cout << &ptr << endl << endl;	//0xB
	
	//------------------------------------------------------------------

	//����� ���ÿ� �ʱ�ȭ�Ǿ����.
	//���ͷ� ����� ������ �� ����.

	/*
		const int y = 8;
		int& c_ref = y;
		
		=> error, const�� �ƴ� ���������� const������ ������ �� �ֱ⿡ error�߻�. 

		const int y = 8;
		const int& c_ref = y;

		=> error �ذ�
	*/

	//-----------------------------------------------------------------

	int value1 = 5;
	int value2 = 10;

	int& ref1 = value1;

	cout << ref1 << endl;

	ref1 = value2;
	//������ ����

	cout << ref1 << endl << endl;

	//----------------------------------------------------------------

	int n = 5;

	cout << n << endl;

	cout << &n << endl;

	douSomething(n);
	//pointer�� �̿��� call-by-reference�� �޴� �Լ��� �����͸Ű������� �ּҸ� �����ϱ⿡ ������ ����� ��.
	//reference�� �̿��� call-by-reference�� �ּ����� ������ �ʿ䰡 ���⿡, ���ɸ鿡���� �� ����

	cout << n << endl << endl;

	//----------------------------------------------------------------

	Other ot;

	int& v1 = ot.st.v1;
	//����ȭ

	v1 = 1.0;

	//---------------------------------------------------------------

	value = 5;
	int* const ptr = &value;
	int& qwe = value;

	*ptr = 10;
	ref = 10;
	//���� ����

	return 0;
}