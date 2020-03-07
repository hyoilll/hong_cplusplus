/*
	STL Iterators
*/

#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <map>
using namespace std;



int main()
{
	{
		vector<int> container;

		for (unsigned int i = 0; i < 10; ++i)
			container.push_back(i);

		//해당 vector<int>를 가르킬 수 있는 Iterator를 생성
		vector<int>::const_iterator itr;

		//container.begin()의 반환값은 iterator
		itr = container.begin();

		while (itr != container.end())
		{
			cout << *itr << " ";

			++itr;
		}
		cout << endl;

		/* ==
			for (auto itr = container.begin(); itr != container.end(); ++itr)
				cout << *itr << " ";
			cout << endl;
		*/
	}

	{
		list<int> container;

		for (unsigned int i = 0; i < 10; ++i)
			container.push_back(i);

		auto itr = container.begin();

		while (itr != container.end())
		{
			cout << *itr << " ";

			++itr;
		}
		cout << endl;
	}

	{
		set<int> container;

		for (unsigned int i = 0; i < 10; ++i)
			container.insert(i);

		auto itr = container.begin();

		while (itr != container.end())
		{
			cout << *itr << " ";

			++itr;
		}
		cout << endl;
	}

	{
		map<int, char> container;

		for (unsigned int i = 0; i < 10; ++i)
			container.insert(std::pair<int, char>(i, (65 + i)));

		auto itr = container.begin();

		while (itr != container.end())
		{
			cout << itr->first << " " << itr->second << " ";

			++itr;
		}
		cout << endl;
	}
	return 0;
}