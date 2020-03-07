#include <iostream>
using namespace std;

int Fibonacci(int idx) 
{
	if (idx == 0)
		return 0;
	else if (idx == 1)
		return 1;
	else
		return Fibonacci(idx - 1) + Fibonacci(idx - 2);

}

int main()
{
	
	cout << Fibonacci(6) << endl;

	return 0;
}