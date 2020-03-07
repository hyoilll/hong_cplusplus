/*
	순수 가상 함수 = 몸체가 없는 함수
	추상 기본 클래스 = 순수 가상 함수를 포함한 클래스
	인터페이스 클래스 = 순수 가상 함수로만 이루어진 클래스
*/

#include <iostream>

using namespace std;

class Animal
{
protected:
	string m_name;

public:
	Animal(const std::string& name) : m_name(name) {}

public:
	string getName()const { return m_name; }

	virtual void speak()const = 0; //pure virtual function

	/*virtual void speak()const
	{
		cout << m_name << " ???" << endl;
	}*/
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

class Cow : public Animal
{
public:
	Cow(const string& name) :Animal(name) {}

	/*void speak()const override
	{
		cout << m_name << " Moooo" << endl;
	}*/
};

class IErrorLog //interface
{
public:
	virtual bool reportError(const char* errorMessage) const = 0;

	virtual ~IErrorLog() {}
};

class FileErrorLog : public IErrorLog
{
public:
	virtual bool reportError(const char* errorMessage)const override
	{
		cout << "Writing error to a file" << endl;
		return true;
	}
};

class ConsoleErrorLog : public IErrorLog
{
public:
	virtual bool reportError(const char* errorMessage)const override
	{
		cout << "Printing error to a console" << endl;
		return true;
	}
};

void doSomething(const IErrorLog& ie)
{
	ie.reportError("Error");
}

int main()
{
//	Animal a("hi"); error 객체 생성 불가 가상함수 때문에

//	Cow c("hi");// error 자식클래스 cow 부모클래스의 가상함수를 override를 안해줬기때문에

	//-----------------------------------------------------

	FileErrorLog file;
	ConsoleErrorLog console;

	doSomething(file);
	doSomething(console);

	return 0;
}