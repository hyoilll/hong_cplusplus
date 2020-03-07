/*
	이니셜라이저 리스트
	std::initializer_list

	[참조] https://blog.naver.com/cutup9999/221302969913
*/

#include <iostream>
#include <cassert>
#include <initializer_list>
using namespace std;

class IntArray
{
private:
	unsigned int m_length = 0;
	int* m_data = nullptr;

public:
	IntArray(const unsigned int& length) :m_length(length)
	{
		m_data = new int[m_length];
	}

	IntArray(const std::initializer_list<int>& list) :IntArray(list.size())
	{
		int count = 0;
		for (const auto& e : list)
		{
			m_data[count] = e;
			++count;
		}

		/*
			for (unsigned int count = 0; count < list.size(); ++count)
				m_data[count] = list[count]

			: error 발생 initializer_list는 []를 제공하지 않음.
		*/
	}

	IntArray& operator = (const IntArray& arr)
	{
		if (this == &arr)
			return *this;

		if (m_data != nullptr)
			delete[] m_data;
		
		m_length = arr.m_length;

		m_data = new int[m_length];

		for (unsigned int i = 0; i < m_length; ++i)
			m_data[i] = arr.m_data[i];

		return *this;
	}

	~IntArray()
	{
		delete[] m_data;
	}

	int getLength()const { return m_length; }

	friend ostream& operator << (ostream& out, const IntArray& arr)
	{
		for (unsigned int i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << " ";
		out << endl;

		return out;
	}

};

int main()
{
	int my_arr1[5] = { 1,2,3,4,5 };
	int* my_arr2 = new int[5]{ 1,2,3,4,5 };

	auto il = { 10,20,30 };

	IntArray int_arr{ 1,2,3,4,5 };
	
	cout << int_arr << endl;

	IntArray int_arr2{ 2,4,6,8,10 };

	int_arr = int_arr2;

	cout << int_arr << endl;
	return 0;
}