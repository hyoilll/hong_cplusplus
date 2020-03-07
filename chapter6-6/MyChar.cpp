/*
	���� �����غ��� strcat_s(), strcmp()
*/

#include <iostream>
#include <cstring>

using namespace std;


void myStrcat_s(char* to, const char* from)
{
	int idx = 0;
	while (true)
	{
		if (to[idx] == '\0')
			break;
		++idx;
	}

	int insert_idx = 0;
	while (true)
	{
		if (from[insert_idx] != '\0')
			to[idx] = from[insert_idx];
		else
		{
			to[idx] = '\0';
			break;
		}

		++idx;
		++insert_idx;
	}

	return;
}

int myStrcmp(const char* ctr1, const char* ctr2)
{
	int idx1 = 0;
	while (true)
	{
		if (ctr1[idx1] == '\0')
			break;
		++idx1;
	}

	int idx2 = 0;
	while (true)
	{
		if (ctr1[idx2] == '\0')
			break;
		++idx2;
	}


	int cnt = 0;

	if (idx1 >= idx2)
		cnt = idx1;
	else
		cnt = idx2;

	for (int i = 0; i < cnt; ++i)
	{
		if (ctr1[i] != ctr2[i])
		{
			return -1;
		}
	}

	return 0;
}

int main()
{
	char source[50] = "world";
	char dest[50] = "hello ";

	myStrcat_s(dest, source);
	/*
		�迭 ��ü�� �����̱⿡ 50bytes �Ҵ�
		cout << sizeof(dest) << endl;

		result�� �ܼ� ������ ���� �� 4bytes �Ҵ�
		cout << sizeof(result) << endl;
	*/

	cout << dest << endl;
	
	if (myStrcmp(dest, source) == 0)
		cout << "equal" << endl;
	else
		cout << "not equal" << endl;

	return 0;
}