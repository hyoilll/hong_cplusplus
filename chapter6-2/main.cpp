/*
	2. array
*/

#include <iostream>
using namespace std;

void doSomething(int students_scores[])
{
	/*
		매개변수의 students_scores는 내부적으로는 포인터 변수로
		바뀌기에 넘겨 받은 배열 메모리 공간을 가르키는 또 다른 포인터 변수
	*/
	
	cout << &students_scores << endl;
	cout << &students_scores[0] << endl;
	cout << students_scores[0] << endl;
	cout << students_scores[1] << endl;
	cout << students_scores[2] << endl;
	cout << sizeof(students_scores) << endl; // x86 - 포인터 변수라서 4bytes, x64 - 8bytes
}

int main()
{
	const int num_students = 5;

	int students_scores[num_students] = { 1,2,3,4,5 };

	cout << students_scores << endl; 
	//주소로 데이터를 주고 받는게 효율적이기에 배열 이름 자체가 주소로 동작함.
	cout << &students_scores << endl;
	cout << &(students_scores[0]) << endl;
	cout << &(students_scores[1]) << endl;
	cout << &(students_scores[2]) << endl;
	cout << &(students_scores[3]) << endl;
	cout << &(students_scores[4]) << endl;

	cout << sizeof(students_scores) << endl; // 배열 자체의 크기 20bytes
	cout << endl;

	//-------------------------------------------------------------------

	doSomething(students_scores);

	return 0;
}