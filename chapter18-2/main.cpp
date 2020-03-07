/*
	ostream으로 출력하기
*/

#include <iostream>
#include <iomanip>

using namespace std;



int main()
{
	//{
	//	//+기호 삽입
	//	cout.setf(std::ios::showpos);

	//	cout << 108 << endl;

	//	//기호 제거
	//	cout.unsetf(std::ios::showpos);

	//	cout << 108 << endl;
	//}

	//{
	//	cout.setf(std::ios::uppercase);// 대문자 표현

	//	//1. 16진수로 표현 (기존 10진수 표현을 꺼주고 16진수 적용)
	//	cout.unsetf(std::ios::dec);

	//	cout.setf(std::ios::hex);

	//	cout << 108 << endl;

	//	//2. 두번째 방법
	//	//cout << std::hex;
	//	//cout << std::hex << std::uppercase; #include <iomanip>

	//	//1. 10진수 적용
	//	cout.setf(std::ios::dec);

	//	//2. 두번째 방법
	//	cout << std::dec;

	//	cout << 10 << endl;
	//}

	/*{
		cout << std::boolalpha;

		cout << true << " " << false << endl;
	}*/

	{
		//cout << std::defaultfloat;

		//유효숫자
		cout << std::setprecision(3) << 123.456 << endl;
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
		cout << endl;

		//소수점 표시
		cout << std::showpoint;
		cout << std::setprecision(3) << 123.456 << endl;
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
		cout << endl;

		//소수점 이하 표시자리
		cout << std::fixed;
		cout << std::setprecision(3) << 123.456 << endl;
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
		cout << endl;

		cout << std::scientific;
		cout << std::setprecision(3) << 123.456 << endl;
		cout << std::setprecision(4) << 123.456 << endl;
		cout << std::setprecision(5) << 123.456 << endl;
		cout << std::setprecision(6) << 123.456 << endl;
		cout << std::setprecision(7) << 123.456 << endl;
		cout.unsetf(std::ios::scientific);
		cout << endl;
	}

	{
		cout << -12345 << endl;
		cout.fill('*');
		cout << std::setw(10) << -12345 << endl; // 10자리를 채워라
		cout << std::setw(10) << std::left << -12345 << endl;
		cout << std::setw(10) << std::right << -12345 << endl;
		cout << std::setw(10) << std::internal << -12345 << endl;
		
	}
	return 0;
}