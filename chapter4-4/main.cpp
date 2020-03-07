/*
	auto키워드와 자료형 추론
*/

#include <iostream>

auto add(int x, int y) //매개변수에 auto가 안되는 이유는 template가 있음
{ //정수 + 정수 이기에 반환값도 int라고 컴파일러가 자동으로 매칭해줌
	return x + y;
}

int main()
{
	using namespace std;

	int a = 123; // == 정수 변수 = 정수 , 굳이 자료형을 따로 명시할 필요가 있을까? 해서 나온게 auto타입

	auto b = 123; // 리터럴타입으로 자료형을 정하기에 선언시 초기화 같이 해야함.
	auto c = 1 + 2;
	auto d = 1.5 + 3;

	cout << sizeof(b) << endl; //int
	cout << sizeof(c) << endl; //int
	cout << sizeof(d) << endl; //double

	auto result = add(60, 5);

	cout << result << endl;

	return 0;
}