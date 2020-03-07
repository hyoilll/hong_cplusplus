/*
	포인터와 참조의 멤버 선택
*/

#include <iostream>
using namespace std;

struct Person
{
	int age;
	double weight;
};

int main()
{
	Person person;

	person.age = 10;

	Person& ref = person;
	Person* ptr = &person;

	cout << "ref.age\t\t" << ref.age << " " << &ref.age << endl;
	cout << "ptr->age\t" << ptr->age << " " << &(ptr->age) << endl;
	cout << "(*ptr).age\t" << (*ptr).age << " " << &((*ptr).age) << endl;

	return 0;
}
