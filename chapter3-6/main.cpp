/*
	�� ������(Logical Operators), short circuit evaluation
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

	//������ �԰�, ü���� 20 �̸��̸� �״´�.
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
	{// => n1 �����Ǵܽ� �������� �Ǻ����� �� &&�̱� ������ �� ������ �� �ʿ���� ������ false�� ������ ������ ������� 
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
	// => &&�� ||���� �켱������ �� ���Ƽ� v1 || (v2 && v3); �̷��� ��

	return 0;
}