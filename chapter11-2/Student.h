#pragma once

//#include <string>
//#include <iostream>
#include "Person.h"

class Student : public Person
{
private:
	//std::string m_name;
	int m_num; //intelligence

public:
	Student(const std::string& name_in, const int& num_in) :Person(name_in), m_num(num_in) {}

	void increaseNum()
	{
		m_num += 1;
	}

	void study()
	{
		std::cout << getName() << " is studing" << std::endl;
	}

	friend std::ostream& operator<<(std::ostream& out, const Student& s)
	{
		out << s.getName() << " " << s.m_num;
		return out;
	}

};