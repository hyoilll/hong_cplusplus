#pragma once

#include <string>
#include "Position.h"

class Monster
{
private:
	std::string m_name;
	Position m_location;

public:
	Monster(const std::string& name_in, const Position& p) :m_name(name_in), m_location(p) {}

	void moveTo(const Position& p)
	{
		m_location.set(p);
	}

	friend std::ostream& operator<<(std::ostream& out, const Monster& m);

}; 
std::ostream& operator<<(std::ostream& out, const Monster& m)
{
	out << m.m_name << " " << m.m_location;
	return out;
}