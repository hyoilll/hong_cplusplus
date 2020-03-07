/*
	참조 변수
*/

#include <iostream>
using namespace std;

void douSomething(int &n) //const int& n 
{
	n = 10;

	cout << "In doSomething " << n << endl;
	cout << &n << endl;
}

struct Something
{
	int v1;
	float v2;
};

struct Other
{
	Something st;
};

int main()
{
	int value = 5;

	int& ref = value; //value의 또 다른 이름

	int* ptr = &value;

	ref = 10;

	cout << ref << " " << value << endl;

	cout << &value << endl;	//0xA
	cout << &ref << endl;	//0xA
	cout << ptr << endl;	//0xA
	cout << &ptr << endl << endl;	//0xB
	
	//------------------------------------------------------------------

	//선언과 동시에 초기화되어야함.
	//리터럴 상수를 참조할 수 없음.

	/*
		const int y = 8;
		int& c_ref = y;
		
		=> error, const가 아닌 참조변수로 const변수를 변경할 수 있기에 error발생. 

		const int y = 8;
		const int& c_ref = y;

		=> error 해결
	*/

	//-----------------------------------------------------------------

	int value1 = 5;
	int value2 = 10;

	int& ref1 = value1;

	cout << ref1 << endl;

	ref1 = value2;
	//재참조 가능

	cout << ref1 << endl << endl;

	//----------------------------------------------------------------

	int n = 5;

	cout << n << endl;

	cout << &n << endl;

	douSomething(n);
	//pointer를 이용한 call-by-reference는 받는 함수의 포인터매개변수에 주소를 복사하기에 복사의 비용이 듦.
	//reference를 이용한 call-by-reference는 주소조차 복사할 필요가 없기에, 성능면에서도 더 좋음

	cout << n << endl << endl;

	//----------------------------------------------------------------

	Other ot;

	int& v1 = ot.st.v1;
	//간결화

	v1 = 1.0;

	//---------------------------------------------------------------

	value = 5;
	int* const ptr = &value;
	int& qwe = value;

	*ptr = 10;
	ref = 10;
	//같은 구문

	return 0;
}