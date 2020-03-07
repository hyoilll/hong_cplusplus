/*
	구조체 struct (초기화 안하면 int = 0 / string = "")
*/

#include <iostream>
#include <string>
using namespace std;

//general function
void printPerson(double height, float weight, int age, string name)
{
	return;
}

//-------------------------------------------------------------------------

struct Person
{//public
	double height = 2.0; 
	//직접 초기화도 가능 (후에 변수값 할당을 안하면 지금 초기화 값을 사용, 하면 새로 할당한 값 사용 = defalut 매개변수 처럼)
	float weight;
	int age;
	string name;
};

struct Family
{
	Person me;
	Person mom;
	Person dad;
};

struct Employee
{
	short id;		// 2bytes
	int age;		// 4bytes
	double wage;	// 8bytes
};

//매개변수의 간략화
void printPerson(Person person)
{
	cout << person.height << " " << person.weight << " " << person.age << " " << person.name << endl;
	return;
}

void printFamilyPerson(Family f)
{
	cout << f.me.height << " " << f.me.weight << " " << f.me.age << " " << f.me.name << endl;
	cout << f.mom.height << " " << f.mom.weight << " " << f.mom.age << " " << f.mom.name << endl;
	cout << f.dad.height << " " << f.dad.weight << " " << f.dad.age << " " << f.dad.name << endl;
	return;
}

Person getMom()
{
	Person mom = { 2.0,100.0,20,"jack jack" };

	return mom;
}

int main()
{
	Person me = { 174, 70, 28, "lee hyo il" }; //uniform initialization
	
	printPerson(me);

	Person mom = getMom();

	Family f = { {me},{mom},{} };

	printFamilyPerson(f);

	Employee emp1; // short 2 + (2 == padding) + int 4 + double 8 = 14bytes?

	cout << sizeof(emp1) << endl; // 16bytes
	//자료를 배치할 때 컴퓨터가 사용하기 편한 상태로 배치하는데 2byte배치가 좀 까다로워서 이렇게 되나봄?

	return 0;
}