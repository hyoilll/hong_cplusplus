/*
	pointer
	지역변수는 '스택' 메모리를 사용하고,
	동적 할당 메모리는 '힙' 메모리를 사용한다.
	큰 메모리에 저장되어 있는 데이터 중에서 일부분을 cpu가 사용하기 위해서
	메모리로부터 가져올 때는 메모리 전체를 모두 뒤지면서 찾는 것이 아니라, 필요한 데이터가 저장되어 있는
	'주소'에 접근하여 가져온다.
*/

#include <iostream>
#include <typeinfo>
using namespace std;

struct Something
{
	int a, b, c, d;
};

int main()
{
	int x = 5;

	cout << x << endl;
	cout << &x << endl; // & : address of operator
	cout << int(&x) << endl;

	//de-reference operator (*)
	cout << *(&x) << endl; //x메모리 주소의 실제 값이 뭐냐? : *

	//pointer
	int* ptr_x = &x;
	//포인터 변수도 자료형을 갖는 이유는 de-reference를 할 때 어느 자료형으로 가져올 건지 정해줘야 해서

	cout << ptr_x << endl;
	cout << *ptr_x << endl; //int 형으로 선언이 되었기에 int타입으로 가져와라

	double d = 1.0;
	double* ptr_y = &d;

	cout << ptr_y << endl;
	cout << *ptr_y << endl;

	cout << typeid(ptr_x).name() << endl;
	cout << typeid(ptr_y).name() << endl;

	cout << sizeof(ptr_x) << endl;
	cout << sizeof(ptr_y) << endl;
	//pointer 변수는 모두 같은 4bytes => 주소가 전부 4byte기 때문 / x64에서는 주소가 더 길어서 8bytes

	Something ss;
	Something* ptr_s;

	cout << sizeof(Something) << endl;	//16
	cout << sizeof(ptr_s) << endl;		//4



	return 0;
}