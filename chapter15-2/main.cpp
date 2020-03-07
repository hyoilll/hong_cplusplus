/*
	������-�� ����
	R-value References
*/

#include <iostream>
using namespace std;

int getResult()
{
	return 100 * 100;
}

void doSomething(const int& lref)
{
	cout << "l-value ref" << endl;
}

void doSomething(const int&& lref)
{
	cout << "r-value ref" << endl;
}

int main()
{
	int x = 5;
	/*
		l-value
		x - �޸� �ּҸ� ���� �ִ� ��

		r-value
		5 - �޸��ּҸ� ���� ���� �ʾ�, �ش� ������ ������ ����� ���
	*/

	int y = getResult();

	const int cx = 6;
	const int cy = getResult();
	
	// l-value references

	int& lr1 = x;		// Modifiable l-vaules
	//int &lr2 = cx;	//non-modifiable l-values const ������ ���� �Ұ�
	//int &lr3 = 5;		//r-values ���������� �ٸ� �޸𸮰����� ���� ���� ���ε� �޸𸮰����� ���� ���� ����.

	const int& lr4 = x;		//Modifialbe l-values
	const int& lr5 = cx;	//non-modifiable l-values
	const int& lr6 = 5;		//r-values

	//r-value references

	//int&& rr1 = x;	l-value �����ϹǷ� error
	//int&& rr2 = cx;	l-value �����ϹǷ� error
	int&& rr3 = 5;
	/*
		r-value������ �ǹ̴� r-value������ �ݴ�� �� ����� ���ͷ������ ���ؼ� ������ �����ϴ�.
		�� �ǹ̴� �ٷ� ������� �ٸ� ���� ������ ���� �ʱ⿡ ����Ʈ�����Ϳ����� �����ǹ����� �߻����� �ʴ´�.
	*/

	//const int&& rr4 = x;	l-value �����ϹǷ� error
	//const int&& rr5 = cx; l-value �����ϹǷ� error
	const int&& rr6 = 5;

	// L/R - value reference parameters
	doSomething(x);
	doSomething(cx);
	doSomething(5);
	doSomething(getResult());


	return 0;
}