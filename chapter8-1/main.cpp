/*
	객체 지향 프로그래밍 / 클래스
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class R
{
private:
	int m_a;
	int m_b;
};

int main()
{
	R r;

	cout << sizeof(r) << endl;
	cout << &r << endl;


	return 0;
}