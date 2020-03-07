/*
	����ó���� ���� �ǰ���(stack Unwinding)

	������ �ѹ� ã�ƺ���
	std::cout
	std::cerr
	std::clog
*/

#include <iostream>
using namespace std;

//void last() throw(int) int���� error�� �߻� �� �� �ִ�.
//void last() throw(...) random���� error�� �߻� �� ���ִ�.
//void last() throw() ��� error�� �߻����� �ʾƿ�.

void last() throw(int) //int���� error�� �߻� �� �� �ִ�.
{
	cout << "last" << endl;
	cout << "Throws exception" << endl;

	throw - 1;

	cout << "End last" << endl;
}

void third()
{
	cout << "Third" << endl;

	last();

	cout << "End third" << endl;
}

void second()
{
	cout << "second" << endl;

	try
	{
		third();
	}
	catch (double)
	{
		cerr << "second caught int exception" << endl;
	}

	cout << "End second" << endl;
}

void first()
{
	cout << "first" << endl;

	try
	{
		second();
	}
	catch (double)
	{
		cerr << "first caught int exception" << endl;
	}

	cout << "End first" << endl;
}

int main()
{
	cout << "Start" << endl;

	try
	{
		first();
		//first�Լ����� ���������� error�� ó���߱⿡ ����ؼ� ������.
		cout << "hi" << endl;
	}
	catch (double)
	{
		cerr << "main caught int exception" << endl;
	}
	catch (...)//��� error�� �� �޾� �ְڴ�.
	{
		cerr << "main caught ellipses exception" << endl;
	}

	cout << "End main" << endl;

	return 0;
}