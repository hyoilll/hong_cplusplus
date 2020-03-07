/*
	직접 만드는 int array
*/
#include <iostream>
#include <initializer_list>
using namespace std;

class IntArray
{
private:
	int m_length = 0;
	int *m_data = nullptr;

public:
	IntArray(const int& length_in) :m_length(length_in)
	{
		m_data = new int[m_length];
	}

	~IntArray()
	{
		delete[] m_data;
	}

	IntArray(const std::initializer_list<int>& list) :IntArray(list.size())
	{
		int cnt = 0;

		for (auto& e : list)
		{
			m_data[cnt] = e;
			++cnt;
		}

	}
	void reset()
	{
		if (m_data != nullptr)
		{
			delete[] m_data;

			m_data = new int[m_length];
		}
	}
	void resize() // size *2
	{
		int* temp = new int[m_length * 2];

		for (unsigned int i = 0; i < m_length; ++i)
			temp[i] = m_data[i];

		m_data = temp;
		m_length *= 2;
	}
	void insertBefore(const int& value, const int& ix)
	{
		if (m_data != nullptr)
		{
			int* temp = new int[m_length + 1];

			for (unsigned int i = 0; i < m_length; ++i)
				temp[i] = m_data[i];

			delete[] m_data;

			m_data = temp;
			m_length += 1;

			for (unsigned int i = m_length - 2; i >= ix; --i)
			{
				m_data[i + 1] = m_data[i];
			}

			m_data[ix] = value;
		}
	}
	void remove(const int& ix)
	{
		if (m_data != nullptr)
		{
			for (unsigned int i = ix + 1; i < m_length; ++i)
			{
				m_data[i - 1] = m_data[i];
			}

			int* temp = new int[m_length - 1];

			m_length -= 1;
			for (unsigned int i = 0; i < m_length; ++i)
			{
				temp[i] = m_data[i];
			}

			delete[] m_data;

			m_data = temp;
		}
	}
	void push_back(const int& value)
	{
		int* temp = new int[m_length + 1];

		for (unsigned int i = 0; i < m_length + 1; ++i)
			temp[i] = m_data[i];

		temp[m_length] = value;

		delete[] m_data;

		m_data = temp;
		m_length += 1;

	}

	friend ostream& operator<<(std::ostream& out, const IntArray& arr)
	{
		for (unsigned int i = 0; i < arr.m_length; ++i)
			out << arr.m_data[i] << " ";
		return out;
	}
};




int main()
{
	IntArray my_arr{ 1,3,5,7,9 };//1 3 5 7 9 0
	cout << my_arr << endl;

	my_arr.insertBefore(10, 1); //1, 10, 3, 5, 7, 9
	cout << my_arr << endl;

	my_arr.remove(3);			//1, 10, 3, 7, 9
	cout << my_arr << endl;
	
	my_arr.remove(3);			//1, 10, 3, 9
	cout << my_arr << endl;

	my_arr.push_back(13);		//1, 10, 3, 7, 9, 13
	cout << my_arr << endl;

	return 0;
}