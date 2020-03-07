/*
	goto
*/

#include <iostream>
#include <cmath> // sqrt()
using namespace std;

int main()
{
	double x;

tryAgain : //label
	cout << "Enter a non-negative number" << endl;
	cin >> x;

	if (x < 0.0)
		goto tryAgain; // -> label로 이동 , 어셈블리 래벨로 가면 goto - 반복문 같음
	
	cout << sqrt(x) << endl;

	//--------------------------------------------------------------------------------------

	/*
		goto skip;

		x = 5; 무조건 goto에 의해 label로 점프하기에 초기화가 될 수 없음.

	skip :

		x = x + 3; 초기화 안 된 변수를 사용하기에 에러
		
	*/


	return 0;
}