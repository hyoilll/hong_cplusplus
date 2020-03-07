/*
	형변환 Type conversion
	명시적 vs 묵시적
*/

#include <iostream>
#include <typeinfo>
#include <iomanip>
using namespace std;

int main()
{
	auto a = 123.0;
	cout << typeid(a).name() << endl; // 자료형 출력

	//numeric promotion
	float f = 1.0f;
	double d = f; 
	// double이 float보다 크기가 크기 때문에 문제없음

	//numeric conversion 변환
	int i = 30000;
	char c = i;
	cout << static_cast<int>(c) << endl; //명시적 형변환
	// char(-128 ~ 127)가 int보다 크기가 작기 때문에 int의 값을 그대로 넣을 수가 없음. 값이 손실됨

	d = 0.123456789123456789;
	f = d;

	cout << std::setprecision(20);
	cout << f << endl; //0.12345679104328155518
	cout << d << endl; //0.1234567891234567838
	// 정밀도가 float가 더 적기 때문에 손실됨(유효숫자)

	//unsigned
	cout << 5u - 10u << endl; //underflow

	//int < unsigned int < long < unsigned long < long long < unsigned long long < float < double < long double

	i = 4.0; //묵시적 변환
	i = (int)4.0; //c style
	i = int(4.0); //c++
	i = static_cast<int>(4.0); //최근
	// => 기능상의 차이는 거의 없음

	return 0;
}