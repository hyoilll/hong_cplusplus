#pragma once

#include <iostream>

class Cents
{
private:
	int m_cents;

public:
	Cents(const int& cents) :m_cents(cents) {}

	bool operator > (const Cents& c)
	{
		return m_cents > c.m_cents;
	}

	friend std::ostream& operator << (std::ostream& out, const Cents& c)
	{
		out << c.m_cents << " Cents";

		return out;
	}
};