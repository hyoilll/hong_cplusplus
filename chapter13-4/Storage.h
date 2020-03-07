#pragma once


#include <iostream>

template <class T>
class Storage
{
private:
	T m_value;

public:
	Storage(T value) :m_value(value) {}

	void print()const
	{
		std::cout << m_value << std::endl;
	}
};

template<>
void Storage<double>::print()const
{
	std::cout << "Double Type" << " ";
	std::cout << std::scientific << m_value << std::endl;
}