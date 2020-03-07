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

		=> error, +1�ؼ� ���� byte�� ������ �������� ����, �ڷ����� void�̱� ������ �� byte���� ��.

		cout << *ptr << endl;

		=> error, void�̱� ������ �̴�δ� ���� ������ �� ����.
	*/

	cout << *static_cast<float*>(ptr) << endl;

	return 0;
}