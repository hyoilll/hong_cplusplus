/*
	클래스와 const
*/

#include <iostream>
#include <string>
using namespace std;

class Something
{
public:
	int m_value = 0;

	Something(const Something& st_in)
	{
		m_value = st_in.m_value;
		cout << "copy Constructor " << endl;
	}

	Something() { cout << "Constructor " << endl; }

	void setValue(const int& value) { m_value = value; }
	int getValue()const { return m_value; } //const : 멤버함수 안에서 값의 변경은 없다.
};

void print(Something st) // 복사 생성자 호출 => Something st = something;  이렇게 됨
{
	cout << &st << endl;
	cout << st.m_value << endl;
}

/*
	호출하는 인자의 reference로 전달하기에 복사가 일어나지 않음.
	void print(const Something& st)
	{
		cout << &st << endl;
		cout << st.m_value << endl;
	}
*/

class Dosomething
{
public:
	string m_value = "default";

	const string& getValue() const 
	{
		cout << "const version" << endl; 
		return m_value; 
	}
	string& getValue() //이쪽의 const가 overroding의 요소 
	{
		cout << "non-const version" << endl; 
		return m_value; 
	}
};

int main()
{
	const Something something;

	//const로 만들어진 인스턴스 something는 값을 바꿀 수가 없음. 고로 값의 변경이 일어나는 setValue는 error
	//something.setValue(3); error

	cout << something.getValue() << endl;
	//const가 붙은 멤버함수만 허용함
	cout << endl;

	//---------------------------------------------------------------------

	//instance send to reference
	cout << &something << endl;

	print(something);
	cout << endl;

	//--------------------------------------------------------------------

	//const overroding
	Dosomething ds;
	ds.getValue();

	const Dosomething ds2;
	ds2.getValue();

	return 0;
}