/*
	cin,,,
*/

#include <iostream>
using namespace std;

int getInt()
{
	while (true)
	{
		cout << "Enter a integer number : ";

		int x;
		cin >> x;

		if (std::cin.fail()) //fail bit 올바르지 않은 입력 값
		{
			std::cin.clear(); //fail bit 초기화
			std::cin.ignore(32767, '\n');//buffer 비우기

			cout << "Invalid number, please try again" << endl;
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return x;
		}
	}
}

bool invalidOperator(char op)
{
	switch (op)
	{
	case '+':
		return true;
	case '-':
		return true;
	case '*':
		return true;
	case '/':
		return true;
	default:
		return false;
	}
}

char getOperator()
{
	char op;

	do
	{
		cout << "Enter an Operator : ";

		op;
		cin >> op;

		std::cin.ignore(32767, '\n');//buffer 비우기

		if (invalidOperator(op) == true)
			break;
	} while (true);

	return op;
}


void printResult(int x, char op, int y)
{
	if (op == '+') cout << x + y << endl;
	else if (op == '-') cout << x - y << endl;
	else cout << "Invalid Operator" << endl;
}

int main()
{
	int x = getInt();
	char op = getOperator();
	int y = getInt();

	printResult(x, op, y);


	return 0;
}