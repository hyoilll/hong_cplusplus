/*
	논리 연산자(Logical Operators), short circuit evaluation
*/

#include <iostream>
using namespace std;

int main()
{
//logical Not
	bool x = true;
	bool y = false;

	cout << !x << endl;

	cout << endl;
	
//AND
	x = true;
	y = false;

	cout << (x && y) << endl;
	
	//ex)

	bool hit = true;
	int health = 10;

	//상저를 입고, 체력이 20 미만이면 죽는다.
	if (hit == true && health < 20)
		cout << "die" << endl;
	else
		health -= 20;

	cout << endl;
	
//OR

	x = true;
	y = false;

	cout << (x || y) << endl;

	//ex)

	int v = 1;

	if (v == 0 || v == 1)
		cout << "v is 0 or 1" << endl;

	cout << endl;

// short circuit evaluation

	int n1 = 1;
	int n2 = 2;

	if (n1 == 1 && n2++ == 2)
	{// => n1 조건판단시 거짓으로 판별됐을 때 &&이기 때문에 뒤 조건을 볼 필요없이 무조건 false가 나오기 때문에 실행안함 
		// do something
	}

	cout << n2 << endl;

	cout << endl;

// De Morgan's Law

	// !(x && y) == !x || !y
	// !(x || y) == !x && !y

//XOR

	// f f f
	// f t t
	// t f t
	// t t f

	x = true;
	y = false;

	cout << (x != y) << endl;
	cout << (x == y) << endl;

	cout << endl;
// OR, AND
	
	bool v1 = true;
	bool v2 = false;
	bool v3 = false;

	bool r1 = v1 || v2 && v3;
	bool r2 = (v1 || v2) && v3;

	cout << r1 << endl;
	cout << r2 << endl;
	// => &&가 ||보다 우선순위가 더 높아서 v1 || (v2 && v3); 이렇게 됨

	return 0;
}