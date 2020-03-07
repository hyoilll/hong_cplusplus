/*
	STL Algorithms
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
using namespace std;

int main()
{
	//list<int> vec;
	vector<int> vec;

	for (unsigned int i = 0; i < 10; ++i)
		vec.push_back(i);

	//max - min
	{
		auto itr = min_element(vec.begin(), vec.end());

		cout << *itr << endl; // 0

		itr = max_element(vec.begin(), vec.end());

		cout << *itr << endl; // 9

		cout << endl;
	}

	//find
	{
		auto itr = find(vec.begin(), vec.end(), 3);

		vec.insert(itr, 30); //3의 자리에 30 추가함.

		for (const auto& e : vec)
			cout << e << " ";
		cout << endl;

		cout << endl;
	}

	//sort
	{
		//vector<int> vec = { 1,5,3,0,7,2 };
		list<int> vec = { 1,5,3,0,7,2 };

		for (const auto& e : vec)
			cout << e << " ";
		cout << endl;

		//vector
		//sort(vec.begin(), vec.end());

		//list
		vec.sort();

		for (const auto& e : vec)
			cout << e << " ";
		cout << endl;

		cout << endl;
	}

	//reverse
	{
		//vector
		reverse(vec.begin(), vec.end());

		//list
		//vec.reverse();

		for (const auto& e : vec)
			cout << e << " ";
		cout << endl;
	}

	return 0;
}