#pragma once

#include <iostream>
#include <string>

/*
	using namespace std; 를 선언안하는 이유는
	부모클래스이기 때문에 선언해버리면 모든 자식클래스에도 선언이 되어버림;
	그래서 굳이 선언하고 싶다면 멤버함수의 정의를 cpp로 옮긴 후 cpp내에서 선언하면됨
*/

class Person
{
private:
	std::string m_name;

public:
	Person(const std::string& name_in = "") :m_name(name_in) {}

	void setName(const std::string& name_in)
	{
		m_name = name_in;
	}

	std::string getName()const
	{
		return m_name;
	}

	void doNothing() const
	{
		std::cout << m_name << " is doing nothing" << std::endl;
	}
};