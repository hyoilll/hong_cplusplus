/*
	오른쪽-값 참조
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
		x - 메모리 주소를 갖고 있는 놈

		r-value
		5 - 메모리주소를 갖고 있지 않아, 해당 문장이 끝나면 사라질 운명
	*/

	int y = getResult();

	const int cx = 6;
	const int cy = getResult();
	
	// l-value references

	int& lr1 = x;		// Modifiable l-vaules
	//int &lr2 = cx;	//non-modifiable l-values const 변수라 참조 불가
	//int &lr3 = 5;		//r-values 참조변수는 다른 메모리공간에 대한 참조 값인데 메모리공간을 갖고 있지 않음.

	const int& lr4 = x;		//Modifialbe l-values
	const int& lr5 = cx;	//non-modifiable l-values
	const int& lr6 = 5;		//r-values

	//r-value references

	//int&& rr1 = x;	l-value 참조하므로 error
	//int&& rr2 = cx;	l-value 참조하므로 error
	int&& rr3 = 5;
	/*
		r-value참조의 의미는 r-value참조와 반대로 곧 사라질 리터럴상수에 대해서 참조가 가능하다.
		이 의미는 바로 사라져도 다른 곳에 영향을 주지 않기에 스마트포인터에서의 소유권문제가 발생하지 않는다.
	*/

	//const int&& rr4 = x;	l-value 참조하므로 error
	//const int&& rr5 = cx; l-value 참조하므로 error
	const int&& rr6 = 5;

	// L/R - value reference parameters
	doSomething(x);
	doSomething(cx);
	doSomething(5);
	doSomething(getResult());


	return 0;
}