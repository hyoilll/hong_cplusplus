/*
	예외처리와 스택 되감기(stack Unwinding)

	차이점 한번 찾아보기
	std::cout
	std::cerr
	std::clog
*/

#include <iostream>
using namespace std;

//void last() throw(int) int형의 error가 발생 할 수 있다.
//void last() throw(...) random형의 error가 발생 할 수있다.
//void last() throw() 어떠한 error도 발생하지 않아요.

void last() throw(int) //int형의 error가 발생 할 수 있다.
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
		//first함수에서 정상적으로 error를 처리했기에 계속해서 실행함.
		cout << "hi" << endl;
	}
	catch (double)
	{
		cerr << "main caught int exception" << endl;
	}
	catch (...)//모든 error를 다 받아 주겠다.
	{
		cerr << "main caught ellipses exception" << endl;
	}

	cout << "End main" << endl;

	return 0;
}