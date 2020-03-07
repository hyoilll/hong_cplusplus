/*
	�͸� ��ü
*/

#include <iostream>
using namespace std;

class A
{
public:
	int m_value;

public:
	A()
	{
		cout << "Constructor" << endl;
		cout << this << endl;
	}
	~A()
	{
		cout << "Destructor" << endl;
	}
	void print()
	{
		cout << "Hello" << endl;
	}
};

class Cents
{
private:
	int m_cents;

public:
	Cents(int cents) { m_cents = cents; }

	int getCents()const { return m_cents; }
};

Cents add(const Cents& c1, const Cents& c2)
{
	return Cents(c1.getCents() + c2.getCents());
}

int main()
{
	/*A a;

	a.print();

	//�ν��Ͻ��� ������ �ʰ� ȣ�� = ���� �Ұ�
	A().print();
	A().print();
	//������ �Ҹ��� �� ���ٿ��� �� �Ͼ
	cout << endl;*/

	//------------------------------------------------------------

	cout << add(Cents(4), Cents(2)).getCents() << endl;
	cout << int(4) + int(2) << endl;

	return 0;
}