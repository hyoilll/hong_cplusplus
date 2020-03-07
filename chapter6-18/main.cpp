/*
	void pointer, generic pointer
*/

#include <iostream>
using namespace std;

int main()
{
	int i = 5;
	float f = 3.0f;
	char c = 'a';

	void* ptr = nullptr;

	ptr = &i;
	ptr = &f;
	ptr = &c;

	/*
		cout << ptr + 1 << endl;

		=> error, +1해서 다음 byte의 공간에 접근하지 못함, 자료형이 void이기 때문에 몇 byte인지 모름.

		cout << *ptr << endl;

		=> error, void이기 때문에 이대로는 값에 접근할 수 없음.
	*/

	cout << *static_cast<float*>(ptr) << endl;

	return 0;
}