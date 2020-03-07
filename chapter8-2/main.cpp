/*
	캡슐화, 접근 지정자, 접근 함수

	struct는 기본 public
	class는 기본 private
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct StructDate
{
	int m_month;
	int m_day;
	int m_year;
};

class ClassDate
{
private:
	int m_month;
	int m_day;
	int m_year;

public:
	void setDate(const int& month_input, const int& day_input, const int& year_input)
	{
		m_month = month_input;
		m_day = day_input;
		m_year = year_input;
	}

	int getDay() const
	{
		return m_day;
	}

	void copyFrom(const ClassDate& original)
	{
		//같은 클래스의 다른 인스턴스에 있는 private 멤버 접근가능
		m_month = original.m_month;
		m_day = original.m_day;
		m_year = original.m_year;
	}
};

int main()
{
	StructDate today1{ 8,4,2025 };
	/*
		==
		today.m_month = 8;
		today.m_day = 4;
		today.m_year = 2025;
	*/

	//------------------------------------------------------------------

	ClassDate today2;

	today2.setDate(8, 4, 2025);

	cout << today2.getDay() << endl;

	ClassDate copy;

	copy.copyFrom(today2);

	return 0;
}