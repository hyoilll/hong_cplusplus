#pragma once

#include <iostream>
#include <string>

class Teacher
{
private:
	std::string m_name;

public:
	Teacher(const std::string& name_in = "No name") :m_name(name_in) {}

	void set(const Teacher* const t)
	{
		set(t->m_name);
	}

	void set(const std::string& name_in)
	{
		m_name = name_in;
	}

	friend std::ostream& operator<<(std::ostream& out, const Teacher& t)
	{
		out << t.m_name;
		return out;
	}

};