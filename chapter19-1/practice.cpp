#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <class T >
void fill(vector<int>& v, T done)
{
	int i = 0;

	while (done() == false)
	{
		v.push_back(i++);
	}
}

int main()
{
	vector<int> v;

	fill(v, [&]() -> bool 
		{
			int sum = 0;
			for_each(v.begin(), v.end(), [&](const int& i) {sum += i; });
			return (sum > 9) ? true : false; 
		});

	for_each(v.begin(), v.end(), [](const int& i) {cout << i << endl; });

	return 0;
}