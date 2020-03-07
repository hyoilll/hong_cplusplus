/*
	다형성의 기본개념
*/

#include <iostream>
#include <string>
using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(const std::string& name) : m_name(name) {}

public:
	string getName()const { return m_name; }

	virtual void speak()const
	{
		cout << m_name << " ???" << endl;
	}
};

class Cat : public Animal
{
public:
	Cat(const string& name) :Animal(name) {}

	void speak()const
	{
		cout << m_name << " Meow" << endl;
	}
};

class Dog : public Animal
{
public:
	Dog(const string& name) :Animal(name) {}

	void speak()const
	{
		cout << m_name << " Woof" << endl;
	}
};

int main()
{
	Animal a("my animal");
	Cat c("my cat");
	Dog d("my dog");

	a.speak();
	c.speak();
	d.speak();

	Animal* ptr_animal1 = &c;
	Animal* ptr_anumal2 = &d;

	ptr_animal1->speak();
	ptr_anumal2->speak();



	return 0;
}