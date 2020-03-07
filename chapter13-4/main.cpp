/*
	�Լ� ���ø� Ư��ȭ(Spectialization)
*/

#include <iostream>
#include "Storage.h"
using namespace std;

template <class T>
T getMax(const T& x, const T& y)
{
	return (x > y) ? x : y;
}

//function Spectialization
//char�� ��쿡�� ���� getMax�� ����ض�.
//if�� ����ؼ� �б��� �� ���� ������ ������ Ÿ�ӿ� ���ؾ� �ϱ� ����.
template<>
char getMax(const char& x, const char& y)
{
	cout << "Warning : comparing chars" << endl;

	return (x > y) ? x : y;
}

int main()
{
	cout << getMax('a', 'b') << endl; // == getMax<int>(1, 2)

	cout << endl;

	//-------------------------------------------------------------

	Storage<int> nValue(5);
	Storage<double> dValue(6.7);

	nValue.print();
	dValue.print();


	return 0;
}