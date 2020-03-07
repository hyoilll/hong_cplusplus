#pragma once

#include <iostream>

class Calc
{
private:
	int m_value;

public:
	Calc(int init_value);

	Calc& add(const int& value);
	Calc& sub(const int& value);
	Calc& mul(const int& value);

	void print();
};

