/*
	overrride = override의도로 함수를 만들었지만 실수로 인한 것을 컴파일러가 잡아주게 하는 키워드
	final = 이 함수를 override하지 말아라라는 키워드
	공변 반환값
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
		c가 나오는 이유 : ptr_c는 C타입 포인터변수이기에 ptr_c->getThis()를 통해 나온 인스턴스 d임에도 
		C타입이므로 c의 put()이 실행됨.
	*/
	cout << endl;
	//-----------------------

	const A& ta = B();

	ta.print();

	const A& tta = ta;

	tta.print();

	return 0;
}