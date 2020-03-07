/*
	pointer
	���������� '����' �޸𸮸� ����ϰ�,
	���� �Ҵ� �޸𸮴� '��' �޸𸮸� ����Ѵ�.
	ū �޸𸮿� ����Ǿ� �ִ� ������ �߿��� �Ϻκ��� cpu�� ����ϱ� ���ؼ�
	�޸𸮷κ��� ������ ���� �޸� ��ü�� ��� �����鼭 ã�� ���� �ƴ϶�, �ʿ��� �����Ͱ� ����Ǿ� �ִ�
	'�ּ�'�� �����Ͽ� �����´�.
*/

#include <iostream>
#include <typeinfo>
using namespace std;

struct Something
{
	int a, b, c, d;
};

int main()
{
	int x = 5;

	cout << x << endl;
	cout << &x << endl; // & : address of operator
	cout << int(&x) << endl;

	//de-reference operator (*)
	cout << *(&x) << endl; //x�޸� �ּ��� ���� ���� ����? : *

	//pointer
	int* ptr_x = &x;
	//������ ������ �ڷ����� ���� ������ de-reference�� �� �� ��� �ڷ������� ������ ���� ������� �ؼ�

	cout << ptr_x << endl;
	cout << *ptr_x << endl; //int ������ ������ �Ǿ��⿡ intŸ������ �����Ͷ�

	double d = 1.0;
	double* ptr_y = &d;

	cout << ptr_y << endl;
	cout << *ptr_y << endl;

	cout << typeid(ptr_x).name() << endl;
	cout << typeid(ptr_y).name() << endl;

	cout << sizeof(ptr_x) << endl;
	cout << sizeof(ptr_y) << endl;
	//pointer ������ ��� ���� 4bytes => �ּҰ� ���� 4byte�� ���� / x64������ �ּҰ� �� �� 8bytes

	Something ss;
	Something* ptr_s;

	cout << sizeof(Something) << endl;	//16
	cout << sizeof(ptr_s) << endl;		//4



	return 0;
}