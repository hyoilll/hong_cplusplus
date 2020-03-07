/*
	부동소수점
	type			최소크기	일반적인크기
	float				4			4
	double				8			8
	long double			8		 8,12,16
*/

#include <iostream>
#include <limits>
#include <iomanip>
#include <cmath>

int main()
{
	using namespace std;

	float f(3.141592f);
	double d(3.141592);
	long double ld(3.141592);

	cout << 31.4e-2 << endl;
	cout << 31.4e-1 << endl; // 31.4 * 10^-1
	cout << 3.14 << endl;
	cout << 31.4e1 << endl;
	cout << 31.4e2 << endl;

	//-------------------------------------------
	
	cout << setprecision(16) << endl; //#include <iomanip> 소수자리 지정
	cout << 1.0 / 3.0 << endl;

	f = (123456789.0f); // 10개의 유효숫자

	cout << setprecision(9);
	cout << f << endl;
	cout << setprecision(8);
	cout << f << endl;
	cout << setprecision(7);
	cout << f << endl;
	cout << setprecision(6);
	cout << f << endl;

	//-------------------------------------------
	cout << endl;
	double d1(1.0);
	double d2(0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);

	cout << d1 << endl;
	cout << d2 << endl;

	cout << setprecision(17);

	cout << d1 << endl;
	cout << d2 << endl;

	//----------------------------------------------
	cout << endl;

	double zero = 0.0;
	double posinf = 5.0 / zero;
	double neginf = -5.0 / zero;
	double nan = zero / zero;

	//isinf = isInfinity
	//isnan = isNan

	cout << posinf <<  " " << isinf(posinf) << endl;
	cout << neginf << " " << isinf(neginf) << endl;
	cout << nan << " " << isnan(nan) << endl;
	cout << 1.0 << " " << isnan(1.0) << endl;

	return 0;
}