#pragma once

#include <string>
#include <iostream>

class Student
{
private:
	std::string m_name;
	int m_num; //intelligence

public:
	Student(const std::string& name_in, const int& num_in) :m_name(name_in), m_num(num_in) {}

	void increaseNum()
	{
		m_num += 1;
	}

	friend std::ostream& operator<<(std::ostream& out, const Student& s)
	{
		out << s.m_name << " " << s.m_num;
		return out;
	}

};