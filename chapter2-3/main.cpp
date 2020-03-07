/*
	고정 너비 정수 c++ 11 <cstdint>
	최소 사이즈를 정의하고 있기에 운영체제에 따라 사이즈가 다를 수가 있다. 
	그 불확실성을 해결하기 위한 똑같은 사이즈를 사용하는 '고정 너비 정수'가 나옴
*/
#include <iostream>

int main()
{
	using namespace std;

	std::int16_t i(5); //16bit를 할당하겠다. = short
	std::int8_t myint = 65; //8bit로 할당한다. = char

	cout << myint << endl; //A

	cout << sizeof(i) << endl; //2bytes
	cout << sizeof(myint) << endl; //1bytes

	std::int_fast8_t fi(5); //int 8bit 중에서 가장 빠른 데이터 타입으로 할당
	std::int_least64_t fl(5); //적어도 64bit로 할당

	cout << sizeof(fi) << endl; //1bytes
	cout << sizeof(fl) << endl; //8bytes

	return 0;
}