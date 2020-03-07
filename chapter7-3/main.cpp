/*
	참조에 의한 전달 call by refernce
*/

#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void addOne(int& y)
{
	y = y + 1;

	cout << "In func " << y << " " << &y << endl;

	return;
}

void getSinCos(const double& degree, double& sin_out, double& cos_out)
{
	static const double pi = 3.141592 / 180.0;

	const double radians = degree * pi;

	sin_out = std::sin(radians);
	cos_out = std::cos(radians);

	return;
}

void foo(const int& x)
{
	cout << x << endl;
}

/*
	typedef int* pint;
	void foo(pint& ptr)
*/
void foo(int*& ptr) //(int*) &ptr
{
	cout << ptr << " " << &ptr << endl;
}

void printElement(const int (&arr)[4])
{
	return;
}

void printVector(const vector<int>& vect)
{
	return;
}

int main()
{
	int x = 5;

	cout << "In main " << x << " " << &x << endl;
	
	addOne(x);

	cout << "In main " << x << " " << &x << endl << endl;

	//----------------------------------------------------------

	double sin(0.0);
	double cos(0.0);

	cout << sin << " " << cos << endl;

	getSinCos(30.0, sin, cos);

	cout << sin << " " << cos << endl << endl;

	//---------------------------------------------------------
	
	/*
		foo(6); - void foo(int& x) : error -> void foo(const int& x) : 기호적(symbolic) 상수로 취급
	*/

	//---------------------------------------------------------
	
	//pointer를 reference로 넘기기
	int x = 5;
	int* ptr = &x;

	cout << ptr << " " << &ptr << endl;

	foo(ptr);
	cout << endl;

	//---------------------------------------------------------
	
	//arr넘기기
	int arr[]{ 1,2,3,4 };

	printElement(arr);

	vector<int> vect{ 1,2,3,4 };

	printVector(vect);

	return 0;
}