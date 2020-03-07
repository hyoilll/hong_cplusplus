#pragma once

#include "Student.h"
#include "Teacher.h"
#include <vector>

class Lecture
{
private:
	std::string m_sub_name;
	Teacher m_t_name;
	
	std::vector<Student*> m_s_vec;
	
public:
	Lecture(const std::string& sub_name_in) :m_sub_name(sub_name_in) {}

	void assignTeacher(const Teacher* const t)
	{
		m_t_name.set(t);
	}

	void registerStudent(Student* const s)
	{
		m_s_vec.push_back(s);
		/*
			std::vector<Student> m_s_vec; 으로 선언되어 있기에

			const Student& s 의 주소와 m_s_vec[0]으로 push된 주소가 다름 == 다른 인스턴스라는 것, 복사해서 넣음.
		*/
	}

	void study()
	{
		for (auto& e : m_s_vec)
			e->increaseNum();
	}

	friend std::ostream& operator<<(std::ostream& out, const Lecture& l)
	{
		out << l.m_sub_name << std::endl << l.m_t_name << std::endl;
		for (const auto& e : l.m_s_vec)
			out << *e << " ";
		out << std::endl;
		return out;
	}
};