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

		if (std::cin.fail()) //fail bit �ùٸ��� ���� �Է� ��
		{
			std::cin.clear(); //fail bit �ʱ�ȭ
			std::cin.ignore(32767, '\n');//buffer ����

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

		std::cin.ignore(32767, '\n');//buffer ����

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