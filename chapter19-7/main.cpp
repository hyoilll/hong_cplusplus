/*
	�Ϻ��� ���ް� std::forward
	Perfect Forwarding
*/

#include <iostream>
#include <vector>
#include <utility> //std::forward

using namespace std;

struct MyStruct
{};

void func(MyStruct& s)
{
	cout << "Pass by L-ref" << endl;
}

void func(MyStruct&& s)
{
	cout << "Pass by R-ref" << endl;
}

//template�� ���� L,R ������ �Ұ���
template <class T>
void func_wrapper(T&& t)
{
	func(std::forward<T>(t));
	//std::forward : �Ű����� t�� r-value�� �������� r-value�� �ٽ� �������ְ�, l-value�� �������� l-value�� ������
}

int main()
{
	MyStruct s;

	func_wrapper(s);
	func_wrapper(MyStruct());

//	func(s);
//	func(MyStruct());

	return 0;
}