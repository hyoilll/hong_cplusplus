/*
	����ü struct (�ʱ�ȭ ���ϸ� int = 0 / string = "")
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
	//���� �ʱ�ȭ�� ���� (�Ŀ� ������ �Ҵ��� ���ϸ� ���� �ʱ�ȭ ���� ���, �ϸ� ���� �Ҵ��� �� ��� = defalut �Ű����� ó��)
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

//�Ű������� ����ȭ
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
	//�ڷḦ ��ġ�� �� ��ǻ�Ͱ� ����ϱ� ���� ���·� ��ġ�ϴµ� 2byte��ġ�� �� ��ٷο��� �̷��� �ǳ���?

	return 0;
}