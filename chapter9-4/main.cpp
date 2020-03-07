/*
	비교 연산자 오버로딩
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cents
{
private:
	int m_cents;

public:
	Cents(const int& cents = 0) : m_cents(cents) {}

	int& getCents() { return m_cents; }

	friend ostream& operator<<(std::ostream& out, const Cents& c)
	{
		out << c.m_cents;
		return out;
	}

	bool operator==(const Cents& c)
	{
		return (m_cents == c.m_cents) ? true : false;
	}

	//비교를 위해선 < 연산자가 필요함 (>는 필요없음.)
	bool operator<(const Cents& c)
	{
		return m_cents < c.m_cents;
		//return m_cents > c.m_cents;
	}

};

int main()
{
	Cents c1(6);
	Cents c2(6);

	if (c1 == c2)
		cout << "Equls" << endl;
	else
		cout << "Not Equls" << endl;

	//---------------------------------------------------

	vector<Cents> arr(20);

	for (unsigned int i = 0; i < arr.size(); ++i)
		arr[i].getCents() = i;

	std::random_shuffle(begin(arr), end(arr));

	for (const auto& e : arr)
		cout << e << " ";
	cout << endl;

	std::sort(begin(arr), end(arr));

	for (const auto& e : arr)
		cout << e << " ";
	cout << endl;


	return 0;
}