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
			std::vector<Student> m_s_vec; ���� ����Ǿ� �ֱ⿡

			const Student& s �� �ּҿ� m_s_vec[0]���� push�� �ּҰ� �ٸ� == �ٸ� �ν��Ͻ���� ��, �����ؼ� ����.
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