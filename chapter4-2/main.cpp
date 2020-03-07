/*
	전역 변수, 정적 변수, 내부 연결, 외부 연결

	int g_x; external linkage	다른 cpp파일에서 접근 가능
	static int g_x; internal linkage	다른 cpp파일에서 접근 불가
	const int g_x; x

	extern int g_z;
	extern const int g_z; o
	
	int g_y(1);
	static int g_y(1);
	const int g_y(1);

	extern int g_w(1); 
	extern const int g_w(1);
*/

#include <iostream>
#include "MyConstant.h"

using namespace std;

int value = 123; //전역변수 해당 파일에서만 쓰는 전역변수

static int g_a = 1; // 다른 cpp파일에선 사용할 수 없는 정적전역변수

extern int z = 9; // 다른 cpp파일에서도 사용할 수 있는 전역변수

extern void print(); //forward declaration 어딘가에 print함수의 몸체가 존재하니 컴파일시 적용해라


void doSomething()
{
	static int a = 1;

	++a;

	cout << a << endl;
}

int main()
{
	

	//전역 변수
	cout << value << endl; // 123
	
	int value = 1;

	cout << value << endl; // 1
	cout << ::value << endl; // 123

	cout << endl;
	//-----------------------------------

	//정적 변수 static
	doSomething();
	doSomething();

	/*
		static 맨 처음 초기화는 한번만 함. 메모리 유지
		static vs global
		1. static은 지역변수처럼 해당 스코프 내에서만 접근이 가능
		2. 전역변수처럼 프로그램이 종료 될때까지 값이 소멸되지 않음.
	*/

	print();
	cout << z << endl;

	cout << "main.cpp " << Constants::pi << " " << &Constants::pi << endl;

	return 0;
}