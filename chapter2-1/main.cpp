/*
	기본 자료형 소개
	초기화 방식
*/
#include <iostream>

int main()
{
	using namespace std;

	bool bValue = false;
	char chValue = 65;
	float fValue = 3.141592f; // f를 붙이는 이유는 소수점 리터럴은 double타입으로 
							  // 정해지기 때문에 f를 빼면 double > float 이런 식으로 되기에 경고
	double dValue = 3.141592;

	cout << fValue << endl;
	cout << dValue << endl;

	auto aValue = "hiqweqwewqeqe";

	cout << sizeof(aValue) << endl;
	cout << sizeof(char*) << endl;

	int a = (int)3.1415;	// copy initialization
	int b((int)3.14);		// direct initialization
	int c{ 3 };				// uniform initialization

	cout << a << " " << b << " " << c << endl;


	return 0;

}