/*
	foreach
*/

#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int fibo[] = { 1,2,3,4,5,6,7,8,9 };
	
	//change array values
	for (auto& number : fibo) //함수 매개변수와 같다고 보면됨
		number *= 10;

	//output
	for (const auto number : fibo)
		cout << number << " ";
	cout << endl;

	//--------------------------------------------------

	int max_number = std::numeric_limits<int>::lowest();

	for (const auto& n : fibo)
		max_number = std::max(max_number, n);

	cout << max_number << endl << endl;

	//-------------------------------------------------

	std::vector<int> fibonacci = { 1,2,3,4,5,6,7,8,9 };

	for (const auto& n : fibonacci)
		max_number = std::max(max_number, n);

	cout << max_number << endl << endl;

	return 0;
}