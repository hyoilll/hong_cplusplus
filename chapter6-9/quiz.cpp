/*
	char�迭 ptr�������� null���� ���
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