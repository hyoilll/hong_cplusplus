#pragma once

#include <cassert>
#include <iostream>

template <class T, unsigned int T_SiZE>
class MyArray
{
private:
	T* m_data;

public:
	MyArray()
	{
		m_data = new T[T_SiZE];
	}

	~MyArray()
	{
		reset();
	}

	void reset()
	{
		delete[] m_data;
		m_data = nullptr;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < T_SiZE);
		return m_data[index];
	}

	int getLength()
	{
		return T_SiZE;
	}

	void print()
	{
		for (unsigned int i = 0; i < T_SiZE; ++i)
			std::cout << m_data[i] << " ";
		std::cout << std::endl;
	}
};

#pragma once
