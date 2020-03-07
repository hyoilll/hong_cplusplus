/*
	2. array
*/

#include <iostream>
using namespace std;

void doSomething(int students_scores[])
{
	/*
		�Ű������� students_scores�� ���������δ� ������ ������
		�ٲ�⿡ �Ѱ� ���� �迭 �޸� ������ ����Ű�� �� �ٸ� ������ ����
	*/
	
	cout << &students_scores << endl;
	cout << &students_scores[0] << endl;
	cout << students_scores[0] << endl;
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;
	cout << sizeof(students_scores) << endl; // x86 - ������ ������ 4bytes, x64 - 8bytes
}

int main()
{
	const int num_students = 5;

	int students_scores[num_students] = { 1,2,3,4,5 };

	cout << students_scores << endl; 
	//�ּҷ� �����͸� �ְ� �޴°� ȿ�����̱⿡ �迭 �̸� ��ü�� �ּҷ� ������.
	cout << &students_scores << endl;
	cout << &(students_scores[0]) << endl;
	cout << &(students_scores[1]) << endl;
	cout << &(students_scores[2]) << endl;
	cout << &(students_scores[3]) << endl;
	cout << &(students_scores[4]) << endl;

	cout << sizeof(students_scores) << endl; // �迭 ��ü�� ũ�� 20bytes
	cout << endl;

	//-------------------------------------------------------------------

	doSomething(students_scores);

	return 0;
}