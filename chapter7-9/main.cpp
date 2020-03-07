/*
	함수 포인터

	[참고] https://boycoding.tistory.com/233
*/

#include <iostream>
#include <array>
#include <functional> //c++ 11
using namespace std;

int func(int x)
{
	return 5;
}

int goo()
{
	return 10;
}

bool isEven(const int& number)
{
	if ((number & 0x01) == 0)
		return true;
	else
		return false;
}

bool isOdd(const int& number)
{
	if ((number & 0x01) != 0)
		return true;
	else
		return false;
}

/*
	typedef bool(*check_fcn_t)(const int&); // check_fcn_t
	using check_fcn_t = bool(*)(const int&);
*/
void printNumbers(const array<int, 10>& arr, bool (*check_fcn)(const int&)) //함수 포인터
{
	for (auto value : arr)
	{
		if (check_fcn(value) == true)
			cout << value << "";
	}
	cout << endl;

	return;
}

void printNumbers(const array<int, 10>& arr, std::function<bool(const int&)> check_fcn)  //functional
{
	for (auto value : arr)
	{
		if (check_fcn(value) == true)
			cout << value << "";
	}
	cout << endl;

	return;
}

int main()
{
	cout << func << endl; //함수도 포인터임, 변수처럼 메모리를 차지함
	cout << goo << endl;
	cout << endl;

	int (*fptr)(int) = func;

	cout << fptr(1) << endl;

	int (*ftptr)() = goo;

	cout << ftptr() << endl;
	cout << endl;

	//------------------------------------------------------------

	//함수 포인터
	std::array<int, 10> arr = {0,1,2,3,4,5,6,7,8,9 };

	printNumbers(arr, isEven);
	printNumbers(arr, isOdd);
	cout << endl;

	//------------------------------------------------------------

	//functional
	std::function<bool(const int&)> fcnptr = isEven;

	printNumbers(arr, fcnptr);

	fcnptr = isOdd;

	printNumbers(arr, fcnptr);
	return 0;
}