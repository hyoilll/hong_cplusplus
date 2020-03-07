/*
	char배열 ptr연산으로 null까지 출력
*/

#include <iostream>
using namespace std;

int main()
{
	char ctr[] = "Hello world";

	char* cptr = ctr;

	while (true)
	{
		cout << *(cptr++) << " ";

		if (*(cptr) == '\0')
			break;
	}


	return 0;
}