/*
	완벽한 전달과 std::forward
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

//template를 쓰면 L,R 구분이 불가함
template <class T>
void func_wrapper(T&& t)
{
	func(std::forward<T>(t));
	//std::forward : 매개변수 t가 r-value로 들어왔으면 r-value로 다시 전달해주고, l-value로 들어왓으면 l-value로 전달함
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