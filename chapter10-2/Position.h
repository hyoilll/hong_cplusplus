#pragma once

#include <iostream>

class Position
{
private:
	int m_x;
	int m_y;

public:
	Position(const int& m_in, const int& y_in) :m_x(m_in), m_y(y_in) {}

	void set(const Position& p)
	{
		set(p.m_x, p.m_y);
	}

	void set(const int& x_target, const int& y_target)
	{
		m_x = x_target;
		m_y = y_target;
	}

	friend std::ostream& operator<<(std::ostream& out, const Position& p)
	{
		out << p.m_x << " " << p.m_y;
		return out;
	}
};