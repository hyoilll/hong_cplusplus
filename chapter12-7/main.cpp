/*
	���� ���� �Լ� = ��ü�� ���� �Լ�
	�߻� �⺻ Ŭ���� = ���� ���� �Լ��� ������ Ŭ����
	�������̽� Ŭ���� = ���� ���� �Լ��θ� �̷���� Ŭ����
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
//	Animal a("hi"); error ��ü ���� �Ұ� �����Լ� ������

//	Cow c("hi");// error �ڽ�Ŭ���� cow �θ�Ŭ������ �����Լ��� override�� ������⶧����

	//-----------------------------------------------------

	FileErrorLog file;
	ConsoleErrorLog console;

	doSomething(file);
	doSomething(console);

	return 0;
}