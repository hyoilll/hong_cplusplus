/*
	ÇÔ¼öÆ÷ÀÎÅÍ ÀÌ¿ëÇÑ µ¡¼À, »¬¼À, °ö¼À, ³ª´°¼À

	function pointer vs functional
	https://cafe.naver.com/cafec/330568
*/

#include <iostream>
#include <functional>
using namespace std;

int add(int a, int b)
{
	return a + b;
}

int sub(int a, int b)
{
	return a - b;
}

int mul(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return static_cast<double>(a) / b;
}

int main()
{
	cout << "num1 : ";
	int num1 = 0;
	cin >> num1;

	cout << "operater : ";
	char c = ' ';
	cin >> c;

	cout << "num2 : ";
	int num2 = 0;
	cin >> num2;

	/*
		typedef int(*Fcnptr)(int, int);
		Fcnptr fcnptr = nullptr;
	*/
	int (*fcnptr)(int, int) = nullptr;					//function pointer

	//std::function<int(int, int)> fcnptr = nullptr;	//fucntional
	
	switch (c)
	{
	case '+':
		fcnptr = add;
		cout << fcnptr(num1, num2) << endl;
		break;
	case '-':
		fcnptr = sub;
		cout << fcnptr(num1, num2) << endl;
		break;
	case '*':
		fcnptr = mul;
		cout << fcnptr(num1, num2) << endl;
		break;
	case '/':
		fcnptr = divide;
		cout << fcnptr(num1, num2) << endl;
		break;
	default:
		break;
	}


	return 0;
}