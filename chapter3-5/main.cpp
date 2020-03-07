/*
	관계 연산자(Relational Operators)
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	//int 끼리의 비교
	int x, y;

	cin >> x >> y;

	cout << "Your input : " << x << " " << y << endl;

	if (x == y)
		cout << "equal" << endl;
	if (x != y)
		cout << "not equal" << endl;
	if (x > y)
		cout << "x is greater than y" << endl;
	if (x < y)
		cout << "x is less than y" << endl;
	if (x >= y)
		cout << "x is greater than y or equal to y" << endl;
	if (x <= y)
		cout << "x is less than or equal to y" << endl;

	cout << endl;
	//float 끼리의 비교

	double d1(100 - 99.99);	//0.01
	double d2(10 - 9.99);	//0.01
	
	cout << d1 << endl;
	cout << d2 << endl;

	if (d1 == d2)
		cout << "equal" << endl;
	else
	{
		cout << "not equal" << endl;

		if (d1 > d2)cout << "d1 > d2" << endl;
		else //if (d1 < d2)
			cout << "d1 < d2" << endl;
	}

	const double epsilon = 1e-10; // epsilon의 결정 범위는 분야에 따라서 달라짐

	if (abs(d1 - d2) < epsilon)
		cout << "Approximately equal" << endl;
	else
		cout << "Not equal" << endl;
	return 0;
}