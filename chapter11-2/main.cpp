/*
	»ó¼Ó
*/

#include "Student.h"
#include "Teacher.h"

int main()
{
	Student s("Jack Jack", 0);
	s.setName("hyo il");

	std::cout << s.getName() << std::endl;

	std::cout << s << std::endl;

	Teacher t("Dr. H");
	t.setName("Dr. K");
	
	std::cout << t.getName() << std::endl;

	std::cout << t << std::endl;

	s.doNothing();
	t.doNothing();

	s.study();
	t.teach();

	Person p;
	p.setName("Mr. Incredible");
	p.getName();

	return 0;
}