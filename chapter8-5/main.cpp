/*
	위임 생성자

	[참조] http://www.qaupot.com/wordpress/?p=2385
*/

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
	int m_id;
	string m_name;

public:
	Student(const int& id_in, const string& name_in) :m_id(id_in), m_name(name_in) {}

	//Student(const string& name_in) :m_id(0), m_name(name_in) {} 
	//좋지 않은 방법 멤버변수의 초기화를 여러 생성자에서 하는건 좋지 않음

	//위의 문제점을 보완하고자 나온 것이 위임생성자
	Student(const string& name_in) : Student(0, name_in) {}

	void print()
	{
		cout << m_id << " " << m_name << endl;
	}
};

int main()
{
	Student st1(0, "Jack Jack");
	st1.print();

	Student st2("Dash");
	st2.print();

	return 0;
}