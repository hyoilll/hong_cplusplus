#include <iostream>
using namespace std;

class stack
{
private:
	int cookie;
	int nacho;
	int kancho;
	int chip;

	static int number;

public:
	stack(int a, int b, int c, int d) : cookie(a), nacho(b), kancho(c), chip(d) {}
	static void sum(int a = 0, int b = 0, int c = 0, int d = 0);
	static void show_sum();
	static void printRef() { cout << &number << endl; }
};

int stack::number = 0;

void stack::sum(int a, int b, int c, int d)
{
	number = number + (a + b + c + d);
}

void stack::show_sum()
{
	cout << number << endl;
}

int main()
{
	stack::sum(10, 20, 30, 40);
	stack::show_sum();

	stack::printRef();

	stack::sum(1, 2, 3, 4);
	stack::show_sum();

	stack::printRef();

	return 0;
}
