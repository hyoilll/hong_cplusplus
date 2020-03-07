/*
	집합관계
*/

#include <iostream>
#include "Lecture.h"

using namespace std;

int main()
{
	//구성관계
	/*Lecture lec1("english class");
	lec1.assignTeacher(Teacher("lee hyo il"));
	lec1.registerStudent(Student("Jack Jack", 0));
	lec1.registerStudent(Student("john", 1));
	lec1.registerStudent(Student("smith", 2));

	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(Teacher("Prof. Good"));
	lec2.registerStudent(Student("Jack Jack", 0));*/

	//집합관계
	Student s1("Jack Jack", 0);
	Student s2("john", 1);
	Student s3("smith", 2);

	Teacher t1("lee hyo il");
	Teacher t2("Prof. Good");

	Lecture lec1("english class");
	lec1.assignTeacher(&t1);
	lec1.registerStudent(&s1);
	lec1.registerStudent(&s2);
	lec1.registerStudent(&s3);

	Lecture lec2("Computational Thinking");
	lec2.assignTeacher(&t2);
	lec2.registerStudent(&s1);

	{
		cout << lec1 << endl;
		cout << lec2 << endl;

		//event
		lec2.study();

		cout << lec1 << endl;
		cout << lec2 << endl;
	}

	return 0;
}