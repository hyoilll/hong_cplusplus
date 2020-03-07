#pragma once

#include <iostream>
#include <string>

/*
	using namespace std; �� ������ϴ� ������
	�θ�Ŭ�����̱� ������ �����ع����� ��� �ڽ�Ŭ�������� ������ �Ǿ����;
	�׷��� ���� �����ϰ� �ʹٸ� ����Լ��� ���Ǹ� cpp�� �ű� �� cpp������ �����ϸ��
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