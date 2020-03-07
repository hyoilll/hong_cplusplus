/*
	c 스타일의 문자열 기호적(Symbolic) 상수
*/

#include <iostream>
using namespace std;

const char* getName()
{
	return "java java";
}

int main()
{
	//char* name = "java java"; 
	//error : "java java"는 리터럴 이라서 포인터변수가 바로 가르키지 못함. "java java"를 담을 메모리가 필요함
	
	const char* name1 = getName(); //const를 붙여주면 기호적인 상수처럼 사용가능함.

	const char* name2 = "java java";

	cout << (uintptr_t)name1 << endl;
	cout << (uintptr_t)name2 << endl;
	//"java java"같으니까 그냥 같은 것 가르켜라~
	//문자열이 달라지면 주소도 달라짐.
	cout << endl;

	//------------------------------------------------------------------------

	int i_arr[] = { 1,2,3,4,5 };
	char c_arr[] = "Hello, World!";
	const char* name = "java java";

	cout << i_arr << endl;	//address
	cout << c_arr << endl;	//Hello, World!
	cout << name << endl;	//java java
	//문자열 포인터일 경우 특별하게 처리함. 포인터보다 그냥 문자열이 아닐까? 라고 가정을 함.
	cout << endl;

	//------------------------------------------------------------------------

	char c = 'Q';

	cout << &c << endl; //문자열이라고 생각을 함.
	

	return 0;
}