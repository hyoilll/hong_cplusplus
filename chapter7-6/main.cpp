/*
	인라인 함수
	
	함수 몸체보다 함수를 호출하는 과정이 더 시간이 많이 소요될 경우
	컴파일러가 처리해줌
*/

#include <iostream>
using namespace std;

inline int min(int x, int y)
{
	return x > y ? y : x;
}

int main()
{
	cout << min(5, 6) << endl;
	cout << min(3, 2) << endl;

	/*
		inline
		cout << (5 > 6) ? 6 : 5 << endl;
		cout << (3 > 2) ? 2 : 3 << endl;
	*/

	return 0;
}