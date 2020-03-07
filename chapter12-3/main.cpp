/*
	overrride = override�ǵ��� �Լ��� ��������� �Ǽ��� ���� ���� �����Ϸ��� ����ְ� �ϴ� Ű����
	final = �� �Լ��� override���� ���ƶ��� Ű����
	���� ��ȯ��
*/

#include <iostream>

using namespace std;

class A
{
public:
	virtual void print()const { cout << "A" << endl; }
};

class B : public A
{
public:
	virtual void print()const override final { cout << "B" << endl; }
};

class C : public B
{
public:
	//void print()const override { cout << "C" << endl; } error - final

	void put()const { cout << "C" << endl; }
	virtual C* getThis() 
	{
		cout << "C::getThis()" << endl;
		return this; 
	}
};

class D : public C
{
public:
	//void print()const override { cout << "D" << endl; } error - final
	
	void put()const { cout << "D" << endl; }
	virtual D* getThis() override 
	{
		cout << "D::getThis()" << endl; 
		return this; 
	}
};

int main()
{
	A a;
	B b;
	C c;
	D d;

	C* ptr_c = &d;

	cout << &d << endl;
	cout << (ptr_c->getThis()) << endl;

	ptr_c->getThis()->put();
	/*
		c�� ������ ���� : ptr_c�� CŸ�� �����ͺ����̱⿡ ptr_c->getThis()�� ���� ���� �ν��Ͻ� d�ӿ��� 
		CŸ���̹Ƿ� c�� put()�� �����.
	*/
	cout << endl;
	//-----------------------

	const A& ta = B();

	ta.print();

	const A& tta = ta;

	tta.print();

	return 0;
}