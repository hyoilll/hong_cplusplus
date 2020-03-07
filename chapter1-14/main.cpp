/*
	��ó������� ù ����
	��ó���� - �����ϱ� ���� ������ ��
	��ó����(preprocessor)�� ���α׷��� �������� �� ������ ������ ����Ǵ� ������ ���α׷�
	��ó: https://boycoding.tistory.com/145 [�ҳ��ڵ�]

*/

#include <iostream>
#include <algorithm>

using namespace std;

//define�� ������ �ش� ���� ������ ���ѵ�
#define MY_NUMBER "Hello World"
#define MAX(a,b) ((a > b) ? a : b)
//#define LIKE_APPLE

int main()
{
	cout << MY_NUMBER << endl;
	cout << MAX(1, 2) << endl;
	cout << std::max(1, 2) << endl;

	
#ifdef LIKE_APPLE //LIKE_APPLE �� ���ǵǾ� ������ ����
	cout << "apple" << endl;
#endif

#ifndef LIKE_APPLE //LIKE_APPLE �� ���ǵǾ� ���� ������ ����
	cout << "orange" << endl;
#endif



	return 0;
}