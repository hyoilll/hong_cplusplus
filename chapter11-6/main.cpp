/*
	������ Ŭ������ ���ο� ��� �߰��ϱ�
*/

#include <iostream>

using namespace std;

class Base
{
protected:
	int m_protected;
	
private:
	int m_private;

public:
	Base(int value) : m_protected(value) {}

	void setValue(const int& value)
	{
		m_private = value;
	}
};

class Derived : public Base
{
public:
	Derived(int value) :Base(value)
	{

	}

	void setValue(int value)
	{
		Base::m_protected = value;	//ù ��° ���  protected ����
		Base::setValue(value);		//�� ��° ���	public �Լ�
	}
};

int main()
{


	return 0;
}